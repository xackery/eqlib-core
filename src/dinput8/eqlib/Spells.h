/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "Common.h"
#include "Containers.h"
#include "CXStr.h"
#include "Items.h"
#include "Requirements.h"

namespace eqlib {

class PlayerZoneClient;

//============================================================================
// Spell Cache
//============================================================================

// EQ Spell "Affect"
// http://everquest.fanra.info/wiki/SPA_list
enum eEQSPA
{
	SPA_HP                                  = 0,
	SPA_AC                                  = 1,
	SPA_ATTACK_POWER                        = 2,
	SPA_MOVEMENT_RATE                       = 3,
	SPA_STR                                 = 4,
	SPA_DEX                                 = 5,
	SPA_AGI                                 = 6,
	SPA_STA                                 = 7,
	SPA_INT                                 = 8,
	SPA_WIS                                 = 9,
	SPA_CHA                                 = 10,
	SPA_HASTE                               = 11, // "Melee Speed"
	SPA_INVISIBILITY                        = 12,
	SPA_SEE_INVIS                           = 13,
	SPA_ENDURING_BREATH                     = 14,
	SPA_MANA                                = 15,
	SPA_NPC_FRENZY                          = 16,
	SPA_NPC_AWARENESS                       = 17,
	SPA_NPC_AGGRO                           = 18,
	SPA_NPC_FACTION                         = 19,
	SPA_BLINDNESS                           = 20,
	SPA_STUN                                = 21,
	SPA_CHARM                               = 22,
	SPA_FEAR                                = 23,
	SPA_FATIGUE                             = 24,
	SPA_BIND_AFFINITY                       = 25,
	SPA_GATE                                = 26,
	SPA_DISPEL_MAGIC                        = 27,
	SPA_INVIS_VS_UNDEAD                     = 28,
	SPA_INVIS_VS_ANIMALS                    = 29,
	SPA_NPC_AGGRO_RADIUS                    = 30,
	SPA_ENTHRALL                            = 31,
	SPA_CREATE_ITEM                         = 32,
	SPA_SUMMON_PET                          = 33,
	SPA_CONFUSE                             = 34,
	SPA_DISEASE                             = 35,
	SPA_POISON                              = 36,
	SPA_DETECT_HOSTILE                      = 37,
	SPA_DETECT_MAGIC                        = 38,
	SPA_NO_TWINCAST                         = 39,
	SPA_INVULNERABILITY                     = 40,
	SPA_BANISH                              = 41,
	SPA_SHADOW_STEP                         = 42,
	SPA_BERSERK                             = 43,
	SPA_LYCANTHROPY                         = 44,
	SPA_VAMPIRISM                           = 45,
	SPA_RESIST_FIRE                         = 46,
	SPA_RESIST_COLD                         = 47,
	SPA_RESIST_POISON                       = 48,
	SPA_RESIST_DISEASE                      = 49,
	SPA_RESIST_MAGIC                        = 50,
	SPA_DETECT_TRAPS                        = 51,
	SPA_DETECT_UNDEAD                       = 52,
	SPA_DETECT_SUMMONED                     = 53,
	SPA_DETECT_ANIMALS                      = 54,
	SPA_STONESKIN                           = 55,
	SPA_TRUE_NORTH                          = 56,
	SPA_LEVITATION                          = 57,
	SPA_CHANGE_FORM                         = 58,
	SPA_DAMAGE_SHIELD                       = 59,
	SPA_TRANSFER_ITEM                       = 60,
	SPA_ITEM_LORE                           = 61,
	SPA_ITEM_IDENTIFY                       = 62,
	SPA_NPC_WIPE_HATE_LIST                  = 63,
	SPA_SPIN_STUN                           = 64,
	SPA_INFRAVISION                         = 65,
	SPA_ULTRAVISION                         = 66,
	SPA_EYE_OF_ZOMM                         = 67,
	SPA_RECLAIM_ENERGY                      = 68,
	SPA_MAX_HP                              = 69,
	SPA_CORPSE_BOMB                         = 70,
	SPA_CREATE_UNDEAD                       = 71,
	SPA_PRESERVE_CORPSE                     = 72,
	SPA_BIND_SIGHT                          = 73,
	SPA_FEIGN_DEATH                         = 74,
	SPA_VENTRILOQUISM                       = 75,
	SPA_SENTINEL                            = 76,
	SPA_LOCATE_CORPSE                       = 77,
	SPA_SPELL_SHIELD                        = 78,
	SPA_INSTANT_HP                          = 79,
	SPA_ENCHANT_LIGHT                       = 80,
	SPA_RESURRECT                           = 81,
	SPA_SUMMON_TARGET                       = 82,
	SPA_PORTAL                              = 83,
	SPA_HP_NPC_ONLY                         = 84,
	SPA_MELEE_PROC                          = 85,
	SPA_NPC_HELP_RADIUS                     = 86,
	SPA_MAGNIFICATION                       = 87,
	SPA_EVACUATE                            = 88,
	SPA_HEIGHT                              = 89,
	SPA_IGNORE_PET                          = 90,
	SPA_SUMMON_CORPSE                       = 91,
	SPA_HATE                                = 92,
	SPA_WEATHER_CONTROL                     = 93,
	SPA_FRAGILE                             = 94,
	SPA_SACRIFICE                           = 95,
	SPA_SILENCE                             = 96,
	SPA_MAX_MANA                            = 97,
	SPA_BARD_HASTE                          = 98,
	SPA_ROOT                                = 99,
	SPA_HEALDOT                             = 100,
	SPA_COMPLETEHEAL                        = 101,
	SPA_PET_FEARLESS                        = 102,
	SPA_CALL_PET                            = 103,
	SPA_TRANSLOCATE                         = 104,
	SPA_NPC_ANTI_GATE                       = 105,
	SPA_BEASTLORD_PET                       = 106,
	SPA_ALTER_PET_LEVEL                     = 107,
	SPA_FAMILIAR                            = 108,
	SPA_CREATE_ITEM_IN_BAG                  = 109,
	SPA_ARCHERY                             = 110,
	SPA_RESIST_ALL                          = 111,
	SPA_FIZZLE_SKILL                        = 112,
	SPA_SUMMON_MOUNT                        = 113,
	SPA_MODIFY_HATE                         = 114,
	SPA_CORNUCOPIA                          = 115,
	SPA_CURSE                               = 116,
	SPA_HIT_MAGIC                           = 117,
	SPA_AMPLIFICATION                       = 118,
	SPA_ATTACK_SPEED_MAX                    = 119,
	SPA_HEALMOD                             = 120,
	SPA_IRONMAIDEN                          = 121,
	SPA_REDUCESKILL                         = 122,
	SPA_IMMUNITY                            = 123,
	SPA_FOCUS_DAMAGE_MOD                    = 124,
	SPA_FOCUS_HEAL_MOD                      = 125,
	SPA_FOCUS_RESIST_MOD                    = 126,
	SPA_FOCUS_CAST_TIME_MOD                 = 127,
	SPA_FOCUS_DURATION_MOD                  = 128,
	SPA_FOCUS_RANGE_MOD                     = 129,
	SPA_FOCUS_HATE_MOD                      = 130,
	SPA_FOCUS_REAGENT_MOD                   = 131,
	SPA_FOCUS_MANACOST_MOD                  = 132,
	SPA_FOCUS_STUNTIME_MOD                  = 133,
	SPA_FOCUS_LEVEL_MAX                     = 134,
	SPA_FOCUS_RESIST_TYPE                   = 135,
	SPA_FOCUS_TARGET_TYPE                   = 136,
	SPA_FOCUS_WHICH_SPA                     = 137,
	SPA_FOCUS_BENEFICIAL                    = 138,
	SPA_FOCUS_WHICH_SPELL                   = 139,
	SPA_FOCUS_DURATION_MIN                  = 140,
	SPA_FOCUS_INSTANT_ONLY                  = 141,
	SPA_FOCUS_LEVEL_MIN                     = 142,
	SPA_FOCUS_CASTTIME_MIN                  = 143,
	SPA_FOCUS_CASTTIME_MAX                  = 144,
	SPA_NPC_PORTAL_WARDER_BANISH            = 145,
	SPA_PORTAL_LOCATIONS                    = 146,
	SPA_PERCENT_HEAL                        = 147,
	SPA_STACKING_BLOCK                      = 148,
	SPA_STRIP_VIRTUAL_SLOT                  = 149,
	SPA_DIVINE_INTERVENTION                 = 150,
	SPA_POCKET_PET                          = 151,
	SPA_PET_SWARM                           = 152,
	SPA_HEALTH_BALANCE                      = 153,
	SPA_CANCEL_NEGATIVE_MAGIC               = 154,
	SPA_POP_RESURRECT                       = 155,
	SPA_MIRROR                              = 156,
	SPA_FEEDBACK                            = 157,
	SPA_REFLECT                             = 158,
	SPA_MODIFY_ALL_STATS                    = 159,
	SPA_CHANGE_SOBRIETY                     = 160,
	SPA_SPELL_GUARD                         = 161,
	SPA_MELEE_GUARD                         = 162,
	SPA_ABSORB_HIT                          = 163,
	SPA_OBJECT_SENSE_TRAP                   = 164,
	SPA_OBJECT_DISARM_TRAP                  = 165,
	SPA_OBJECT_PICKLOCK                     = 166,
	SPA_FOCUS_PET                           = 167,
	SPA_DEFENSIVE                           = 168,
	SPA_CRITICAL_MELEE                      = 169,
	SPA_CRITICAL_SPELL                      = 170,
	SPA_CRIPPLING_BLOW                      = 171,
	SPA_EVASION                             = 172,
	SPA_RIPOSTE                             = 173,
	SPA_DODGE                               = 174,
	SPA_PARRY                               = 175,
	SPA_DUAL_WIELD                          = 176,
	SPA_DOUBLE_ATTACK                       = 177,
	SPA_MELEE_LIFETAP                       = 178,
	SPA_PURETONE                            = 179,
	SPA_SANCTIFICATION                      = 180,
	SPA_FEARLESS                            = 181,
	SPA_HUNDRED_HANDS                       = 182,
	SPA_SKILL_INCREASE_CHANCE               = 183, // Unused
	SPA_ACCURACY                            = 184,
	SPA_SKILL_DAMAGE_MOD                    = 185,
	SPA_MIN_DAMAGE_DONE_MOD                 = 186,
	SPA_MANA_BALANCE                        = 187,
	SPA_BLOCK                               = 188,
	SPA_ENDURANCE                           = 189,
	SPA_INCREASE_MAX_ENDURANCE              = 190,
	SPA_AMNESIA                             = 191,
	SPA_HATE_OVER_TIME                      = 192,
	SPA_SKILL_ATTACK                        = 193,
	SPA_FADE                                = 194,
	SPA_STUN_RESIST                         = 195,
	SPA_STRIKETHROUGH1                      = 196, // Deprecated
	SPA_SKILL_DAMAGE_TAKEN                  = 197,
	SPA_INSTANT_ENDURANCE                   = 198,
	SPA_TAUNT                               = 199,
	SPA_PROC_CHANCE                         = 200,
	SPA_RANGE_ABILITY                       = 201,
	SPA_ILLUSION_OTHERS                     = 202,
	SPA_MASS_GROUP_BUFF                     = 203,
	SPA_GROUP_FEAR_IMMUNITY                 = 204,
	SPA_RAMPAGE                             = 205,
	SPA_AE_TAUNT                            = 206,
	SPA_FLESH_TO_BONE                       = 207,
	SPA_PURGE_POISON                        = 208,
	SPA_CANCEL_BENEFICIAL                   = 209,
	SPA_SHIELD_CASTER                       = 210,
	SPA_DESTRUCTIVE_FORCE                   = 211,
	SPA_FOCUS_FRENZIED_DEVASTATION          = 212,
	SPA_PET_PCT_MAX_HP                      = 213,
	SPA_HP_MAX_HP                           = 214,
	SPA_PET_PCT_AVOIDANCE                   = 215,
	SPA_MELEE_ACCURACY                      = 216,
	SPA_HEADSHOT                            = 217,
	SPA_PET_CRIT_MELEE                      = 218,
	SPA_SLAY_UNDEAD                         = 219,
	SPA_INCREASE_SKILL_DAMAGE               = 220,
	SPA_REDUCE_WEIGHT                       = 221,
	SPA_BLOCK_BEHIND                        = 222,
	SPA_DOUBLE_RIPOSTE                      = 223,
	SPA_ADD_RIPOSTE                         = 224,
	SPA_GIVE_DOUBLE_ATTACK                  = 225,
	SPA_2H_BASH                             = 226,
	SPA_REDUCE_SKILL_TIMER                  = 227,
	SPA_ACROBATICS                          = 228,
	SPA_CAST_THROUGH_STUN                   = 229,
	SPA_EXTENDED_SHIELDING                  = 230,
	SPA_BASH_CHANCE                         = 231,
	SPA_DIVINE_SAVE                         = 232,
	SPA_METABOLISM                          = 233,
	SPA_POISON_MASTERY                      = 234,
	SPA_FOCUS_CHANNELING                    = 235,
	SPA_FREE_PET                            = 236,
	SPA_PET_AFFINITY                        = 237,
	SPA_PERM_ILLUSION                       = 238,
	SPA_STONEWALL                           = 239,
	SPA_STRING_UNBREAKABLE                  = 240,
	SPA_IMPROVE_RECLAIM_ENERGY              = 241,
	SPA_INCREASE_CHANGE_MEMWIPE             = 242,
	SPA_ENHANCED_CHARM                      = 243,
	SPA_ENHANCED_ROOT                       = 244,
	SPA_TRAP_CIRCUMVENTION                  = 245,
	SPA_INCREASE_AIR_SUPPLY                 = 246,
	SPA_INCREASE_MAX_SKILL                  = 247,
	SPA_EXTRA_SPECIALIZATION                = 248,
	SPA_OFFHAND_MIN_WEAPON_DAMAGE           = 249,
	SPA_INCREASE_PROC_CHANCE                = 250,
	SPA_ENDLESS_QUIVER                      = 251,
	SPA_BACKSTAB_FRONT                      = 252,
	SPA_CHAOTIC_STAB                        = 253,
	SPA_NOSPELL                             = 254,
	SPA_SHIELDING_DURATION_MOD              = 255,
	SPA_SHROUD_OF_STEALTH                   = 256,
	SPA_GIVE_PET_HOLD                       = 257, // Deprecated
	SPA_TRIPLE_BACKSTAB                     = 258,
	SPA_AC_LIMIT_MOD                        = 259,
	SPA_ADD_INSTRUMENT_MOD                  = 260,
	SPA_SONG_MOD_CAP                        = 261,
	SPA_INCREASE_STAT_CAP                   = 262,
	SPA_TRADESKILL_MASTERY                  = 263,
	SPA_REDUCE_AA_TIMER                     = 264,
	SPA_NO_FIZZLE                           = 265,
	SPA_ADD_2H_ATTACK_CHANCE                = 266,
	SPA_ADD_PET_COMMANDS                    = 267,
	SPA_ALCHEMY_FAIL_RATE                   = 268,
	SPA_FIRST_AID                           = 269,
	SPA_EXTEND_SONG_RANGE                   = 270,
	SPA_BASE_RUN_MOD                        = 271,
	SPA_INCREASE_CASTING_LEVEL              = 272,
	SPA_DOTCRIT                             = 273,
	SPA_HEALCRIT                            = 274,
	SPA_MENDCRIT                            = 275,
	SPA_DUAL_WIELD_AMT                      = 276,
	SPA_EXTRA_DI_CHANCE                     = 277,
	SPA_FINISHING_BLOW                      = 278,
	SPA_FLURRY                              = 279,
	SPA_PET_FLURRY                          = 280,
	SPA_PET_FEIGN                           = 281,
	SPA_INCREASE_BANDAGE_AMT                = 282,
	SPA_WU_ATTACK                           = 283,
	SPA_IMPROVE_LOH                         = 284,
	SPA_NIMBLE_EVASION                      = 285,
	SPA_FOCUS_DAMAGE_AMT                    = 286,
	SPA_FOCUS_DURATION_AMT                  = 287,
	SPA_ADD_PROC_HIT                        = 288,
	SPA_DOOM_EFFECT                         = 289,
	SPA_INCREASE_RUN_SPEED_CAP              = 290,
	SPA_PURIFY                              = 291,
	SPA_STRIKETHROUGH                       = 292,
	SPA_STUN_RESIST2                        = 293,
	SPA_SPELL_CRIT_CHANCE                   = 294,
	SPA_REDUCE_SPECIAL_TIMER                = 295,
	SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL        = 296,
	SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL        = 297,
	SPA_TINY_COMPANION                      = 298,
	SPA_WAKE_DEAD                           = 299,
	SPA_DOPPELGANGER                        = 300,
	SPA_INCREASE_RANGE_DMG                  = 301,
	SPA_FOCUS_DAMAGE_MOD_CRIT               = 302,
	SPA_FOCUS_DAMAGE_AMT_CRIT               = 303,
	SPA_SECONDARY_RIPOSTE_MOD               = 304,
	SPA_DAMAGE_SHIELD_MOD                   = 305,
	SPA_WEAK_DEAD_2                         = 306,
	SPA_APPRAISAL                           = 307,
	SPA_ZONE_SUSPEND_MINION                 = 308,
	SPA_TELEPORT_CASTERS_BINDPOINT          = 309,
	SPA_FOCUS_REUSE_TIMER                   = 310,
	SPA_FOCUS_COMBAT_SKILL                  = 311,
	SPA_OBSERVER                            = 312,
	SPA_FORAGE_MASTER                       = 313,
	SPA_IMPROVED_INVIS                      = 314,
	SPA_IMPROVED_INVIS_UNDEAD               = 315,
	SPA_IMPROVED_INVIS_ANIMALS              = 316,
	SPA_INCREASE_WORN_HP_REGEN_CAP          = 317,
	SPA_INCREASE_WORN_MANA_REGEN_CAP        = 318,
	SPA_CRITICAL_HP_REGEN                   = 319,
	SPA_SHIELD_BLOCK_CHANCE                 = 320,
	SPA_REDUCE_TARGET_HATE                  = 321,
	SPA_GATE_STARTING_CITY                  = 322,
	SPA_DEFENSIVE_PROC                      = 323,
	SPA_HP_FOR_MANA                         = 324,
	SPA_NO_BREAK_AE_SNEAK                   = 325,
	SPA_ADD_SPELL_SLOTS                     = 326,
	SPA_ADD_BUFF_SLOTS                      = 327,
	SPA_INCREASE_NEGATIVE_HP_LIMIT          = 328,
	SPA_MANA_ABSORB_PCT_DMG                 = 329,
	SPA_CRIT_ATTACK_MODIFIER                = 330,
	SPA_FAIL_ALCHEMY_ITEM_RECOVERY          = 331,
	SPA_SUMMON_TO_CORPSE                    = 332,
	SPA_DOOM_RUNE_EFFECT                    = 333,
	SPA_NO_MOVE_HP                          = 334,
	SPA_FOCUSED_IMMUNITY                    = 335,
	SPA_ILLUSIONARY_TARGET                  = 336,
	SPA_INCREASE_EXP_MOD                    = 337,
	SPA_EXPEDIENT_RECOVERY                  = 338,
	SPA_FOCUS_CASTING_PROC                  = 339,
	SPA_CHANCE_SPELL                        = 340,
	SPA_WORN_ATTACK_CAP                     = 341,
	SPA_NO_PANIC                            = 342,
	SPA_SPELL_INTERRUPT                     = 343,
	SPA_ITEM_CHANNELING                     = 344,
	SPA_ASSASSINATE_MAX_LEVEL               = 345,
	SPA_HEADSHOT_MAX_LEVEL                  = 346,
	SPA_DOUBLE_RANGED_ATTACK                = 347,
	SPA_FOCUS_MANA_MIN                      = 348,
	SPA_INCREASE_SHIELD_DMG                 = 349,
	SPA_MANABURN                            = 350,
	SPA_SPAWN_INTERACTIVE_OBJECT            = 351,
	SPA_INCREASE_TRAP_COUNT                 = 352,
	SPA_INCREASE_SOI_COUNT                  = 353,
	SPA_DEACTIVATE_ALL_TRAPS                = 354,
	SPA_LEARN_TRAP                          = 355,
	SPA_CHANGE_TRIGGER_TYPE                 = 356,
	SPA_FOCUS_MUTE                          = 357,
	SPA_INSTANT_MANA                        = 358,
	SPA_PASSIVE_SENSE_TRAP                  = 359,
	SPA_PROC_ON_KILL_SHOT                   = 360,
	SPA_PROC_ON_DEATH                       = 361,
	SPA_POTION_BELT                         = 362,
	SPA_BANDOLIER                           = 363,
	SPA_ADD_TRIPLE_ATTACK_CHANCE            = 364,
	SPA_PROC_ON_SPELL_KILL_SHOT             = 365,
	SPA_GROUP_SHIELDING                     = 366,
	SPA_MODIFY_BODY_TYPE                    = 367,
	SPA_MODIFY_FACTION                      = 368,
	SPA_CORRUPTION                          = 369,
	SPA_RESIST_CORRUPTION                   = 370,
	SPA_SLOW                                = 371,
	SPA_GRANT_FORAGING                      = 372,
	SPA_DOOM_ALWAYS                         = 373,
	SPA_TRIGGER_SPELL                       = 374,
	SPA_CRIT_DOT_DMG_MOD                    = 375,
	SPA_FLING                               = 376,
	SPA_DOOM_ENTITY                         = 377,
	SPA_RESIST_OTHER_SPA                    = 378,
	SPA_DIRECTIONAL_TELEPORT                = 379,
	SPA_EXPLOSIVE_KNOCKBACK                 = 380,
	SPA_FLING_TOWARD                        = 381,
	SPA_SUPPRESSION                         = 382,
	SPA_FOCUS_CASTING_PROC_NORMALIZED       = 383,
	SPA_FLING_AT                            = 384,
	SPA_FOCUS_WHICH_GROUP                   = 385,
	SPA_DOOM_DISPELLER                      = 386,
	SPA_DOOM_DISPELLEE                      = 387,
	SPA_SUMMON_ALL_CORPSES                  = 388,
	SPA_REFRESH_SPELL_TIMER                 = 389,
	SPA_LOCKOUT_SPELL_TIMER                 = 390,
	SPA_FOCUS_MANA_MAX                      = 391,
	SPA_FOCUS_HEAL_AMT                      = 392,
	SPA_FOCUS_HEAL_MOD_BENEFICIAL           = 393,
	SPA_FOCUS_HEAL_AMT_BENEFICIAL           = 394,
	SPA_FOCUS_HEAL_MOD_CRIT                 = 395,
	SPA_FOCUS_HEAL_AMT_CRIT                 = 396,
	SPA_ADD_PET_AC                          = 397,
	SPA_FOCUS_SWARM_PET_DURATION            = 398,
	SPA_FOCUS_TWINCAST_CHANCE               = 399,
	SPA_HEALBURN                            = 400,
	SPA_MANA_IGNITE                         = 401,
	SPA_ENDURANCE_IGNITE                    = 402,
	SPA_FOCUS_SPELL_CLASS                   = 403,
	SPA_FOCUS_SPELL_SUBCLASS                = 404,
	SPA_STAFF_BLOCK_CHANCE                  = 405,
	SPA_DOOM_LIMIT_USE                      = 406,
	SPA_DOOM_FOCUS_USED                     = 407,
	SPA_LIMIT_HP                            = 408,
	SPA_LIMIT_MANA                          = 409,
	SPA_LIMIT_ENDURANCE                     = 410,
	SPA_FOCUS_LIMIT_CLASS                   = 411,
	SPA_FOCUS_LIMIT_RACE                    = 412,
	SPA_FOCUS_BASE_EFFECTS                  = 413,
	SPA_FOCUS_LIMIT_SKILL                   = 414,
	SPA_FOCUS_LIMIT_ITEM_CLASS              = 415,
	SPA_AC2                                 = 416,
	SPA_MANA2                               = 417,
	SPA_FOCUS_INCREASE_SKILL_DMG_2          = 418,
	SPA_PROC_EFFECT_2                       = 419,
	SPA_FOCUS_LIMIT_USE                     = 420,
	SPA_FOCUS_LIMIT_USE_AMT                 = 421,
	SPA_FOCUS_LIMIT_USE_MIN                 = 422,
	SPA_FOCUS_LIMIT_USE_TYPE                = 423,
	SPA_GRAVITATE                           = 424,
	SPA_FLY                                 = 425,
	SPA_ADD_EXTENDED_TARGET_SLOTS           = 426,
	SPA_SKILL_PROC                          = 427,
	SPA_PROC_SKILL_MODIFIER                 = 428,
	SPA_SKILL_PROC_SUCCESS                  = 429,
	SPA_POST_EFFECT                         = 430,
	SPA_POST_EFFECT_DATA                    = 431,
	SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS   = 432,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT    = 433,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2  = 434,
	SPA_FRAGILE_DEFENSE                     = 435,
	SPA_FREEZE_BUFF_TIMER                   = 436,
	SPA_TELEPORT_TO_ANCHOR                  = 437,
	SPA_TRANSLOCATE_TO_ANCHOR               = 438,
	SPA_ASSASSINATE                         = 439,
	SPA_FINISHING_BLOW_MAX                  = 440,
	SPA_DISTANCE_REMOVAL                    = 441,
	SPA_REQUIRE_TARGET_DOOM                 = 442,
	SPA_REQUIRE_CASTER_DOOM                 = 443,
	SPA_IMPROVED_TAUNT                      = 444,
	SPA_ADD_MERC_SLOT                       = 445,
	SPA_STACKER_A                           = 446,
	SPA_STACKER_B                           = 447,
	SPA_STACKER_C                           = 448,
	SPA_STACKER_D                           = 449,
	SPA_DOT_GUARD                           = 450,
	SPA_MELEE_THRESHOLD_GUARD               = 451,
	SPA_SPELL_THRESHOLD_GUARD               = 452,
	SPA_MELEE_THRESHOLD_DOOM                = 453,
	SPA_SPELL_THRESHOLD_DOOM                = 454,
	SPA_ADD_HATE_PCT                        = 455,
	SPA_ADD_HATE_OVER_TIME_PCT              = 456,
	SPA_RESOURCE_TAP                        = 457,
	SPA_FACTION_MOD                         = 458,
	SPA_SKILL_DAMAGE_MOD_2                  = 459,
	SPA_OVERRIDE_NOT_FOCUSABLE              = 460,
	SPA_FOCUS_DAMAGE_MOD_2                  = 461,
	SPA_FOCUS_DAMAGE_AMT_2                  = 462,
	SPA_SHIELD                              = 463,
	SPA_PC_PET_RAMPAGE                      = 464,
	SPA_PC_PET_AE_RAMPAGE                   = 465,
	SPA_PC_PET_FLURRY                       = 466,
	SPA_DAMAGE_SHIELD_MITIGATION_AMT        = 467,
	SPA_DAMAGE_SHIELD_MITIGATION_PCT        = 468,
	SPA_CHANCE_BEST_IN_SPELL_GROUP          = 469,
	SPA_TRIGGER_BEST_IN_SPELL_GROUP         = 470,
	SPA_DOUBLE_MELEE_ATTACKS                = 471,
	SPA_AA_BUY_NEXT_RANK                    = 472,
	SPA_DOUBLE_BACKSTAB_FRONT               = 473,
	SPA_PET_MELEE_CRIT_DMG_MOD              = 474,
	SPA_TRIGGER_SPELL_NON_ITEM              = 475,
	SPA_WEAPON_STANCE                       = 476,
	SPA_HATELIST_TO_TOP                     = 477,
	SPA_HATELIST_TO_TAIL                    = 478,
	SPA_FOCUS_LIMIT_MIN_VALUE               = 479,
	SPA_FOCUS_LIMIT_MAX_VALUE               = 480,
	SPA_FOCUS_CAST_SPELL_ON_LAND            = 481,
	SPA_SKILL_BASE_DAMAGE_MOD               = 482,
	SPA_FOCUS_INCOMING_DMG_MOD              = 483,
	SPA_FOCUS_INCOMING_DMG_AMT              = 484,
	SPA_FOCUS_LIMIT_CASTER_CLASS            = 485,
	SPA_FOCUS_LIMIT_SAME_CASTER             = 486,
	SPA_EXTEND_TRADESKILL_CAP               = 487,
	SPA_DEFENDER_MELEE_FORCE_PCT            = 488,
	SPA_WORN_ENDURANCE_REGEN_CAP            = 489,
	SPA_FOCUS_MIN_REUSE_TIME                = 490,
	SPA_FOCUS_MAX_REUSE_TIME                = 491,
	SPA_FOCUS_ENDURANCE_MIN                 = 492,
	SPA_FOCUS_ENDURANCE_MAX                 = 493,
	SPA_PET_ADD_ATK                         = 494,
	SPA_FOCUS_DURATION_MAX                  = 495,
	SPA_CRIT_MELEE_DMG_MOD_MAX              = 496,
	SPA_FOCUS_CAST_PROC_NO_BYPASS           = 497,
	SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT        = 498,
	SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT      = 499,
	SPA_FOCUS_CAST_TIME_MOD2                = 500,
	SPA_FOCUS_CAST_TIME_AMT                 = 501,
	SPA_FEARSTUN                            = 502,
	SPA_MELEE_DMG_POSITION_MOD              = 503,
	SPA_MELEE_DMG_POSITION_AMT              = 504,
	SPA_DMG_TAKEN_POSITION_MOD              = 505,
	SPA_DMG_TAKEN_POSITION_AMT              = 506,
	SPA_AMPLIFY_MOD                         = 507,
	SPA_AMPLIFY_AMT                         = 508,
	SPA_HEALTH_TRANSFER                     = 509,
	SPA_FOCUS_RESIST_INCOMING               = 510,
	SPA_FOCUS_TIMER_MIN                     = 511,
	SPA_PROC_TIMER_MOD                      = 512,
	SPA_MANA_MAX                            = 513,
	SPA_ENDURANCE_MAX                       = 514,
	SPA_AC_AVOIDANCE_MAX                    = 515,
	SPA_AC_MITIGATION_MAX                   = 516,
	SPA_ATTACK_OFFENSE_MAX                  = 517,
	SPA_ATTACK_ACCURACY_MAX                 = 518,
	SPA_LUCK_AMT                            = 519,
	SPA_LUCK_PCT                            = 520,
	SPA_ENDURANCE_ABSORB_PCT_DMG            = 521,
	SPA_INSTANT_MANA_PCT                    = 522,
	SPA_INSTANT_ENDURANCE_PCT               = 523,
	SPA_DURATION_HP_PCT                     = 524,
	SPA_DURATION_MANA_PCT                   = 525,
	SPA_DURATION_ENDURANCE_PCT              = 526,

