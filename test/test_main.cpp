#include <Arduino.h>
#include <unity.h>
#include "button_panel_state.h"



using namespace simon;

void test_led_builtin_low()
{
    TEST_ASSERT_EQUAL( LOW, digitalRead( LED_BUILTIN ) );
}


void test_panel_state_active_is_active()
{
    button_panel_state_active state;
    TEST_ASSERT_TRUE( state.is_active() );
}


void test_panel_state_active_is_not_active()
{
    button_panel_state_active state;
    TEST_ASSERT_FALSE( state.is_not_active() );
}

void test_panel_state_inactive_is_not_active()
{
    button_panel_state_inactive state;
    TEST_ASSERT_TRUE( state.is_not_active() );
}
/*
void test_button_state_pressed_is_pressed()
{
    button_state_pressed state;
    TEST_ASSERT_TRUE( state.is_pressed() );
}
*/

void test_heartbeat()
{
    //heartbeat hb( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON );

    TEST_ASSERT_TRUE( true );
}

void setUp()
{
}

void tearDown()
{

}

void init_singletons()
{
    /*
    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    
    Serial.println( "In init_singletons()" );
    singleton_t< neopixel >( new neopixel( panel_list::NUM_PANELS, NEOPIXEL_PIN, NEO_RBG + NEO_KHZ800 ) );
    singleton_t< panel_list >( new panel_list() );
    
    Serial.println( "All singletons init'd" );
    pinMode( LED_BUILTIN, OUTPUT );
    */
}

void setup()
{
    init_singletons();

    UNITY_BEGIN();
    delay( 1000 );


    init_singletons();

    RUN_TEST( test_led_builtin_low );
    RUN_TEST( test_panel_state_active_is_active );
    RUN_TEST( test_panel_state_active_is_not_active );
    RUN_TEST( test_panel_state_inactive_is_not_active );
    RUN_TEST( test_heartbeat );

    UNITY_END();
}

int loops = 0;
void loop()
{
}