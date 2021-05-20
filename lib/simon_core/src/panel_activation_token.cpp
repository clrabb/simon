#include "panel_activation_token.h"
#include "panel.h"
#include <Arduino.h>

using namespace simon;

void 
panel_activation_token::owner( abstract_panel* a_panel )
{
    this->owner( a_panel );
    this->owned_at_mills( millis() );
}

bool
panel_activation_token::is_owned()
{
    return this->owner() != NULL;
}

bool 
panel_activation_token::should_leave_panel()
{
    unsigned long now = millis();

    return ( now - this->age() ) > this->lifespan();
}

unsigned long 
panel_activation_token::age()
{
    return millis() - this->owned_at_mills();
}

void 
panel_activation_token::tick()
{
    if ( this->should_leave_panel() )
    {
        this->owner()->evict_token();
        this->unset_owner();
    }
    else
    {
        this->owner()->tick_from_active_token();   
    }
}

void
panel_activation_token::unset_owner()
{
    this->owner( NULL );
    this->owned_at_mills( 0 );
}
