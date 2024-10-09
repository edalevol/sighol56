#include <quantum.h>

void keyboard_pre_init_kb(void) {
    gpio_set_pin_input(GP7);
}


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
}
