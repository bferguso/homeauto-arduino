/*
 *  Simple HTTP get webclient test
 */

#include "Esp8266RemoteStation.h"

/* BME280 includes */
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "BME280Reader.h"
#include "CCS811Reader.h"

#include <SparkFunCCS811.h>

EnvData data;

Esp8266RemoteStation espRemote("office_test");

Adafruit_BME280 bme; // I2C
BME280Reader reader(&bme);

#define CCS811_ADDR 0x5B //Default I2C Address
CCS811 ccs811Sensor(CCS811_ADDR);
CCS811Reader ccs811Reader(&ccs811Sensor);

// END BME280

void setup() {
    Serial.begin(9600);
    // We start by connecting to a WiFi network

    //espRemote.setSendInterval(5000);
    espRemote.setCapability(String("environment_sensor"), String("BME280"));
    espRemote.setCapability(String("air_quality_sensor"), String("CCS811"));
    //espRemote.setBufferInterval(600000);
    espRemote.initServer();

    Serial.println("ESP Config "+espRemote.getConfig());

    delay(100);

    // BME
    if (!bme.begin()) {
        // default settings
        // You can also pass in a Wire library object like &Wire2
        // status = bme.begin(0x76, &Wire2)
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x");
        Serial.println(bme.sensorID(), 16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
    }
    // END BME
    if (!ccs811Sensor.begin())
    {
        Serial.println("Could not find CCS811 sensor");
        while (1) delay(10);
    }
}

void loop() {
    if (espRemote.readyToSendEnv() || espRemote.readyToPrint())
    {
        data = reader.readEnv();
        String errors = ccs811Reader.readEnv(&data);
        if (errors != "")
        {
            Serial.println(errors);
        }
        else
        {
            Serial.println("No CCS811 errors");
        }
        if (espRemote.readyToSendEnv())
        {
            espRemote.sendEnv(data);
        }
        if (espRemote.readyToPrint())
        {
            espRemote.printEnv(data);
        }
    }
    espRemote.handleClient();
}
