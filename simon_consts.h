#ifndef SIMON_CONSTS_H
#define SIMON_CONSTS_H


/* ---------------- BUTTON CONSTANTS ---------- */
static const int BTN_LATCHED_MILLS   = 700;     // How long you need to hold the button down before it speeds up
static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode (speed of the 'fast' mode)
static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go

#endif // SIMON_CONSTS_H
