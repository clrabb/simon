#ifndef LIGHT_H
#define LIGHT_H

#include "simon_types.h"

class light
{
// Private members
//
private:
    unsigned short m_pixel_number;
    unsigned short m_red_value;
    unsigned short m_gree_value;
    unsigned short m_blue_value;

// Public methods
public:
    light()
    {
    }

    void pixel_number( short value )         { m_pixel_number = value; }
    void red_value( unsigned short value )   { m_red_value    = value; }
    void green_value( unsigned short value ) { m_green_value  = value; }
    void blue_value( unsigned short value )  { m_blue_value   = value; } 
   
    
    void turn_on();
    void turn_off();
    
// Private methods
//
private:
    unsigned short light_pin() { return m_light_pin; }
    
    light( const light& );
    light& operator=( const light& );

};



#endif // LIGHT_H
