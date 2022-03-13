#include "CCS811Reader.h"
#include "EnvData.h"

CCS811Reader::CCS811Reader(CCS811 *ccs811) {
    _ccs811 = ccs811;
}

EnvData CCS811Reader::readEnv() {
    EnvData envData = EnvData();
    readEnv(&envData);
}

bool CCS811Reader::readEnv(EnvData *envData) {
    if(_ccs811->dataAvailable())
    {
        _ccs811->readAlgorithmResults();
        envData->co2 = _ccs811->getCO2();
        envData->voc = _ccs811->getTVOC();
        //This sends the temperature data to the CCS811
        if (envData->temperature && envData->humidity)
        {
            _ccs811->setEnvironmentalData(envData->humidity, envData->temperature);
        }
        return true;
    }
    return false;
}
