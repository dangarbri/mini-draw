#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([MiniDraw], [0.1], [dg.briseno@gmail.com])
AC_CONFIG_SRCDIR([src/constants.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([SDL2/SDL.h], [], [AC_MSG_ERROR(Missing SDL.h Make sure SDL2 is installed.)])
AC_CHECK_HEADER([SDL2/SDL_image.h], [], [AC_MSG_ERROR(Missing SDL_image.h Make sure SDL2_image is installed)])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_LIB([SDL2], [SDL_VideoInit], [], [AC_MSG_ERROR(Missing library SDL2)])
AC_CHECK_LIB([SDL2_image], [IMG_LoadTexture], [], [AC_MSG_ERROR(Missing library SDL2_image)])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 lib/Makefile])
AC_OUTPUT
