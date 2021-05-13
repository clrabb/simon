#ifndef BUTTON_PANEL_STATE_H
#define BUTTON_PANEL_STATE_H
#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"
#include "panel_list.h"


namespace simon
{
    class button_panel;

    class abstract_button_panel_state
    {
        private:
            

        public:
            abstract_button_panel_state(){}
            ~abstract_button_panel_state(){}

            virtual void press( button_panel& ) = 0;
            virtual bool is_active() = 0;
            bool is_not_active() { return !( this->is_active() ); }
    };

    class button_panel_state_active : public abstract_button_panel_state
    {
        public:
            button_panel_state_active();
            ~button_panel_state_active();

            void press( button_panel& ) override;
            bool is_active() { return true; }
    };

    class button_panel_state_inactive : public abstract_button_panel_state
    {
        public:
            button_panel_state_inactive(){}
            ~button_panel_state_inactive(){}

            void press( button_panel& ) override;
            bool is_active() { return false; }
            
    };
}

#endif // BUTTON_PANEL_STATE_H