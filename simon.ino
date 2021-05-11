#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "button.h"
#include "button_panel.h"

using namespace simon;

abstract_button_panel* panels[ 4 ];
const short RED_IDX    = 0;
const short GREEN_IDX  = 1;
const short YELLOW_IDX = 2;
const short BLUE_IDX   = 3;

void setup()
{
    init_singletons();
    neopixel& pixels = singleton_t< neopixel >::instance();
    pixels.begin();
    pixels.show();

    delay( 1000 );

    panels[ RED_IDX    ] = new red_button_panel();
    panels[ GREEN_IDX  ] = new green_button_panel();
    panels[ YELLOW_IDX ] = new yellow_button_panel();
    panels[ BLUE_IDX   ] = new blue_button_panel();
}

boolean first_time = true;
void loop()
{

    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();
}

void init_singletons()
{
    singleton_t< heartbeat >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< neopixel  >( new neopixel( NUM_NEOPIXELS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800 ) );
}
