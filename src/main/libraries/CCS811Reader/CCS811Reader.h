/*
 * Library for CCS811 sensor which reads the sensor and returns data in an EnvData object
 * The CCS sensor needs burn-in of 48hours and a run-in of 20 minutes
*/

#ifndef CCS811Reader_h
#define CCS811Reader_h

/* CCS811 includes */
#include <SparkFunCCS811.h>
#include <EnvData.h>

class CCS811Reader {
public:
    CCS811Reader(CCS811 *ccs811);

    EnvData readEnv();
    bool readEnv(EnvData *envData);

private:
    CCS811 *_ccs811;
};

#endif