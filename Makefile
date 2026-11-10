.SUFFIXES:

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment.")
endif

TOPDIR ?= $(CURDIR)

include $(DEVKITPRO)/libnx/switch_rules

TARGET := SwitchPorts
BUILD := build
SOURCES := source
DATA := data
INCLUDES := include

APP_TITLE := SwitchPorts
APP_AUTHOR := SwitchPorts
APP_VERSION := 1.0.0

CFLAGS := -O2 -Wall
CXXFLAGS := $(CFLAGS) -std=gnu++17
LIBS := -lnx
