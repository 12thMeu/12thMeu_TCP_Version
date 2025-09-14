/*
  ==============================================================================
  config_macros.hpp

  This file contains a comprehensive set of macros for creating uniforms, helmets,
  caps, boonie hats, etc. It leverages hiddenSelectionsTextures to define how 
  multiple camos and roles (e.g., medic, PL, etc.) are generated en masse.

  Key Macros:
    - ALL_UNI_VEH / ALL_UNI_WEP / ALL_UNI_GI to produce all platoon+role combos.
    - ALL_HELM / ALL_HELM_GI to produce multiple variations of a single helmet 
      in standard or NV variants.
    - BOONIE_WEP / PATROLCAP_WEP for boonie/patrol caps.
    - PILOT_HELM for custom pilot helmet references.

  Remember to look at the expansions near the bottom of config.cpp for usage:
    ALL_UNI_WEP(std), ALL_UNI_WEP(forest), etc.
  ==============================================================================
*/
#define P(PATH) \x\12thMEU\addons\12th_armor\##PATH
#define QP(PATH) #P(PATH)
#define GLUE(A,B) A##B

#define HELM_TEX_PATH(SUFFIX) P(helmets\infantry\Helm_co_##SUFFIX.paa)

#define INF_UNI_DISP(CAMO,PLATOON,ROLE) [12th][INF][CAMO][PLATOON][ROLE] Armor

// stands for 'extended path', used to denote background image
// paths for extended arsenal icon backgrounds
#define XTP(SFX) QP(xtd_icons\##SFX.paa)

/* Stands for uniform gear info. */
#define UNIFORM_GI(CAMO,PLATOON,ROLE)                     \
class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_wep {     \
  model="twelfth_base_uniforms";                          \
  camo=#CAMO;                                             \
  element=#PLATOON;                                       \
  role=#ROLE;                                             \
  visor="No";                                             \
};                                                        \





/*
  Defines a standard-visor helmet.
  Input:
  - SUFFIX:
    defines the texture name suffix in the `helmets/infantry` folder.
    I.e sets the texture path in this format:
    `twelfth_armor/helmets/infantry/Helm_co_[SUFFIX].paa`
  - DISPLAY:
    the string that gets displayed in the ACE arsenal.
    Provide in quotes.
*/
#define HELM_SV(SUFFIX,DISPLAY)                 \
class twelfth_helm_##SUFFIX##: twelfth_helm_base {    \
  scope=2;                                      \
  author="Weber";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  hiddenSelections[] = {"camo","decals"};              \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH(SUFFIX)                      \
  };                                            \
    hiddenSelections[] = {"camo","decals"};             \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH(SUFFIX)                    \
    };                                          \
  };                                            \
};

// this is shoved into here so that it need not be repeated 20x for different variants

#define ALL_HELM(CAMO)                                                  \
  HELM_SV(##CAMO##,         "[12th][Inf] Helmet")                       \


/* Stands for helm, standard visor, gear info. */
#define HELM_SV_GI(CSFX,CAMO,EL,ROLE) \
class twelfth_helm_##CSFX## {            \
  model="twelfth_base_helms";            \
  camo=#CAMO;                         \
  element=#EL;                        \
  role=#ROLE;                         \
};

#define ALL_HELM_GI(CAMO)       \
    HELM_SV_GI(##CAMO##,##CAMO##,na,na)       \


/*
For those of you peeking around, sorry, couldn't
have made this macro work cleanly without carrying
a local copy of the base textures from UNSCF around here.
*/
