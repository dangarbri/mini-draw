check_PROGRAMS = compiled/test_keyboard
#check_PROGRAMS = compiled/test_sprite compiled/test_keyboard

#compiled_test_sprite_SOURCES = test_sprite.cpp ../Sprite.cpp
compiled_test_keyboard_SOURCES = test_keyboard.cpp ../Keyboard.cpp

AM_CPPFLAGS = -I.. -I/usr/local/include/SDL2
AM_LDFLAGS = -L..

TESTS = $(check_PROGRAMS)
AUTOMAKE_OPTIONS = subdir-objects

