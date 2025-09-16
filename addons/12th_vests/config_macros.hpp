/*
  ==============================================================================
  config_macros.hpp

  This file contains all macros used in our 12th_vests config. Macros reduce
  duplication and make it easier to manage changes across multiple vests. 

  Notable macros here:
    - P() and Q() to handle path building and string quoting.
    - VEST_MASS: standard ACE mass for these vests.
    - VEST_MAXLOAD: total carrying capacity for the vest container.
    - VEST_HITPOINT_INFO: sets up armor (hit) values for various body parts.
    - UNSCF_VEST_ITEM_INFO and INVIS_VEST_ITEM_INFO: define vest parameters like
      mass, containerClass, and the hitpoint info.
    - UNSCF_VEST_ALL_VARIANTS: expands into multiple definitions for each vest
      selection set (Rifleman, Breacher, Grenadier, etc.) with each
      combination of pouches.
  ==============================================================================
*/
// Basic path macros
#define P(PATH) \x\12thMEU\addons\12th_vests\##PATH
  // P(something) => "\x\12thMEU\addons\12th_vests\something"
#define Q(INPUT) #INPUT
  // Q(INPUT) => "INPUT"
#define GLUE(A,B) A##B
  // GLUE(A,B) => AB (concatenates tokens)

// Standard vest attributes
#define VEST_MASS 80      // The vest’s "mass" for ACE/Arma calculations
#define VEST_MAXLOAD 200  // The vest’s carrying capacity (in “inventory units”)

// Macro for the hitpoint data applied to vests
#define VEST_HITPOINT_INFO       \
class HitpointsProtectionInfo {  \
  class Neck {                   \
    hitpointName="HitNeck";      \
    armor=20;                    \
    passThrough=0.30000001;      \
  };                             \
  class Arms {                   \
    hitpointName="HitArms";      \
    armor=10;                    \
    passThrough=0.60000002;      \
  };                             \
  class Chest {                  \
    hitpointName="HitChest";     \
    armor=20;                    \
    passThrough=0.30000001;      \
  };                             \
  class Diaphragm {              \
    hitpointName="HitDiaphragm"; \
    armor=20;                    \
    passThrough=0.30000001;      \
  };                             \
  class Abdomen {                \
    hitpointName="HitAbdomen";   \
    armor=20;                    \
    passThrough=0.30000001;      \
  };                             \
  class Body {                   \
    hitpointName="HitBody";      \
    passThrough=0.30000001;      \
    armor=20;                    \
  };                             \
  class Legs {                   \
    hitpointName="HitLegs";      \
    armor=10;                    \
    passThrough=0.60000002;      \
  };                             \
};

// Macro for the invisible vest’s item info
#define INVIS_VEST_ITEM_INFO \
class ItemInfo: VestItem { \
  vestType="Rebreather"; \
  uniformModel = "\halo_marine\null.p3d"; \
  containerClass="twelfth_vest_supply"; \
  mass=VEST_MASS; \
  VEST_HITPOINT_INFO \
};

// Macro that resolves the path to a specific texture, e.g., std\misc_co.paa
#define UNSCF_TEXPATH(CAMO,FILE) P(data\unscf_vest\##CAMO\##FILE)

// Macro for standard UNSC Foundries vest item info
#define UNSCF_VEST_ITEM_INFO(SEL_SET,CAMO)                          \
class ItemInfo: VestItem {                                          \
  vestType="Rebreather";                                            \
  uniformModel="\19th_H2A_armor\19th_H2A_marines_vests.p3d";        \
  containerClass="twelfth_vest_supply";                                \
  mass=VEST_MASS;                                                   \
  hiddenSelections[] = { SEL_SET };                                 \
  hiddenSelectionsTextures[] = {Q(UNSCF_TEXPATH(CAMO,misc_co.paa))};\
  VEST_HITPOINT_INFO                                                \
};

/*
  UNSCF_VEST Macro:
    - CNAME: class name for the new vest (must be unique).
    - CAMO: folder name for the textures (e.g. "std" or "winter").
    - SEL_SET: the hiddenSelections the vest uses (defined in unscf_vest_sel.hpp).
    - DISPLAY: text that shows up in Arsenal.
*/
#define UNSCF_VEST(CNAME,CAMO,SEL_SET,DISPLAY)                     \
class CNAME : twelfth_unscf_vest_base {                               \
  scope=2;                                                         \
  scopeArsenal=2;                                                  \
  displayName=DISPLAY;                                             \
  hiddenSelections[]={                                             \
    SEL_SET                                                        \
  };                                                               \
  hiddenSelectionsTextures[]={Q(UNSCF_TEXPATH(CAMO,misc_co.paa))}; \
  UNSCF_VEST_ITEM_INFO(SEL_SET,CAMO)                               \
};

