#include "light.h"
#include "singleton_t.h"
#include <Arduino.h>

using namespace simon;

void
light::turn_on()
{
    neopixel& pixel_array = singleton_t< neopixel >::instance();
    pixel_array.setPixelColor( 
            this->pixel_number(),
            this->red_value(),
            this->green_value(),
            this->blue_value()
        );

    pixel_array.show();
}

void
light::turn_off()
{
    neopixel& pixel_array = singleton_t< neopixel >::instance();
    pixel_array.setPixelColor(
            this->pixel_number(),
            0,
            0,
            0
        );

    pixel_array.show();
}
