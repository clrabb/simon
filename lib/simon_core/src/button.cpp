#include "button.h"
#include "simon_types.h"
#include "button_state.h"
#include "panel.h"


using namespace simon;

button::button( short pin )
    :m_pin( pin )
{
    this->pressed_state(   new button_state_pressed()   );
    this->unpressed_state( new button_state_unpressed() );
    
    this->current_state( this->unpressed_state() );
}

bool
button::is_pressed()
{
    return this->current_state()->is_pressed();
}

bool
button::is_unpressed()
{
    return this->current_state()->is_unpressed();
}

void
button::update()
{
    this->current_state()->update( this );
    return;
}

void
button::tick( simon::abstract_panel* a_panel )
{
    this->current_state()->tick( a_panel );
}