# IoT-Enabled-Irrigation-System

## Overview

This project implements an IoT-driven precision irrigation system that monitors soil moisture, temperature, and humidity in real time, and automates water pump control accordingly. It integrates Arduino Nano + NodeMCU ESP8266 + mobile app (Blynk), offering both offline usability (LCD display) and remote accessibility (cloud dashboard + push alerts).

Designed as a low-cost solution for smart agriculture and urban gardening, it reduces water wastage, enhances plant care, and enables real-time monitoring via smartphone.

## Key Features

* IoT Integration – Live sensor data transmitted via ESP8266 WiFi to the Blynk IoT cloud.

* Mobile App Control – Remote irrigation management with manual override, live dashboard, and push notifications.

* Automated Pump Control – Relay-based irrigation triggered when soil moisture drops below threshold.

* Data Visualization – Real-time monitoring of moisture, temperature, humidity, and pump status.

* Offline LCD Display – 16x2 LCD showing all sensor data for on-site monitoring.

* Smart Alerts – Instant mobile notifications for pump ON/OFF events.

* Future Enhancements – Solar-powered deployment, weather-API integration, predictive irrigation schedules.

## Circuit Diagram

![Alt text]([myimage.png](https://github.com/manisha-1112/IoT-Enabled-Irrigation-System/blob/main/circuit.png))


## Tech Stack

* Hardware: Arduino Nano, NodeMCU ESP8266, Soil Moisture Sensor, DHT11, Relay Module, 16x2 LCD

* Software: Arduino IDE (C/C++), Blynk IoT Cloud, MQTT/HTTP protocols

* Mobile App: Blynk Dashboard (custom widgets for monitoring and control)

* Other Tools: Serial Monitor for debugging, Cloud logging

## How It Works

* Sensors read real-time soil moisture, temperature, and humidity.

* Arduino logic compares soil moisture with a threshold.

* Relay module automatically controls the pump.

* ESP8266 transmits live data to the Blynk IoT cloud.

* Mobile App displays readings and allows remote pump control.

* Notifications alert the user when pump state changes.

## Project Prototype Image 

![Alt text]([images/myimage.png](https://github.com/manisha-1112/IoT-Enabled-Irrigation-System/blob/main/prototype.png))

## Future Enhancements

* Integration with weather APIs for predictive irrigation.

* Solar-powered, battery-operated standalone deployment.

* AI-driven crop-specific irrigation recommendations.

* Enhanced data analytics & visualization dashboards.


## Impact

* Provides a low-cost, IoT-enabled smart farming solution
* Reduces water wastage by ~40% through precision irrigation
* Empowers users with real-time monitoring & remote control
* Demonstrates potential for scalable smart agriculture systems
