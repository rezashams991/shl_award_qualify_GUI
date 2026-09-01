/****************************************************************************
*                                                                           *
*  award_actions.c - Actions for each award (extracted from main.c)         *
*  Copyright (C) 2026 Reza Shams  (rezashams991) <rezashams1698@gmail.com>  *
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

#include "award_actions.h"
#include "os_wrapper.h"
#include <stdlib.h>

/* Define the award names using the macros from os_wrapper.h */
const char *award_names[NUM_AWARDS] = {
    AWARD_1,  AWARD_2,  AWARD_3,  AWARD_4,  AWARD_5,
    AWARD_6,  AWARD_7,  AWARD_8,  AWARD_9,  AWARD_10,
    AWARD_11, AWARD_12, AWARD_13, AWARD_14, AWARD_15,
    AWARD_16, AWARD_17, AWARD_18, AWARD_19, AWARD_20,
    AWARD_21, AWARD_22, AWARD_23, AWARD_24, AWARD_25,
    AWARD_26, AWARD_27, AWARD_28, AWARD_29, AWARD_30,
    AWARD_31, AWARD_32, AWARD_33, AWARD_34, AWARD_35,
    AWARD_36, AWARD_37, AWARD_38, AWARD_39, AWARD_40,
    AWARD_41, AWARD_42, AWARD_43, AWARD_44, AWARD_45,
    AWARD_46, AWARD_47, AWARD_48, AWARD_49, AWARD_50,
    AWARD_51, AWARD_52, AWARD_53, AWARD_54, AWARD_55,
    AWARD_56, AWARD_57, AWARD_58, AWARD_59, AWARD_60
};

