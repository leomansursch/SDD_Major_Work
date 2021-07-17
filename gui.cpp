//Use g++ for build
#include <iostream>  //cout
#include <winsock2.h> // scanner()
#include <Windows.h> //Sleep
#include <stdlib.h> //System
#include <ws2tcpip.h> // scanner()
#include <stdio.h>  // scanner()
#include <fstream> // fout() file creation,opening,editing,closing
#include <string.h> // string 
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "ws2_32.lib") // dependancy of <winsock2.h>
using namespace std;

// Register the window class.
const wchar_t CLASS_NAME[]  = L"Sample Window Class";

WNDCLASS wc = { };

wc.lpfnWndProc   = WindowProc;
wc.hInstance     = hInstance;
wc.lpszClassName = CLASS_NAME;

RegisterClass(&wc);

// Create the window.

HWND hwnd = CreateWindowEx(
    0,                              // Optional window styles.
    CLASS_NAME,                     // Window class
    L"Learn to Program Windows",    // Window text
    WS_OVERLAPPEDWINDOW,            // Window style

    // Size and position
    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

    NULL,       // Parent window    
    NULL,       // Menu
    hInstance,  // Instance handle
    NULL        // Additional application data
    );

if (hwnd == NULL)
{
    return 0;
}

ShowWindow(hwnd, nCmdShow);