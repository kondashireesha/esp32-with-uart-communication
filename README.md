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

## 🔄 How UART Works

**UART (Universal Asynchronous Receiver/Transmitter)** is a widely used serial communication protocol. It facilitates full-duplex communication between two devices (like ESP32 and PC).

### UART Communication Process

1. **Baud Rate Setup**: Both devices must be configured at the same baud rate (e.g., 115200 bps).
2. **Data Transmission**:
   - The transmitter converts data into bits and sends:  
     `Start Bit (0) + 8 Data Bits + Optional Parity Bit + Stop Bit(s) (1)`
3. **Data Reception**:
   - The receiver detects the start bit, reads the data bits, and confirms with the stop bit.
   - If a parity bit is present, it verifies the data integrity.

ESP32 has **3 UARTs**:
- UART0 (used for USB communication with the PC),
- UART1, and
- UART2 (can be mapped to GPIOs for device-to-device communication).

## 🧪 Project Behavior

- The ESP32 monitors Serial input (UART0).
- When the user sends any message from the Serial Monitor:
  - LED connected to GPIO2 turns ON.
  - The message is printed back via Serial.
  - LED turns OFF after a delay or on the next message
