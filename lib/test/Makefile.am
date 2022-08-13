check_PROGRAMS = compiled/test_transition compiled/test_cubic_bezier compiled/test_scratchpad compiled/test_font_cache compiled/test_sprite compiled/test_keyboard

compiled_test_transition_SOURCES = test_transition.cpp ../curve/CubicBezier.cpp
compiled_test_cubic_bezier_SOURCES = test_cubic_bezier.cpp ../curve/CubicBezier.cpp
compiled_test_scratchpad_SOURCES = test_scratchpad.cpp
compiled_test_sprite_SOURCES = test_sprite.cpp ../Sprite.cpp
compiled_test_keyboard_SOURCES = test_keyboard.cpp ../Keyboard.cpp
compiled_test_font_cache_SOURCES = test_font_cache.cpp ../FontCache.cpp

AM_CPPFLAGS = -I.. -I/usr/local/include/SDL2 -I/usr/include/SDL2
AM_LDFLAGS = -L..

TESTS = $(check_PROGRAMS)
AUTOMAKE_OPTIONS = subdir-objects

