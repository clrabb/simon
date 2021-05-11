#ifndef SIMON_CONSTS_H
#define SIMON_CONSTS_H

namespace simon
{

    /* ---------------- BUTTON CONSTANTS ---------- */
    static const int BTN_LATCHED_MILLS   = 700;     // How long you need to hold the button down before it speeds up
    static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode (speed of the 'fast' mode)
    static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
    static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go
    
    /* ------------- HEARTBEAT -------------------- */
    static const short HEARTBEAT_PIN = 8;
    static const unsigned long HEARTBEAT_DURATION_OFF = 400;
    static const unsigned long HEARTBEAT_DURATION_ON  = 1000;

    /* ------------- SOUNDS ----------------------- */
    static int RED_BUZZER_FREQ    = 440;
    static int GREEN_BUZZER_FREQ  = 493;
    static int BLUE_BUZZER_FREQ   = 523;
    static int YELLOW_BUZZER_FREQ = 587;
    
    /* ------------- LEDs --------------------------*/
    static const short NEOPIXEL_PIN        = 6;
    static const short NUM_NEOPIXELS       = 4;
    
    static const short RED_PIXEL_NUM       = 0;
    static const short GREEN_PIXEL_NUM     = 1;
    static const short BLUE_PIXEL_NUM      = 2;
    static const short YELLOW_PIXEL_NUM    = 3;
    
    static const short RED_BUTTON_PIN      = 1;
    static const short GREEN_BUTTON_PIN    = 2;
    static const short BLUE_BUTTON_PIN     = 3;
    static const short YELLOW_BUTTON_PIN   = 4;

    static const short RED_R_VALUE         = 70;
    static const short RED_G_VALUE         = 0;
    static const short RED_B_VALUE         = 0;

    static const short BLUE_R_VALUE        = 0;
    static const short BLUE_G_VALUE        = 0;
    static const short BLUE_B_VALUE        = 70;

    static const short GREEN_R_VALUE       = 0;
    static const short GREEN_G_VALUE       = 70;
    static const short GREEN_B_VALUE       = 0;

    static const short YELLOW_R_VALUE      = 70;
    static const short YELLOW_G_VALUE      = 70;
    static const short YELLOW_B_VALUE      = 0;

    
    

    
}

#endif // SIMON_CONSTS_H
