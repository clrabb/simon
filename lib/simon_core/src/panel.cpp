#include "panel.h"
#include "simon_consts.h"
#include "button.h"
#include "light.h"
#include "panel_activation_token.h"


using namespace simon;


abstract_panel::abstract_panel()
{
    abstract_activation_token* token = new inactive_panel_token();
    this->m_inactive_token           = token;
    this->m_current_activation_token = token;
}

void
abstract_panel::init()
{
    this->init_light();
    this->init_buzzer();
    this->init_button();
}

void
abstract_panel::activate( abstract_activation_token* token )
{
    this->current_activation_token( token );
    token->owner( this );
}    

void
abstract_panel::tick()
{
    this->current_activation_token()->tick();
    this->button()->update();
}

void
abstract_panel::tick_from_active_token()
{
    this->light()->turn_on();
    this->buzzer()->turn_on();
}

void
abstract_panel::tick_from_inactive_token()
{
    this->light()->turn_off();
    this->buzzer()->turn_off();
}

void
abstract_panel::evict_token()
{
    this->light()->turn_off();
    this->buzzer()->turn_off();
    this->current_activation_token()->unset_owner();
    this->current_activation_token( this->inactive_token() );
}


/* -------------------  RED PANEL --------------- */

red_button_panel::red_button_panel()
{
}

void
red_button_panel::init_light()
{
    simon::light* l = new simon::light();
    l->pixel_number( RED_PIXEL_NUM  );
    l->red_value(    RED_R_VALUE    );
    l->green_value(  RED_G_VALUE    );
    l->blue_value(   RED_B_VALUE    );
    l->init_once();

    this->light( l );
}

void
red_button_panel::init_button()
{
    this->button( new simon::button( RED_BUTTON_PIN ) );
}



void
red_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( RED_BUZZER_FREQ );

    this->buzzer( b );
}

/* ------------------ BLUE PANEL --------------- */

blue_button_panel::blue_button_panel()
{
}

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
blue_button_panel::init_button()
{
    this->button( new simon::button( BLUE_BUTTON_PIN ) );
}

void
blue_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( BLUE_BUZZER_FREQ );

    this->buzzer( b );
}


/* ------------------ GREEN PANEL --------------- */

green_button_panel::green_button_panel()
{
}

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

void
green_button_panel::init_button()
{
    this->button( new simon::button( GREEN_BUTTON_PIN ) );
}


/* --------------- YELLOW PANEL ---------------- */

yellow_button_panel::yellow_button_panel()
{
}

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
yellow_button_panel::init_button()
{
    this->button( new simon::button( YELLOW_BUTTON_PIN ) );
}

void 
yellow_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( YELLOW_BUZZER_FREQ );

    this->buzzer( b );
}

