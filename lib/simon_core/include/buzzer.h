#ifndef BUZZER_H
#define BUZZER_H

namespace simon
{
    class buzzer
    {
    private:
        int m_frequency;
        
    public:
        buzzer( int frequency )
            : m_frequency( frequency )
        {
        }

    void turn_on();
    void turn_off();
        
    private:
        buzzer( const buzzer& );
        buzzer& operator=( const buzzer& );
        
    };
}

#endif // BUZZER_H
