/****************************************************************************
*                                                                           *
*  gui_main.c - Graphical user interface for shl_award_qualify              *
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

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <commctrl.h>
#include <stdlib.h>
#include <stdio.h>

#include "os_wrapper.h"
#include "award_actions.h"

/* Control IDs */
#define IDC_LIST         1001
#define IDC_APPLY        1002
#define IDC_CLOSE        1003
#define IDC_SELECT_ALL   1004
#define IDC_CLEAR_ALL    1005
#define IDC_STATUS       1006

/* Custom message for thread completion */
#define WM_APPLY_DONE    (WM_USER + 100)

/* Structure passed to worker thread */
typedef struct {
    HWND hwnd;
    int selected[NUM_AWARDS];
    int count;
} ThreadData;

/* Forward declarations */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ApplyThread(LPVOID lpParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc = {0};
    HWND hwnd;
    MSG msg;

    /* Initialize common controls (for ListView) */
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&icex);

    /* Register window class */
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = L"SHLAwardUnlocker";
    wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(101));
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Window registration failed!", L"Error", MB_ICONERROR);
        return 1;
    }

    /* Create main window */
    hwnd = CreateWindowEx(0, L"SHLAwardUnlocker",
                          L"Stronghold Legends Award Unlocker",
                          WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
                          CW_USEDEFAULT, CW_USEDEFAULT, 620, 520,
                          NULL, NULL, hInstance, NULL);
    if (!hwnd) {
        MessageBox(NULL, L"Window creation failed!", L"Error", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    /* Message loop */
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hList, hStatus, hApply, hClose, hSelAll, hClearAll;
    static int listview_created = 0;

    switch (uMsg) {
        case WM_CREATE: {
            /* Create ListView with checkboxes */
            hList = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, L"",
                                   WS_CHILD | WS_VISIBLE | WS_BORDER |
                                   LVS_REPORT | LVS_SINGLESEL,
                                   10, 40, 580, 340,
                                   hwnd, (HMENU)IDC_LIST,
                                   ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            if (!hList) {
                MessageBox(hwnd, L"Failed to create list view!", L"Error", MB_ICONERROR);
                return -1;
            }

            /* Enable checkboxes */
            ListView_SetExtendedListViewStyle(hList, LVS_EX_CHECKBOXES);

            /* Insert columns */
            LVCOLUMN col = {0};
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            col.pszText = L"#";
            col.cx = 40;
            ListView_InsertColumn(hList, 0, &col);
            col.pszText = L"Award Name";
            col.cx = 520;
            ListView_InsertColumn(hList, 1, &col);

            /* Insert items (award names) */
            LVITEM item = {0};
            item.mask = LVIF_TEXT;
            wchar_t numstr[8];
            for (int i = 0; i < NUM_AWARDS; i++) {
                item.iItem = i;
                item.iSubItem = 0;
                swprintf(numstr, 8, L"%d", i+1);
                item.pszText = numstr;
                ListView_InsertItem(hList, &item);

                /* Set subitem text (award name) */
                wchar_t wname[256];
                MultiByteToWideChar(CP_UTF8, 0, award_names[i], -1, wname, 256);
                ListView_SetItemText(hList, i, 1, wname);
            }
            listview_created = 1;

            /* Create buttons */
            hApply = CreateWindow(L"BUTTON", L"Apply",
                                  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                  10, 390, 80, 30, hwnd, (HMENU)IDC_APPLY,
                                  ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            hClose = CreateWindow(L"BUTTON", L"Close",
                                  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                  100, 390, 80, 30, hwnd, (HMENU)IDC_CLOSE,
                                  ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            hSelAll = CreateWindow(L"BUTTON", L"Select All",
                                   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                   200, 390, 90, 30, hwnd, (HMENU)IDC_SELECT_ALL,
                                   ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            hClearAll = CreateWindow(L"BUTTON", L"Clear All",
                                     WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                     300, 390, 90, 30, hwnd, (HMENU)IDC_CLEAR_ALL,
                                     ((LPCREATESTRUCT)lParam)->hInstance, NULL);

            /* Create status text (static) */
            hStatus = CreateWindow(L"STATIC", L"Select awards and click Apply.",
                                   WS_CHILD | WS_VISIBLE | SS_LEFT,
                                   10, 430, 550, 40, hwnd, (HMENU)IDC_STATUS,
                                   ((LPCREATESTRUCT)lParam)->hInstance, NULL);
            break;
        }

        case WM_COMMAND: {
            int id = LOWORD(wParam);
            if (id == IDC_CLOSE) {
                PostQuitMessage(0);
            }
            else if (id == IDC_APPLY) {
                /* Disable Apply button to prevent double-click */
                EnableWindow(hApply, FALSE);
                /* Count selected items */
                int count = 0;
                int selected[NUM_AWARDS];
                for (int i = 0; i < NUM_AWARDS; i++) {
                    if (ListView_GetCheckState(hList, i)) {
                        selected[count++] = i + 1;  /* award numbers 1..60 */
                    }
                }
                if (count == 0) {
                    SetWindowTextW(hStatus, L"No awards selected. Please check at least one.");
                    EnableWindow(hApply, TRUE);
                    break;
                }
                /* Update status */
                SetWindowTextW(hStatus, L"Waiting for Stronghold Legends to start...");

                /* Create thread data */
                ThreadData *data = (ThreadData*)malloc(sizeof(ThreadData));
                if (!data) {
                    MessageBox(hwnd, L"Memory allocation failed!", L"Error", MB_ICONERROR);
                    EnableWindow(hApply, TRUE);
                    break;
                }
                data->hwnd = hwnd;
                data->count = count;
                memcpy(data->selected, selected, count * sizeof(int));

                /* Start worker thread */
                HANDLE hThread = CreateThread(NULL, 0, ApplyThread, data, 0, NULL);
                if (!hThread) {
                    free(data);
                    SetWindowTextW(hStatus, L"Failed to start worker thread.");
                    EnableWindow(hApply, TRUE);
                } else {
                    CloseHandle(hThread);  /* we don't need to wait for it */
                }
            }
            else if (id == IDC_SELECT_ALL) {
                for (int i = 0; i < NUM_AWARDS; i++) {
                    ListView_SetCheckState(hList, i, TRUE);
                }
            }
            else if (id == IDC_CLEAR_ALL) {
                for (int i = 0; i < NUM_AWARDS; i++) {
                    ListView_SetCheckState(hList, i, FALSE);
                }
            }
            break;
        }

        case WM_APPLY_DONE: {
            /* This message is sent by the worker thread when finished */
            int success = (int)wParam;
            const wchar_t *msg;
            if (success) {
                msg = L"All selected awards have been unlocked. You may close the window.";
            } else {
                msg = L"An error occurred. Please check if Stronghold Legends is running.";
            }
            SetWindowTextW(hStatus, msg);
            EnableWindow(hApply, TRUE);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

/* Worker thread: finds PID, base address, applies patches */
DWORD WINAPI ApplyThread(LPVOID lpParam)
{
    ThreadData *data = (ThreadData*)lpParam;
    HWND hwnd = data->hwnd;
    int count = data->count;
    int *selected = data->selected;
    int success = 0;

    /* Find PID (may wait) */
    long shpid = getshpid();
    if (shpid == 0) {
        goto done;
    }

    /* Get base address */
    long base = get_opcode_address(shpid);
    if (base == 0) {
        goto done;
    }

    /* Apply each selected award */
    for (int i = 0; i < count; i++) {
        apply_award(selected[i], shpid, base);
    }

    success = 1;

done:
    free(data);
    /* Send completion message back to main window */
    PostMessage(hwnd, WM_APPLY_DONE, (WPARAM)success, 0);
    return 0;
}