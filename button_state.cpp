#include "button_state.h"
#include "button.h"
#include "singleton_t.h"
#include "simon_consts.h"
//#include <Wire.h>
#include <Arduino.h>

/* -------------------- BASE -------------------- */

void
button_state::update( button* btn )
{
    ( digitalRead( btn->pin() ) == HIGH )
        ? this->button_pressed( btn )
        : this->button_unpressed( btn )
    ;

    return;
}

void
button_state::switch_to_pressed( button* btn )
{
    btn->current_state( btn->pressed_state() );

    return;
}

void
button_state::switch_to_unpressed( button* btn )
{
    btn->current_state( btn->unpressed_state() );

    return;
}


/* -------------------- UNPRESSED -------------------- */

void
button_state_unpressed::button_pressed( button* btn )
{
    this->switch_to_pressed( btn );
    return;
}

void
button_state_unpressed::button_unpressed( button* btn )
{
    // I'm already unpresed
    //
    return;
}

/* -------------------- PRESSED -------------------- */

button_state_pressed::button_state_pressed()
{
}

unsigned long
button_state_pressed::mills_since_first_pressed()
{
    unsigned long now = millis();
    unsigned long first_pressed = this->first_pressed_mills();
    unsigned long interval = now - first_pressed;

    return interval;
}

void
button_state_pressed::button_unpressed( button* btn )
{
    this->switch_to_unpressed( btn );
    return;
}

void
button_state_pressed::reset_state()
{
    button_state::reset_state();
    this->first_pressed_mills( millis() );

    return;
}

void
button_state_pressed::button_pressed( button* btn )
{
    // fix this
    
    return;
}
