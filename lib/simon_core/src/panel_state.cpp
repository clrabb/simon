#include "panel_state.h"
#include "panel.h"

using namespace simon;

void
panel_state_active::activate( abstract_panel* a_panel )
{
    // Nothing to do... already active
    //
}

void
panel_state_active::deactivate( abstract_panel* a_panel )
{
    a_panel->turn_off_light();
    a_panel->turn_off_sound();
    a_panel->_change_to_inactive_state();
}

unsigned long 
panel_state_active::age_mills()
{
    unsigned long mills
}

bool 
panel_state_active::should_deactivate()
{
    unsigned long mills_since_active = this->mills_since_activation();
    unsigned long lifespan           = this->lifespan_mills();
    unsigned long now                = millis();

    return ( mills_since_active - now > lifespan;
}

void
panel_state_active::tick( abstract_panel* a_panel )
{
    if( this->should_deactivate() )
    {
        this->deactivate( a_panel );
    }
}