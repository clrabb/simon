#include "light.h"
#include <Arduino.h>

void
light::turn_on()
{
    digitalWrite( this->light_pin(), HIGH ); 
}

void
light::turn_off()
{
    
}

void
light::blink()
{
    
}
