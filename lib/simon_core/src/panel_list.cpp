#include "panel_list.h"
#include "panel.h"
#include "simon_consts.h"
#include <Arduino.h>
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace simon;

panel_list::panel_list()
{
    this->m_panels[ RED_IDX    ] = new red_button_panel();
    this->m_panels[ BLUE_IDX   ] = new blue_button_panel();
    this->m_panels[ YELLOW_IDX ] = new yellow_button_panel();
    this->m_panels[ GREEN_IDX  ] = new green_button_panel();

    this->init_panels();

    this->normal_activation_token( new active_panel_token( NORMAL_PANEL_LIFESPAN ) );
    this->lightshow_activation_token( new active_panel_token( LIGHTSHOW_PANEL_LIFESPAN ) );
}

void
panel_list::init_panels()
{
    for ( int i = 0; i < panel_list::NUM_PANELS; ++i )
    {
        this->m_panels[ i ]->init();
    }
}

void
panel_list::tick()
{
    for ( int i = 0; i < NUM_PANELS; ++i )
    {
        ( this->panel_at_index( i ) )->tick();
    }
}
  
void
panel_list::random_lightshow()
{
    unsigned long start_time = millis();

    randomSeed( analogRead( 0 ) );


    

    for ( ;; )
    {
        unsigned long now               = millis();
        unsigned long mills_since_start = now - start_time;


        if ( mills_since_start > LIGHTSHOW_DURATION )
            break;

        abstract_activation_token* token = this->lightshow_activation_token();
        if ( token->is_not_owned() )
        {
            int rand_idx = random( NUM_PANELS );
            this->activate_panel( rand_idx, token );
        }

        this->tick();      
    }
}

void
panel_list::activate_panel( const short panel_idx, abstract_activation_token* token )
{
    abstract_panel* panel = this->m_panels[ panel_idx ];
    panel->activate( token );
}

abstract_panel* 
panel_list::panel_at_index( int idx )
{
    return this->m_panels[ idx ];
}

// The list doesn't know who is active... Only the panels know that
// Peraps the wrong design
//
void
panel_list::turn_on_active_panel()
{
    for ( int i = 0; i < NUM_PANELS; ++i )
    {
        ( this->panel_at_index( i ) )->turn_on();
    }
}

