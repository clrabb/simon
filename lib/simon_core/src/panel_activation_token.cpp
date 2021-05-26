#include "panel_activation_token.h"
#include "panel.h"
#include <Arduino.h>

using namespace simon;

void 
abstract_activation_token::owner( abstract_panel* a_panel )
{
    this->m_owner = a_panel;
    this->owned_at_mills( millis() );
}

abstract_panel* 
abstract_activation_token::owner()
{
    return this->m_owner;
}

void
abstract_activation_token::owned_at_mills( unsigned long owned_at_mills )
{
    this->m_owned_at_mills = owned_at_mills;
}

unsigned long
abstract_activation_token::owned_at_mills()
{ 
    return this->m_owned_at_mills;
}

void
abstract_activation_token::unset_owner()
{
    this->owner( nullptr );
    this->owned_at_mills( 0 );
}


bool 
active_panel_token::should_leave_panel()
{
    unsigned long now      = millis();
    unsigned long age      = this->age();
    unsigned long lifespan = this -> lifespan();
    bool should_leave      = ( now - age ) > lifespan;

    return should_leave;
}

unsigned long 
active_panel_token::age()
{
    unsigned long now            =  millis();
    unsigned long owned_at_mills = this->owned_at_mills();
    
    return now - owned_at_mills;
}

void 
active_panel_token::tick()
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


