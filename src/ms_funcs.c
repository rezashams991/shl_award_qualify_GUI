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

/* This file contains all MS specific code that is used by the os_wrapper
 * source file. */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <tlhelp32.h>
#include "ms_funcs.h"
#include "os_wrapper.h"

void
write_into_memory(long shpid, long aval, unsigned long long new_opcode, int nbytes)
{
    DWORD access = PROCESS_VM_READ |
                   PROCESS_QUERY_INFORMATION |
                   PROCESS_VM_WRITE |
                   PROCESS_VM_OPERATION;
    HANDLE *proc;
    SIZE_T nwritten = 0;
    if (!(proc = OpenProcess(access, true, shpid))) {
        printf("Error while opening handle to PID: %ld\n", shpid);
        exit(EXIT_FAILURE);
    }
    if (!(WriteProcessMemory(proc, (void *)(uintptr_t)aval,
                             &new_opcode, nbytes, &nwritten))
        || nwritten != (SIZE_T)nbytes) {
        CloseHandle(proc);
        /* We don't bother checking return value here since we will exit
         * with failure in any case. */
        printf("Error while writing memory to PID: %ld\n", shpid);
        exit(EXIT_FAILURE);
    }
    CloseHandle(proc);
}


long
get_base_address(long shpid)
{
    void *bad = NULL;
    HANDLE hsnap;
    MODULEENTRY32 modentry;
    char mname[] = MODULE_NAME;
    int i;
    modentry.dwSize = sizeof(modentry);

    hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32,
                                     shpid);
    if (hsnap != INVALID_HANDLE_VALUE) {
        if (Module32First(hsnap, &modentry)) {
            do {
                i = 0;
                while ((modentry.szModule[i] != '\0' && mname[i] != '\0')
                       && modentry.szModule[i] == mname[i])
                    i++;
                if (i && (mname[i] == '\0' && modentry.szModule[i] == '\0')) {
                    bad = modentry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hsnap, &modentry));
        }
    } else {
        printf("Error while attempting to get base module address.\n");
        exit(EXIT_FAILURE);
    }
    CloseHandle(hsnap);
    return (long)(uintptr_t)bad;
}

long
find_stronghold_pid(const char *pname)
{
    HANDLE hsnap;
    PROCESSENTRY32 proc;
    int i;
    long rpid = 0;
    proc.dwSize = sizeof(proc);

    while (1) {
        hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hsnap == INVALID_HANDLE_VALUE)
            break;
        if (!(Process32First(hsnap, &proc)))
            break;
        do {
            i = 0;
            while ((proc.szExeFile[i] != '\0' && pname[i] != '\0')
                   && proc.szExeFile[i] == pname[i])
                i++;
            if (i && (pname[i] == '\0' && proc.szExeFile[i] == '\0')) {
                rpid = (long)proc.th32ProcessID;
                CloseHandle(hsnap);
                Sleep(3000);
                return rpid;
            }
        } while (Process32Next(hsnap, &proc));
        CloseHandle(hsnap);
        Sleep(3000);
    }
    /* We only reach this point if there is an error getting the pid. */
    printf("Error while attempting to obtain PID.\n");
    return rpid;
}
