#ifndef PANEL_STATE_H
#define PANEL_STATE_H
#include "singleton_t.h"
#include "heartbeat.h"
#include "simon_consts.h"

namespace simon
{
    class abstract_panel;

    /* ------- Abstract panel state ---------- */
    class abstract_panel_state
    {
        public:
            abstract_panel_state(){}
            ~abstract_panel_state(){}

            virtual void press( abstract_panel* ) = 0;
            virtual bool is_active() = 0;
            bool is_not_active() { return !( this->is_active() ); }
            virtual void activate( abstract_panel* );
            virtual void deactivate( abstract_panel* );
            virtual void tick( abstract_panel* );
    };

    /* ------ Panel state active ------------- */
    class panel_state_active : public abstract_panel_state
    {
        private:
            unsigned long m_mills_since_active;
            unsigned long m_lifespan_mills; 
        
        public:
            panel_state_active( unsigned long lifespan_mills )
                : m_lifespan_mills( lifespan_mills )
                {

                }

            ~panel_state_active();

            // Members
            //
            unsigned long lifespan_mills() { return m_lifespan_mills; }

            // Testing
            //
            bool is_active() { return true; }
            bool should_deactivate();

            // Behavior
            //
            void press( abstract_panel* ) override;
            void activate( abstract_panel* );
            void deactivate( abstract_panel* );
            
            // Timing
            //
            void tick( abstract_panel* );
            unsigned long mills_since_activation();

        private:
            // Disable compiler generated shit
            //
            panel_state_active( const panel_state_active& );
            panel_state_active& operator=( const panel_state_active& );
    };

    /* ------ Panel state inactive ----------- */
    class panel_state_inactive : public abstract_panel_state
    {


        public:
            panel_state_inactive( unsigned long duration_mills ) {}

            ~panel_state_inactive(){}

            // Testing
            //          
            bool should_deactivate();
            bool is_active() { return false; }

            // Behavior
            //
            void press( abstract_panel* ) override;
            void activate( abstract_panel* );
            void deactivate( abstract_panel* );
            
            // Timing thread
            //
            void tick( abstract_panel* );      

        private:
            // Disable compiler shit
            //
            panel_state_inactive( const panel_state_active& );
            panel_state_inactive& operator=( const panel_state_inactive );
    };
}

#endif // PANEL_STATE_H