	// I renamed these, so these are here for backwards compatibility
	SPA_MOVEMENTRATE DEPRECATE("Use SPA_MOVEMENT_RATE instead") = SPA_MOVEMENT_RATE,
	SPA_PLAYERSIZE DEPRECATE("Use SPA_HEIGHT instead") = SPA_HEIGHT,
	SPA_SUMMONCORPSE DEPRECATE("Use SPA_SUMMON_CORPSE instead") = SPA_SUMMON_CORPSE,
	SPA_BARDOVERHASTE DEPRECATE("Use SPA_BARD_HASTE instead") = SPA_BARD_HASTE,
	SPA_SPELLDAMAGE DEPRECATE("Use SPA_FOCUS_DAMAGE_MOD instead") = SPA_FOCUS_DAMAGE_MOD,
	SPA_HEALING DEPRECATE("Use SPA_FOCUS_HEAL_MOD instead") = SPA_FOCUS_HEAL_MOD,
	SPA_REAGENTCHANCE DEPRECATE("Use SPA_FOCUS_REAGENT_MOD instead") = SPA_FOCUS_REAGENT_MOD,
	SPA_SPELLMANACOST DEPRECATE("Use SPA_FOCUS_MANACOST_MOD instead") = SPA_FOCUS_MANACOST_MOD,
	SPA_DOUBLEATTACK DEPRECATE("Use SPA_DOUBLE_ATTACK instead") = SPA_DOUBLE_ATTACK,
	SPA_STUNRESIST DEPRECATE("Use SPA_STUN_RESIST instead") = SPA_STUN_RESIST,
	SPA_PROCMOD DEPRECATE("Use SPA_PROC_CHANCE instead") = SPA_PROC_CHANCE,
	SPA_DIVINEREZ DEPRECATE("Use SPA_DIVINE_SAVE instead") = SPA_DIVINE_SAVE,
	SPA_TRIPLEBACKSTAB DEPRECATE("Use SPA_TRIPLE_BACKSTAB instead") = SPA_TRIPLE_BACKSTAB,
	SPA_PETFLURRY DEPRECATE("Use SPA_PET_FLURRY instead") = SPA_PET_FLURRY,
	SPA_SPELLCRITCHANCE DEPRECATE("Use SPA_SPELL_CRIT_CHANCE instead") = SPA_SPELL_CRIT_CHANCE,
	SPA_INCSPELLDMG DEPRECATE("Use SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL instead") = SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL,
	SPA_DAMAGECRITMOD DEPRECATE("Use SPA_FOCUS_DAMAGE_MOD_CRIT instead") = SPA_FOCUS_DAMAGE_MOD_CRIT,
	SPA_SHIELDBLOCKCHANCE DEPRECATE("Use SPA_SHIELD_BLOCK_CHANCE instead") = SPA_SHIELD_BLOCK_CHANCE,
	SPA_SPELLDAMAGETAKEN DEPRECATE("Use SPA_FOCUS_INCOMING_DMG_MOD instead") = SPA_FOCUS_INCOMING_DMG_MOD,
	SPA_REMOVE_DETRIMENTAL DEPRECATE("Use SPA_CANCEL_NEGATIVE_MAGIC instead") = SPA_CANCEL_NEGATIVE_MAGIC,
	SPA_INVIS DEPRECATE("Use SPA_INVISIBILITY instead") = SPA_INVISIBILITY,
	SPA_INVIS_TO_UNDEAD DEPRECATE("Use SPA_INVIS_VS_UNDEAD instead") = SPA_INVIS_VS_UNDEAD,
	SPA_INVIS_TO_ANIMALS DEPRECATE("Use SPA_INVIS_VS_ANIMALS instead") = SPA_INVIS_VS_ANIMALS,

