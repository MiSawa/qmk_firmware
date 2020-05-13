# QMK Standard Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
#   See TOP/keyboards/helix/rules.mk for a list of options that can be set.
#   See TOP/docs/config_options.md for more information.
#
#

LINK_TIME_OPTIMIZATION_ENABLE = yes  # if firmware size over limit, try this option

# Build options
RGBLIGHT_ENABLE = no        # Disable keyboard RGB underglow
OLED_DRIVER_ENABLE = yes            # OLED_ENABLE

SRC += oled_tasks.c