/* Include the thing */
#include "unscf_vest_sel.hpp"

/*
  The big macro that generates every variant (rifleman, breacher, grenadier,
  with different pouches) for a given camo. 
  - BC: A prefix for all vest classes (e.g., twelfth_unscf_vest_std).
  - CAMO: the subfolder for textures (e.g., "std", "winter").
  - BD: a bracketed label appended to the displayName: e.g., [12th][S].

  Each line expands into one fully-defined vest class with a unique set
  of hiddenSelections.
*/
#define UNSCF_VEST_ALL_VARIANTS(BC,CAMO,BD)                                                                                           \
UNSCF_VEST(GLUE(BC,_rf)      ,CAMO,RIFLEMAN_BASE_SEL,              Q(GLUE(BD, Rifleman Vest)))                                        \
UNSCF_VEST(GLUE(BC,_rf_l)    ,CAMO,RIFLEMAN_LEG_SEL,               Q(GLUE(BD, Rifleman Vest (Leg Pouches))))                          \
UNSCF_VEST(GLUE(BC,_rf_h)    ,CAMO,RIFLEMAN_HEAVY_SEL,             Q(GLUE(BD, Rifleman Vest (Heavy))))                                \
UNSCF_VEST(GLUE(BC,_rf_hl)   ,CAMO,RIFLEMAN_HEAVY_LEG_SEL,         Q(GLUE(BD, Rifleman Vest (Heavy & Leg Pouches))))                  \
UNSCF_VEST(GLUE(BC,_rf_c)    ,CAMO,RIFLEMAN_CHEST_SEL,             Q(GLUE(BD, Rifleman Vest (Chest Pouches))))                        \
UNSCF_VEST(GLUE(BC,_rf_cl)   ,CAMO,RIFLEMAN_CHEST_LEG_SEL,         Q(GLUE(BD, Rifleman Vest (Chest & Leg Pouches))))                  \
UNSCF_VEST(GLUE(BC,_rf_ch)   ,CAMO,RIFLEMAN_CHEST_HEAVY_SEL,       Q(GLUE(BD, Rifleman Vest (Heavy & Chest Pouches))))                \
UNSCF_VEST(GLUE(BC,_rf_chl)  ,CAMO,RIFLEMAN_CHEST_HEAVY_LEG_SEL,   Q(GLUE(BD, Rifleman Vest (Heavy & Chest & Leg Pouches))))          \
UNSCF_VEST(GLUE(BC,_rf_c2)   ,CAMO,RIFLEMAN_CHEST2_SEL,            Q(GLUE(BD, Rifleman Vest (Partial Chest Pouches))))                \
UNSCF_VEST(GLUE(BC,_rf_c2l)  ,CAMO,RIFLEMAN_CHEST2_LEG_SEL,        Q(GLUE(BD, Rifleman Vest (Partial Chest & Leg Pouches))))          \
UNSCF_VEST(GLUE(BC,_rf_c2h)  ,CAMO,RIFLEMAN_CHEST2_HEAVY_SEL,      Q(GLUE(BD, Rifleman Vest (Heavy & Partial Chest Pouches))))        \
UNSCF_VEST(GLUE(BC,_rf_c2hl) ,CAMO,RIFLEMAN_CHEST2_HEAVY_LEG_SEL,  Q(GLUE(BD, Rifleman Vest (Heavy & Partial Chest & Leg Pouches))))  \
UNSCF_VEST(GLUE(BC,_br)      ,CAMO,BREACHER_BASE_SEL,              Q(GLUE(BD, Breacher Vest)))                                        \
UNSCF_VEST(GLUE(BC,_br_l)    ,CAMO,BREACHER_LEG_SEL,               Q(GLUE(BD, Breacher Vest (Leg Pouches))))                          \
UNSCF_VEST(GLUE(BC,_br_h)    ,CAMO,BREACHER_HEAVY_SEL,             Q(GLUE(BD, Breacher Vest (Heavy))))                                \
UNSCF_VEST(GLUE(BC,_br_hl)   ,CAMO,BREACHER_HEAVY_LEG_SEL,         Q(GLUE(BD, Breacher Vest (Heavy & Leg Pouches))))                  \
UNSCF_VEST(GLUE(BC,_br_c)    ,CAMO,BREACHER_CHEST_SEL,             Q(GLUE(BD, Breacher Vest (Chest Pouches))))                        \
UNSCF_VEST(GLUE(BC,_br_cl)   ,CAMO,BREACHER_CHEST_LEG_SEL,         Q(GLUE(BD, Breacher Vest (Chest & Leg Pouches))))                  \
UNSCF_VEST(GLUE(BC,_br_ch)   ,CAMO,BREACHER_CHEST_HEAVY_SEL,       Q(GLUE(BD, Breacher Vest (Heavy & Chest Pouches))))                \
UNSCF_VEST(GLUE(BC,_br_chl)  ,CAMO,BREACHER_CHEST_HEAVY_LEG_SEL,   Q(GLUE(BD, Breacher Vest (Heavy & Chest & Leg Pouches))))          \
UNSCF_VEST(GLUE(BC,_br_c2)   ,CAMO,BREACHER_CHEST2_SEL,            Q(GLUE(BD, Breacher Vest (Partial Chest Pouches))))                \
UNSCF_VEST(GLUE(BC,_br_c2l)  ,CAMO,BREACHER_CHEST2_LEG_SEL,        Q(GLUE(BD, Breacher Vest (Partial Chest & Leg Pouches))))          \
UNSCF_VEST(GLUE(BC,_br_c2h)  ,CAMO,BREACHER_CHEST2_HEAVY_SEL,      Q(GLUE(BD, Breacher Vest (Heavy & Partial Chest Pouches))))        \
UNSCF_VEST(GLUE(BC,_br_c2hl) ,CAMO,BREACHER_CHEST2_HEAVY_LEG_SEL,  Q(GLUE(BD, Breacher Vest (Heavy & Partial Chest & Leg Pouches))))  \
UNSCF_VEST(GLUE(BC,_gr)      ,CAMO,GRENADIER_BASE_SEL,             Q(GLUE(BD, Grenadier Vest)))                                       \
UNSCF_VEST(GLUE(BC,_gr_l)    ,CAMO,GRENADIER_LEG_SEL,              Q(GLUE(BD, Grenadier Vest (Leg Pouches))))                         \
UNSCF_VEST(GLUE(BC,_gr_h)    ,CAMO,GRENADIER_HEAVY_SEL,            Q(GLUE(BD, Grenadier Vest (Heavy))))                               \
UNSCF_VEST(GLUE(BC,_gr_hl)   ,CAMO,GRENADIER_HEAVY_LEG_SEL,        Q(GLUE(BD, Grenadier Vest (Heavy & Leg Pouches))))                 \
UNSCF_VEST(GLUE(BC,_gr_c)    ,CAMO,GRENADIER_CHEST_SEL,            Q(GLUE(BD, Grenadier Vest (Chest Pouches))))                       \
UNSCF_VEST(GLUE(BC,_gr_cl)   ,CAMO,GRENADIER_CHEST_LEG_SEL,        Q(GLUE(BD, Grenadier Vest (Chest & Leg Pouches))))                 \
UNSCF_VEST(GLUE(BC,_gr_ch)   ,CAMO,GRENADIER_CHEST_HEAVY_SEL,      Q(GLUE(BD, Grenadier Vest (Heavy & Chest Pouches))))               \
UNSCF_VEST(GLUE(BC,_gr_chl)  ,CAMO,GRENADIER_CHEST_HEAVY_LEG_SEL,  Q(GLUE(BD, Grenadier Vest (Heavy & Chest & Leg Pouches))))         \
UNSCF_VEST(GLUE(BC,_gr_c2)   ,CAMO,GRENADIER_CHEST2_SEL,           Q(GLUE(BD, Grenadier Vest (Partial Chest Pouches))))               \
UNSCF_VEST(GLUE(BC,_gr_c2l)  ,CAMO,GRENADIER_CHEST2_LEG_SEL,       Q(GLUE(BD, Grenadier Vest (Partial Chest & Leg Pouches))))         \
UNSCF_VEST(GLUE(BC,_gr_c2h)  ,CAMO,GRENADIER_CHEST2_HEAVY_SEL,     Q(GLUE(BD, Grenadier Vest (Heavy & Partial Chest Pouches))))       \
UNSCF_VEST(GLUE(BC,_gr_c2hl) ,CAMO,GRENADIER_CHEST2_HEAVY_LEG_SEL, Q(GLUE(BD, Grenadier Vest (Heavy & Partial Chest & Leg Pouches)))) \
