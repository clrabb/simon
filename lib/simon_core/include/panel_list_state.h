#ifndef PANEL_LIST_STATE_H
#define PANEL_LIST_STATE_H


namespace simon
{
    class panel_list;

    class abstract_panel_list_state
    {
        public:
            abstract_panel_list_state(){}
            virtual ~abstract_panel_list_state(){}

            virtual void tick( panel_list* ) = 0;

        private:
            abstract_panel_list_state( const abstract_panel_list_state& );
            abstract_panel_list_state& operator=( const abstract_panel_list_state& );
    };

    class lightshow_panel_list_state : public abstract_panel_list_state
    {
        private:
            unsigned long          m_panel_on_time;
            unsigned short         m_num_panels_activated;
            simon::panel_list*     m_panel_list;

        public:
            lightshow_panel_list_state(){}
            virtual ~lightshow_panel_list_state(){}

            virtual void tick( panel_list* ) override;

        private:
            unsigned long panel_on_time() { return this->m_panel_on_time; }
            void panel_on_time( unsigned long time ) { this->m_panel_on_time = time; }

            unsigned short num_panels_activated() { return this->m_num_panels_activated; }
            void num_panels_activated( unsigned short num ) { this->m_num_panels_activated = num; }

            simon::panel_list* panel_list();
            void panel_list( simon::panel_list* list );

            void increment_num_panels_activated();
            void turn_on_panel();
            void turn_off_panel();

        private:
            lightshow_panel_list_state( const lightshow_panel_list_state& );
            lightshow_panel_list_state& operator=( const lightshow_panel_list_state& );
    };


}

#endif // PANEL_LIST_STATE_H