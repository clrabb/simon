#ifndef BUTTON_STATE_H
#define BUTTON_STATE_H


namespace simon { class button; }

namespace simon
{

    class abstract_panel;

    class button_state
    {
    protected:
        virtual void switch_to_pressed( simon::button* btn );
        virtual void switch_to_unpressed( simon::button* btn );
    
    public:
        button_state() {}
        
        virtual void button_pressed( simon::button* btn )   = 0;
        virtual void button_unpressed( simon::button* btn ) = 0;
        virtual void reset_state() {}
        virtual bool is_unpressed() = 0;
        virtual bool is_pressed()   = 0;
        virtual void tick( simon::abstract_panel* a_panel ) = 0;
        void update( simon::button* btn );
    
    private:
        button_state( button_state& );
        button_state& operator=( button_state& );
    };

    /* -------------- UNPRESSED ------------- */
    
    class button_state_unpressed : public button_state
    {    
    public:
        button_state_unpressed() {}
    
        virtual void button_pressed( simon::button* btn ) override;
        virtual void button_unpressed( simon::button* btn ) override;
        virtual bool is_unpressed() override { return true;  }
        virtual bool is_pressed() override { return false; }
        virtual void tick( simon::abstract_panel* a_panel ) override;
    };
    
    /* ------------ PRESSED ---------------- */

    class button_state_pressed: public button_state
    {
    private:
        unsigned long   m_first_pressed_mills;
        bool            m_has_updated_setpoint;
                     
        void            first_pressed_mills( unsigned long mills ) { m_first_pressed_mills = mills; }
        bool            is_first_pressed();
        
    protected:
        unsigned long   mills_since_first_pressed();
        unsigned long   first_pressed_mills() { return m_first_pressed_mills; }    
         
    public:    
        button_state_pressed();
        virtual void button_pressed( simon::button* btn );
        virtual void button_unpressed( simon::button* btn );
        virtual bool is_unpressed() { return false; }
        virtual bool is_pressed()   { return true;  }
        virtual void reset_state() override;
        virtual void tick( simon::abstract_panel* a_panel ) override;
    
    private:
        button_state_pressed( button_state_pressed& );
        button_state_pressed& operator=( button_state_pressed& );
    };
}

#endif // BUTTON_STATE_H
