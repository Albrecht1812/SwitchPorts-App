.SUFFIXES:

include $(DEVKITPRO)/libnx/switch_rules

TARGET := SwitchPorts

SOURCES := source
DATA := data
INCLUDES := include

APP_TITLE := SwitchPorts
APP_AUTHOR := SwitchPorts
APP_VERSION := 1.0.0

CFLAGS := -O2 -Wall
CXXFLAGS := $(CFLAGS) -std=c++17
