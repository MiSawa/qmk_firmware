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
OLED_DRIVER_ENABLE = no     # OLED_ENABLE
EXTRAKEY_ENABLE = yes       # Audio control and System control

TIME_LIMITED_AUTO_SHIFT_ENABLE = yes     # Enable auto-shift
OLED_COMMAND_MODE_ENABLE = no            # Enable command mode

THIS_KEYMAP_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include $(THIS_KEYMAP_DIR)/time_limited_auto_shift/rules.mk

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_tasks.c
endif
ifeq ($(strip $(OLED_COMMAND_MODE_ENABLE)), yes)
	OPT_DEFS += -DOLED_COMMAND_MODE_ENABLE
	include $(THIS_KEYMAP_DIR)/command_mode/rules.mk
endif

LAYOUTS = pinkey2u
# DEBOUNCE_TYPE = eager_pk

