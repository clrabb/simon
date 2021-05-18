#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

#include "button.h"
#include "light.h"
#include "buzzer.h"

namespace simon
{
    class abstract_button_panel
    {
    private:
    
        simon::button* m_button;
        simon::light*  m_light;
        simon::buzzer* m_buzzer;
        
    public:
        abstract_button_panel()
        {
        }

        void tick();
        void random_lightshow();
    
    public:
        void init();
        void turn_on_beep();
        void turn_off_beep();
        void turn_on_light();
        void turn_off_light();
        void lightshow_beep();
    
    
    protected:
    
        virtual void init_light() = 0;
        virtual void init_buzzer() = 0;
    

        void button( simon::button* b ) { this->m_button = b; }
        simon::button* button() { return this->m_button; }
        
    
        simon::light* light() { return m_light; }
        void light( simon::light* a_light ) { m_light = a_light; }
    
        const simon::buzzer* buzzer() { return m_buzzer; }
        void buzzer( simon::buzzer* a_buzzer ) { m_buzzer = a_buzzer; }
        
    private:
        abstract_button_panel( const abstract_button_panel& );
        abstract_button_panel& operator=( const abstract_button_panel& );
    };



    /* ------------------- RED PANEL --------------*/
    
    class red_button_panel : public abstract_button_panel
    {
    public: 
        red_button_panel() 
            : abstract_button_panel()
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

    class blue_button_panel : public abstract_button_panel
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

    class green_button_panel : public abstract_button_panel
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

    class yellow_button_panel : public abstract_button_panel
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