	SPA_CANCEL_MAGIC = SPA_CANCEL_NEGATIVE_MAGIC,
	SPA_NPC_REACTION_RATING = SPA_NPC_AGGRO_RADIUS,
	SPA_CLEAR_NPC_TARGETLIST = SPA_NPC_WIPE_HATE_LIST,
};

enum eEQSPELLCAT
{
	SPELLCAT_AEGOLISM = 1,
	SPELLCAT_AGILITY = 2,
	SPELLCAT_ALLIANCE = 3,
	SPELLCAT_ANIMAL = 4,
	SPELLCAT_ANTONICA = 5,
	SPELLCAT_ARMOR_CLASS = 6,
	SPELLCAT_ATTACK = 7,
	SPELLCAT_BANE = 8,
	SPELLCAT_BLIND = 9,
	SPELLCAT_BLOCK = 10,
	SPELLCAT_CALM = 11,
	SPELLCAT_CHARISMA = 12,
	SPELLCAT_CHARM = 13,
	SPELLCAT_COLD = 14,
	SPELLCAT_COMBAT_ABILITIES = 15,
	SPELLCAT_COMBAT_INNATES = 16,
	SPELLCAT_CONVERSIONS = 17,
	SPELLCAT_CREATE_ITEM = 18,
	SPELLCAT_CURE = 19,
	SPELLCAT_DAMAGE_OVER_TIME = 20,
	SPELLCAT_DAMAGE_SHIELD = 21,
	SPELLCAT_DEFENSIVE = 22,
	SPELLCAT_DESTROY = 23,
	SPELLCAT_DEXTERITY = 24,
	SPELLCAT_DIRECT_DAMAGE = 25,
	SPELLCAT_DISARM_TRAPS = 26,
	SPELLCAT_DISCIPLINES = 27,
	SPELLCAT_DISCORD = 28,
	SPELLCAT_DISEASE = 29,
	SPELLCAT_DISEMPOWERING = 30,
	SPELLCAT_DISPEL = 31,
	SPELLCAT_DURATION_HEALS = 32,
	SPELLCAT_DURATION_TAP = 33,
	SPELLCAT_ENCHANT_METAL = 34,
	SPELLCAT_ENTHRALL = 35,
	SPELLCAT_FAYDWER = 36,
	SPELLCAT_FEAR = 37,
	SPELLCAT_FIRE = 38,
	SPELLCAT_FIZZLE_RATE = 39,
	SPELLCAT_FUMBLE = 40,
	SPELLCAT_HASTE = 41,
	SPELLCAT_HEALS = 42,
	SPELLCAT_HEALTH = 43,
	SPELLCAT_HEALTH_MANA = 44,
	SPELLCAT_HP_BUFFS = 45,
	SPELLCAT_HP_TYPE_ONE = 46,
	SPELLCAT_HP_TYPE_TWO = 47,
	SPELLCAT_ILLUSION_OTHER = 48,
	SPELLCAT_ILLUSION_ADVENTURER = 49,
	SPELLCAT_IMBUE_GEM = 50,
	SPELLCAT_INVISIBILITY = 51,
	SPELLCAT_INVULNERABILITY = 52,
	SPELLCAT_JOLT = 53,
	SPELLCAT_KUNARK = 54,
	SPELLCAT_LEVITATE = 55,
	SPELLCAT_LIFE_FLOW = 56,
	SPELLCAT_LUCLIN = 57,
	SPELLCAT_MAGIC = 58,
	SPELLCAT_MANA = 59,
	SPELLCAT_MANA_DRAIN = 60,
	SPELLCAT_MANA_FLOW = 61,
	SPELLCAT_MELEE_GUARD = 62,
	SPELLCAT_MEMORY_BLUR = 63,
	SPELLCAT_MISC = 64,
	SPELLCAT_MOVEMENT = 65,
	SPELLCAT_OBJECTS = 66,
	SPELLCAT_ODUS = 67,
	SPELLCAT_OFFENSIVE = 68,
	SPELLCAT_PET = 69,
	SPELLCAT_PET_HASTE = 70,
	SPELLCAT_PET_MISC_BUFFS = 71,
	SPELLCAT_PHYSICAL = 72,
	SPELLCAT_PICKLOCK = 73,
	SPELLCAT_PLANT = 74,
	SPELLCAT_POISON = 75,
	SPELLCAT_POWER_TAP = 76,
	SPELLCAT_QUICK_HEAL = 77,
	SPELLCAT_REFLECTION = 78,
	SPELLCAT_REGEN = 79,
	SPELLCAT_RESIST_BUFF = 80,
	SPELLCAT_RESIST_DEBUFFS = 81,
	SPELLCAT_RESURRECTION = 82,
	SPELLCAT_ROOT = 83,
	SPELLCAT_RUNE = 84,
	SPELLCAT_SENSE_TRAP = 85,
	SPELLCAT_SHADOWSTEP = 86,
	SPELLCAT_SHIELDING = 87,
	SPELLCAT_SLOW = 88,
	SPELLCAT_SNARE = 89,
	SPELLCAT_SPECIAL = 90,
	SPELLCAT_SPELL_FOCUS = 91,
	SPELLCAT_SPELL_GUARD = 92,
	SPELLCAT_SPELLSHIELD = 93,
	SPELLCAT_STAMINA = 94,
	SPELLCAT_STATISTIC_BUFFS = 95,
	SPELLCAT_STRENGTH = 96,
	SPELLCAT_STUN = 97,
	SPELLCAT_SUM_AIR = 98,
	SPELLCAT_SUM_ANIMATION = 99,
	SPELLCAT_SUM_EARTH = 100,
	SPELLCAT_SUM_FAMILIAR = 101,
	SPELLCAT_SUM_FIRE = 102,
	SPELLCAT_SUM_UNDEAD = 103,
	SPELLCAT_SUM_WARDER = 104,
	SPELLCAT_SUM_WATER = 105,
	SPELLCAT_SUMMON_ARMOR = 106,
	SPELLCAT_SUMMON_FOCUS = 107,
	SPELLCAT_SUMMON_FOOD_WATER = 108,
	SPELLCAT_SUMMON_UTILITY = 109,
	SPELLCAT_SUMMON_WEAPON = 110,
	SPELLCAT_SUMMONED = 111,
	SPELLCAT_SYMBOL = 112,
	SPELLCAT_TAELOSIA = 113,
	SPELLCAT_TAPS = 114,
	SPELLCAT_TECHNIQUES = 115,
	SPELLCAT_THE_PLANES = 116,
	SPELLCAT_TIMER_1 = 117,
	SPELLCAT_TIMER_2 = 118,
	SPELLCAT_TIMER_3 = 119,
	SPELLCAT_TIMER_4 = 120,
	SPELLCAT_TIMER_5 = 121,
	SPELLCAT_TIMER_6 = 122,
	SPELLCAT_TRANSPORT = 123,
	SPELLCAT_UNDEAD = 124,
	SPELLCAT_UTILITY_BENEFICIAL = 125,
	SPELLCAT_UTILITY_DETRIMENTAL = 126,
	SPELLCAT_VELIOUS = 127,
	SPELLCAT_VISAGES = 128,
	SPELLCAT_VISION = 129,
	SPELLCAT_WISDOM_INTELLIGENCE = 130,
	SPELLCAT_TRAPS = 131,
	SPELLCAT_AURAS = 132,
	SPELLCAT_ENDURANCE = 133,
	SPELLCAT_SERPENTS_SPINE = 134,
	SPELLCAT_CORRUPTION = 135,
	SPELLCAT_LEARNING = 136,
	SPELLCAT_CHROMATIC = 137,
	SPELLCAT_PRISMATIC = 138,
	SPELLCAT_SUM_SWARM = 139,
	SPELLCAT_DELAYED = 140,
	SPELLCAT_TEMPORARY = 141,
	SPELLCAT_TWINCAST = 142,
	SPELLCAT_SUM_BODYGUARD = 143,
	SPELLCAT_HUMANOID = 144,
	SPELLCAT_HASTE_SPELL_FOCUS = 145,
	SPELLCAT_TIMER_7 = 146,
	SPELLCAT_TIMER_8 = 147,
	SPELLCAT_TIMER_9 = 148,
	SPELLCAT_TIMER_10 = 149,
	SPELLCAT_TIMER_11 = 150,
	SPELLCAT_TIMER_12 = 151,
	SPELLCAT_HATRED = 152,
	SPELLCAT_FAST = 153,
	SPELLCAT_ILLUSION_SPECIAL = 154,
	SPELLCAT_TIMER_13 = 155,
	SPELLCAT_TIMER_14 = 156,
	SPELLCAT_TIMER_15 = 157,
	SPELLCAT_TIMER_16 = 158,
	SPELLCAT_TIMER_17 = 159,
	SPELLCAT_TIMER_18 = 160,
	SPELLCAT_TIMER_19 = 161,
	SPELLCAT_TIMER_20 = 162,
	SPELLCAT_ALARIS = 163,
	SPELLCAT_COMBINATION = 164,
	SPELLCAT_INDEPENDENT = 165,
	SPELLCAT_SKILL_ATTACKS = 166,
	SPELLCAT_INCOMING = 167,
	SPELLCAT_CURSE = 168,
	SPELLCAT_TIMER_21 = 169,
	SPELLCAT_TIMER_22 = 170,
	SPELLCAT_TIMER_23 = 171,
	SPELLCAT_TIMER_24 = 172,
	SPELLCAT_TIMER_25 = 173,
	SPELLCAT_DRUNKENNESS = 174,
	SPELLCAT_THROWING = 175,
	SPELLCAT_MELEE_DAMAGE = 176
};

inline bool IsSpellCountersSPA(int attrib)
{
	return attrib == SPA_DISEASE                     // Disease Counters
		|| attrib == SPA_POISON                      // Poison Counters
		|| attrib == SPA_CURSE                       // Curse Counters
		|| attrib == SPA_CORRUPTION;                 // Corruption Counters
}

inline bool IsDamageAbsorbSPA(int attrib)
{
	return attrib == SPA_STONESKIN                   // Absorb Damage
		|| attrib == SPA_SPELL_SHIELD                // SpellShield
		|| attrib == SPA_SPELL_GUARD                 // Mitigate Spell Damage
		|| attrib == SPA_MELEE_GUARD                 // Mitigate Melee Damage
		|| attrib == SPA_DOT_GUARD                   // DoT Guard
		|| attrib == SPA_MELEE_THRESHOLD_GUARD       // Melee Threshold Guard
		|| attrib == SPA_SPELL_THRESHOLD_GUARD;      // Spell Threshold Guard
}

enum eResistType
{
	ResistType_None = 0,
	ResistType_Magic = 1,
	ResistType_Fire = 2,
	ResistType_Cold = 3,
	ResistType_Poison = 4,
	ResistType_Disease = 5,
	ResistType_Chromatic = 6,
	ResistType_Prismatic = 7,
	ResistType_Physical = 8,
	ResistType_Corruption = 9,
};

enum eSpellType : uint8_t
{
	SpellType_Detrimental = 0,
	SpellType_Beneficial = 1,
	SpellType_BeneficialGroupOnly = 2
};

// Determines the algorithm used to affect the spell value, potentially affected by
// time or by level or other things too...
enum eSpellValueRangeCalc
{
	SpellValueRangeCalc_DecayTick1 = 107,
	SpellValueRangeCalc_DecayTick2 = 108,
	SpellValueRangeCalc_DecayTick5 = 120,
	SpellValueRangeCalc_DecayTick12 = 122,
	SpellValueRangeCalc_Random = 123,
};

enum eSpellNoOverwrite : int
{
	NoOverwrite_Default,     // Spell can be overwritten normally
	NoOverwrite_OtherSpells, // Spell cannot be overwritten by other spells, except itself
	NoOverwrite_AllSpells,   // Spell cannot be overwritten by any spell
};

enum eSpellRecourseType : int
{
	SpellRecourseType_AlwaysHit,            // Recourse for every target that it could hit
	SpellRecourseType_AlwaysHitNoResist,    // Recourse for every target
	SpellRecourseType_OnceNoResist,         // Recourse once, if target exists
	SpellRecourseType_Once,                 // Recourse once, if spell hits
};

enum eSpellTargetType : uint8_t
{
	TargetType_None = 0,
	TargetType_LineOfSight = 1,
	TargetType_AEPC_v1 = 2,                 // players in area around caster
	TargetType_Group_v1 = 3,                // group members around caster
	TargetType_PBAE = 4,                    // area around caster
	TargetType_Single = 5,                  // current target
	TargetType_Self = 6,                    // targets self only
	TargetType_TargetArea = 8,              // radius around target
	TargetType_TargetAnimal = 9,
	TargetType_TargetUndead = 10,
	TargetType_TargetSummoned = 11,
	TargetType_TargetDrain = 13,
	TargetType_Pet = 14,                    // caster's pet
	TargetType_TargetCorpse = 15,
	TargetType_TargetPlant = 16,
	TargetType_TargetGiants = 17,
	TargetType_TargetDragons = 18,
	TargetType_TargetColdain = 19,
	TargetType_TargetAEDrain = 20,
	TargetType_TargetAEUndead = 24,
	TargetType_TargetAESummoned = 25,
	TargetType_HateList = 32,               // all players on hatelist in range
	TargetType_HateList_All = 33,           // all players on hatelist regardless of range
	TargetType_TargetCursed = 34,
	TargetType_TargetMuramite = 35,
	TargetType_CasterAreaPC = 36,
	TargetType_CasterAreaNPC = 37,
	TargetType_Pet_v2 = 38,                 // targeted pet
	TargetType_TargetPC = 39,               // targeted player
	TargetType_AEPC_v2 = 40,                // area beneficial players
	TargetType_Group_v2 = 41,               // area grouped players
	TargetType_DirectionalCone = 42,        // projected cone in front of player
	TargetType_SingleGrouped = 43,          // single target grouped
	TargetType_Beam = 44,
	TargetType_FreeTarget = 45,             // player picks a point in space
	TargetType_TargetOfTarget = 46,
	TargetType_PetOwner = 47,               // cast on pet's owner
	TargetType_AreaDetrimental = 50,        // targets enemies of caster
	TargetType_TargetBeneficial = 52,
};

enum eSpellStringType
{
	SpellStringCastByMe,
	SpellStringCastByOther,
	SpellStringCastOnYou,
	SpellStringCastOnAnother,
	SpellStringWearOff,
};

constexpr int MAX_SPELL_REAGENTS = 4;
constexpr int MAX_EFFECT_SLOTS = 12;

struct [[offsetcomments]] SpellAffectData
{
/*0x00*/ int     Slot = 0;
/*0x08*/ int64_t Base = 0;
/*0x10*/ int64_t Base2 = 0;
/*0x18*/ int64_t Max = 0;
/*0x20*/ int     Calc = 0;
/*0x24*/ int     Attrib = SPA_NOSPELL;
/*0x28*/
};

using SPELLCALCINFO = SpellAffectData;
using PSPELLCALCINFO = SPELLCALCINFO*;


#pragma pack(push)
#pragma pack(1)

// @sizeof(EQ_Spell) == 0x4ed :: 2013-05-10 (emu) @ 0x4AFB06
constexpr size_t EQ_Spell_size = 0x4ed;

class [[offsetcomments]] EQ_Spell
{
public:
	EQLIB_OBJECT EQ_Spell(char*);
	EQLIB_OBJECT bool IsStackableDot() const;
	EQLIB_OBJECT int IsPermIllusionSpell() const;
	EQLIB_OBJECT int SpellUsesDragonBreathEffect();
	EQLIB_OBJECT unsigned char SpellAffects(int) const;                  // this one takes an attrib(soe calls it affect) and returns the index for it...
	EQLIB_OBJECT unsigned char GetSpellLevelNeeded(EQClass) const;       // takes a Class, druid for example is 6
	EQLIB_OBJECT int SpellAffectBase(int) const;                         // takes a SPA, returns the first matching base it finds for it
	EQLIB_OBJECT const SpellAffectData* GetSpellAffectByIndex(int Index) const;
	EQLIB_OBJECT static bool IsDegeneratingLevelMod(int);

