# APM32F103 DHT11 温湿度采集示例 / APM32F103 DHT11 Temperature and Humidity Example

[中文](#中文说明) | [English](#english)

## 中文说明

本项目演示 APM32F103 读取 DHT11 温湿度传感器，并通过 USART1 输出测量结果。

### 功能与环境

- 目标 MCU/开发板：APM32F103 / APM32F103 MINI
- 传感器：DHT11
- 串口：USART1，115200 8N1
- 工程：Keil MDK-ARM
- 主要代码：`dht11.c/.h`、`main.c`

### 使用方法

1. 按工程中的 GPIO 定义连接 DHT11 数据线，并确认供电及上拉电阻。
2. 打开 `GPIO_Toggle.uvprojx`，检查目标器件及引脚配置。
3. 编译并下载程序。
4. 将 USART1 连接至串口工具，设置为 115200 8N1。
5. 观察输出的温度与湿度数据。

### 注意事项

DHT11 对时序较敏感。修改系统时钟、优化等级或 GPIO 后，应重新验证延时。仓库中部分工程名称沿用了 GPIO Toggle 模板，请以实际 DHT11 源码功能为准。

### 技术支持

更多资料请访问：[www.geehy.com](https://www.geehy.com/)。

---

## English

This project demonstrates DHT11 temperature and humidity acquisition on the APM32F103 and outputs the measurements through USART1.

### Features and environment

- Target MCU/board: APM32F103 / APM32F103 MINI
- Sensor: DHT11
- Serial output: USART1, 115200 8N1
- Project: Keil MDK-ARM
- Main code: `dht11.c/.h` and `main.c`

### Usage

1. Connect the DHT11 data pin according to the project GPIO definitions and verify power and pull-up requirements.
2. Open `GPIO_Toggle.uvprojx` and check the target device and pin configuration.
3. Build and program the project.
4. Connect USART1 to a serial utility configured for 115200 8N1.
5. Observe the reported temperature and humidity.

### Notes

DHT11 communication is timing-sensitive. Revalidate the delay implementation after changing the system clock, optimization level, or GPIO configuration. Some project names retain the original GPIO Toggle template name; refer to the DHT11 source code for the actual behavior.

### Support

For more resources, visit [www.geehy.com](https://www.geehy.com/).
