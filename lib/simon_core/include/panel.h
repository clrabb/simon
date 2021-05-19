#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

#include "button.h"
#include "light.h"
#include "buzzer.h"
#include "panel_state.h"
#include "simon_consts.h"

namespace simon
{
    /* --------------- Abstract panel ------------- */
    class abstract_panel
    {
    private:
    
        simon::button*               m_button;
        simon::light*                m_light;
        simon::buzzer*               m_buzzer;
        simon::abstract_panel_state* m_current_state;
        simon::abstract_panel_state* m_active_state;
        simon::abstract_panel_state* m_inactive_state;
        
        
    public:
        abstract_panel()
        {
            m_active_state   = new panel_state_active( PANEL_AGE_DEFAULT );
            m_inactive_state = new panel_state_inactive();
            m_current_state  = m_inactive_state;
        }

        // Initialization
        //
        void init();
        
        // Behavior
        //
        void activate();
        void _change_to_active_state();
        void _change_to_inactive_state();

        // Timing
        //
        void tick();
    
    protected:
    
        virtual void init_light() = 0;
        virtual void init_buzzer() = 0;
    

        void button( simon::button* b ) { this->m_button = b; }
        simon::button* button() { return this->m_button; }
        
    
        simon::light* light() { return m_light; }
        void light( simon::light* a_light ) { m_light = a_light; }
    
        const simon::buzzer* buzzer() { return m_buzzer; }
        void buzzer( simon::buzzer* a_buzzer ) { m_buzzer = a_buzzer; }

        abstract_panel_state* current_state()  { return m_current_state;  }
        abstract_panel_state* active_state()   { return m_active_state;   } 
        abstract_panel_state* inactive_state() { return m_inactive_state; }
        
    private:
        
        void current_state( abstract_panel_state* a_state ) { this->m_current_state = a_state; }
        abstract_panel( const abstract_panel& );
        abstract_panel& operator=( const abstract_panel& );
    };



    /* ------------------- RED PANEL --------------*/
    
    class red_button_panel : public abstract_panel
    {
    public: 
        red_button_panel() 
            : abstract_panel()
            {
            }
    
    protected: 
        void init_light() override;
        void init_buzzer() override;
    

    private:
        red_button_panel( const red_button_panel& );
        red_button_panel& operator=( const red_button_panel& );
    };

    /* ---------------- BLUE PANEL -------------- */

    class blue_button_panel : public abstract_panel
    {
    public:
        blue_button_panel(){}

    protected:
        void init_light() override;
        void init_buzzer() override;

    private:
        blue_button_panel( const blue_button_panel& );
        blue_button_panel& operator=( const blue_button_panel& );
        
    };

    /* --------------- GREEN PANEL ------------- */

    class green_button_panel : public abstract_panel
    {
    public:
        green_button_panel(){}  

    protected:
        void init_light() override;
        void init_buzzer() override;

    private:
        green_button_panel( const green_button_panel& );
        green_button_panel& operator=( green_button_panel& );
    };

    /* ----------------- YELLOW PANEL --------- */

    class yellow_button_panel : public abstract_panel
    {
    public:
        yellow_button_panel(){}

    protected:
        void init_light() override;
        void init_buzzer() override;

    private:
        yellow_button_panel( const yellow_button_panel& );
        yellow_button_panel& operator=( const yellow_button_panel& );  
    };

}


#endif // BUTTON_PANEL_H