	EQLIB_OBJECT static bool IsSPAStacking(int Spa);
	EQLIB_OBJECT static bool IsSPAIgnoredByStacking(int Spa);

	inline bool IsNoDispell() const { return NoDispell; }
	inline bool IsStackableOnAnyone() const { return SpellAffects(424) != 0; }
	inline int GetNoOverwrite() const { return NoOverwrite; }
	inline bool IsShortEffectDuration() const { return DurationWindow; }
	inline bool GetIsSkillSpell() const { return IsSkill; }

	inline bool IsLullSpell() const
	{
		for (int i = 0; i < GetNumEffects(); ++i)
		{
			int attrib = GetEffectAttrib(i);

			if (attrib == SPA_NPC_AGGRO
				|| attrib == SPA_NPC_AGGRO_RADIUS
				|| attrib == SPA_NPC_HELP_RADIUS)
			{
				return true;
			}
		}

		return false;
	}

	inline bool IsDoTSpell() const
	{
		return SpellAffects(0) || SpellAffects(20) || SpellAffects(69) || SpellAffects(114) || SpellAffects(125);
	}

	inline bool IsStackable() const
	{
		if (NotStackableDot)
			return false;
		if (SpellType != SpellType_Detrimental)
			return false;
		if (DurationType == 0) // TODO: Constant
			return false;

		return SpellAffects(SPA_HP) != 0 || SpellAffects(SPA_GRAVITATE) != 0;
	}

