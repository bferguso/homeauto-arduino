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
    // Sets the environment data in the envData.
    // IF not successful looks returns an error message of any errors that occurred
    String readEnv(EnvData *envData);
    bool calibrate(EnvData *envData);
    String getSensorError();

private:
    CCS811 *_ccs811;
};

#endif