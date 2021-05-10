#include "button_panel.h"
#include "simon_consts.h"
#include "button.h"

using namespace simon;

void
red_button_panel::init()
{
    this->button( new simon::button( RED_BUTTON_PIN ) );

    light* l = new light();
    l->pixel_number( RED_BUTTON_PIN );
    l->red_value(    RED_R_VALUE    );
    l->green_value(  RED_G_VALUE    );
    l->blue_value(   RED_B_VALUE    );
}
