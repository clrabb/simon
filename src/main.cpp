#include <Arduino.h>
#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "panel_list.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif 

using namespace simon;

abstract_button_panel* panels[1];
abstract_button_panel* rbp;
void init_singletons()
{
    Serial.println( "In init_singletons()" );
    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    //singleton_t< red_button_panel >( new red_button_panel() );
    //simon::singleton_t< panel_list >( new panel_list() );

    abstract_button_panel* rbp2 = new red_button_panel();
    rbp2->tick();
   
}

void setup()
{

    Serial.begin( 115200 );

    
    init_singletons();

    
    neopixel& pixels = singleton_t< neopixel >::instance();
    pixels.begin();
    pixels.show();
    

    delay( 1000 );

    Serial.println( "Hello" );

    pinMode( LED_BUILTIN, OUTPUT );
}

long last_touch = millis();
bool is_on = false;
void cheap_heartbeat()
{
    if ( ( millis() - last_touch ) > 1000 )
    {
        if ( is_on )
        {
            // Turn off
            //
            digitalWrite( LED_BUILTIN, LOW );
            is_on = false;
            Serial.println( "Off" );
        }
        else
        {
            digitalWrite( LED_BUILTIN, HIGH );
            is_on = true;
            Serial.println( "On" );
        }

        last_touch = millis();
    }
}


void loop()
{
    //cheap_heartbeat();
    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();

} 


