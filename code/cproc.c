//===================================================
// Author: Carlos Rivera
// Date: 06/24/2022
// File: cproc.c
//===================================================

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>

#include <stdio.h>

void main(int argc, char **argv) {
    HANDLE snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process_entry = {0};
    process_entry.dwSize = sizeof(PROCESSENTRY32);

    Process32First(snapshot_handle, &process_entry);

    printf("Name:               PID:\n");
    printf("===========================\n");
    for (;;) {
        // HANDLE process_handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, process_entry.th32ProcessID);

        printf("%-32s %u\n", process_entry.szExeFile, process_entry.th32ProcessID);

        // CloseHandle(process_handle);
        if (Process32Next(snapshot_handle, &process_entry) == 0) {
            break;
        }
    }

    CloseHandle(snapshot_handle);
}
