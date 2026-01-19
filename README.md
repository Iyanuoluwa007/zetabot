<p align="center">
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_173936_01_saved.jpg?raw=true" alt="ZetaBot Robot" width="380"/>
</p>

# 🤖 ZetaBot  
### Mobile Control Robotic Arm on Robotic Tank Wheel

> A low-cost, mobile robotic platform combining a robotic arm and tank-wheel locomotion, controlled via a custom Android app with live video streaming.

---

## 📌 Project Overview

**ZetaBot** is a research focused mobile robot designed for field applications such as agriculture, inspection, and robotics experimentation.  
It integrates a **robotic arm**, **tank wheel mobility**, **Bluetooth control**, and **Wi-Fi video streaming** using affordable, open-source hardware.

The system is controlled through a **custom Android application** built with Kodular, enabling real-time motion control and manipulation.

---

## 🧠 Key Features

✅ Mobile tank-wheel navigation  
✅ 6 - DOF robotic arm control  
✅ Android app control (Bluetooth)  
✅ Live video streaming over Wi-Fi  
✅ Low-cost, modular, and scalable design  
✅ LCD status feedback  
✅ Open-source software stack  

---

## ⚙️ System Architecture
**Control Flow:**

<p align="center">
  <img 
    src="https://raw.githubusercontent.com/Iyanuoluwa007/zetabot/main/Screenshot%202026-01-08%20233002.png" 
    alt="ZetaBot System Architecture"
    width="500"
  />
</p>

- Android App → Bluetooth → ESP32-CAM  
- ESP32-CAM → Motor Driver (movement)  
- ESP32-CAM → Arduino Nano (arm & LCD)  
- ESP32-CAM → Wi-Fi → Live video stream  

---

## 🧩 Hardware Components

- ESP32-CAM (Wi-Fi + Bluetooth + camera)
- Arduino Nano
- L298N Motor Driver
- MG996R / MG995 Servo Motors
- 12V DC Geared Motors (Tank Wheels)
- 16×2 I2C LCD Display
- 18650 Lithium Batteries (3S & 2S)
- XL6019 DC - DC Boost Converter
- Solar Panel (5.5V, optional)
- Android Smartphone (Controller)

---

## 💻 Software & Tools

- **Arduino IDE** – Firmware development  
- **Kodular** – Android app builder  
- **ESP32 Camera Web Server** – Live video streaming  
- **C / C++** – Embedded programming  

---

## 📱 Mobile Application

The Android app is divided into two sections:

🔹 **Tank Control**
- Forward / Backward
- Left / Right
- Stop
- Headlight control

🔹 **Robotic Arm Control**
- Waist rotation  
- Shoulder movement  
- Elbow control  
- Grip open/close  
- Roll & pitch control  

---

## 🎥 Live Video Streaming

- ESP32-CAM streams live footage over Wi-Fi  
- Accessed via browser using ESP32 IP address  
- Useful for remote inspection and monitoring  

---

## 🧪 Results

✔ Stable movement and arm manipulation  
✔ Reliable Bluetooth communication  
✔ Clear live video stream over local Wi-Fi  
✔ Successful integration of all subsystems  

---

## 🚀 Applications

- Agricultural field research  
- Robotics education & prototyping  
- Remote inspection  
- Mechatronics research platform  
- Smart surveillance experiments  

---

## ⚠️ Limitations

- Bluetooth range limited compared to full internet control  
- Requires stable Wi-Fi for video streaming  
- Arm payload limited by servo torque  

---

## 🔮 Future Improvements

- Full internet based control (IoT)
- Autonomous navigation (SLAM)
- Object detection using computer vision
- Stronger servos & metal arm structure
- Cloud based monitoring dashboard

---

## 🎓 Academic Context

**Project Title:**  
*Design and Construction of a Mobile Control Robot Arm on a Robotic Wheel*

**Degree:**  
Bachelor of Engineering (B.Eng.) – Electrical & Information Engineering  

**Institution:**  
Landmark University, Nigeria  

**Year:**  
2022  

---

## 👤 Author

**Iyanuoluwa Enoch Oke**  
Robotics & AI Engineer  
📧 Email: [oke.iyanuoluwa12@gmail.com](mailto:oke.iyanuoluwa12@gmail.com)
🔗 LinkedIn: [Iyanuoluwa Enoch Oke](https://www.linkedin.com/in/iyanuoluwa-enoch-oke/)

---

## 📜 License

Permission is granted to use, modify, and build upon this work for academic and research purposes, provided appropriate attribution is given.

---

⭐ *If you like this project, consider giving it a star!*  


---

## 🖼️ Project Gallery

<p align="center">
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_173936_01_saved.jpg?raw=true" width="260"/>
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_181042_01_saved.jpg?raw=true" width="260"/>
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_181103_01_saved.jpg?raw=true" width="260"/>
</p>

<p align="center">
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_181203_01_saved.jpg?raw=true" width="260"/>
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_181349_01_saved.jpg?raw=true" width="260"/>
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Building/20210815_181430_01.jpg?raw=true" width="260"/>
</p>


### The app interface:
<p align="center">
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Screenshot_20260117_002237.jpg?raw=true" width="520"/>
  <img src="https://github.com/Iyanuoluwa007/zetabot/blob/main/Screenshot_20260117_002242.jpg?raw=true" width="260"/>
</p>

