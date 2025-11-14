# Pump Driver

STM32F427 驱动与示例工程。包含 CAN、TIM、USART、FreeRTOS 等基础外设配置与泵控驱动示例。

## 构建与烧录（VS Code）
- 任务：
  - `build`：调用 EIDE 构建
  - `flash`：下载到目标设备
  - `build and flash`：构建并下载
  - `clean`：清理

在 VS Code 命令面板或“终端 -> 运行任务”中选择相应任务。

## 工程结构
- `Core/`：应用入口与外设初始化
- `Drivers/`：STM32 HAL、CMSIS 等第三方依赖（保留其各自 LICENSE）
- `Middlewares/Third_Party/FreeRTOS/`：FreeRTOS 内核（MIT 许可）
- `UserCode/`：用户层业务代码（泵控驱动、BSP 等）

## 许可
- 本仓库代码采用 MIT 许可证（见 `LICENSE`）。
- 第三方组件许可请见 `THIRD_PARTY_LICENSES.md` 及对应目录下的 `LICENSE.txt`。

## 贡献
- 建议分支：`feature/*`、`fix/*`；主分支 `main` 受保护。
- 提交信息遵循 Conventional Commits：如 `feat: add pump speed control`。
- 若向组织仓库提交，请在 `HITSZ-WTR2026` 下创建/选择目标仓库后推送。