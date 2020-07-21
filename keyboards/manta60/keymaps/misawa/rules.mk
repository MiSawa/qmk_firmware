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
OLED_DRIVER_ENABLE = yes    # OLED_ENABLE
EXTRAKEY_ENABLE = yes       # Audio control and System control

TIME_LIMITED_AUTO_SHIFT_ENABLE = yes     # Enable auto-shift

THIS_KEYMAP_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include $(THIS_KEYMAP_DIR)/command_mode/rules.mk
include $(THIS_KEYMAP_DIR)/time_limited_auto_shift/rules.mk

SRC += oled_tasks.c
LAYOUTS = pinkey2u
DEBOUNCE_TYPE = eager_pk