	inline bool IsBeneficialSpell() const
	{
		return SpellType >= SpellType_Beneficial;
	}

	inline bool IsBeneficialSpellUsedDetrimentally() const
	{
		int attrib = GetEffectAttrib(0);

		return attrib == SPA_NPC_WIPE_HATE_LIST
			|| attrib == SPA_NPC_AGGRO_RADIUS
			|| attrib == SPA_NPC_FACTION
			|| attrib == SPA_DISPEL_MAGIC
			|| IsLullSpell();
	}

	inline bool IsDetrimentalSpell() const
	{
		return !IsBeneficialSpell() || IsBeneficialSpellUsedDetrimentally();
	}

	inline bool IsNoRemove() const
	{
		return !IsBeneficialSpell() || NoRemove;
	}

/*0x000*/ float                Range = 0.0f;
/*0x004*/ float                AERange = 0.0f;
/*0x008*/ float                PushBack = 0.0f;
/*0x00c*/ float                PushUp = 0.0f;
/*0x010*/ uint32_t             CastTime = 0;
/*0x014*/ uint32_t             RecoveryTime = 0;
/*0x018*/ uint32_t             RecastTime = 0;
/*0x01c*/ uint32_t             DurationType = 0;                    // DurationFormula on Lucy
/*0x020*/ uint32_t             DurationCap = 0;
/*0x024*/ uint32_t             AEDuration = 0;
/*0x028*/ int                  ManaCost = 0;
/*0x02c*/ int                  Base[MAX_EFFECT_SLOTS];              // Base1-Base12
/*0x05c*/ int                  Base2[MAX_EFFECT_SLOTS];             // SpellID of spell for added effects
/*0x08c*/ int                  Max[MAX_EFFECT_SLOTS];               // Max1-Max12
/*0x0bc*/ int                  ReagentID[MAX_SPELL_REAGENTS];       // ReagentId1-ReagentId4d
/*0x0cc*/ int                  ReagentCount[MAX_SPELL_REAGENTS];    // ReagentCount1-ReagentCount4
/*0x0dc*/ int                  NoExpendReagent[MAX_SPELL_REAGENTS];
/*0x0ec*/ int                  Calc[MAX_EFFECT_SLOTS];              // Calc1-Calc12
/*0x11c*/ int                  Attrib[MAX_EFFECT_SLOTS];            // Attrib1-Attrib12
/*0x14c*/ int                  BookIcon = 0;
/*0x150*/ int                  GemIcon = 0;
/*0x154*/ int                  DescriptionIndex = 0;
/*0x158*/ int                  ResistAdj = 0;
/*0x15c*/ int                  Deity = 0;
/*0x160*/ int                  spaindex = 0;
/*0x164*/ int                  SpellAnim = 0;
/*0x168*/ int                  SpellIcon = 0;
/*0x16c*/ int                  DurationParticleEffect = 0;
/*0x170*/ int                  NPCUsefulness = 0;
/*0x174*/ int                  ID = 0;
/*0x178*/ int                  Autocast = 0;                  // SpellID of spell to instacast on caster when current spell lands on target
/*0x17c*/ int                  Category = 0;
/*0x180*/ int                  Subcategory = 0;
/*0x184*/ int                  Subcategory2 = 0;
/*0x188*/ int                  HateMod = 0;                   // Additional hate
/*0x18c*/ int                  ResistPerLevel = 0;
/*0x190*/ int                  ResistCap = 0;
/*0x194*/ int                  EnduranceCost = 0;             // CA Endurance Cost
/*0x198*/ int                  ReuseTimerIndex = 0;           // ID of combat timer, i think.
/*0x19c*/ int                  EnduranceUpkeep = 0;
/*0x1a0*/ int                  HateGenerated = 0;             // Hate override
/*0x1a4*/ int                  HitCountType = 0;
/*0x1a8*/ int                  HitCount = 0;
/*0x1ac*/ int                  ConeStartAngle = 0;
/*0x1b0*/ int                  ConeEndAngle = 0;
/*0x1b4*/ int                  PvPResistBase = 0;
/*0x1b8*/ int                  PvPCalc = 0;
/*0x1bc*/ int                  PvPResistCap = 0;
/*0x1c0*/ uint32_t             PvPDuration = 0;               // DurationType for PVP
/*0x1c4*/ uint32_t             PvPDurationCap = 0;
/*0x1c8*/ int                  GlobalGroup = 0;
/*0x1cc*/ int                  PCNPCOnlyFlag = 0;
/*0x1d0*/ int                  NPCMemCategory = 0;
/*0x1d4*/ int                  SpellGroup = 0;
/*0x1d8*/ int                  SpellSubGroup = 0;
/*0x1dc*/ int                  SpellRank = 0;
/*0x1e0*/ int                  SpellClass = 0;
/*0x1e4*/ int                  SpellSubClass = 0;
/*0x1e8*/ int                  SpellReqAssociationID = 0;
/*0x1ec*/ int                  CasterRequirementID = 0;
/*0x1f0*/ int                  MaxResist = 0;
/*0x1f4*/ int                  MinResist = 0;
/*0x1f8*/ int                  MinSpreadTime = 0;
/*0x1fc*/ int                  MaxSpreadTime = 0;
/*0x200*/ int                  SpreadRadius = 0;
/*0x204*/ int                  BaseEffectsFocusCap = 0;       // song cap, maybe other things?
/*0x208*/ int                  CritChanceOverride = 0;
/*0x20c*/ int                  MaxTargets = 0;                // how many targets a spell will affect
/*0x210*/ uint32_t             AIValidTargets = 0;
/*0x214*/ int                  BaseEffectsFocusOffset = 0;
/*0x218*/ float                BaseEffectsFocusSlope = 1.0f;
/*0x21c*/ CVector2             DistanceModStart = { 0, 0 };
/*0x224*/ CVector2             DistanceModEnd = { 0, 0 };
/*0x22c*/ float                MinRange = 0.0f;
/*0x230*/ bool                 NoNPCLOS = false;              // NPC skips LOS checks
/*0x231*/ bool                 Feedbackable = false;
/*0x232*/ bool                 Reflectable = false;
/*0x233*/ bool                 NoPartialSave = false;
/*0x234*/ bool                 NoResist = false;
/*0x235*/ bool                 UsesPersistentParticles = false;
/*0x236*/ bool                 SmallTargetsOnly = false;
/*0x237*/ bool                 DurationWindow = false;        // 0=Long, 1=Short
/*0x238*/ bool                 Uninterruptable = false;
/*0x239*/ bool                 NotStackableDot = false;
/*0x23a*/ bool                 Deletable = false;
/*0x23b*/ bool                 BypassRegenCheck = false;
/*0x23c*/ bool                 CanCastInCombat = false;
/*0x23d*/ bool                 CanCastOutOfCombat = false;
/*0x23e*/ bool                 NoHealDamageItemMod = false;   // disable worn focus bonuses
/*0x23f*/ bool                 OnlyDuringFastRegen = false;
/*0x240*/ bool                 CastNotStanding = false;
/*0x241*/ bool                 CanMGB = false;
/*0x242*/ bool                 NoDispell = false;
/*0x243*/ bool                 AffectInanimate = false;       // ldon trap spells etc
/*0x244*/ bool                 IsSkill = false;
/*0x245*/ bool                 ShowDoTMessage = false;
/*0x246*/ uint8_t              ClassLevel[MAX_CLASSES + 1];
/*0x26a*/ uint8_t              LightType = 0;
/*0x26b*/ eSpellType           SpellType = SpellType_Detrimental; // 0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x26c*/ uint8_t              Activated;                     // emu
/*0x26d*/ uint8_t              Resist = 0;                    // enum eResistType
/*0x26e*/ uint8_t              TargetType = 0;                // enum eSpellTargetType
/*0x26f*/ uint8_t              CastDifficulty = 0;
/*0x270*/ uint8_t              Skill = 0;
/*0x271*/ uint8_t              ZoneType = 0;                  // 01=Outdoors, 02=dungeons, ff=Any
/*0x272*/ uint8_t              Environment = 0;
/*0x273*/ uint8_t              TimeOfDay = 0;                 // 0=any, 1=day only, 2=night only
/*0x274*/ uint8_t              CastingAnim = 0;
/*0x275*/ uint8_t              AnimVariation = 0;
/*0x276*/ uint8_t              TargetAnim = 0;
/*0x277*/ uint8_t              TravelType = 0;
/*0x278*/ uint8_t              CancelOnSit = 0;
/*0x279*/ bool                 CountdownHeld = false;
/*0x27a*/ char                 Name[64];
/*0x2ba*/ char                 Target[32];
/*0x2da*/ char                 Extra[32];                     // This is 'Extra' from Lucy (portal shortnames etc) official = NPC_FILENAME
/*0x2fa*/ char                 CastByMe[96];
/*0x35a*/ char                 CastByOther[96];
/*0x3ba*/ char                 CastOnYou[96];
/*0x41a*/ char                 CastOnAnother[96];
/*0x47a*/ char                 WearOff[96];
/*0x4da*/ bool                 ShowWearOffMessage = false;
/*0x4db*/ uint8_t              NPCChanceofKnowingSpell = 0;   // if this is 0 there is no way an npc can cast this spell...
/*0x4dc*/ bool                 SneakAttack = false;
/*0x4dd*/ bool                 NotFocusable = false;          // ignores all(?) focus effects
/*0x4de*/ bool                 NoHate = false;
/*0x4df*/ bool                 StacksWithSelf = false;
/*0x4e0*/ bool                 NoBuffBlock = false;
/*0x4e1*/ bool                 Scribable = 1;
/*0x4e2*/ bool                 NoStripOnDeath = false;
/*0x4e3*/ bool                 NoRemove = false;              // spell can't be clicked off?
/*0x4e4*/ eSpellNoOverwrite    NoOverwrite = NoOverwrite_Default;
/*0x4e8*/ uint8_t              CRC32Marker = 0;
/*0x4e9*/ eSpellRecourseType   SpellRecourseType = SpellRecourseType_AlwaysHit;
/*0x4f0*/

