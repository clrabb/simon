#ifndef LIGHT_H
#define LIGHT_H

#include "simon_types.h"

namespace simon
{

    class light
    {
    // Private members
    //
    private:
        unsigned short m_pixel_number;
        unsigned short m_red_value;
        unsigned short m_green_value;
        unsigned short m_blue_value;
        bool           m_is_on;
    
    // Public methods
    public:
        light();

        void init_once();
    
        void pixel_number( unsigned value )      { m_pixel_number = value; }
        unsigned short pixel_number()            { return m_pixel_number;  } 
        
        void red_value( unsigned short value )   { m_red_value    = value; }
        unsigned short red_value()               { return m_red_value;     }
        
        void green_value( unsigned short value ) { m_green_value  = value; }
        unsigned short green_value()             { return m_green_value;   }
    
        void blue_value( unsigned short value )  { m_blue_value   = value; } 
        unsigned short blue_value()              { return m_blue_value;    }

        bool is_on() { return this->m_is_on; }
        bool is_off() { return !( this->is_on() ); }
       
        
        void turn_on();
        void turn_off();
        
    // Private methods
    //
    private:
        void is_on( bool state ) { this->m_is_on = state; }

        // Compiler crap
        //
        light( const light& );
        light& operator=( const light& );
    
    };
}


#endif // LIGHT_H
