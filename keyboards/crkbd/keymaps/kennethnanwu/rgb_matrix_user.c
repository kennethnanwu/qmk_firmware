#include QMK_KEYBOARD_H
#include "rgb_matrix_user.h"

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }

    if (layer_state_is(1)) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            rgb_matrix_set_color(i, RGB_GREEN);
        }
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}