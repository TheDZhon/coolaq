#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>

#include "pin_map_config.h"

namespace hw
{
    class TemperatureSensors
    {
    public:
        explicit TemperatureSensors (int frig_temp_sensor_id = 0, int env_temp_sensor_id = 1);
        void setup ();

        size_t connectedSensors ();

        void refresh ();

        float frigTemperatureC () const;
        float envTemperatureC () const;
    private:
        TemperatureSensors (const TemperatureSensors&) = delete;
        TemperatureSensors& operator= (const TemperatureSensors&) = delete;

        OneWire one_wire_;
        DallasTemperature sensors_;

        int frig_temp_sensor_id_;
        int env_temp_sensor_id_;

        float frig_temp_sensor_val_;
        float env_temp_sensor_val_;
    };
}