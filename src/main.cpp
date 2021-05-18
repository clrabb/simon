#include <Arduino.h>
#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "panel_list.h"
#include "junk.h"

#ifndef LED_BUILTIN
//#define LED_BUILTIN 13
#endif 

#ifndef UNIT_TEST

using namespace simon;

void init_singletons()
{
    Serial.println( "In init_singletons()" );
    singleton_t< neopixel >( new neopixel( panel_list::NUM_PANELS, NEOPIXEL_PIN, NEO_RBG + NEO_KHZ800 ) );
    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< panel_list >( new panel_list() );
    
    Serial.println( "All singletons init'd" );
}

void setup()
{
    Serial.begin( 115200 );
    init_singletons();

    panel_list& pl = singleton_t< panel_list >::instance();
    pl.random_lightshow();

    pinMode( LED_BUILTIN, OUTPUT );

    junk j;
    Serial.println( j.junkit() );

}


void loop()
{
    heartbeat& hb = singleton_t< heartbeat >::instance();
    panel_list& panels = singleton_t< panel_list >::instance();

    hb.beat();
    panels.tick();
} 

#endif // UNIT_TEST
