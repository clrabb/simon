#ifndef SIMON_CONSTS_H
#define SIMON_CONSTS_H


/* ---------------- BUTTON CONSTANTS ---------- */
static const int BTN_LATCHED_MILLS   = 700;     // How long you need to hold the button down before it speeds up
static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode (speed of the 'fast' mode)
static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go

/* ------------- HEARTBEAT -------------------- */
static const short HEARTBEAT_PIN = 8;
static const unsigned long HEARTBEAT_DURATION_OFF = 400;
static const unsigned long HEARTBEAT_DURATION_ON  = 1000;

/* ------------- LEDs --------------------------*/
static const short NEOPIXEL_PIN  = 6;
static const short NUM_NEOPIXELS = 2;

#endif // SIMON_CONSTS_H
