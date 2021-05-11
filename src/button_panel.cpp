#include "button_panel.h"
#include "simon_consts.h"
#include "button.h"
#include "light.h"

using namespace simon;

void
abstract_button_panel::init()
{
    this->init_light();
    this->init_buzzer();
}

void 
abstract_button_panel::tick()
{
    
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

    this->light( l );
}

void 
yellow_button_panel::init_buzzer()
{
    simon::buzzer* b = new simon::buzzer( YELLOW_BUZZER_FREQ );

    this->buzzer( b );
}
