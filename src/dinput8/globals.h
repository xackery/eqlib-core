#pragma once

#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)

// the preferred base of eqgame.exe
#if defined(_M_AMD64)
constexpr uintptr_t EQGamePreferredAddress = 0x140000000;
#else
constexpr uintptr_t EQGamePreferredAddress = 0x400000;
#endif // defined(_M_AMD64)

// the base address of eqgame.exe
uintptr_t EQGameBaseAddress = (uintptr_t)GetModuleHandle(nullptr);

// the base address of eqgraphicsdx9.dll
uintptr_t EQGraphicsBaseAddress = (uintptr_t)GetModuleHandle("EQGraphicsDX9.dll");

// the base address of eqmain.dll
uintptr_t EQMainBaseAddress = (uintptr_t)GetModuleHandle("eqmain.dll");

// the base address of kernel32.dll
uintptr_t Kernel32BaseAddress = (uintptr_t)GetModuleHandle("kernel32.dll");

// the base address of gdi32.dll
uintptr_t Gdi32BaseAddress = (uintptr_t)GetModuleHandle("gdi32.dll");

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, void>>
inline uintptr_t FixEQGameOffset(T nOffset)
{
	return static_cast<uintptr_t>(nOffset) - static_cast<uintptr_t>(EQGamePreferredAddress) + EQGameBaseAddress;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, void>>
inline uintptr_t FixEQGraphicsOffset(T nOffset)
{
	return static_cast<uintptr_t>(nOffset) - static_cast<uintptr_t>(EQLibraryPreferredAddress) + EQGraphicsBaseAddress;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>, void>>
inline uintptr_t FixEQMainOffset(T nOffset)
{
	return static_cast<uintptr_t>(nOffset) - static_cast<uintptr_t>(EQLibraryPreferredAddress) + EQMainBaseAddress;
}

static void PatchMemory(void* dest, void* src, size_t length)
{
	HANDLE hProcess = GetCurrentProcess();

	DWORD oldPerms = 0;
	FlushInstructionCache(hProcess, dest, length);
	VirtualProtectEx(hProcess, dest, length, PAGE_EXECUTE_READWRITE, &oldPerms);
	WriteProcessMemory(hProcess, dest, src, length, nullptr);
	VirtualProtectEx(hProcess, dest, length, oldPerms, &oldPerms);
}