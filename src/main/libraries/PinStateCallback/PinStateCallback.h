//
//  Callback to write to a digital pin
//

#ifndef ARDUINO_PINSTATECALLBACK_H
#define ARDUINO_PINSTATECALLBACK_H
#include "RemoteServerCallback.h"

class PinStateCallback : public RemoteServerCallback {
public:
    PinStateCallback(int pinNumber);
    String execute();

private:
    int _pinNumber;
};
#endif //ARDUINO_PINSTATECALLBACK_H
