# Electric Pole Tilt Monitoring IoT System

## 📌 Overview
This project monitors the tilt/rotation of an electric pole using the **MPU6050 accelerometer & gyroscope sensor** and sends real-time data to **ThingSpeak IoT cloud**.  
Designed for detecting pole tilt for **public safety & infrastructure monitoring**.

## 🚀 Features
- Real-time pole tilt monitoring
- Detects unsafe & danger tilt angles
- Sends data to ThingSpeak cloud
- Works on WiFi (ESP32 / Wokwi simulation)
- Serial monitor live status messages

## 🧠 Tech Stack
- ESP32 
- MPU6050 Gyro + Accelerometer
- ThingSpeak Cloud
- Wokwi IoT Simulator

## 🧩 Components Used
| Component | Quantity |
|----------|---------|
ESP32 / NodeMCU | 1  
MPU6050 Sensor | 1  
WiFi Network | -  
ThingSpeak Channel | 1  

## 🔗 Simulation Link
Wokwi Online Simulation: *(https://wokwi.com/projects/410367786725774337)*  


## 🧭 How It Works
- Reads tilt angles on **X, Y, Z axes**
- Converts gyro data to degrees
- Classifies as:  
  - ✅ Safe  
  - ⚠️ Unsafe  
  - 🚨 Danger  
- Sends values to ThingSpeak fields

## 📊 ThingSpeak Fields
| Field | Data |
|-------|------|
Field 1 | X-axis tilt  
Field 2 | Y-axis tilt  
Field 3 | Z-axis tilt  


