/*
  ==============================================================================
  unscf_vest_sel.hpp

  This file defines "selection sets" that specify which hiddenSelections
  (pouch compartments, chest rigs, leg pouches, etc.) are shown on the vest
  model. Each #define is a comma-separated list of hiddenSelections.

  For instance, RIFLEMAN_BASE_SEL might include "Leg" but not "Breacher"
  or "Grenedier", etc. By combining these sets with macros, we can create
  multiple variations of the same vest model with different pouches visible.

  Each #define = a bunch of string literal selection names. If your vest model
  changes or you want to rename a selection in your .p3d, update these here.
  ==============================================================================
*/
#ifndef UNSCF_VEST_SEL_HPP
#define UNSCF_VEST_SEL_HPP

/* -------------------------------------------------------------------------- */
/* Rifleman Selection Sets                                                    */
/* -------------------------------------------------------------------------- */
#define RIFLEMAN_BASE_SEL             \
  "camo5",                            \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set focusing on leg pouches.
#define RIFLEMAN_LEG_SEL              \
  "camo5",                            \
  "Chest",                            \
  "ChestCorner",                      \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set focusing on heavy pouches.
#define RIFLEMAN_HEAVY_SEL            \
  "camo5",                            \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \

// Rifleman selection set with both heavy and leg pouches.
#define RIFLEMAN_HEAVY_LEG_SEL        \
  "camo5",                            \
  "Chest",                            \
  "ChestCorner",                      \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \

// Rifleman selection set focusing on chest pouches.
#define RIFLEMAN_CHEST_SEL            \
  "camo5",                            \
  "Leg",                              \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set with chest and leg pouches.
#define RIFLEMAN_CHEST_LEG_SEL        \
  "camo5",                            \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set with chest and heavy pouches.
#define RIFLEMAN_CHEST_HEAVY_SEL      \
  "camo5",                            \
  "Leg",                              \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \

// Rifleman selection set with chest, heavy, and leg pouches.
#define RIFLEMAN_CHEST_HEAVY_LEG_SEL  \
  "camo5",                            \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \

// Rifleman selection set with a second chest variation.
#define RIFLEMAN_CHEST2_SEL           \
  "camo5",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set with a second chest and leg pouches.
#define RIFLEMAN_CHEST2_LEG_SEL       \
  "camo5",                            \
  "ChestCorner",                      \
  "Heavy",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Rifleman selection set with a second chest and heavy pouches.
#define RIFLEMAN_CHEST2_HEAVY_SEL     \
  "camo5",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \

// Rifleman selection set with a second chest, heavy, and leg pouches.
#define RIFLEMAN_CHEST2_HEAVY_LEG_SEL \
  "camo5",                            \
  "ChestCorner",                      \
  "light",                            \
  "Breacher",                         \
  "Grenedier",                        \
  "Shotgun",                          \
  "HeavyBreacher"                     \
// ... (and so on for each selection variant)


// Additional sets for chest pouches, partial chest pouches, etc.
// The pattern is the same: each #define is a unique combination
// of hiddenSelection names used by the vest model.


/* -------------------------------------------------------------------------- */
/* Breacher Selection Sets                                                    */
/* -------------------------------------------------------------------------- */
// Similar structure to the Rifleman sets but includes "Breacher" references
#define BREACHER_BASE_SEL             \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set focusing on leg pouches.
#define BREACHER_LEG_SEL              \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set focusing on heavy pouches.
#define BREACHER_HEAVY_SEL            \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \

// Breacher selection set with both heavy and leg pouches.
#define BREACHER_HEAVY_LEG_SEL        \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \

// Breacher selection set focusing on chest pouches.
#define BREACHER_CHEST_SEL            \
  "camo5",                            \
  "Rifleman",                         \
  "Leg",                              \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set with chest and leg pouches.
#define BREACHER_CHEST_LEG_SEL        \
  "camo5",                            \
  "Rifleman",                         \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set with chest and heavy pouches.
#define BREACHER_CHEST_HEAVY_SEL      \
  "camo5",                            \
  "Rifleman",                         \
  "Leg",                              \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \

// Breacher selection set with chest, heavy, and leg pouches.
#define BREACHER_CHEST_HEAVY_LEG_SEL  \
  "camo5",                            \
  "Rifleman",                         \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \

// Breacher selection set with a second chest variation.
#define BREACHER_CHEST2_SEL           \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set with a second chest and leg pouches.
#define BREACHER_CHEST2_LEG_SEL       \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Heavy",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Breacher selection set with a second chest and heavy pouches.
#define BREACHER_CHEST2_HEAVY_SEL     \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \

// Breacher selection set with a second chest, heavy, and leg pouches.
#define BREACHER_CHEST2_HEAVY_LEG_SEL \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "light",                            \
  "Grenedier",                        \
  "HeavyRifle",                       \
// ... (and so on, each set controlling different combinations)

/* -------------------------------------------------------------------------- */
/* Grenadier Selection Sets                                                  */
/* -------------------------------------------------------------------------- */
// Mirrors the same structure for "GRENEDIER" sets.
#define GRENADIER_BASE_SEL            \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set focusing on leg pouches.
#define GRENADIER_LEG_SEL             \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set focusing on heavy pouches.
#define GRENADIER_HEAVY_SEL           \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

// Grenadier selection set with both heavy and leg pouches.
#define GRENADIER_HEAVY_LEG_SEL       \
  "camo5",                            \
  "Rifleman",                         \
  "Chest",                            \
  "ChestCorner",                      \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

// Grenadier selection set focusing on chest pouches.
#define GRENADIER_CHEST_SEL           \
  "camo5",                            \
  "Rifleman",                         \
  "Leg",                              \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set with chest and leg pouches.
#define GRENADIER_CHEST_LEG_SEL       \
  "camo5",                            \
  "Rifleman",                         \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set with chest and heavy pouches.
#define GRENADIER_CHEST_HEAVY_SEL     \
  "camo5",                            \
  "Rifleman",                         \
  "Leg",                              \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

// Grenadier selection set with chest, heavy, and leg pouches.
#define GRENADIER_CHEST_HEAVY_LEG_SEL \
  "camo5",                            \
  "Rifleman",                         \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

// Grenadier selection set with a second chest variation.
#define GRENADIER_CHEST2_SEL          \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Leg",                              \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set with a second chest and leg pouches.
#define GRENADIER_CHEST2_LEG_SEL      \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Heavy",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \
  "HeavyBreacher"                     \

// Grenadier selection set with a second chest and heavy pouches.
#define GRENADIER_CHEST2_HEAVY_SEL    \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "Leg",                              \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

// Grenadier selection set with a second chest, heavy, and leg pouches.
#define GRENADIER_CHEST2_HEAVY_LEG_SEL \
  "camo5",                            \
  "Rifleman",                         \
  "ChestCorner",                      \
  "light",                            \
  "Shotgun",                          \
  "HeavyRifle",                       \

#endif // UNSCF_VEST_SEL_HPP