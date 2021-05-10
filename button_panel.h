#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

#include "button.h"

//#include "buzzer.h"
//#include "light.h"

class abstract_button_panel
{
private:
    button* m_button;
    //light*  m_light;
    //buzzer* m_buzzer;

    
public:
    abstract_button_panel()
    {
    }

protected:
    virtual void init();
    

protected:
    

    void b( button* b ) { this->m_button = b; }

    //light& light() { return m_light; }
    //void light( light* a_light ) { m_light = a_light; }

    //const buzzer* buzzer() { return m_buzzer; }
    //void buzzer( buzzer* a_buzzer ) { m_buzzer = buzzer; }
    

private:
    //button_panel( const button_panel& );
    //button_panel& operator=( const button_panel& );
};

class red_button_panel : abstract_button_panel
{
public: 
    red_button_panel() {}

protected: 
    void init() override;
    
};

#endif // BUTTON_PANEL_H
