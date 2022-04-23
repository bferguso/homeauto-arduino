#include "CCS811Reader.h"
#include "EnvData.h"

CCS811Reader::CCS811Reader(CCS811 *ccs811) {
    _ccs811 = ccs811;
}

EnvData CCS811Reader::readEnv() {
    EnvData envData = EnvData();
    readEnv(&envData);
}

String CCS811Reader::readEnv(EnvData *envData) {
    if(_ccs811->dataAvailable())
    {
        _ccs811->readAlgorithmResults();
        envData->co2 = _ccs811->getCO2();
        envData->voc = _ccs811->getTVOC();
        //This sends the temperature data to the CCS811
        if (!this->calibrate(envData))
        {
            return "Unable to calibrate sensor";
        }
        return "";
    }
    else if (_ccs811->checkForStatusError())
    {
        //If the CCS811 found an internal error, print it.
        return getSensorError();
    }
    return "";
}

bool CCS811Reader::calibrate(EnvData *envData) {
    if (envData->temperature && envData->humidity)
    {
        _ccs811->setEnvironmentalData(envData->humidity, envData->temperature);
        return true;
    }
    return false;
}

//printSensorError gets, clears, then prints the errors
//saved within the error register.
String CCS811Reader::getSensorError()
{
    uint8_t error = _ccs811->getErrorRegister();
    String returnVal;

    if (error == 0xFF) //comm error
    {
        returnVal = "Failed to get ERROR_ID register.";
    }
    else
    {
        returnVal = "Error: ";
        if (error & 1 << 5)
            returnVal = returnVal + "HeaterSupply";
        if (error & 1 << 4)
            returnVal = returnVal + "HeaterFault";
        if (error & 1 << 3)
            returnVal = returnVal + "MaxResistance";
        if (error & 1 << 2)
            returnVal = returnVal + "MeasModeInvalid";
        if (error & 1 << 1)
            returnVal = returnVal + "ReadRegInvalid";
        if (error & 1 << 0)
            returnVal = returnVal + "MsgInvalid";
    }
    return returnVal;
}
