#ifndef BUTTON_H
#define BUTTON_H

#include "button_state.h"

namespace simon
{
    class button
    {
    private:
        short m_pin;
        button_state* m_current_state;
        button_state* m_btn_unpressed;
        button_state* m_btn_pressed;
        
    public:
        button() {}
        button( short pin );
        short pin() { return m_pin; }
    
        void update();
    
        button_state* current_state() { return m_current_state; }
        void current_state( button_state* state ) { state->reset_state(); m_current_state = state; }
    
        button_state* unpressed_state() { return m_btn_unpressed; }
        void unpressed_state( button_state* state ) { state->reset_state(); m_btn_unpressed= state; }
    
        button_state* pressed_state() { return m_btn_pressed; }
        void pressed_state( button_state* state ) { state->reset_state(); m_btn_pressed = state; }
    
            
        //------------------------------------------
        // 
        // Testing
        //
        //------------------------------------------
        bool is_unpressed();
        bool is_pressed();
        bool is_latched();
    
    private:
        button( const button& );
        button& operator=( const button& );
        
    };
}

#endif // BUTTON_H
