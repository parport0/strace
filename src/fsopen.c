/*
 * Copyright (c) 2019 Dmitry V. Levin <ldv@strace.io>
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"
#include <linux/mount.h>
#include "xlat/fsopen_flags.h"

SYS_FUNC(fsopen)
{
	printstr(tcp, tcp->u_arg[0]);
	tprints(", ");
	printflags(fsopen_flags, tcp->u_arg[1], "FSOPEN_???");
	return RVAL_DECODED | RVAL_FD;
}
