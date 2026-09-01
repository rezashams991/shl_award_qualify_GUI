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

#define VERSION "0.1"
#define BUFFERSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include "os_wrapper.h"

int
main(void)
{
    long shpid = 0;
    long aval = 0;
    long usel = -1;
    char buffer[BUFFERSIZE];
    int i;

    printf("Stronghold Legends Steam Edition - Qualify for Awards\n");
    printf("Starting to look for Stronghold Legends process, please ensure Stronghold Legends is running...");
    fflush(stdout);
    shpid = getshpid();
    if (!shpid)
        return EXIT_FAILURE;
    printf(" found PID: %ld\n", shpid);

    printf("\nFinding base address for game code.\n");
    aval = get_opcode_address(shpid);
    printf("Found base address: %lx\n", aval);

    while (1) {
        usel = -1;
        printf("\nPlease select which award you would like to unlock.\n\n");
        printf(" 1. %-25s 21. %-25s 41. %-25s\n", AWARD_1, AWARD_21, AWARD_41);
        printf(" 2. %-25s 22. %-25s 42. %-25s\n", AWARD_2, AWARD_22, AWARD_42);
        printf(" 3. %-25s 23. %-25s 43. %-25s\n", AWARD_3, AWARD_23, AWARD_43);
        printf(" 4. %-25s 24. %-25s 44. %-25s\n", AWARD_4, AWARD_24, AWARD_44);
        printf(" 5. %-25s 25. %-25s 45. %-25s\n", AWARD_5, AWARD_25, AWARD_45);
        printf(" 6. %-25s 26. %-25s 46. %-25s\n", AWARD_6, AWARD_26, AWARD_46);
        printf(" 7. %-25s 27. %-25s 47. %-25s\n", AWARD_7, AWARD_27, AWARD_47);
        printf(" 8. %-25s 28. %-25s 48. %-25s\n", AWARD_8, AWARD_28, AWARD_48);
        printf(" 9. %-25s 29. %-25s 49. %-25s\n", AWARD_9, AWARD_29, AWARD_49);
        printf("10. %-25s 30. %-25s 50. %-25s\n", AWARD_10, AWARD_30, AWARD_50);
        printf("11. %-25s 31. %-25s 51. %-25s\n", AWARD_11, AWARD_31, AWARD_51);
        printf("12. %-25s 32. %-25s 52. %-25s\n", AWARD_12, AWARD_32, AWARD_52);
        printf("13. %-25s 33. %-25s 53. %-25s\n", AWARD_13, AWARD_33, AWARD_53);
        printf("14. %-25s 34. %-25s 54. %-25s\n", AWARD_14, AWARD_34, AWARD_54);
        printf("15. %-25s 35. %-25s 55. %-25s\n", AWARD_15, AWARD_35, AWARD_55);
        printf("16. %-25s 36. %-25s 56. %-25s\n", AWARD_16, AWARD_36, AWARD_56);
        printf("17. %-25s 37. %-25s 57. %-25s\n", AWARD_17, AWARD_37, AWARD_57);
        printf("18. %-25s 38. %-25s 58. %-25s\n", AWARD_18, AWARD_38, AWARD_58);
        printf("19. %-25s 39. %-25s 59. %-25s\n", AWARD_19, AWARD_39, AWARD_59);
        printf("20. %-25s 40. %-25s 60. %-25s\n", AWARD_20, AWARD_40, AWARD_60);
        printf("\n\t61. Enable all                62. Exit\n");
        printf("\nType your selection: ");
        fflush(stdout);

        while (usel < 1 || usel > 62) {
            for (i = 0; i < BUFFERSIZE; i++) {
                if ((buffer[i] = fgetc(stdin)) == '\n' || buffer[i] == EOF)
                    break;
            }
            usel = strtol(buffer, NULL, 10);
        }
        if (usel == 62)
            exit(EXIT_SUCCESS);

        if (usel == 61) {
            usel = 1;
            i = 60;
        } else
            i = 1;

        printf("\n");
        while (i--) {
            switch (usel++) {
                case 1:
                    printf("Enabling %s\n", AWARD_1);
                    overwrite_opcode(shpid, aval + 0x55c20, 0x9090, 2);
                    break;
                case 2:
                    printf("Enabling %s\n", AWARD_2);
                    overwrite_opcode(shpid, aval + 0x55c7e, 0x9090, 2);
                    break;
                case 3:
                    printf("Enabling %s\n", AWARD_3);
                    overwrite_opcode(shpid, aval + 0x55cb5, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55cc2, 0x909090909090, 6);
                    break;
                case 4:
                    printf("Enabling %s\n", AWARD_4);
                    overwrite_opcode(shpid, aval + 0x55cf7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55d04, 0x909090909090, 6);
                    break;
                case 5:
                    printf("Enabling %s\n", AWARD_5);
                    overwrite_opcode(shpid, aval + 0x55d39, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55d46, 0x909090909090, 6);
                    break;
                case 6:
                    printf("Enabling %s\n", AWARD_6);
                    overwrite_opcode(shpid, aval + 0x55d7b, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55d88, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55d95, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55da2, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55daf, 0x909090909090, 6);
                    break;
                case 7:
                    printf("Enabling %s\n", AWARD_7);
                    overwrite_opcode(shpid, aval + 0x55df9, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55e06, 0x909090909090, 6);
                    break;
                case 8:
                    printf("Enabling %s\n", AWARD_8);
                    overwrite_opcode(shpid, aval + 0x55e56, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55e63, 0x909090909090, 6);
                    break;
                case 9:
                    printf("Enabling %s\n", AWARD_9);
                    overwrite_opcode(shpid, aval + 0x55eb2, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55ebf, 0x909090909090, 6);
                    break;
                case 10:
                    printf("Enabling %s\n", AWARD_10);
                    overwrite_opcode(shpid, aval + 0x55f42, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55f4a, 0x909090909090, 6);
                    break;
                case 11:
                    printf("Enabling %s\n", AWARD_11);
                    overwrite_opcode(shpid, aval + 0x55fe7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x55fef, 0x909090909090, 6);
                    break;
                case 12:
                    printf("Enabling %s\n", AWARD_12);
                    overwrite_opcode(shpid, aval + 0x5609a, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x560a2, 0x909090909090, 6);
                    break;
                case 13:
                    printf("Enabling %s\n", AWARD_13);
                    overwrite_opcode(shpid, aval + 0x5611f, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56127, 0x909090909090, 6);
                    break;
                case 14:
                    printf("Enabling %s\n", AWARD_14);
                    overwrite_opcode(shpid, aval + 0x56160, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x5616d, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x5617a, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56187, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56194, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x561a7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56194, 0x00000031b8, 5);
                    break;
                case 15:
                    printf("Enabling %s\n", AWARD_15);
                    overwrite_opcode(shpid, aval + 0x561d7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x561e4, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x561f7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x561e4, 0x00000031b8, 5);
                    break;
                case 16:
                    printf("Enabling %s\n", AWARD_16);
                    overwrite_opcode(shpid, aval + 0x56227, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56230, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56239, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56249, 0x9090, 2);
                    break;
                case 17:
                    printf("Enabling %s\n", AWARD_17);
                    overwrite_opcode(shpid, aval + 0x56297, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x562a0, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x562a9, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x562b8, 0x9090, 2);
                    break;
                case 18:
                    printf("Enabling %s\n", AWARD_18);
                    overwrite_opcode(shpid, aval + 0x56307, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56310, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56319, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56328, 0x9090, 2);
                    break;
                case 19:
                    printf("Enabling %s\n", AWARD_19);
                    overwrite_opcode(shpid, aval + 0x56377, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56380, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x56390, 0x9090, 2);
                    break;
                case 20:
                    printf("Enabling %s\n", AWARD_20);
                    overwrite_opcode(shpid, aval + 0x563de, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x563e7, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x563f6, 0x9090, 2);
                    break;
                case 21:
                    printf("Enabling %s\n", AWARD_21);
                    overwrite_opcode(shpid, aval + 0x56445, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x5644e, 0x9090, 2);
                    overwrite_opcode(shpid, aval + 0x5645d, 0x9090, 2);
                    break;
                case 22:
                    printf("Enabling %s\n", AWARD_22);
                    overwrite_opcode(shpid, aval + 0x564aa, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x564b7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x564c7, 0x909090909090, 6);
                    break;
                case 23:
                    printf("Enabling %s\n", AWARD_23);
                    overwrite_opcode(shpid, aval + 0x56505, 0x909090909090, 6);
                    break;
                case 24:
                    printf("Enabling %s\n", AWARD_24);
                    overwrite_opcode(shpid, aval + 0x56553, 0x909090909090, 6);
                    break;
                case 25:
                    printf("Enabling %s\n", AWARD_25);
                    overwrite_opcode(shpid, aval + 0x565a4, 0x909090909090, 6);
                    break;
                case 26:
                    printf("Enabling %s\n", AWARD_26);
                    overwrite_opcode(shpid, aval + 0x56611, 0x909090909090, 6);
                    break;
                case 27:
                    printf("Enabling %s\n", AWARD_27);
                    overwrite_opcode(shpid, aval + 0x5667e, 0x909090909090, 6);
                    break;
                case 28:
                    printf("Enabling %s\n", AWARD_28);
                    overwrite_opcode(shpid, aval + 0x566b9, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x566cf, 0x909090909090, 6);
                    break;
                case 29:
                    printf("Enabling %s\n", AWARD_29);
                    overwrite_opcode(shpid, aval + 0x56711, 0x909090909090, 6);
                    break;
                case 30:
                    printf("Enabling %s\n", AWARD_30);
                    overwrite_opcode(shpid, aval + 0x5674f, 0x909090909090, 6);
                    break;
                case 31:
                    printf("Enabling %s\n", AWARD_31);
                    overwrite_opcode(shpid, aval + 0x5678d, 0x909090909090, 6);
                    break;
                case 32:
                    printf("Enabling %s\n", AWARD_32);
                    overwrite_opcode(shpid, aval + 0x56812, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x5681a, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56867, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56874, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56881, 0x909090909090, 6);
                    break;
                case 33:
                    printf("Enabling %s\n", AWARD_33);
                    overwrite_opcode(shpid, aval + 0x568fe, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56908, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56959, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56966, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56973, 0x909090909090, 6);
                    break;
                case 34:
                    printf("Enabling %s\n", AWARD_34);
                    overwrite_opcode(shpid, aval + 0x569fa, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56a55, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56a61, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56a6e, 0x909090909090, 6);
                    break;
                case 35:
                    printf("Enabling %s\n", AWARD_35);
                    overwrite_opcode(shpid, aval + 0x56ab5, 0x909090909090, 6);
                    break;
                case 36:
                    printf("Enabling %s\n", AWARD_36);
                    overwrite_opcode(shpid, aval + 0x56af9, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56b12, 0x909090909090, 6);
                    break;
                case 37:
                    printf("Enabling %s\n", AWARD_37);
                    overwrite_opcode(shpid, aval + 0x56b8f, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56b9c, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56ba4, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56bbd, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56bca, 0x909090909090, 6);
                    break;
                case 38:
                    printf("Enabling %s\n", AWARD_38);
                    overwrite_opcode(shpid, aval + 0x56c3f, 0x909090909090, 6);
                    break;
                case 39:
                    printf("Enabling %s\n", AWARD_39);
                    overwrite_opcode(shpid, aval + 0x56c80, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56c99, 0x909090909090, 6);
                    break;
                case 40:
                    printf("Enabling %s\n", AWARD_40);
                    overwrite_opcode(shpid, aval + 0x56cdc, 0x909090909090, 6);
                    break;
                case 41:
                    printf("Enabling %s\n", AWARD_41);
                    overwrite_opcode(shpid, aval + 0x56d1f, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d2c, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d39, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d46, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d53, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d6d, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56d53, 0x00000018b8, 5);
                    break;
                case 42:
                    printf("Enabling %s\n", AWARD_42);
                    overwrite_opcode(shpid, aval + 0x56da0, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dad, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dba, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dc7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dd4, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dee, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56dd4, 0x00000018b8, 5);
                    break;
                case 43:
                    printf("Enabling %s\n", AWARD_43);
                    overwrite_opcode(shpid, aval + 0x56e21, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e2e, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e3b, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e48, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e55, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e6f, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x56e55, 0x00000018b8, 5);
                    break;
                case 44:
                    printf("Enabling %s\n", AWARD_44);
                    overwrite_opcode(shpid, aval + 0x56ea9, 0x909090909090, 6);
                    break;
                case 45:
                    printf("Enabling %s\n", AWARD_45);
                    overwrite_opcode(shpid, aval + 0x56ef3, 0x909090909090, 6);
                    break;
                case 46:
                    printf("Enabling %s\n", AWARD_46);
                    overwrite_opcode(shpid, aval + 0x56f3d, 0x909090909090, 6);
                    break;
                case 47:
                    printf("Enabling %s\n", AWARD_47);
                    overwrite_opcode(shpid, aval + 0x56f87, 0x909090909090, 6);
                    break;
                case 48:
                    printf("Enabling %s\n", AWARD_48);
                    overwrite_opcode(shpid, aval + 0x56fd1, 0x909090909090, 6);
                    break;
                case 49:
                    printf("Enabling %s\n", AWARD_49);
                    overwrite_opcode(shpid, aval + 0x57018, 0x909090909090, 6);
                    break;
                case 50:
                    printf("Enabling %s\n", AWARD_50);
                    overwrite_opcode(shpid, aval + 0x5705f, 0x909090909090, 6);
                    break;
                case 51:
                    printf("Enabling %s\n", AWARD_51);
                    overwrite_opcode(shpid, aval + 0x570a6, 0x909090909090, 6);
                    break;
                case 52:
                    printf("Enabling %s\n", AWARD_52);
                    overwrite_opcode(shpid, aval + 0x570ed, 0x909090909090, 6);
                    break;
                case 53:
                    printf("Enabling %s\n", AWARD_53);
                    overwrite_opcode(shpid, aval + 0x57134, 0x909090909090, 6);
                    break;
                case 54:
                    printf("Enabling %s\n", AWARD_54);
                    overwrite_opcode(shpid, aval + 0x5717b, 0x909090909090, 6);
                    break;
                case 55:
                    printf("Enabling %s\n", AWARD_55);
                    overwrite_opcode(shpid, aval + 0x571f8, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x57206, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x5721b, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x57227, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x57233, 0x909090909090, 6);
                    break;
                case 56:
                    printf("Enabling %s\n", AWARD_56);
                    overwrite_opcode(shpid, aval + 0x572bd, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x572c7, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x572d4, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x572e1, 0x909090909090, 6);
                    break;
                case 57:
                    printf("Enabling %s\n", AWARD_57);
                    overwrite_opcode(shpid, aval + 0x5736a, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x57377, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x57384, 0x909090909090, 6);
                    break;
                case 58:
                    printf("Enabling %s\n", AWARD_58);
                    overwrite_opcode(shpid, aval + 0x573e1, 0x909090909090, 6);
                    break;
                case 59:
                    printf("Enabling %s\n", AWARD_59);
                    overwrite_opcode(shpid, aval + 0x574b0, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x574bc, 0x909090909090, 6);
                    overwrite_opcode(shpid, aval + 0x574cb, 0x909090909090, 6);
                    break;
                case 60:
                    printf("Enabling %s\n", AWARD_60);
                    overwrite_opcode(shpid, aval + 0x57502, 0x9090, 2);
                    break;
                default:
                    exit(EXIT_FAILURE);
            }
        }
        printf("When next you finish a map, you will be given your selection.\n");
    }
    
    return EXIT_SUCCESS;
}
