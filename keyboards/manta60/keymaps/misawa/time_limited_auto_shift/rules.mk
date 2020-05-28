
SRC += time_limited_auto_shift/process_time_limited_auto_shift.c


ifeq ($(strip $(TIME_LIMITED_AUTO_SHIFT_ENABLE)), yes)
    OPT_DEFS += -DTIME_LIMITED_AUTO_SHIFT_ENABLE
endif

