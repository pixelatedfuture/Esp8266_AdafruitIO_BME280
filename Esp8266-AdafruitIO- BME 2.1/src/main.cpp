
/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"
#include <Arduino.h>
#include <AdafruitIO.h>
#include <AdafruitIO_MQTT.h>
#include <ArduinoHttpClient.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;

// set up the feeds to adafruitIO
//s1 indications which sensor / feed
//You can change s1 to anything you want but must replace here, as well as the sender in the void loop
AdafruitIO_Feed *s1temp = io.feed("housefeeds.s1temp");
AdafruitIO_Feed *s1humidity = io.feed("housefeeds.s1humidity");

void setup()
{

  Serial.begin(115200);
  Serial.setTimeout(2000);

  //start the BME 280 @ Ox76

  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }

  //Some folks want the LED on the chip on so you know its powered.  I shut it off to save battery.
  // pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(LED_BUILTIN, HIGH);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED)
  {
    Serial.println(io.statusText());
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop()
{
  io.run();
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.

  // save the current temp to the Temp feed
  s1temp->save(1.8 * bme.readTemperature() + 32);
  //save the current humidity to the humidity feed
  s1humidity->save(bme.readHumidity());

  //Print to the Serial Monitor
  Serial.print("Temperature = ");
  Serial.print(1.8 * bme.readTemperature() + 32);
  Serial.println(" *F");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  // Deep sleep mode for 30 seconds, the ESP8266 wakes up by itself when GPIO 16 (D0 in NodeMCU board) is connected to the RESET pin
  Serial.println("I'm awake, but I'm going into deep sleep mode for 10 minutes");
  //Send the ESP to deepsleep for XX microseconds (Just google the conversion)
  ESP.deepSleep(6e+8);
}
