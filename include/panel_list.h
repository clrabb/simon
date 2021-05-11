#ifndef PANEL_LIST_H
#define PANEL_LIST_H

#include "button_panel.h"

namespace simon
{
class panel_list
{
    private:
        abstract_button_panel* m_panels[ 4 ];

        static const short RED_IDX    = 0;
        static const short GREEN_IDX  = 1;
        static const short BLUE_IDX   = 2;
        static const short YELLOW_IDX = 3;
        static const short NUM_PANELS = 4;

    public:
        panel_list();
        void tick();
        void random_lightshow();
};
}


#endif // PANEL_LIST_H
