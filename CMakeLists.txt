cmake_minimum_required(VERSION 3.17)
project(arduino)

set(CMAKE_CXX_STANDARD 11)

# Arduino Libraries
include_directories(/Users/brettferguson/Documents/Arduino/libraries/Adafruit_BME280_Library/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/SparkFun_CCS811_Arduino_Library/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/Adafruit_Unified_Sensor/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/DHT_sensor_library/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/DHT_sensor_library_for_ESPx/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/Dictionary/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/Queue/src)
include_directories(/Users/brettferguson/Documents/Arduino/libraries/ArduinoJson/src)
include_directories(/Users/brettferguson/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/libraries/ESP8266WiFi/src)
include_directories(/Users/brettferguson/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/libraries/ESP8266WebServer/src)
include_directories(/Users/brettferguson/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.4/libraries/ESP8266HTTPClient/src)
include_directories(/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino)
include_directories(/Applications/Arduino.app/Contents/Java/libraries/WiFi/src)
include_directories(/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/libraries/SoftwareSerial/src)
include_directories(/Applications/Arduino.app/Contents/Java/hardware/tools/avr/avr/include/avr)

include_directories(src/main/libraries/BME280Reader)
include_directories(src/main/libraries/CCS811Reader)
include_directories(src/main/libraries/DHTReader)
include_directories(src/main/libraries/EnvData)
include_directories(src/main/libraries/Esp8266RemoteStation)
include_directories(src/main/libraries/JsonEncoder)
include_directories(src/main/libraries/PressButtonCallback)
include_directories(src/main/libraries/RemoteServerCallback)
include_directories(src/main/sketches/DHTandLCD)
include_directories(src/main/sketches/esp8266_bme280)
include_directories(src/main/sketches/esp8266_dht)
include_directories(src/main/sketches/mechanical_room)
include_directories(src/main/sketches/range_hood_esp8266)
include_directories(venv3/lib/python3.9/site-packages/cffi)

add_executable(arduino
        src/main/libraries/BME280Reader/BME280Reader.cpp
        src/main/libraries/BME280Reader/BME280Reader.h
        src/main/libraries/DHTReader/DHTReader.cpp
        src/main/libraries/DHTReader/DHTReader.h
        src/main/libraries/EnvData/EnvData.cpp
        src/main/libraries/EnvData/EnvData.h
        src/main/libraries/Esp8266RemoteStation/Esp8266RemoteStation.cpp
        src/main/libraries/Esp8266RemoteStation/Esp8266RemoteStation.h
        src/main/libraries/JsonEncoder/JsonEncoder.cpp
        src/main/libraries/JsonEncoder/JsonEncoder.h
        src/main/libraries/PressButtonCallback/PressButtonCallback.cpp
        src/main/libraries/PressButtonCallback/PressButtonCallback.h
        src/main/libraries/RemoteServerCallback/RemoteServerCallback.h
        src/main/sketches/DHTandLCD/DHTandLCD.ino
        src/main/sketches/esp8266_bme280/esp8266_bme280.ino
        src/main/sketches/esp8266_dht/esp8266_dht.ino
        src/main/sketches/mechanical_room/mechanical_room.ino
        src/main/sketches/range_hood_esp8266/range_hood_esp8266.ino
        venv3/lib/python3.9/site-packages/ansible_collections/ansible/windows/tests/integration/targets/win_command/files/crt_setmode.c
        venv3/lib/python3.9/site-packages/cffi/_cffi_errors.h
        venv3/lib/python3.9/site-packages/cffi/_cffi_include.h
        venv3/lib/python3.9/site-packages/cffi/_embedding.h
        venv3/lib/python3.9/site-packages/cffi/parse_c_type.h
        venv3/lib/python3.9/site-packages/markupsafe/_speedups.c)
