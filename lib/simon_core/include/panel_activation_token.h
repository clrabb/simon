#ifndef PANEL_ACTIVATION_TOKEN
#define PANEL_ACTIVATION_TOKEN

#include <stddef.h>

namespace simon
{
    class abstract_panel;

    class abstract_activation_token
    {
        private:
            abstract_panel* m_owner;
            unsigned long   m_owned_at_mills;

        public:
            abstract_activation_token()
                : m_owner( nullptr )
            {}

            virtual ~abstract_activation_token(){}

        public:
            virtual void tick() = 0;
            abstract_panel* owner();
            void owner( abstract_panel* a_panel );
            void unset_owner();
            unsigned long owned_at_mills();

            // Testing
            //
            bool is_owned() { return this->m_owner != nullptr; }
            bool is_not_owned() { return !( this->is_owned() ); }
            virtual bool is_active()   { return false; }
            virtual bool is_inactive() { return false; }


        private:
            void owned_at_mills( unsigned long owned_at_mills );
    };

    class inactive_panel_token : public abstract_activation_token
    {
        public:
            inactive_panel_token(){}
            virtual ~inactive_panel_token(){}

            void tick() override {};

            // Testing
            //
            virtual bool is_inactive() override { return true; }

        private:
            inactive_panel_token& operator=( const inactive_panel_token& );
            inactive_panel_token( const inactive_panel_token& );
    };

    class active_panel_token : public abstract_activation_token
    {
        private:
            unsigned long   m_lifespan;

        public:   
            active_panel_token( unsigned long lifespan )
                : m_lifespan( lifespan )
            {}
            virtual ~active_panel_token(){}
            
            // Testing
            bool    should_leave_panel();
            virtual bool is_active() { return true; }

            // Behavior
            //
            void tick() override;
            unsigned long age();



        private:
            
            unsigned long lifespan() { return this->m_lifespan; }
            void lifespan( unsigned long span ) { this->m_lifespan = span; }

            // Compiler crap
            //
            active_panel_token& operator=( const active_panel_token& );
            active_panel_token( const active_panel_token& );
    };
}


#endif // PANEL_ACTIVATION_TOKEN