	ALT_MEMBER_ALIAS_DEPRECATED(int, Deity, Diety, "Diety is misspelled, use Deity instead.")
	ALT_MEMBER_ALIAS_DEPRECATED(int, EnduranceUpkeep, EndurUpkeep, "EndurUpkeep has been replaced with EnduranceUpkeep.")
	ALT_MEMBER_ALIAS_DEPRECATED(uint32_t, PvPDurationCap, PvPDurationValue1, "PvPDurationValue1 has been replaced with PvPDurationCap")
	ALT_MEMBER_ALIAS_DEPRECATED(bool, NoDispell, NoDisspell, "NoDisspell is misspelled, use IsNoDispell() instead")

	ALT_MEMBER_GETTER(bool, ShowDoTMessage, bShowDoTMessage);
	ALT_MEMBER_GETTER(bool, CastDifficulty, FizzleAdj);
	ALT_MEMBER_GETTER(bool, CountdownHeld, IsCountdownHeld);
	ALT_MEMBER_GETTER(bool, NPCChanceofKnowingSpell, NPCNoCast);
	ALT_MEMBER_GETTER(bool, NoHate, NoDetrimentalSpellAggro);

	int get_NumEffects() const { return MAX_EFFECT_SLOTS; }
	__declspec(property(get = get_NumEffects)) int NumEffects;

