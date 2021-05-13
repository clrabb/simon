#include "panel_list.h"
#include "button_panel.h"
#include "simon_consts.h"
#include <Arduino.h>


using namespace simon;

panel_list::panel_list()
{
    this->m_panels[ RED_IDX    ] = new red_button_panel();
    this->m_panels[ BLUE_IDX   ] = new blue_button_panel();
    this->m_panels[ YELLOW_IDX ] = new yellow_button_panel();
    this->m_panels[ GREEN_IDX  ] = new green_button_panel();

    this->init_panels();
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
        ( this->m_panels[ i ] )->tick();
    }
}
  
void
panel_list::random_lightshow()
{
    for ( int i = 0; i < NUM_RAND_LIGHTSHOW; ++i )
    {
        int rand_value = random( NUM_PANELS );
        
        this->m_panels[ rand_value ]->lightshow_beep();
    }
}

void
panel_list::beep_panel( const short panel_idx )
{
    abstract_button_panel* panel = this->m_panels[ panel_idx ];
    panel->beep();
}