void apply_award(int award_num, long shpid, long base_addr)
{
    long aval = base_addr;  /* base address */

    /* This is an exact copy of the switch/case logic from main.c,
       without the printf statements. */
    switch (award_num) {
        case 1:
            overwrite_opcode(shpid, aval + 0x55c20, 0x9090, 2);
            break;
        case 2:
            overwrite_opcode(shpid, aval + 0x55c7e, 0x9090, 2);
            break;
        case 3:
            overwrite_opcode(shpid, aval + 0x55cb5, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55cc2, 0x909090909090, 6);
            break;
        case 4:
            overwrite_opcode(shpid, aval + 0x55cf7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55d04, 0x909090909090, 6);
            break;
        case 5:
            overwrite_opcode(shpid, aval + 0x55d39, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55d46, 0x909090909090, 6);
            break;
        case 6:
            overwrite_opcode(shpid, aval + 0x55d7b, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55d88, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55d95, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55da2, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55daf, 0x909090909090, 6);
            break;
        case 7:
            overwrite_opcode(shpid, aval + 0x55df9, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55e06, 0x909090909090, 6);
            break;
        case 8:
            overwrite_opcode(shpid, aval + 0x55e56, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55e63, 0x909090909090, 6);
            break;
        case 9:
            overwrite_opcode(shpid, aval + 0x55eb2, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55ebf, 0x909090909090, 6);
            break;
        case 10:
            overwrite_opcode(shpid, aval + 0x55f42, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55f4a, 0x909090909090, 6);
            break;
        case 11:
            overwrite_opcode(shpid, aval + 0x55fe7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x55fef, 0x909090909090, 6);
            break;
        case 12:
            overwrite_opcode(shpid, aval + 0x5609a, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x560a2, 0x909090909090, 6);
            break;
        case 13:
            overwrite_opcode(shpid, aval + 0x5611f, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56127, 0x909090909090, 6);
            break;
        case 14:
            overwrite_opcode(shpid, aval + 0x56160, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x5616d, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x5617a, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56187, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56194, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x561a7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56194, 0x00000031b8, 5);
            break;
        case 15:
            overwrite_opcode(shpid, aval + 0x561d7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x561e4, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x561f7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x561e4, 0x00000031b8, 5);
            break;
        case 16:
            overwrite_opcode(shpid, aval + 0x56227, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56230, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56239, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56249, 0x9090, 2);
            break;
        case 17:
            overwrite_opcode(shpid, aval + 0x56297, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x562a0, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x562a9, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x562b8, 0x9090, 2);
            break;
        case 18:
            overwrite_opcode(shpid, aval + 0x56307, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56310, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56319, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56328, 0x9090, 2);
            break;
        case 19:
            overwrite_opcode(shpid, aval + 0x56377, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56380, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x56390, 0x9090, 2);
            break;
        case 20:
            overwrite_opcode(shpid, aval + 0x563de, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x563e7, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x563f6, 0x9090, 2);
            break;
        case 21:
            overwrite_opcode(shpid, aval + 0x56445, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x5644e, 0x9090, 2);
            overwrite_opcode(shpid, aval + 0x5645d, 0x9090, 2);
            break;
        case 22:
            overwrite_opcode(shpid, aval + 0x564aa, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x564b7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x564c7, 0x909090909090, 6);
            break;
        case 23:
            overwrite_opcode(shpid, aval + 0x56505, 0x909090909090, 6);
            break;
        case 24:
            overwrite_opcode(shpid, aval + 0x56553, 0x909090909090, 6);
            break;
        case 25:
            overwrite_opcode(shpid, aval + 0x565a4, 0x909090909090, 6);
            break;
        case 26:
            overwrite_opcode(shpid, aval + 0x56611, 0x909090909090, 6);
            break;
        case 27:
            overwrite_opcode(shpid, aval + 0x5667e, 0x909090909090, 6);
            break;
        case 28:
            overwrite_opcode(shpid, aval + 0x566b9, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x566cf, 0x909090909090, 6);
            break;
        case 29:
            overwrite_opcode(shpid, aval + 0x56711, 0x909090909090, 6);
            break;
        case 30:
            overwrite_opcode(shpid, aval + 0x5674f, 0x909090909090, 6);
            break;
        case 31:
            overwrite_opcode(shpid, aval + 0x5678d, 0x909090909090, 6);
            break;
        case 32:
            overwrite_opcode(shpid, aval + 0x56812, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x5681a, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56867, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56874, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56881, 0x909090909090, 6);
            break;
        case 33:
            overwrite_opcode(shpid, aval + 0x568fe, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56908, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56959, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56966, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56973, 0x909090909090, 6);
            break;
        case 34:
            overwrite_opcode(shpid, aval + 0x569fa, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56a55, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56a61, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56a6e, 0x909090909090, 6);
            break;
        case 35:
            overwrite_opcode(shpid, aval + 0x56ab5, 0x909090909090, 6);
            break;
        case 36:
            overwrite_opcode(shpid, aval + 0x56af9, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56b12, 0x909090909090, 6);
            break;
        case 37:
            overwrite_opcode(shpid, aval + 0x56b8f, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56b9c, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56ba4, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56bbd, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56bca, 0x909090909090, 6);
            break;
        case 38:
            overwrite_opcode(shpid, aval + 0x56c3f, 0x909090909090, 6);
            break;
        case 39:
            overwrite_opcode(shpid, aval + 0x56c80, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56c99, 0x909090909090, 6);
            break;
        case 40:
            overwrite_opcode(shpid, aval + 0x56cdc, 0x909090909090, 6);
            break;
        case 41:
            overwrite_opcode(shpid, aval + 0x56d1f, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d2c, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d39, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d46, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d53, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d6d, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56d53, 0x00000018b8, 5);
            break;
        case 42:
            overwrite_opcode(shpid, aval + 0x56da0, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dad, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dba, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dc7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dd4, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dee, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56dd4, 0x00000018b8, 5);
            break;
        case 43:
            overwrite_opcode(shpid, aval + 0x56e21, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e2e, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e3b, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e48, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e55, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e6f, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x56e55, 0x00000018b8, 5);
            break;
        case 44:
            overwrite_opcode(shpid, aval + 0x56ea9, 0x909090909090, 6);
            break;
        case 45:
            overwrite_opcode(shpid, aval + 0x56ef3, 0x909090909090, 6);
            break;
        case 46:
            overwrite_opcode(shpid, aval + 0x56f3d, 0x909090909090, 6);
            break;
        case 47:
            overwrite_opcode(shpid, aval + 0x56f87, 0x909090909090, 6);
            break;
        case 48:
            overwrite_opcode(shpid, aval + 0x56fd1, 0x909090909090, 6);
            break;
        case 49:
            overwrite_opcode(shpid, aval + 0x57018, 0x909090909090, 6);
            break;
        case 50:
            overwrite_opcode(shpid, aval + 0x5705f, 0x909090909090, 6);
            break;
        case 51:
            overwrite_opcode(shpid, aval + 0x570a6, 0x909090909090, 6);
            break;
        case 52:
            overwrite_opcode(shpid, aval + 0x570ed, 0x909090909090, 6);
            break;
        case 53:
            overwrite_opcode(shpid, aval + 0x57134, 0x909090909090, 6);
            break;
        case 54:
            overwrite_opcode(shpid, aval + 0x5717b, 0x909090909090, 6);
            break;
        case 55:
            overwrite_opcode(shpid, aval + 0x571f8, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x57206, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x5721b, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x57227, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x57233, 0x909090909090, 6);
            break;
        case 56:
            overwrite_opcode(shpid, aval + 0x572bd, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x572c7, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x572d4, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x572e1, 0x909090909090, 6);
            break;
        case 57:
            overwrite_opcode(shpid, aval + 0x5736a, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x57377, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x57384, 0x909090909090, 6);
            break;
        case 58:
            overwrite_opcode(shpid, aval + 0x573e1, 0x909090909090, 6);
            break;
        case 59:
            overwrite_opcode(shpid, aval + 0x574b0, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x574bc, 0x909090909090, 6);
            overwrite_opcode(shpid, aval + 0x574cb, 0x909090909090, 6);
            break;
        case 60:
            overwrite_opcode(shpid, aval + 0x57502, 0x9090, 2);
            break;
        default:
            exit(EXIT_FAILURE);
    }
}