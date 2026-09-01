/****************************************************************************
*                                                                           *
*  shl_award_qualify - Qualify for awards in SHL Steam Edition              *
*  Copyright (C) 2023  Daniel Jenssen <daerandin@gmail.com>                 *
*                                                                           *
*  This program is free software: you can redistribute it and/or modify     *
*  it under the terms of the GNU General Public License as published by     *
*  the Free Software Foundation, either version 3 of the License, or        *
*  (at your option) any later version.                                      *
*                                                                           *
*  This program is distributed in the hope that it will be useful,          *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
*  GNU General Public License for more details.                             *
*                                                                           *
*  You should have received a copy of the GNU General Public License        *
*  along with this program.  If not, see <https://www.gnu.org/licenses/>.   *
*                                                                           *
*****************************************************************************/

/* This file contains wrapper functions that perform calls to OS specific
 * functions in other source files. */

#ifdef STRONGHOLD_ON_GNU_LINUX
#include "gnu_linux_funcs.h"
#else
#include "ms_funcs.h"
#endif /* STRONGHOLD_ON_GNU_LINUX */

#include <stdlib.h>
#include "os_wrapper.h"

/* This will find automatically find the PID of the game.
 * The actual work is handled by the OS specific functions.
 * If Stronghold Legends is not currently running, then this function will simply
 * wait and try again every 3 seconds. */
long
getshpid(void)
{
    return find_stronghold_pid(MODULE_NAME);
}

/* This will get the base address of the game, and add the offset to it. */
long
get_opcode_address(long shpid)
{
    return get_base_address(shpid);
}

/* Here we will call OS specific functions to write the new opcode into
 * the specified address. */
void
overwrite_opcode(long shpid, long address, unsigned long long byteseq, int nbytes)
{
    int i;
    for (i = 0; i < nbytes; i++)
        write_into_memory(shpid, address, byteseq, nbytes);
}

