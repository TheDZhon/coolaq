#include "temperature_sensors.h"

namespace hw
{
    TemperatureSensors::TemperatureSensors (int frig_temp_sensor_id, int env_temp_sensor_id):    
        one_wire_ (PINs::kOneWireBus),
        sensors_ (&one_wire_),
        frig_temp_sensor_id_ (frig_temp_sensor_id),
        env_temp_sensor_id_ (env_temp_sensor_id),
        frig_temp_sensor_val_ (-999.f),
        env_temp_sensor_val_ (-999.f)
    {}

    void TemperatureSensors::refresh () 
    {
        sensors_.requestTemperatures ();

        frig_temp_sensor_val_ = sensors_.getTempCByIndex (frig_temp_sensor_id_);
        env_temp_sensor_val_ = sensors_.getTempCByIndex (env_temp_sensor_id_);
    }

    float TemperatureSensors::frigTemperatureC () const
    {
        return frig_temp_sensor_val_;
    }

    float TemperatureSensors::envTemperatureC () const
    {
        return env_temp_sensor_val_;
    }
}