#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

#include "button.h"
#include "light.h"

//#include "buzzer.h"
//#include "light.h"

namespace simon
{
    class abstract_button_panel
    {
    private:
        simon::button* m_button;
        simon::light*  m_light;
        //buzzer* m_buzzer;
    
        
    public:
        abstract_button_panel()
        {
        }
    
    protected:
        virtual void init();
    
    protected:
        void button( simon::button* b ) { this->m_button = b; }
        simon::button* button() { return this->m_button; }
        
    
        //light& light() { return m_light; }
        //void light( light* a_light ) { m_light = a_light; }
    
        //const buzzer* buzzer() { return m_buzzer; }
        //void buzzer( buzzer* a_buzzer ) { m_buzzer = buzzer; }
        
    
    private:
        abstract_button_panel( const abstract_button_panel& );
        abstract_button_panel& operator=( const abstract_button_panel& );
    };
    
    class red_button_panel : abstract_button_panel
    {
    public: 
        red_button_panel() {}
    
    protected: 
        void init() override;

    private:
        red_button_panel( const red_button_panel& );
        red_button_panel& operator=( const red_button_panel& );
        
    };

    class blue_button_panel : abstract_button_panel
    {
    public:
        blue_button_panel(){}

    protected:
        void init() override;

    private:
        blue_button_panel( const blue_button_panel& );
        blue_button_panel& operator=( const blue_button_panel& );
        
    };
}

#endif // BUTTON_PANEL_H
