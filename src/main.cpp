#include <Arduino.h>
#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "panel_list.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif 

using namespace simon;

void init_singletons()
{
    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< neopixel   >( new neopixel( NUM_NEOPIXELS, NEOPIXEL_PIN, NEO_RGB + NEO_KHZ800 ) );
    singleton_t< panel_list >( new panel_list() );
}

void setup()
{
    init_singletons();
    neopixel& pixels = singleton_t< neopixel >::instance();
    pixels.begin();
    pixels.show();

    delay( 1000 );

}

void loop()
{

    heartbeat&  hb = singleton_t< heartbeat >::instance();
    panel_list& pl = singleton_t< panel_list >::instance();
    
    hb.beat();
    pl.tick();
}


