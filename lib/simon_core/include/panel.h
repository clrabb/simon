#ifndef BUTTON_PANEL_H
#define BUTTON_PANEL_H

#include "button.h"
#include "light.h"
#include "buzzer.h"
#include "panel_activation_token.h"
#include "simon_consts.h"

namespace simon
{
    /* --------------- Abstract panel ------------- */
    class abstract_panel
    {
    private:
    
        simon::button*                    m_button;
        simon::light*                     m_light;
        simon::buzzer*                    m_buzzer; 
        simon::abstract_activation_token* m_current_activation_token;   
        simon::abstract_activation_token* m_inactive_token;             // I own this
        
    public:
        abstract_panel();

        // Initialization
        //
        void init();
        
        // Behavior
        //
        void activate( abstract_activation_token* activation_token );

        // Timing
        //
        void tick();
        void evict_token();
        void turn_on();
        void turn_on_light();
        void turn_on_buzzer();
        void turn_off_light();
        void turn_off_buzzer();

    
    public:
        // dispatch from token
        //
        void tick_from_active_token();
        void tick_from_inactive_token();

    protected:
    
        virtual void init_light() = 0;
        virtual void init_buzzer() = 0;
    

        void button( simon::button* b ) { this->m_button = b; }
        simon::button* button() { return this->m_button; }
        
        simon::light* light() { return m_light; }
        void light( simon::light* a_light ) { m_light = a_light; }
    
        simon::buzzer* buzzer() { return m_buzzer; }
        void buzzer( simon::buzzer* a_buzzer ) { m_buzzer = a_buzzer; }

    protected:
        abstract_activation_token* current_activation_token(){ return this->m_current_activation_token; }
        void current_activation_token( abstract_activation_token* token ) { this->m_current_activation_token = token; }

    private:
        abstract_activation_token* inactive_token() { return this->m_inactive_token; }

    private:
        // Compiler shit
        abstract_panel( const abstract_panel& );
        abstract_panel& operator=( const abstract_panel& );
    };



    /* ------------------- RED PANEL --------------*/
    
    class red_button_panel : public abstract_panel
    {
    public: 
        red_button_panel();
    
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
        blue_button_panel();

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
        green_button_panel();

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
        yellow_button_panel();

    protected:
        void init_light() override;
        void init_buzzer() override;

    private:
        yellow_button_panel( const yellow_button_panel& );
        yellow_button_panel& operator=( const yellow_button_panel& );  
    };

}


#endif // BUTTON_PANEL_H
