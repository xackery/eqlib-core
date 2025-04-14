#include <windows.h>

#include "_options.h"
#include "eqlib.h"
#include "eqlib/eqgame.h"
#include "gamma.h"
#include <mq/base/Detours.h>
#include "fmt.h"

typedef HRESULT(WINAPI* DirectInput8Create_t)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);


HMODULE realDInput8 = nullptr;
DirectInput8Create_t real_DirectInput8Create = nullptr;

extern "C" __declspec(dllexport)
HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riid, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
    if (!realDInput8) {
        char systemPath[MAX_PATH];
        GetSystemDirectoryA(systemPath, MAX_PATH);
        strcat_s(systemPath, "\\dinput8.dll");

        realDInput8 = LoadLibraryA(systemPath);
        if (!realDInput8) return E_FAIL;

        real_DirectInput8Create = (DirectInput8Create_t)GetProcAddress(realDInput8, "DirectInput8Create");
        if (!real_DirectInput8Create) return E_FAIL;
    }
    Println("EQLib Injection Started");

    AttachGammaHook();
    
    return real_DirectInput8Create(hinst, dwVersion, riid, ppvOut, punkOuter);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        DetachGammaHook();
        DisableThreadLibraryCalls(hModule);
        Println("EQLib Injection Ended");
        return TRUE;
    }
    return TRUE;
}