#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

class abstract_button_panel
{
private:
    button        m_button;
    light         m_light;
    buzzer        m_buzzer;

    
public:
    button_panel()
    {     
    }

private:
    int buzzer_frequency() = 0;
    int light_color

private:
    button_panel( const button_panel& );
    button_panel& operator=( const button_panel& );
};

#endif // BUTTON_PANEL_H
