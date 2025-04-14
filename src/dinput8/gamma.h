#pragma once
#include <windows.h>
#include <mq/base/Detours.h>
#include "globals.h"
#include "fmt.h"

DETOUR_TRAMPOLINE_DEF(bool, SetDeviceGammaRamp_Trampoline, (HDC hdc, LPVOID lpRamp))
bool SetDeviceGammaRamp_Hook(HDC hdc, LPVOID lpRamp)
{
	return true;
}

void AttachGammaHook()
{
    if (!IsOptionGammaRestoreOnCrashEnabled) {
        return;
    }
    Println("Applying gamma restore patch");
    uintptr_t jmpToDeviceGamma = (uintptr_t)GetProcAddress((HMODULE)Gdi32BaseAddress, "SetDeviceGammaRamp");
    EzDetour(jmpToDeviceGamma, SetDeviceGammaRamp_Hook, SetDeviceGammaRamp_Trampoline);
}

void DetachGammaHook()
{
	if (!IsOptionGammaRestoreOnCrashEnabled) {
		return;
	}
	Println("Removing gamma restore patch");

}