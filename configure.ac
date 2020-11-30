#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(libcdio-discid, 1.0.0, no-define)
AN_INIT_AUTOMAKE(libcdio-discid, 1.0.0, no-define)
AC_CONFIG_SRCDIR([cdio-discid.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(LIBCDIO, libcdio >= 2.0.0, [], [AC_MSG_ERROR(Required libcdio library not found. Please get libcdio from http://www.gnu.org/software/libcdio/ and install it.)])


# Checks for header files.
AC_CHECK_HEADERS([inttypes.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT32_T

# Checks for library functions.

AC_OUTPUT