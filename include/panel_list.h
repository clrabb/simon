#ifndef PANEL_LIST_H
#define PANEL_LIST_H

#include "button_panel.h"

namespace simon
{
    class panel_list
    {
        public:
            static const short NUM_PANELS = 4;

        private:
            static const short RED_IDX    = 0;
            static const short GREEN_IDX  = 1;
            static const short BLUE_IDX   = 2;
            static const short YELLOW_IDX = 3;
            

            abstract_button_panel* m_panels[ panel_list::NUM_PANELS ];

            void init_panels();

        public:
            panel_list();
            void tick();
            void random_lightshow();
            void beep_panel( const short panel_idx );
    };
}

#endif // PANEL_LIST_H
