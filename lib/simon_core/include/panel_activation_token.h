#ifndef PANEL_ACTIVATION_TOKEN
#define PANEL_ACTIVATION_TOKEN

namespace simon
{
    class abstract_panel;

    class abstract_activation_token
    {
        public:
            abstract_activation_token(){}
            virtual ~abstract_activation_token(){}

        public:
            virtual void tick() = 0;
            virtual void owner( abstract_panel* ){}
            virtual bool is_owned() { return false; }
    };

    class null_activation_token : public abstract_activation_token
    {
        public:
            null_activation_token(){}
            virtual ~null_activation_token(){}

            void tick() override {};

        private:
            null_activation_token& operator=( const null_activation_token& );
            null_activation_token( const null_activation_token& );
    };

    class panel_activation_token : public abstract_activation_token
    {
        private:
            abstract_panel* m_owner;
            unsigned long   m_owned_at_mills;
            unsigned long   m_lifespan;

        public:   
            panel_activation_token( unsigned long lifespan )
                : m_lifespan( lifespan )
            {}
            virtual ~panel_activation_token(){}

            
            // Testing
            bool should_leave_panel();
            bool is_owned() override;

            // Behavior
            //
            void tick() override;
            void unset_owner();
            unsigned long age();

        private:
            // Setters/getters
            //
            unsigned long owned_at_mills() { return m_owned_at_mills; }
            void owned_at_mills( unsigned long mills ) { this->m_owned_at_mills = mills; }
            
            abstract_panel* owner() { return this->m_owner; }
            void owner( abstract_panel* ) override;

            unsigned long lifespan() { return this->m_lifespan; }
            void lifespan( unsigned long span ) { this->m_lifespan = span; }

            // Compiler crap
            //
            panel_activation_token& operator=( const panel_activation_token& );
            panel_activation_token( const panel_activation_token& );
    };
}


#endif // PANEL_ACTIVATION_TOKEN