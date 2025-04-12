#include <windows.h>

#include "eqlib.h"
#include "eqlib/eqgame.h"
#include <mq/base/Detours.h>

uintptr_t EQGameBaseAddress = (uintptr_t)GetModuleHandle(nullptr);


typedef HRESULT(WINAPI* DirectInput8Create_t)(
    HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN
);




uintptr_t fdebug_addr = FixEQGameOffset(0x808E50);
FUNCTION_AT_ADDRESS(void, fdebug(const char*, ...), fdebug_addr);


HMODULE realDInput8 = nullptr;
DirectInput8Create_t real_DirectInput8Create = nullptr;

extern "C" __declspec(dllexport)
HRESULT WINAPI DirectInput8Create(
    HINSTANCE hinst, DWORD dwVersion, REFIID riid, LPVOID* ppvOut, LPUNKNOWN punkOuter)
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
    OutputDebugStringA("[dinput8 wrapper] DirectInput8Create intercepted\n");
    fdebug("[eqlib] Test");

    return real_DirectInput8Create(hinst, dwVersion, riid, ppvOut, punkOuter);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        OutputDebugStringA("[dinput8 wrapper] DllMain called\n");
        return TRUE;
    }
    return TRUE;
}