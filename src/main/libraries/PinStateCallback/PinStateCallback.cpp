#include "PinStateCallback.h"
#include <Arduino.h>
#include "JsonEncoder.h"

PinStateCallback::PinStateCallback(int pinNumber) {
   _pinNumber = pinNumber;
}

String PinStateCallback::execute()
{
    return JsonEncoder::openBrace
           + JsonEncoder::wrapValue("pinState", digitalRead(_pinNumber))
           + JsonEncoder::closeBrace;
}