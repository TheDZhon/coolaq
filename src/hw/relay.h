#pragma once

namespace hw
{
    class Relay 
    {
        explicit Relay ();
        ~Relay ();

        void setup ();

        bool state () const;
        void setState (bool on) const;
    };
}