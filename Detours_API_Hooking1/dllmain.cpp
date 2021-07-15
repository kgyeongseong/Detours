// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include "C:\\Users\\root\\Desktop\\Reversing\\Detours-master\\include\\detours.h"

#pragma comment(lib, "C:\\Users\\root\\Desktop\\Reversing\\Detours-master\\lib.X86\\detours.lib")

static INT(WINAPI* TrueMessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) = MessageBoxA;

extern "C" __declspec(dllexport) INT WINAPI HookMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    return TrueMessageBoxA(hWnd, "Hooking", lpCaption, uType);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID&)TrueMessageBoxA, HookMessageBoxA);
        DetourTransactionCommit();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID&)TrueMessageBoxA, HookMessageBoxA);
        DetourTransactionCommit();
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

