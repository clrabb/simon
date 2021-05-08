#ifndef LIGHT_H
#define LIGHT_H

class light
{
// Private members
//
private:
    unsigned short m_light_pin;

// Public methods
public:
    light( unsigned short light_pin )
        : m_light_pin( light_pin )
    {
    }
    
    void turn_on();
    void turn_off();
    void blink();

// Private methods
//
private:
    unsigned short light_pin() { return m_light_pin; }
    
    light( const light& );
    light& operator=( const light& );

};



#endif // LIGHT_H
