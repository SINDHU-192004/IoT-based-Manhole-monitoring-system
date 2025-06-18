#  IoT-Based Manhole Monitoring System

An innovative real-time monitoring solution using IoT to detect drainage overflow, toxic gas accumulation, and manhole cover tampering—aimed at improving public safety and supporting smart city infrastructure.


##  Project Overview

In modern urban environments, the timely maintenance of manholes is essential to avoid hazards such as gas leaks, water overflow, and unauthorized access. Traditional inspection methods are reactive, costly, and inefficient.

This project presents an **IoT-Based Manhole Monitoring System** using NodeMCU ESP8266 and multiple sensors to detect:

*  Toxic gas levels (MQ-2 Gas Sensor)
*  Drainage overflow (Ultrasonic Sensor)
*  Manhole cover displacement (Tilt Sensor)

The system sends **automated email alerts** and provides a **web-based dashboard** (Blynk) for real-time monitoring and prompt response.

---

##  Features

*  Real-time sensor data monitoring
*  Automated email and app notifications on hazard detection
*  Web and mobile dashboard interface via Blynk
*  Modular, scalable design for smart city integration
*  Serial output for development/debugging

---

##  Technologies & Components
###  Hardware

*  NodeMCU ESP8266 (WiFi-enabled microcontroller)
*  MQ-2 Gas Sensor
*  JSN-SR04T Waterproof Ultrasonic Sensor
*  KY-017 Mercury Tilt Switch
*  Breadboard & jumper wires

###  Software & Tools

* Arduino IDE (Firmware development)
* Blynk App (Dashboard + Notifications)
* SMTP Email Alerts
* Serial Monitor (Testing & Debugging)

---

##  Working Principle

1. **Water Level Monitoring**: Ultrasonic sensor detects high water level indicating possible overflow.
2. **Gas Detection**: MQ-2 sensor identifies harmful gas concentrations (e.g., methane, CO).
3. **Tilt Detection**: Mercury tilt sensor senses displacement or unauthorized access of the manhole cover.
4. **Data Transmission**: Sensor data is sent via WiFi using NodeMCU.
5. **Alerts**: On anomaly detection, alerts are sent via Blynk notifications and email.
6. **Monitoring**: A user-friendly Blynk dashboard displays live sensor readings and event logs.

---

## Circuit Diagram & Setup

* Schematic: See `circuit_diagram.png` (add image to repo)
* Wiring:

  * MQ-2 Gas → A0
  * Ultrasonic: TRIG → D6, ECHO → D7
  * Tilt Sensor → D5

---

##  Output Screenshots

*  Blynk App Notifications
*  Email Alerts
*  Serial Monitor Logs

---

##  How to Run

1. Connect all hardware as per the circuit diagram.
2. Flash the `manhole_monitoring.ino` sketch from the Arduino IDE.
3. Replace WiFi credentials and Blynk token in the code:

   ```cpp
   char ssid[] = "YourWiFi";
   char pass[] = "YourPassword";
   char auth[] = "YourBlynkToken";
   ```
4. Open Serial Monitor for debug output.
5. Monitor data and alerts on the Blynk app.

---

##  Limitations

*  Dependent on stable Wi-Fi connectivity
*  Power supply in remote manholes can be challenging
*  Sensor reliability in harsh environments
*  Requires secure communication to prevent data breaches

---

##  Future Enhancements

* Integration with **LoRaWAN** or **NB-IoT** for better range
* Solar-powered operation for sustainability
* Extended dashboard with geolocation and analytics

## Snapshots

## CIRCUIT DIAGRAM
![image](https://github.com/user-attachments/assets/ada9588d-b843-4403-ac6e-eed11e8e5894)

## OUTPUT
![image](https://github.com/user-attachments/assets/698e17c5-4832-4261-bf5c-00756a60d88e)
![image](https://github.com/user-attachments/assets/0fe72c93-1f0d-4a3b-b261-4fec2151ef7a)
![image](https://github.com/user-attachments/assets/44df5991-4066-4f26-b3d9-92c366271017)
