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
    Serial.println( "In init_singletons()" );
    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< red_button_panel >( new red_button_panel() );


    //simon::singleton_t< panel_list >( new panel_list() );
}

void setup()
{
    Serial.begin( 115200 );
    init_singletons();

    red_button_panel& rbp = singleton_t< red_button_panel >::instance();
    rbp.init();

    Serial.println( "Hello" );
    pinMode( LED_BUILTIN, OUTPUT );
}


void loop()
{
    heartbeat& hb = singleton_t< heartbeat >::instance();
    red_button_panel& rbp = singleton_t< red_button_panel >::instance();

    hb.beat();
    rbp.tick();
} 


