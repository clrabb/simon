#include "panel.h"
#include "simon_consts.h"
#include "button.h"
#include "light.h"


using namespace simon;


void
abstract_panel::init()
{
    this->init_light();
    this->init_buzzer();
    this->activation_token( this->null_activation_token() );
}

void
abstract_panel::activate( abstract_activation_token* token )
{
    token->owner( this );
}    

void
abstract_panel::tick()
{
    this->activation_token()->tick();
}

void
abstract_panel::tick_from_active_token()
{

}

void
abstract_panel::evict_token()
{
    this->activation_token( this->null_activation_token() );
}

/* -------------------  RED PANEL --------------- */


void
red_button_panel::init_light()
{
    this->button( new simon::button( RED_BUTTON_PIN ) );

    simon::light* l = new simon::light();
    l->pixel_number( RED_PIXEL_NUM  );
    l->red_value(    RED_R_VALUE    );
    l->green_value(  RED_G_VALUE    );
    l->blue_value(   RED_B_VALUE    );
    l->init_once();

    this->light( l );
}



void
red_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( RED_BUZZER_FREQ );

    this->buzzer( b );
}

/* ------------------ BLUE PANEL --------------- */

void
blue_button_panel::init_light()
{
    simon::light* l = new simon::light();
    l->pixel_number( BLUE_PIXEL_NUM  );
    l->red_value(    BLUE_R_VALUE    );
    l->green_value(  BLUE_G_VALUE    );
    l->blue_value(   BLUE_B_VALUE    );
    l->init_once();

    this->light( l );
} 

void
blue_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( BLUE_BUZZER_FREQ );

    this->buzzer( b );
}


/* ------------------ GREEN PANEL --------------- */


void
green_button_panel::init_light()
{
    simon::light* l = new simon::light();
    l->pixel_number( GREEN_PIXEL_NUM );
    l->red_value(    GREEN_R_VALUE   );
    l->green_value(  GREEN_G_VALUE   );
    l->blue_value(   GREEN_B_VALUE   );
    l->init_once();

    this->light( l );
}

void
green_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( GREEN_BUZZER_FREQ );

    this->buzzer( b );
}


/* --------------- YELLOW PANEL ---------------- */


void
yellow_button_panel::init_light()
{
    simon::light* l = new simon::light();
    l->pixel_number( YELLOW_PIXEL_NUM );
    l->red_value(    YELLOW_R_VALUE   );
    l->green_value(  YELLOW_G_VALUE   );
    l->blue_value(   YELLOW_B_VALUE   );
    l->init_once();

    this->light( l );
}

void 
yellow_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( YELLOW_BUZZER_FREQ );

    this->buzzer( b );
}
