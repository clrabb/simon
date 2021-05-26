#ifndef PANEL_LIST_H
#define PANEL_LIST_H

#include "panel.h"

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

            abstract_panel*            m_panels[ panel_list::NUM_PANELS ];
            abstract_activation_token* m_activation_token;

            

        public:
            panel_list();
            void tick();
            void random_lightshow();
            void activate_panel( const short panel_idx );
            void turn_on_active_panel();
            void init_panels();
            
        private:
            abstract_panel* panel_at_index( int idx );

        private:
            abstract_activation_token* activation_token() { return this->m_activation_token; }
            void activation_token( abstract_activation_token* a_token ) { this->m_activation_token = a_token; }

    };
}

#endif // PANEL_LIST_H
