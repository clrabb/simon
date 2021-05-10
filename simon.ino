#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "button.h"


void setup()
{
    init_singletons();
    neopixel& pixels = singleton_t< neopixel >::instance();
    pixels.begin();
    pixels.show();

    delay( 5000 );

    button b( 1 );
}

boolean first_time = true;
void loop()
{

    heartbeat& hb = singleton_t< heartbeat >::instance();
    neopixel& pixels = singleton_t< neopixel >::instance();

    if ( first_time )
    {
        pixels.setPixelColor( 0, 70, 0, 0  );
        delay( 5 );
        pixels.show();

        pixels.setPixelColor( 1, 0, 70, 0  );
        delay( 5 );
        pixels.show();

        pixels.setPixelColor( 2, 0, 0, 70  );
        delay( 5 );
        pixels.show();

        pixels.setPixelColor( 3, 70, 70, 0 );
        delay( 5 );



        pixels.show();
        first_time = false;
    }

    hb.beat();
}

void init_singletons()
{
    singleton_t< heartbeat >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< neopixel  >( new neopixel( NUM_NEOPIXELS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800 ) );
}
