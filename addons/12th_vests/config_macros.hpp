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

#define QP(PATH) #P(PATH)
#define Q(INPUT) #INPUT
  // Q(INPUT) => "INPUT"
#define GLUE(A,B) A##B
  // GLUE(A,B) => AB (concatenates tokens)


//Common texture paths
#define HELM_DEC_PATH "tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa"

#define VEST_PATH_01(CAMO)\
  QP(data\vests\##CAMO\vest_01_co.paa) 

#define VEST_PATH_02(CAMO)\
  QP(data\vests\##CAMO\vest_02_co.paa) 

/*
#define GUNGNIR_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa) 

#define VEST_PATH_02(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)

#define BASESEC_PATH(CAMO,FILE) #P(data\vest\##CAMO##\##FILE##.paa)
*/

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

/* New vest stuff */



#define NEW_VEST_SETUP              \
	NEW_VEST(BaseSec_1)               \
	NEW_VEST(BaseSec_2)               \
	NEW_VEST(BaseSec_3)               \
	NEW_VEST(GungnirS_1)              \
	NEW_VEST(GungnirS_2)              \
	NEW_VEST(GungnirS_3)              \
	NEW_VEST(GungnirL_1)              \
	NEW_VEST(GungnirL_2)              \
	NEW_VEST(GungnirL_3)              \
	NEW_VEST(Light)

#define ALL_VESTS(CAMO)                                     \
  MEU_VEST_LIGHT(CAMO,1pl,na,"[12th][1PL][Inf] Light Armor")            \
  MEU_VEST_LIGHT(CAMO,1pl,med,"[12th][1PL][Inf][Med] Light Armor")      \
  MEU_VEST_LIGHT(CAMO,2pl,na,"[12th][2PL][Inf] Light Armor")            \
  MEU_VEST_LIGHT(CAMO,2pl,med,"[12th][2PL][Inf][Med] Light Armor")      \
  MEU_VEST_LIGHT(CAMO,hq,na,"[12th][HQ][Inf] Light Armor")              \
  MEU_VEST_LIGHT(CAMO,hq,med,"[12th][HQ][Inf][Med] Light Armor")        \
  MEU_VEST_LIGHT(CAMO,lpl,na,"[12th][LOGI][Inf] Light Armor")           \
  MEU_VEST_LIGHT(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Light Armor") \
  MEU_VEST_BS1(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS1(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS1(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS1(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS1(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS1(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS1(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS1(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS2(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS2(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS2(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS2(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS2(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS2(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")     \
  MEU_VEST_BS3(CAMO,1pl,na,"[12th][1PL][Inf] Base Security Armor")            \
  MEU_VEST_BS3(CAMO,1pl,med,"[12th][1PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS3(CAMO,2pl,na,"[12th][2PL][Inf] Base Security Armor")            \
  MEU_VEST_BS3(CAMO,2pl,med,"[12th][2PL][Inf][Med] Base Security Armor")      \
  MEU_VEST_BS3(CAMO,hq,na,"[12th][HQ][Inf] Base Security Armor")              \
  MEU_VEST_BS3(CAMO,hq,med,"[12th][HQ][Inf][Med] Base Security Armor")        \
  MEU_VEST_BS3(CAMO,lpl,na,"[12th][LOGI][Inf] Base Security Armor")           \
  MEU_VEST_BS3(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Base Security Armor")     \
  MEU_VEST_GUNGNIR1(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR1(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR1(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR1(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR1(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR1(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR1(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR1(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR2(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR2(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR2(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR2(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR2(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR2(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR2(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR2(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR3(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR3(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR3(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Armor")            \
  MEU_VEST_GUNGNIR3(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Armor")      \
  MEU_VEST_GUNGNIR3(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Armor")              \
  MEU_VEST_GUNGNIR3(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Armor")        \
  MEU_VEST_GUNGNIR3(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Armor")           \
  MEU_VEST_GUNGNIR3(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Armor")     \
  MEU_VEST_GUNGNIR1_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR1_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR1_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR1_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR1_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR1_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR1_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR1_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \
  MEU_VEST_GUNGNIR2_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR2_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR2_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR2_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR2_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR2_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR2_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR2_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \
  MEU_VEST_GUNGNIR3_L(CAMO,1pl,na,"[12th][1PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR3_L(CAMO,1pl,med,"[12th][1PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR3_L(CAMO,2pl,na,"[12th][2PL][Inf] Gungnir Large Armor")            \
  MEU_VEST_GUNGNIR3_L(CAMO,2pl,med,"[12th][2PL][Inf][Med] Gungnir Large Armor")      \
  MEU_VEST_GUNGNIR3_L(CAMO,hq,na,"[12th][HQ][Inf] Gungnir Large Armor")              \
  MEU_VEST_GUNGNIR3_L(CAMO,hq,med,"[12th][HQ][Inf][Med] Gungnir Large Armor")        \
  MEU_VEST_GUNGNIR3_L(CAMO,lpl,na,"[12th][LOGI][Inf] Gungnir Large Armor")           \
  MEU_VEST_GUNGNIR3_L(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Gungnir Large Armor")     \



#define NEW_VEST(ARMOUR) 						                                                  \
  class TCP_V_M43A_##ARMOUR##_Base: ItemCore {                                       \
    class ItemInfo;								                                                    \
  };

#define MEU_VEST_LIGHT(CAMO,PLATOON,ROLE,DISPLAYNAME)                                       \
  class twelfth_M43A_Light_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_Light_Base      \
  {                                                                                   \
    scope = 2;                                                                        \
    scopeArsenal = 2;                                                                 \
    author = "Sammy";                                                                 \
    displayName = DISPLAYNAME;                                                        \
    ACE_GForceCoef = 0.4;                                                             \
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_Light.p3d";             \
    hiddenSelections[] = {"camo","decals"};                                           \
    hiddenSelectionsTextures[] =                                                    \
    {                                                                               \
      VEST_PATH_01(CAMO),                               \
      HELM_DEC_PATH                                                                 \
    };  \
    class ItemInfo: VestItem                                                          \
    {                                                                                 \
      containerClass = "Supply100";                                                   \
      mass = 80;                                                                      \
      VEST_HITPOINT_INFO                                                              \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_Light.p3d";    \
      hiddenSelections[] = {"camo","decals"};                                           \
      hiddenSelectionsTextures[] =                                                    \
      {                                                                               \
        VEST_PATH_01(CAMO),                               \
        HELM_DEC_PATH                                                                 \
      };                                                                              \
    };                                                                                \
  };


#define MEU_VEST_BS1(CAMO,PLATOON,ROLE,DISPLAYNAME)                                         \
	class twelfth_M43A_BaseSec1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_1_Base {     \
    scope = 2;                                                                              \
    scopeArsenal = 2;                                                                       \
    author = "Sammy";                                                                       \
    displayName = DISPLAYNAME;                                                              \
    ACE_GForceCoef = 0.4;                                                                   \
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";               \
		hiddenSelections[] = {"camo","camo1","decals"};                                         \
    hiddenSelectionsTextures[] =                                                            \
    {                                                                                       \
      VEST_PATH_01(CAMO),                            \
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),                      \
      HELM_DEC_PATH                                                                         \
    };                                                                                      \
    class ItemInfo: VestItem                                                                \
    {                                                                                       \
      containerClass = "Supply100";                                                         \
      mass = 80;                                                                            \
      VEST_HITPOINT_INFO                                                                    \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_1.p3d";      \
      hiddenSelections[] = {"camo","camo1","decals"};                                       \
		  hiddenSelectionsTextures[] = {                                                        \
        VEST_PATH_01(CAMO),                          \
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),                    \
        HELM_DEC_PATH                                                                       \
      };                                                                                    \
    };                                                                                      \
  };


#define MEU_VEST_BS2(CAMO,PLATOON,ROLE,DISPLAYNAME)                                       \
  class twelfth_M43A_BaseSec2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH};\
      };\
  };


#define MEU_VEST_BS3(CAMO,PLATOON,ROLE,DISPLAYNAME)    \
  class twelfth_M43A_BaseSec3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_BaseSec_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BaseSec_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_BaseSecurity_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR1(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
		hiddenSelections[] = {"camo","camo1","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_1.p3d";\
      hiddenSelections[] = {"camo","camo1","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR2(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_BGungnirS_2.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
		  hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR3(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirS_3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirS_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = { \
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirS_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
      hiddenSelectionsTextures[] = { \
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR1_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
   class twelfth_M43A_GungnirL_1_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_1_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
		hiddenSelections[] = {"camo","camo1","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_1.p3d";\
      hiddenSelections[] = {"camo","camo1","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR2_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirL_2_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_2_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
    hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_2.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };


#define MEU_VEST_GUNGNIR3_L(CAMO,PLATOON,ROLE,DISPLAYNAME) \
  class twelfth_M43A_GungnirL_3_##CAMO##_##PLATOON##_##ROLE##: TCP_V_M43A_GungnirL_3_Base {\
    scope = 2;\
    scopeArsenal = 2;\
    author = "Sammy";\
    displayName = DISPLAYNAME;\
    ACE_GForceCoef = 0.4;\
    model = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
		hiddenSelections[] = {"camo","camo1","camo2","decals"};\
    hiddenSelectionsTextures[] = {\
      VEST_PATH_01(CAMO),\
      QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
      VEST_PATH_02(CAMO),\
      HELM_DEC_PATH\
    };\
    class ItemInfo: VestItem\
    {\
      containerClass = "Supply100";\
      mass = 80;\
      VEST_HITPOINT_INFO \
			uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\M43A_GungnirL_3.p3d";\
      hiddenSelections[] = {"camo","camo1","camo2","decals"};\
      hiddenSelectionsTextures[] = {\
        VEST_PATH_01(CAMO),\
        QP(data\vests\##CAMO##\##PLATOON##_##ROLE##_Gungnir_co.paa),\
        VEST_PATH_02(CAMO),\
        HELM_DEC_PATH\
      };\
    };\
  };

