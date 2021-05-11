#include "panel_list.h"
#include "button_panel.h"

using namespace simon;

panel_list::panel_list()
{
    this->m_panels[ RED_IDX    ] = new red_button_panel();
    this->m_panels[ BLUE_IDX   ] = new blue_button_panel();
    this->m_panels[ YELLOW_IDX ] = new yellow_button_panel();
    this->m_panels[ GREEN_IDX  ] = new green_button_panel();
}

void
panel_list::tick()
{
    for ( int i = 0; i < NUM_PANELS; ++i )
    {
        ( this->m_panels[ i ] )->tick();
    }
}
  