	// Fields that aren't available in emu
	bool get_CannotBeScribed() const { return false; }
	__declspec(property(get = get_CannotBeScribed)) bool CannotBeScribed;

	int get_ActorTagId() const { return 0; }
	__declspec(property(get = get_ActorTagId)) int ActorTagId;

	float get_DistanceMod() const { return 0.0f; }
	__declspec(property(get = get_DistanceMod)) float DistanceMod;

	bool get_StacksWithDiscs() const { return false; }
	__declspec(property(get = get_StacksWithDiscs)) bool bStacksWithDiscs;

	int get_CalcIndex() const { return -1; }
	__declspec(property(get = get_CalcIndex)) int CalcIndex;

	// Currently necessary because of MQ2DataTypes
	EQLIB_OBJECT EQ_Spell();
	EQLIB_OBJECT ~EQ_Spell() = default;

	DEPRECATE("Data property is not needed, use Spell directly.")
	EQLIB_OBJECT EQ_Spell& get_Data() { return *this; }
	__declspec(property(get = get_Data)) EQ_Spell& Data;

	inline int GetNumEffects() const { return MAX_EFFECT_SLOTS; }
	EQLIB_OBJECT int GetEffectAttrib(int index) const;
	EQLIB_OBJECT int64_t GetEffectBase(int index) const;
	EQLIB_OBJECT int64_t GetEffectBase2(int index) const;
	EQLIB_OBJECT int64_t GetEffectMax(int index) const;
	EQLIB_OBJECT int GetEffectCalc(int index) const;
};
using SPELL = EQ_Spell;
using PSPELL = EQ_Spell*;

#pragma pack(pop) // EQ_Spell

SIZE_CHECK(EQ_Spell, EQ_Spell_size);

//----------------------------------------------------------------------------

class [[offsetcomments]] SpellRequirementAssociationManager : public RequirementAssociationManager
{
public:
/*0x230*/ HashList<HashList<HashList<int, 10>, 10>, 200> ReqAssocData;
/*0x560*/
};

enum EEffectActor
{
	EEA_None,
	EEA_Caster,
	EEA_Missile,
	EEA_Target,
	EEA_COUNT,
};

enum EAttachPoint
{
	EAP_None,
	EAP_Default,
	EAP_Chest,
	EAP_Head,
	EAP_LeftHand,
	EAP_RightHand,
	EAP_LeftFoot,
	EAP_RightFoot,
	EAP_Weapon,
	EAP_LeftEye,
	EAP_RightEye,
	EAP_Mouth,
	EAP_Ground,
	EAP_Cnt,
};

struct [[offsetcomments]] SpellEffectEmitter
{
/*0x00*/ int DefIndex;
/*0x04*/ int RequiredLevel;
/*0x08*/ EEffectActor EffectActor;
/*0x0c*/ EAttachPoint AttachPoint;
/*0x10*/
};

struct [[offsetcomments]] SpellEffectStage
{
/*0x00*/ int                SoundNum;
/*0x04*/ SpellEffectEmitter Emitters[4];
/*0x44*/
};

struct [[offsetcomments]] NewSpellEffect
{
/*0x000*/ char               szSpellEffectName[0x40];
/*0x040*/ SpellEffectStage   Stages[3];
/*0x10c*/
};

struct [[offsetcomments]] StageType
{
/*0x000*/ char               BlitSprite[3][0x20];
/*0x060*/ char               AttachTag[0x20];
/*0x080*/ int                DAGnum[3];
/*0x08c*/ int                pcloud[3];
/*0x098*/ char               SpriteTAG[0xc][0x20];
/*0x218*/ int                SpritEffect;
/*0x21c*/ int                SoundNum;
/*0x220*/ ARGBCOLOR          Tint[3];
/*0x22c*/ float              Gravity[3];
/*0x238*/ float              NormalX1;
/*0x23c*/ float              NormalY1;
/*0x240*/ float              NormalZ1;
/*0x244*/ float              NormalX2;
/*0x248*/ float              NormalY2;
/*0x24c*/ float              NormalZ2;
/*0x250*/ float              NormalX3;
/*0x254*/ float              NormalY3;
/*0x258*/ float              NormalZ3;
/*0x25c*/ float              Radius[3];
/*0x268*/ float              Angle[3];
/*0x274*/ ULONG              Lifespan[3];
/*0x280*/ float              Velocity[3];
/*0x28c*/ ULONG              Rate[3];
/*0x298*/ float              Scale[3];
/*0x2a4*/ EQRGB              SpriteRGB[0xc];
/*0x2c8*/ float              RollRate[0xc];
/*0x2f8*/ short              HdgOffset[0xc];
/*0x310*/ short              PitchOffset[0xc];
/*0x328*/ float              Distance[0xc];
/*0x358*/ short              EffectType[12];
/*0x370*/ float              ScaleFactor[12];
/*0x3a0*/
};

struct [[offsetcomments]] OldSpellEffect
{
/*0x000*/ int                Tgts;
/*0x004*/ int                Perm;
/*0x008*/ StageType          stages[3];
/*0xae8*/
};

class [[offsetcomments]] EQSpellExtra
{
public:
/*0x00*/ OldSpellEffect*    OldSpellEff;
/*0x04*/ NewSpellEffect*    NewSpellEff;
/*0x08*/
};

//Matching stack group ID rules
enum ESpellStackingRules
{
	ESSR_None,                                   // default
	ESSR_SingleCaster,
	ESSR_AllCasters,
	ESSR_SingleCasterOnlyGreater,
	ESSR_AllCastersOnlyGreater,
	ESSR_SingleCasterNeverOverwrite,
	ESSR_AllCastersNeverOverwrite,
	ESSR_SingleCasterAlwaysOverwrite,
	ESSR_AllCastersAlwaysOverwrite,
	ESSR_Invalid,
};

struct [[offsetcomments]] StackingGroupData
{
/*0x00*/ int StackingGroupID;
/*0x04*/ int StackingGroupRank;
/*0x08*/ ESpellStackingRules StackingGroupRuleType;
/*0x0c*/
};

constexpr int TOTAL_SPELL_COUNT = 45001;
constexpr int TOTAL_SPELL_AFFECT_COUNT = 15000;

class [[offsetcomments]] SpellManager : public FileStatMgr
{
public:
/*0x00014*/ int              SpellsCrc32[TOTAL_SPELL_COUNT];
/*0x2bf38*/ EQ_Spell*        MissingSpell;
/*0x2bf3c*/ int              MissingSpellCrc32;
/*0x2bf40*/ int              SpellFileCRC;
/*0x2bf44*/ int              SpellAssocFileCRC;
/*0x2bf48*/ RequirementAssociationManager ReqAssocManager;
/*0x2c170*/ HashTable<int, int> SpellGroups;
/*0x2c180*/

