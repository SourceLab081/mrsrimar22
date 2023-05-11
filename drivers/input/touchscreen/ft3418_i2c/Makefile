# Makefile for the focaltech touchscreen drivers.

subdir-ccflags-y += -I$(srctree)/drivers/input/touchscreen/xiaomi
subdir-ccflags-y += -I$(srctree)/$(src)

obj-$(CONFIG_TOUCHSCREEN_FTS)	+= focaltech_core.o \
				   focaltech_ex_fun.o \
				   focaltech_ex_mode.o \
				   focaltech_gesture.o \
				   focaltech_esdcheck.o \
				   focaltech_point_report_check.o \
				   focaltech_flash.o \
				   focaltech_i2c.o

obj-$(CONFIG_TOUCHSCREEN_FTS)	+= focaltech_flash/
