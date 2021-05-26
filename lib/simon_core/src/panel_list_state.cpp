#include "panel_list_state.h"
#include "panel_list.h"

using namespace simon;

void
lightshow_panel_list_state::tick( simon::panel_list* a_list )
{

}

void 
lightshow_panel_list_state::turn_on_panel()
{
    this->panel_list()->turn_on_active_panel();
}

simon::panel_list* 
lightshow_panel_list_state::panel_list()
{
    return this->m_panel_list;
}

void 
lightshow_panel_list_state::panel_list( simon::panel_list* list )
{
    this->m_panel_list = list;
}