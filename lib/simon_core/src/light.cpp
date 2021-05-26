#include "light.h"
#include "singleton_t.h"
#include <Arduino.h>

using namespace simon;

simon::light::light()
{
    this->m_is_on = false;
}

void
simon::light::init_once()
{
    static bool once = []()
    {
        neopixel& np = singleton_t< neopixel >::instance();
        np.begin();
        np.show();
        Serial.println( "inited neopixels" );
        return true;
    }();
}

void
simon::light::turn_on()
{
    if ( this->is_on() )
        return;  // Early out if we are already on.


    neopixel& pixel_array = singleton_t< neopixel >::instance();
    pixel_array.setPixelColor( 
            this->pixel_number(),
            this->red_value(),
            this->green_value(),
            this->blue_value()
        );

    this->is_on( true );

    pixel_array.show();
}

void
simon::light::turn_off()
{
    if ( this->is_off() )
        return; // Early out if off

    neopixel& pixel_array = singleton_t< neopixel >::instance();
    pixel_array.setPixelColor(
            this->pixel_number(),
            0,
            0,
            0
        );

    this->is_on( false );

    pixel_array.show();
}
