# NodeMCU_AdafruitIO_BME280

//Thank you Adafruit, r/esp8266, r/esp32, and the open source communities that have all contributed code and knowledge to make projects like this possible. 

<img width="1792" alt="Screen Shot 2022-01-13 at 8 34 30 AM" src="https://user-images.githubusercontent.com/57408800/149534980-d1546cdd-539b-4bed-8a30-7e0371cd0cbd.png">

This is a simple project to create and enviromental sensor system using adafruit IO. Everything is assemebled on a breadboard to make this quick and easy to order/assemble/flash/deploy.  


Parts list: 
1. NodeMCU or Wemos D1 Mini 
2. BME 280 sensor 
3. Breadboard/PCB 
4. Wires for assembly 
5. Wemos D1 battery shield (Optional) 


Wiring Diagram: 

![04_fritzing_Ps1S7zdiF9](https://user-images.githubusercontent.com/57408800/149536507-9f4553a0-7166-4fc1-8b2a-91322001be01.jpg)



Pinout:  
MCU -> BME280   
3.3v to VIN   
Gnd to Gnd   
D2 to SDA  
D1 to SCLA  




The Sketch is setup and only requires you to enter the following: 
1. Wifi Name (config.h)
2. Wifi Password (config.h)
3. Name of the sensor/group/feed   (Main.cpp)
  



The Sketch loops through the following: 

1. Wake up 
2. Connect to Adafruit IO 
3. Read BME Temp/Humidity (Pressure too if you want) 
4. Send the BME Readings to Adafruit IO 
5. Go to sleep for 10 minutes
6. Reset and repeat using GIOPin 16/RST Pin 

  
    
This guide was very helpful:
https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test


For an enclosure Im currently using something like this: 
https://www.amazon.com/Sunnyglade-Dustproof-Waterproof-Universal-Electrical/dp/B07PZT8FWD/ref=sr_1_4_sspa?crid=1X2KWC9X2WDR&keywords=waterproof%2Benclosure&qid=1642173280&sprefix=waterproof%2520enclosure%2Caps%2C47&sr=8-4-spons&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEySEtUMjdaTE1DNklHJmVuY3J5cHRlZElkPUEwNzY0MjMyT0dLT0IwNjBZQ01PJmVuY3J5cHRlZEFkSWQ9QTA4NjY2NzExN0NJTVpQVjdMWTFOJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ&th=1

However a 3d print file will be available soon after prototyping/testing.  Its reccomended to use a narrow rectangle mounted vertically with vent holes on the top and bottom to create airflow and allow proper venting/readings.  Always place the MCU on the top of the enclosure and the BME towards the bottom to avoid readings that include the heat of the MCU.  (It is worth noting that the MCU is on for a VERY short amount of time and likely wouldn't affect the temp reading given the current loop configuration.)



