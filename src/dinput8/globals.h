#pragma once


// the preferred base of eqgame.exe
#if defined(_M_AMD64)
constexpr uintptr_t EQGamePreferredAddress = 0x140000000;
#else
constexpr uintptr_t EQGamePreferredAddress = 0x400000;
#endif // defined(_M_AMD64)


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