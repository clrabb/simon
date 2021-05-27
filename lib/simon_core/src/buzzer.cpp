#include "buzzer.h"
#include "simon_consts.h"
#include <Arduino.h>

using namespace simon;

void
buzzer::turn_on()
{
    tone( SPEAKER_PIN, this->frequency() );
}

void 
buzzer::turn_off()
{
    noTone( SPEAKER_PIN );   
}