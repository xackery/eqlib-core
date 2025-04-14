#pragma once

#include <string>

std::string OptionServerPrefix = "[rebuildeq]"; // Logs/dbg.txt will prefix each log event with this string

// Default true. This fixes a bug in RoF2 where gamma gets overwritten by in game.
// For most people, having this set to true is preferred.
// In edge cases you may want to set this to false
bool IsOptionGammaRestoreOnCrashEnabled = true;