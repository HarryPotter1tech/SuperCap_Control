# SUPERCAP 

简述：基于 STM32G4 的超级电容管理与闭环控制项目。代码按功能分层，便于替换算法或移植外设。

### 快速上手
- 依赖：STM32 工具链（arm-none-eabi）、CMake、Ninja（或 MSVC 工具链）、VS Code（推荐 CMake Tools 插件）。
- 本地构建（Windows，已生成 build）：  
  cd d:\supercap\codes\SUPERCAP\build\Debug  
  cmake --build . --config Debug
- 在 VS Code 中打开仓库，使用 CMake Tools 导入并调试 main。

### 代码目录
- Core/Inc, Core/Src：CubeMX 生成的 MCU 外设初始化与中断入口（ADC、HRTIM、TIM、GPIO 等）。  
- User/：项目代码，按模块分组：
  - data/：常量与数据结构（const_data.h、module_data.h）。  
  - interface/：模块头文件与回调接口（HAL_callback.h、Data_collect.h、MOS_driver.h、CAN_communicate.h）。  
  - math_tools/：算法实现（ADC_Calibration、PID）。  
  - v1/src、v2/src：C / C++ 不同版本的模块实现。  
  - test/：测试用例（主机或模拟测试）。

### 主要模块
- HAL 回调（User/v1/src/HAL_callback.c）  
  - 中断入口：ADC 完成、HRTIM Compare、定时器回调，调用数据处理与控制逻辑。
- Data_collect（采样层）  
  - HRTIM 触发 ADC 采样，ADC 回调写入 datacollect（原始 counts / 采样缓冲）。
- ADC_Calibration（标定）  
  - 两点校准：offset + scale。counts -> Vadc -> Vreal（再乘分压倍数）。  
  - 若回调频繁，建议回调只存 counts，主循环/定时器做浮点校准。
- PID_controller（控制器）  
  - 电流环 / 电压环 / 功率环，按 TIM6/TIM7/TIM1 周期计算输出。
- MOS_driver（驱动层）  
  - 根据 PID 输出设置 MOS（PWM 或驱动逻辑）。
- CAN_communicate（通信）  
  - 接收目标功率与使能，定期发送状态（TIM16 触发）。
  具体设计见https://fa4g5no1b1f.feishu.cn/wiki/AhU2wcN2ditQpXkVa6RcQfOXnyc

### 重要注意事项
- datacollect 的生命周期：建议在单一 .c 中定义实例或在 main 中创建并通过注册函数（hal_callback_set_datacollect）一次性传入回调模块，回调无需重复注册。    
- 回调中保持轻量：避免大量浮点运算或阻塞，复杂计算可移到定时器任务或主循环。

### 测试与调试
- 测试用例在 User/test/。在主机或支持 C++ 的环境编译运行这些测试以验证控制算法与 PWM 输出逻辑。  
- 调试方法见https://fa4g5no1b1f.feishu.cn/wiki/MsbMw05AsiN0lbkC2NecwQ2knag

### 维护建议
- 头文件仅做声明（types / extern / prototypes），变量实体放 .c。避免头文件直接定义导致重定义或类型冲突。  
- 将硬件常数（ADC 位宽、Vref、分压比）集中管理在 const_data.h，便于校准与移植。

