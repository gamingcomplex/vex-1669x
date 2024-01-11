#include "main.h"

bool state = false;

void toggle_wings() {
    if (WINGS_TOGGLE) {
        state = !state;
        wings.set_value(state);
    }
}