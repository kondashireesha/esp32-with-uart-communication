# 🚀 ESP32 UART Communication
This project demonstrates basic **UART (Universal Asynchronous Receiver/Transmitter)** communication using an **ESP32** microcontroller. It toggles an **LED connected to GPIO2** ON or OFF each time a message is received through the **Serial Monitor**.
UART-based ESP32 project using C/C++. An LED on GPIO2 toggles ON/OFF each time user input is entered via the Serial Monitor. Built with PlatformIO, simulated in Wokwi, and ideal for learning serial communication and GPIO control.
## 🔧 Project Details
- **Board**: ESP32 DevKit v1
- **Platform**: PlatformIO (VS Code)
- **Language**: C/C++
- **Framework**: ESP-IDF or Arduino (via PlatformIO)
- **Simulation**: Wokwi (Optional)
## 🛠️ Hardware Requirements
- ESP32 DevKit v1
- USB Cable (for programming and Serial Communication)
- Onboard LED (connected to GPIO2) or
- External LED + 220Ω Resistor (connected to GPIO2)
## 📂 Project Structure
esp32-with-uart-communication/
├── include/
├── lib/
├── src/
│ └── main.c # Main source file with UART + LED logic
├── platformio.ini # PlatformIO configuration file
├── .vscode/ # Optional: VSCode settings
├── README.md # Project documentation
