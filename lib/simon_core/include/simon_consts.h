#ifndef SIMON_CONSTS_H
#define SIMON_CONSTS_H

namespace simon
//r b g y
{
    /* ------------- BUTTONS ---------------------- */
    static const short RED_BUTTON_PIN    = 5;
    static const short BLUE_BUTTON_PIN   = 3;
    static const short GREEN_BUTTON_PIN  = 4;
    static const short YELLOW_BUTTON_PIN = 2;

    /* ------------- PANEL ------------------------ */
    static const unsigned long NORMAL_PANEL_LIFESPAN    = 700;
    static const unsigned long LIGHTSHOW_PANEL_LIFESPAN = 200;
    static const unsigned long LIGHTSHOW_DURATION       = 3000; 

    /* ------------- HEARTBEAT -------------------- */
    static const short HEARTBEAT_PIN = 8;
    static const unsigned long HEARTBEAT_DURATION_OFF = 1500;
    static const unsigned long HEARTBEAT_DURATION_ON  = 100;

    /* ------------- SOUNDS ----------------------- */
    
    static const int RED_BUZZER_FREQ    = 310;
    static const int GREEN_BUZZER_FREQ  = 415;
    static const int BLUE_BUZZER_FREQ   = 209;
    static const int YELLOW_BUZZER_FREQ = 252;
    static const int SPEAKER_PIN        = 7;
    

    /* ------------- LEDs --------------------------*/
    static const short NEOPIXEL_PIN        = 6;
    static const short NUM_NEOPIXELS       = 4;
    
    static const short RED_PIXEL_NUM       = 0;
    static const short GREEN_PIXEL_NUM     = 1;
    static const short BLUE_PIXEL_NUM      = 2;
    static const short YELLOW_PIXEL_NUM    = 3;

    static const short RED_R_VALUE         = 70;
    static const short RED_G_VALUE         = 0;
    static const short RED_B_VALUE         = 0;

    static const short BLUE_R_VALUE        = 0;
    static const short BLUE_G_VALUE        = 0;
    static const short BLUE_B_VALUE        = 70;

    static const short GREEN_R_VALUE       = 0;
    static const short GREEN_G_VALUE       = 70;
    static const short GREEN_B_VALUE       = 0;

    static const short YELLOW_R_VALUE      = 70;  // red?
    static const short YELLOW_G_VALUE      = 0;  // blue?
    static const short YELLOW_B_VALUE      = 70; // green?

    /* PANELS */
    static const short NUM_RAND_LIGHTSHOW   = 20;
    static const short LS_BEEP_DURATION_MS  = 50;
}

#endif // SIMON_CONSTS_H