	SpellManager(char*);
	virtual ~SpellManager() {}

	EQLIB_OBJECT const EQ_Spell* GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};

// @sizeof(ClientSpellManager) == 0xafeec :: 2013-05-10 (emu) @ 0x51C3F1
constexpr size_t ClientSpellManager_size = 0xafeec;

class [[offsetcomments]] ClientSpellManager : public SpellManager
{
public:
	// virtuals
	EQLIB_OBJECT virtual ~ClientSpellManager();
	EQLIB_OBJECT virtual bool LoadSpells(const char* FileName, const char* AssocFilename, const char* StackingFileName);
	EQLIB_OBJECT virtual bool DoesMeetRequirement(PlayerZoneClient* pPlayer, int SpellAssocID);
	EQLIB_OBJECT virtual EQ_Spell* GetSpellByID(int SpellID);

	EQLIB_OBJECT bool LoadSpellStackingData(const char* StackingFileName);
	EQLIB_OBJECT void PrintFailedRequirementString(int StrToken, int StringID);
	EQLIB_OBJECT int GetSpellStackingGroupID(int SpellID);
	EQLIB_OBJECT int GetSpellStackingGroupRank(int SpellID);
	EQLIB_OBJECT ESpellStackingRules GetSpellStackingGroupRule(int SpellID);

	EQLIB_OBJECT SpellAffectData* GetSpellAffect(const EQ_Spell* pSpell, int slot);
	EQLIB_OBJECT SpellAffectData* GetSpellAffectEmpty(bool);

	// Accessors for EQ spell data
	EQLIB_OBJECT int GetSpellAttrib(EQ_Spell* pSpell, int index) const;
	EQLIB_OBJECT int GetSpellBase(EQ_Spell* pSpell, int index) const;
	EQLIB_OBJECT int GetSpellBase2(EQ_Spell* pSpell, int index) const;
	EQLIB_OBJECT int GetSpellMax(EQ_Spell* pSpell, int index) const;
	EQLIB_OBJECT int GetSpellCalc(EQ_Spell* pSpell, int index) const;

	bool AllSpellsLoaded() const { return Spells[TOTAL_SPELL_COUNT - 1] != nullptr; }

/*0x2c180*/ EQ_Spell*                    Spells[TOTAL_SPELL_COUNT];                       // 0x41960        0x2c180
/*0x580a4*/ EQSpellExtra                 SpellExtraData[TOTAL_SPELL_COUNT];               // 0x16e5e0       0x580a4
/*0xafeec*/
};

inline namespace deprecated {
	using SPELLMGR DEPRECATE("Use ClientSpellManager instead of SPELLMGR") = ClientSpellManager;
	using PSPELLMGR DEPRECATE("Use ClientSpellManager* instead of PSPELLMGR") = ClientSpellManager*;
}

SIZE_CHECK(ClientSpellManager, ClientSpellManager_size);

class [[offsetcomments]] MercenaryAbilityEffectsDefinition
{
public:
/*0x00*/ void*     vfTable;
/*0x04*/ int       ID;
/*0x08*/ int       AbilityID;
/*0x0c*/ int       FromID;
/*0x10*/ int       Base;
/*0x14*/ int       Base2;
/*0x18*/ int       LevelMod;
/*0x1c*/ int       Cap;
/*0x20*/ int       Slot;
/*0x24*/
};

struct [[offsetcomments]] FocusEffectData
{
/*0x00*/ int       Type;
/*0x04*/ int       Base;
/*0x08*/ int       Base2;
/*0x0c*/ int       Slot;
/*0x10*/
};

struct [[offsetcomments]] CachedFocusAbility
{
/*0x00*/ FocusEffectData*   pEffectData;
/*0x04*/ int                Percent;
/*0x08*/
};

class [[offsetcomments]] SpellCache
{
public:
	struct EffectCache
	{
		int SubIndex;
		int TotalPlayerEffects;
		int TotalItemEffects;
		bool bDegenerating;
		int TotalContrib;
	};

	struct AltEffectCache
	{
		int SubIndex;
		int AltTotal;
	};

	struct CachedFocusItem
	{
		ItemClient*    pContents;
		int	           Percent;
		ItemSpellTypes SpellType;
	};

	struct CachedFocusEffect
	{
		PSPELL     pSpell;
		int	       Percent;
		short      AffectIndex;
	};

	struct CachedFocusMercAbility
	{
		MercenaryAbilityEffectsDefinition* pAbilityEffectDef;
		int Percent;
	};

/*0x00*/ HashTable<EffectCache>*                    pCachedEffects;
/*0x04*/ bool                                       bCachedSpellEffects;
/*0x08*/ HashTable<AltEffectCache>*                 pCachedAltAbilityEffects;
/*0x0c*/ bool                                       bCachedAltEffects;
/*0x10*/ HashTable<EffectCache>*                    pCachedLimitedEffects;
/*0x14*/ bool                                       bCachedLimitedEffects;
/*0x18*/ HashTable<CachedFocusItem, int64_t>        CachedFocusItems;
/*0x28*/ HashTable<CachedFocusEffect, int64_t>      CachedFocusEffects;
/*0x38*/ HashTable<CachedFocusAbility, int64_t>     CachedFocusAbilities;
/*0x48*/ HashTable<CachedFocusMercAbility, int64_t> CachedFocusMercAbilities;
/*0x58*/
};

constexpr int NUM_SLOTDATA = 6;

struct [[offsetcomments]] SlotData
{
/*0x00*/ int Slot;
/*0x04*/ int32_t Value;
/*0x08*/
};

constexpr size_t EQ_Affect_size = 0x58;

class [[offsetcomments]] EQ_Affect
{
public:
	EQLIB_OBJECT void Reset();

	// Get/Set individual slot data
	EQLIB_OBJECT int64_t GetAffectData(int slot) const;
	EQLIB_OBJECT void SetAffectData(int slot, int64_t value);

	// Populate all slot data from a specified spell.
	EQLIB_OBJECT void PopulateFromSpell(const EQ_Spell* pSpell);

/*0x00*/ uint8_t   Type;
/*0x01*/ uint8_t   Level;                        // casterlevel
/*0x02*/ uint8_t   ChargesRemaining;             // dont think this is used anymore.
/*0x03*/ uint8_t   Activatable;                  // dont think this is used anymore. We used to think this was DamageShield
/*0x04*/ float     Modifier;                     // Bard song modifier, 1.0 is default BaseDmgMod
/*0x08*/ int       SpellID;                      // -1 or 0 for no spell..
/*0x0c*/ int       Duration;
/*0x10*/ int       CasterID;
/*0x14*/ int       HitCount;
/*0x18*/ float     Y;                            // Referenced by SPA 441 (distance removal)
/*0x1c*/ float     X;
/*0x20*/ float     Z;
/*0x24*/ uint32_t  Flags;
/*0x28*/ SlotData  SlotData[NUM_SLOTDATA];       // used for book keeping of various effects (debuff counter, rune/vie damage remaining)
/*0x58*/

	EQ_Affect()
	{
		memset(&this->SlotData, 0, sizeof(SlotData));
		Flags = 0;
		SpellID = 0;
		Duration = 0;
		HitCount = 0;
		Modifier = 1.0f;
		Y = 0;
		X = 0;
		Z = 0;
		Type = 2;   // 2 indicates a buff type
		Level = 0;
		ChargesRemaining = 0;
		Activatable = 0;
	}

	// Fields that don't yet exist.
	int get_EmptyValue() const { return 0; }
	__declspec(property(get = get_EmptyValue)) int ViralTimer;
	__declspec(property(get = get_EmptyValue)) int InitialDuration;

	EqGuid get_CasterGuid() const {
		EqGuid guid;
		guid.UniqueEntityID = CasterID;
		return guid;
	}
	void put_CasterGuid(const EqGuid& guid) {
		CasterID = guid.UniqueEntityID;
	}
	__declspec(property(get = get_CasterGuid, put = put_CasterGuid)) EqGuid CasterGuid;
};

SIZE_CHECK(EQ_Affect, EQ_Affect_size);

inline namespace deprecated {
	using PSPELLBUFF DEPRECATE("Use EQ_Affect* instead of PSPELLBUFF") = EQ_Affect*;
	using SPELLBUFF = EQ_Affect;
}

class EQSpellStrings
{
public:
	EQLIB_OBJECT const char* GetString(int SpellID, int StrIndex);
};

// Returns true if the given spell Id is a resurrection sickness spell
EQLIB_VAR bool IsResEffectSpell(int spellID);

} // namespace eqlib
