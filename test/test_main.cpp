#include <Arduino.h>
#include <unity.h>
#include "button_panel_state.h"
#include "junk.h"


using namespace simon;

void init_singletons()
{

    singleton_t< heartbeat  >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
    singleton_t< neopixel >( new neopixel( panel_list::NUM_PANELS, NEOPIXEL_PIN, NEO_RBG + NEO_KHZ800 ) );
    singleton_t< panel_list >( new panel_list() );
    
    Serial.println( "All singletons init'd" );
    pinMode( LED_BUILTIN, OUTPUT );
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


void test_button_state_pressed_is_pressed()
{
    button_state_pressed state;
    TEST_ASSERT_TRUE( state.is_pressed() );
}


void test_heartbeat_beat()
{
    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();
    TEST_ASSERT_TRUE( true );
}

void test_button_constructor()
{
    button* b = new button( 5 );  // 5 is the pin
    TEST_ASSERT_NOT_NULL( b );
    delete( b );
}

void test_button_pressed()
{

} 

void setup()
{
    init_singletons();
    UNITY_BEGIN();
    delay( 1000 );

    RUN_TEST( test_heartbeat_beat       );
    RUN_TEST( test_button_constructor   );
    RUN_TEST( test_button_pressed       );
    //RUN_TEST( test_panel_state_active_is_active );

    /*
    RUN_TEST( test_panel_state_active_is_not_active );
    RUN_TEST( test_panel_state_inactive_is_not_active );
    */



    UNITY_END();
}

void loop()
{
}