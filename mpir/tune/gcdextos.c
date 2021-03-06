/* mpn/generic/gcdext.c forced to one single limb step. */

/*
Copyright 2000 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

#include "mpir.h"
#include "gmp-impl.h"

#undef GCDEXT_DC_THRESHOLD
#define GCDEXT_DC_THRESHOLD  MP_SIZE_T_MAX
#define WANT_GCDEXT_ONE_STEP 1
#define INSIDE_TUNE_GCDEXT_BIN 1

#include "../mpn/generic/gcdext.c"
