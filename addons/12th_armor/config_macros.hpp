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
#define QOUTE(s) #s
#define PILOT_H_TEX(CAMOTYPE,FILENAME) P(helmets\pilot\##CAMOTYPE\##FILENAME)

#define UNIFORM_WEP_CLASSNAME(CAMO,PLATOON,ROLE) twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_veh
#define HELM_DEC_PATH tcp\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\White\vest_M43_DecalSheet_CA.paa
#define UNIFORM_OLD_VEH_TEXPATH(SUFFIX) P(uniforms\armor_old\Uniform_co_##SUFFIX.paa)
#define UNIFORM_OLD_WEP_CLASSPATH(SUFFIX) twelfth_uni_##SUFFIX##_veh



#define TWELFTH_WEP_NORMAL(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_##CAMO##
#define TWELFTH_VEH_NORMAL(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_##CAMO##
//Bloused
#define TWELFTH_WEP_BLOUSED(CAMO,SHIRT,SLEEVE)  twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO##
#define TWELFTH_VEH_BLOUSED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO##
//Gloves
#define TWELFTH_WEP_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO##
#define TWELFTH_VEH_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO##
//Bloused_Gloves
#define TWELFTH_WEP_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO##
#define TWELFTH_VEH_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO##
//Unzipped
#define TWELFTH_WEP_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO##
#define TWELFTH_VEH_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO##
//Bloused_Unzipped
#define TWELFTH_WEP_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO##
#define TWELFTH_VEH_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO##
//Gloves_Unzipped
#define TWELFTH_WEP_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO##
#define TWELFTH_VEH_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO##
//GLOVES_BLOUSED_UNZIPPED
#define TWELFTH_WEP_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO##
#define TWELFTH_VEH_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO##

#define HELM_TEX_PATH(SUFFIX) P(helmets\infantry\Helm_co_##SUFFIX.paa)
#define HELM_TEX_PATH_CH43A(SUFFIX) P(helmets\infantry\CH43A\Helm_co_##SUFFIX.paa)
#define CAP_TEX_PATH(SUFFIX) P(helmets\cap_b\cap_co_##SUFFIX.paa)

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
};                                                        


#define VEST_GI(TYPE,CAMO,PLATOON,ROLE)                     \
class twelfth_M43A_##TYPE##_##CAMO##_##PLATOON##_##ROLE## {     \
  model="twelfth_base_vests";                          \
  type=#TYPE;                                            \
  camo=#CAMO;                                             \
  element=#PLATOON;                                       \
  role=#ROLE;                                             \
};          


//TCP CLASS DEFINITONS WEP
#define TCP_WEP_CLASS_NORMAL(SHIRT,SLEEVE)                          \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Base;

#define TCP_WEP_CLASS_BLOUSED(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Base;                      

#define TCP_WEP_CLASS_GLOVES(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Base;                                 

#define TCP_WEP_CLASS_BLOUSED_GLOVES(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Base;                 

#define TCP_WEP_CLASS_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Unzipped_Base;                             

#define TCP_WEP_CLASS_BLOUSED_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Unzipped_Base;

#define TCP_WEP_CLASS_GLOVES_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Unzipped_Base;                                    

#define TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_Base;

//TCP CLASS DEFINITONS VEH
#define TCP_VEH_CLASS_NORMAL(SHIRT,SLEEVE)                          \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Base;

#define TCP_VEH_CLASS_BLOUSED(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Base;                      

#define TCP_VEH_CLASS_GLOVES(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Base;                                 

#define TCP_VEH_CLASS_BLOUSED_GLOVES(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Base;                 

#define TCP_VEH_CLASS_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Unzipped_Base;                             

#define TCP_VEH_CLASS_BLOUSED_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Unzipped_Base;

#define TCP_VEH_CLASS_GLOVES_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Unzipped_Base;                                    

#define TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(SHIRT,SLEEVE)           \
  class TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_Base;   

//Twelfth VEH class setup
#define VEH_CLASS_NORMAL(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_NORMAL(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_NORMAL(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Base{\
    scope=2;\
    displayName="[12th] Normal";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_NORMAL(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };
//Bloused
#define VEH_CLASS_BLOUSED(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_BLOUSED(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_BLOUSED(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Base{\
    scope=2;\
    displayName="[12th] Bloused";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_BLOUSED(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };
//Gloves
#define VEH_CLASS_GLOVES(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_GLOVES(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_GLOVES(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Base{\
    scope=2;\
    displayName="[12th] Gloves";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_GLOVES(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };

//Bloused Gloves
#define VEH_CLASS_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Base{\
    scope=2;\
    displayName="[12th] Bloused Gloves";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };

//Unzipped
#define VEH_CLASS_UNZIPPED(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Unzipped_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_UNZIPPED(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_UNZIPPED(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Unzipped_Base{\
    scope=2;\
    displayName="[12th] Unzipped";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_UNZIPPED(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };
//BLOUSED UNZIPPED
#define VEH_CLASS_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Unzipped_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Bloused_Unzipped_Base{\
    scope=2;\
    displayName="[12th] Bloused Unzipped";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };

//GLOVES_UNZIPPED
#define VEH_CLASS_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Unzipped_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Unzipped_Base{\
    scope=2;\
    displayName="[12th] Gloves Unzipped";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };

//GLOVES_BLOUSED_UNZIPPED
#define VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO## : TCP_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_Base {\
      author="Sammy";\
      scope= 1;\
      scopeArsenal= 1;\
      scopeCurator = 1;\
      hiddenSelectionsTextures[] = {\
        QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Pants_CO.paa),\
        QP(uniforms\uniform\##CAMO##\CBUU_Gloves_CO.paa)\
        };\
      uniformClass = QOUTE(TWELFTH_WEP_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE));\
  };

#define WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE) \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO## : TCP_U_B_CBUU_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_Base{\
    scope=2;\
    displayName="[12th] Gloves Bloused Unzipped";\
    ACE_GForceCoef=0.4;\
    class ItemInfo : ItemInfo {\
      uniformClass = QOUTE(TWELFTH_VEH_GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE));\
      containerClass="Supply100"; \
      mass=1;\
      uniformType = "Neopren";\
      allowedSlots[]={"701","801","901"};\
      armor=20;\
    };\
    hiddenSelectionsTextures[] = {\
      QP(uniforms\uniform\##CAMO##\CBUU_##SHIRT##_CO.paa)\
    };\
  };





/* New uniform gear info */
#define NORMAL(CAMO,SHIRT,SLEEVE)                          \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_##CAMO## {       \
    model="twelfth_new_uniforms";                          \
    camo=#CAMO;                                            \
    sleeve=#SLEEVE;                                        \
    glove="no";                                            \
    shirt=#SHIRT;                                          \
    blouse="noblouse";                                     \
    zip="zipped";                                          \
  };

#define BLOUSED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped";                                         \
  };                      

#define GLOVES(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="zipped";                                         \
  };                                 

#define BLOUSED_GLOVES(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="zipped";                                         \
  };                 

#define UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="unzipped";                                         \
  };                             

#define BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Bloused_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="no";                     \
    shirt=#SHIRT;                    \
    blouse="blouse";                \
    zip="unzipped";                                         \
  };                           

#define GLOVES_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                             \
    sleeve=#SLEEVE;                     \
    glove="yes";                     \
    shirt=#SHIRT;                    \
    blouse="noblouse";                \
    zip="unzipped";                                         \
  };                                    


#define GLOVES_BLOUSED_UNZIPPED(CAMO,SHIRT,SLEEVE)           \
  class twelfth_U_B_##SHIRT##_##SLEEVE##_Gloves_Bloused_Unzipped_##CAMO## {   \
    model="twelfth_new_uniforms";                           \
    camo=#CAMO;                                              \
    sleeve=#SLEEVE;                                         \
    glove="yes";                                             \
    shirt=#SHIRT;                                            \
    blouse="blouse";                                        \
    zip="unzipped";                                         \
  };                                    



// LATER ME NOTE
// REWRITE THIS TO PULL ARMOR TEXTURES FROM ONE FOLDER PER TYPE OF ARMOR (EX STD VS DRK)
// SINCE ARMOR NOW MATCHES PLT COLORS ANYWAYS, NO NEED FOR DIFFERENTIATION BETWEEN ARM/LEGS/CHEST
#define UNIFORM_VEH(CAMO,PLATOON,ROLE,ARM,DISPLAYNAME)                          \
  class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_veh: twelfth_uni_ng_base_veh{   \
    author="Waylen";                                                              \
    picture="";                                                                   \
    scope=1;                                                                      \
    scopeArsenal=2;                                                               \
    displayName=DISPLAYNAME;                                                      \
    hiddenSelectionsTextures[] =                                                  \
    {                                                                             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_chest_co.paa),                   \
      QP(uniforms\armor\arms\##ARM\##PLATOON##_##ROLE##_arms_co.paa),             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_legs_co.paa),                    \
      QP(uniforms\armor\bases\##CAMO\bdu_co.paa),                                 \
      QP(uniforms\armor\bases\##CAMO\misc_co.paa)                                 \
    };                                                                            \
  };                                                                              \

#define TSHIRT_UNIFORM_VEH(CAMO,PLATOON,ROLE,ARM,DISPLAYNAME)                          \
  class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_veh: twelfth_uni_ng_base_veh{   \
    author="Waylen";                                                              \
    picture="";                                                                   \
    scope=1;                                                                      \
    scopeArsenal=2;                                                               \
    displayName=DISPLAYNAME;                                                      \
    hiddenSelectionsTextures[] =                                                  \
    {                                                                             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_chest_co.paa),                   \
      QP(uniforms\armor\arms\##ARM\##PLATOON##_##ROLE##_arms_co.paa),             \
      QP(uniforms\armor\bases\##CAMO\##PLATOON##_legs_co.paa),                    \
      QP(uniforms\armor\bases\##CAMO\bdu_co.paa),                                 \
      QP(uniforms\armor\bases\##CAMO\misc_co.paa)                                 \
    };                                                                            \
  };             


/* 12th Uniform class definition */



#define UNIFORM_WEP(CAMO,PLATOON,ROLE,DISPLAYNAME)                              \
  class twelfth_uni_##CAMO##_##PLATOON##_##ROLE##_wep : twelfth_uni_ng_base_wep { \
    author="Waylen";                                                              \
    picture="";                                                                   \
    scope=1;                                                                      \
    scopeArsenal=2;                                                               \
    displayName=DISPLAYNAME;                                                      \
    ACE_GForceCoef=0.4;                                                           \
    class ItemInfo: UniformItem {                                                 \
      uniformModel="-";                                                           \
      uniformType="Neopren";                                                      \
      uniformClass = #UNIFORM_WEP_CLASSNAME(CAMO,PLATOON,ROLE);                   \
      containerClass="Supply100";                                                 \
      mass=1;                                                                     \
      allowedSlots[]={"701","801","901"};                                         \
      armor=20;                                                                   \
    };                                                                            \
  };                                                                              

#define ALL_UNI_WEP(CAMO)                                  \
  UNIFORM_WEP(CAMO,na,na,"[12th][N/A][Inf] Armor")          \
  UNIFORM_WEP(CAMO,na,med,"[12th][N/A][Inf][Med] Armor")     \
  UNIFORM_WEP(CAMO,1pl,na,"[12th][1PL][Inf] Armor")         \
  UNIFORM_WEP(CAMO,1pl,med,"[12th][1PL][Inf][Med] Armor")    \
  UNIFORM_WEP(CAMO,2pl,na,"[12th][2PL][Inf] Armor")           \
  UNIFORM_WEP(CAMO,2pl,med,"[12th][2PL][Inf][Med] Armor")     \
  UNIFORM_WEP(CAMO,hq,na,"[12th][HQ][Inf] Armor")             \
  UNIFORM_WEP(CAMO,hq,med,"[12th][HQ][Inf][Med] Armor")       \
  UNIFORM_WEP(CAMO,lpl,na,"[12th][LOGI][Inf] Armor")          \
  UNIFORM_WEP(CAMO,lpl,med,"[12th][LOGI][Inf][Med] Armor")    \

#define ALL_UNI_VEH(CAMO,ARM)                                  \
  UNIFORM_VEH(CAMO,na,na,ARM,"[12th][N/A][Inf] Armor")          \
  UNIFORM_VEH(CAMO,na,med,ARM,"[12th][N/A][Inf][Med] Armor")     \
  UNIFORM_VEH(CAMO,1pl,na,ARM,"[12th][1PL][Inf] Armor")         \
  UNIFORM_VEH(CAMO,1pl,med,ARM,"[12th][1PL][Inf][Med] Armor")    \
  UNIFORM_VEH(CAMO,2pl,na,ARM,"[12th][2PL][Inf] Armor")         \
  UNIFORM_VEH(CAMO,2pl,med,ARM,"[12th][2PL][Inf][Med] Armor")    \
  UNIFORM_VEH(CAMO,hq,na,ARM,"[12th][HQ][Inf] Armor")           \
  UNIFORM_VEH(CAMO,hq,med,ARM,"[12th][HQ][Inf][Med] Armor")      \
  UNIFORM_VEH(CAMO,lpl,na,ARM,"[12th][LOGI][Inf] Armor")         \
  UNIFORM_VEH(CAMO,lpl,med,ARM,"[12th][LOGI][Inf][Med] Armor")   \

#define ALL_UNI_GI(CAMO)      \
  UNIFORM_GI(CAMO,na,na)        \
  UNIFORM_GI(CAMO,na,med)       \
  UNIFORM_GI(CAMO,1pl,na)       \
  UNIFORM_GI(CAMO,1pl,med)      \
  UNIFORM_GI(CAMO,2pl,na)       \
  UNIFORM_GI(CAMO,2pl,med)      \
  UNIFORM_GI(CAMO,hq,na)        \
  UNIFORM_GI(CAMO,hq,med)       \
  UNIFORM_GI(CAMO,lpl,na)       \
  UNIFORM_GI(CAMO,lpl,med)      \
  VEST_GI(Light,CAMO,na,na)        \
  VEST_GI(Light,CAMO,na,med)       \
  VEST_GI(Light,CAMO,1pl,na)       \
  VEST_GI(Light,CAMO,1pl,med)      \
  VEST_GI(Light,CAMO,2pl,na)       \
  VEST_GI(Light,CAMO,2pl,med)      \
  VEST_GI(Light,CAMO,hq,na)        \
  VEST_GI(Light,CAMO,hq,med)       \
  VEST_GI(Light,CAMO,lpl,na)       \
  VEST_GI(Light,CAMO,lpl,med)      \
  VEST_GI(BaseSec1,CAMO,na,na)        \
  VEST_GI(BaseSec1,CAMO,na,med)       \
  VEST_GI(BaseSec1,CAMO,1pl,na)       \
  VEST_GI(BaseSec1,CAMO,1pl,med)      \
  VEST_GI(BaseSec1,CAMO,2pl,na)       \
  VEST_GI(BaseSec1,CAMO,2pl,med)      \
  VEST_GI(BaseSec1,CAMO,hq,na)        \
  VEST_GI(BaseSec1,CAMO,hq,med)       \
  VEST_GI(BaseSec1,CAMO,lpl,na)       \
  VEST_GI(BaseSec1,CAMO,lpl,med)      \
  VEST_GI(BaseSec2,CAMO,na,na)        \
  VEST_GI(BaseSec2,CAMO,na,med)       \
  VEST_GI(BaseSec2,CAMO,1pl,na)       \
  VEST_GI(BaseSec2,CAMO,1pl,med)      \
  VEST_GI(BaseSec2,CAMO,2pl,na)       \
  VEST_GI(BaseSec2,CAMO,2pl,med)      \
  VEST_GI(BaseSec2,CAMO,hq,na)        \
  VEST_GI(BaseSec2,CAMO,hq,med)       \
  VEST_GI(BaseSec2,CAMO,lpl,na)       \
  VEST_GI(BaseSec2,CAMO,lpl,med)      \
  VEST_GI(BaseSec3,CAMO,na,na)        \
  VEST_GI(BaseSec3,CAMO,na,med)       \
  VEST_GI(BaseSec3,CAMO,1pl,na)       \
  VEST_GI(BaseSec3,CAMO,1pl,med)      \
  VEST_GI(BaseSec3,CAMO,2pl,na)       \
  VEST_GI(BaseSec3,CAMO,2pl,med)      \
  VEST_GI(BaseSec3,CAMO,hq,na)        \
  VEST_GI(BaseSec3,CAMO,hq,med)       \
  VEST_GI(BaseSec3,CAMO,lpl,na)       \
  VEST_GI(BaseSec3,CAMO,lpl,med)      \
  VEST_GI(GungnirS_1,CAMO,na,na)        \
  VEST_GI(GungnirS_1,CAMO,na,med)       \
  VEST_GI(GungnirS_1,CAMO,1pl,na)       \
  VEST_GI(GungnirS_1,CAMO,1pl,med)      \
  VEST_GI(GungnirS_1,CAMO,2pl,na)       \
  VEST_GI(GungnirS_1,CAMO,2pl,med)      \
  VEST_GI(GungnirS_1,CAMO,hq,na)        \
  VEST_GI(GungnirS_1,CAMO,hq,med)       \
  VEST_GI(GungnirS_1,CAMO,lpl,na)       \
  VEST_GI(GungnirS_1,CAMO,lpl,med)      \
  VEST_GI(GungnirS_2,CAMO,na,na)        \
  VEST_GI(GungnirS_2,CAMO,na,med)       \
  VEST_GI(GungnirS_2,CAMO,1pl,na)       \
  VEST_GI(GungnirS_2,CAMO,1pl,med)      \
  VEST_GI(GungnirS_2,CAMO,2pl,na)       \
  VEST_GI(GungnirS_2,CAMO,2pl,med)      \
  VEST_GI(GungnirS_2,CAMO,hq,na)        \
  VEST_GI(GungnirS_2,CAMO,hq,med)       \
  VEST_GI(GungnirS_2,CAMO,lpl,na)       \
  VEST_GI(GungnirS_2,CAMO,lpl,med)      \
  VEST_GI(GungnirS_3,CAMO,na,na)        \
  VEST_GI(GungnirS_3,CAMO,na,med)       \
  VEST_GI(GungnirS_3,CAMO,1pl,na)       \
  VEST_GI(GungnirS_3,CAMO,1pl,med)      \
  VEST_GI(GungnirS_3,CAMO,2pl,na)       \
  VEST_GI(GungnirS_3,CAMO,2pl,med)      \
  VEST_GI(GungnirS_3,CAMO,hq,na)        \
  VEST_GI(GungnirS_3,CAMO,hq,med)       \
  VEST_GI(GungnirS_3,CAMO,lpl,na)       \
  VEST_GI(GungnirS_3,CAMO,lpl,med)      \
  VEST_GI(GungnirL_1,CAMO,na,na)        \
  VEST_GI(GungnirL_1,CAMO,na,med)       \
  VEST_GI(GungnirL_1,CAMO,1pl,na)       \
  VEST_GI(GungnirL_1,CAMO,1pl,med)      \
  VEST_GI(GungnirL_1,CAMO,2pl,na)       \
  VEST_GI(GungnirL_1,CAMO,2pl,med)      \
  VEST_GI(GungnirL_1,CAMO,hq,na)        \
  VEST_GI(GungnirL_1,CAMO,hq,med)       \
  VEST_GI(GungnirL_1,CAMO,lpl,na)       \
  VEST_GI(GungnirL_1,CAMO,lpl,med)      \
  VEST_GI(GungnirL_2,CAMO,na,na)        \
  VEST_GI(GungnirL_2,CAMO,na,med)       \
  VEST_GI(GungnirL_2,CAMO,1pl,na)       \
  VEST_GI(GungnirL_2,CAMO,1pl,med)      \
  VEST_GI(GungnirL_2,CAMO,2pl,na)       \
  VEST_GI(GungnirL_2,CAMO,2pl,med)      \
  VEST_GI(GungnirL_2,CAMO,hq,na)        \
  VEST_GI(GungnirL_2,CAMO,hq,med)       \
  VEST_GI(GungnirL_2,CAMO,lpl,na)       \
  VEST_GI(GungnirL_2,CAMO,lpl,med)      \
  VEST_GI(GungnirL_3,CAMO,na,na)        \
  VEST_GI(GungnirL_3,CAMO,na,med)       \
  VEST_GI(GungnirL_3,CAMO,1pl,na)       \
  VEST_GI(GungnirL_3,CAMO,1pl,med)      \
  VEST_GI(GungnirL_3,CAMO,2pl,na)       \
  VEST_GI(GungnirL_3,CAMO,2pl,med)      \
  VEST_GI(GungnirL_3,CAMO,hq,na)        \
  VEST_GI(GungnirL_3,CAMO,hq,med)       \
  VEST_GI(GungnirL_3,CAMO,lpl,na)       \
  VEST_GI(GungnirL_3,CAMO,lpl,med)      \












//New Uniform class definitions
//cfgVehicle
#define TCP_VEH_CLASS_DEF                                     \
  TCP_VEH_CLASS_NORMAL(TShirt,Untucked)                       \
  TCP_VEH_CLASS_NORMAL(TShirt,Tucked)                       \
  TCP_VEH_CLASS_NORMAL(FieldTop,Full)                       \
  TCP_VEH_CLASS_NORMAL(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_NORMAL(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_NORMAL(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_NORMAL(TacShirt,Full)                       \
  TCP_VEH_CLASS_NORMAL(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_NORMAL(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_NORMAL(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED(TShirt,Tucked)                       \
  TCP_VEH_CLASS_BLOUSED(TShirt,UnTucked)                       \
  TCP_VEH_CLASS_BLOUSED(FieldTop,Full)                       \
  TCP_VEH_CLASS_BLOUSED(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED(TacShirt,Full)                       \
  TCP_VEH_CLASS_BLOUSED(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_GLOVES(TShirt,Tucked)                       \
  TCP_VEH_CLASS_GLOVES(TShirt,UnTucked)                       \
  TCP_VEH_CLASS_GLOVES(FieldTop,Full)                       \
  TCP_VEH_CLASS_GLOVES(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_GLOVES(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_GLOVES(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_GLOVES(TacShirt,Full)                       \
  TCP_VEH_CLASS_GLOVES(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_GLOVES(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_GLOVES(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TShirt,Tucked)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TShirt,UnTucked)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(FieldTop,Full)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TacShirt,Full)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED_GLOVES(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_UNZIPPED(FieldTop,Full)                       \
  TCP_VEH_CLASS_UNZIPPED(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_UNZIPPED(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_UNZIPPED(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_UNZIPPED(TacShirt,Full)                       \
  TCP_VEH_CLASS_UNZIPPED(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_UNZIPPED(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_UNZIPPED(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(FieldTop,Full)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(FieldTop,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(FieldTop,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(FieldTop,SlimSleeve)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(TacShirt,Full)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(TacShirt,HalfRoll)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(TacShirt,QuarterRoll)                       \
  TCP_VEH_CLASS_BLOUSED_UNZIPPED(TacShirt,SlimSleeve)                       \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(FieldTop,Full)                                       \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(FieldTop,HalfRoll)                                   \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(FieldTop,QuarterRoll)                                \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(FieldTop,SlimSleeve)                                 \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(TacShirt,Full)                                       \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(TacShirt,HalfRoll)                                   \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(TacShirt,QuarterRoll)                                \
  TCP_VEH_CLASS_GLOVES_UNZIPPED(TacShirt,SlimSleeve)                                 \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,Full)                               \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,HalfRoll)                           \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,QuarterRoll)                        \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,SlimSleeve)                         \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,Full)                               \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,HalfRoll)                           \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,QuarterRoll)                        \
  TCP_VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,SlimSleeve)                         \

//cfgWeapon
#define TCP_WEP_CLASS_DEF \
  TCP_WEP_CLASS_NORMAL(TShirt,Tucked)                       \
  TCP_WEP_CLASS_NORMAL(TShirt,Untucked)                       \
  TCP_WEP_CLASS_NORMAL(FieldTop,Full)                       \
  TCP_WEP_CLASS_NORMAL(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_NORMAL(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_NORMAL(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_NORMAL(TacShirt,Full)                       \
  TCP_WEP_CLASS_NORMAL(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_NORMAL(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_NORMAL(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED(TShirt,Tucked)                       \
  TCP_WEP_CLASS_BLOUSED(TShirt,UnTucked)                       \
  TCP_WEP_CLASS_BLOUSED(FieldTop,Full)                       \
  TCP_WEP_CLASS_BLOUSED(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED(TacShirt,Full)                       \
  TCP_WEP_CLASS_BLOUSED(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_GLOVES(TShirt,Tucked)                       \
  TCP_WEP_CLASS_GLOVES(TShirt,UnTucked)                       \
  TCP_WEP_CLASS_GLOVES(FieldTop,Full)                       \
  TCP_WEP_CLASS_GLOVES(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_GLOVES(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_GLOVES(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_GLOVES(TacShirt,Full)                       \
  TCP_WEP_CLASS_GLOVES(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_GLOVES(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_GLOVES(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TShirt,Tucked)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TShirt,UnTucked)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(FieldTop,Full)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TacShirt,Full)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED_GLOVES(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_UNZIPPED(FieldTop,Full)                       \
  TCP_WEP_CLASS_UNZIPPED(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_UNZIPPED(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_UNZIPPED(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_UNZIPPED(TacShirt,Full)                       \
  TCP_WEP_CLASS_UNZIPPED(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_UNZIPPED(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_UNZIPPED(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(FieldTop,Full)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(FieldTop,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(FieldTop,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(FieldTop,SlimSleeve)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(TacShirt,Full)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(TacShirt,HalfRoll)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(TacShirt,QuarterRoll)                       \
  TCP_WEP_CLASS_BLOUSED_UNZIPPED(TacShirt,SlimSleeve)                       \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(FieldTop,Full)                                       \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(FieldTop,HalfRoll)                                   \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(FieldTop,QuarterRoll)                                \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(FieldTop,SlimSleeve)                                 \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(TacShirt,Full)                                       \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(TacShirt,HalfRoll)                                   \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(TacShirt,QuarterRoll)                                \
  TCP_WEP_CLASS_GLOVES_UNZIPPED(TacShirt,SlimSleeve)                                 \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,Full)                               \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,HalfRoll)                           \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,QuarterRoll)                        \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(FieldTop,SlimSleeve)                         \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,Full)                               \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,HalfRoll)                           \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,QuarterRoll)                        \
  TCP_WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(TacShirt,SlimSleeve)                         \


// New uniform class setup
#define VEH_UNI_CLASS(CAMO)                                     \
  VEH_CLASS_NORMAL(CAMO,TShirt,Untucked)                       \
  VEH_CLASS_NORMAL(CAMO,TShirt,Tucked)                       \
  VEH_CLASS_NORMAL(CAMO,FieldTop,Full)                       \
  VEH_CLASS_NORMAL(CAMO,FieldTop,HalfRoll)                       \
  VEH_CLASS_NORMAL(CAMO,FieldTop,QuarterRoll)                       \
  VEH_CLASS_NORMAL(CAMO,FieldTop,SlimSleeve)                       \
  VEH_CLASS_NORMAL(CAMO,TacShirt,Full)                       \
  VEH_CLASS_NORMAL(CAMO,TacShirt,HalfRoll)                       \
  VEH_CLASS_NORMAL(CAMO,TacShirt,QuarterRoll)                       \
  VEH_CLASS_NORMAL(CAMO,TacShirt,SlimSleeve)                       \
  VEH_CLASS_BLOUSED(CAMO,TShirt,Tucked)                       \
  VEH_CLASS_BLOUSED(CAMO,TShirt,UnTucked)                       \
  VEH_CLASS_BLOUSED(CAMO,FieldTop,Full)                       \
  VEH_CLASS_BLOUSED(CAMO,FieldTop,HalfRoll)                       \
  VEH_CLASS_BLOUSED(CAMO,FieldTop,QuarterRoll)                       \
  VEH_CLASS_BLOUSED(CAMO,FieldTop,SlimSleeve)                       \
  VEH_CLASS_BLOUSED(CAMO,TacShirt,Full)                       \
  VEH_CLASS_BLOUSED(CAMO,TacShirt,HalfRoll)                       \
  VEH_CLASS_BLOUSED(CAMO,TacShirt,QuarterRoll)                       \
  VEH_CLASS_BLOUSED(CAMO,TacShirt,SlimSleeve)                       \
  VEH_CLASS_GLOVES(CAMO,TShirt,Tucked)                       \
  VEH_CLASS_GLOVES(CAMO,TShirt,UnTucked)                       \
  VEH_CLASS_GLOVES(CAMO,FieldTop,Full)                       \
  VEH_CLASS_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  VEH_CLASS_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  VEH_CLASS_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  VEH_CLASS_GLOVES(CAMO,TacShirt,Full)                       \
  VEH_CLASS_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  VEH_CLASS_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  VEH_CLASS_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TShirt,Tucked)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TShirt,UnTucked)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,Full)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,Full)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  VEH_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  VEH_CLASS_UNZIPPED(CAMO,FieldTop,Full)                       \
  VEH_CLASS_UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  VEH_CLASS_UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  VEH_CLASS_UNZIPPED(CAMO,FieldTop,SlimSleeve)\
  VEH_CLASS_UNZIPPED(CAMO,TacShirt,Full)\
  VEH_CLASS_UNZIPPED(CAMO,TacShirt,HalfRoll)\
  VEH_CLASS_UNZIPPED(CAMO,TacShirt,QuarterRoll)\
  VEH_CLASS_UNZIPPED(CAMO,TacShirt,SlimSleeve)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)\
  VEH_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,Full)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,HalfRoll)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,QuarterRoll)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,SlimSleeve)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,Full)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,HalfRoll)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,QuarterRoll)\
  VEH_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,SlimSleeve)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)\
  VEH_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)\

//cfgWeapon
#define WEP_UNI_CLASS(CAMO) \
  WEP_CLASS_NORMAL(CAMO,TShirt,Tucked)                       \
  WEP_CLASS_NORMAL(CAMO,TShirt,Untucked)                       \
  WEP_CLASS_NORMAL(CAMO,FieldTop,Full)                       \
  WEP_CLASS_NORMAL(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_NORMAL(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_NORMAL(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_NORMAL(CAMO,TacShirt,Full)                       \
  WEP_CLASS_NORMAL(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_NORMAL(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_NORMAL(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_BLOUSED(CAMO,TShirt,Tucked)                       \
  WEP_CLASS_BLOUSED(CAMO,TShirt,UnTucked)                       \
  WEP_CLASS_BLOUSED(CAMO,FieldTop,Full)                       \
  WEP_CLASS_BLOUSED(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_BLOUSED(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_BLOUSED(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_BLOUSED(CAMO,TacShirt,Full)                       \
  WEP_CLASS_BLOUSED(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_BLOUSED(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_BLOUSED(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_GLOVES(CAMO,TShirt,Tucked)                       \
  WEP_CLASS_GLOVES(CAMO,TShirt,UnTucked)                       \
  WEP_CLASS_GLOVES(CAMO,FieldTop,Full)                       \
  WEP_CLASS_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_GLOVES(CAMO,TacShirt,Full)                       \
  WEP_CLASS_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TShirt,Tucked)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TShirt,UnTucked)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,Full)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,Full)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_BLOUSED_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_UNZIPPED(CAMO,FieldTop,Full)                       \
  WEP_CLASS_UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_UNZIPPED(CAMO,TacShirt,Full)                       \
  WEP_CLASS_UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  WEP_CLASS_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,Full)                                       \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,HalfRoll)                                   \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,QuarterRoll)                                \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,FieldTop,SlimSleeve)                                 \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,Full)                                       \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,HalfRoll)                                   \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,QuarterRoll)                                \
  WEP_CLASS_GLOVES_UNZIPPED(CAMO,TacShirt,SlimSleeve)                                 \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                               \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                           \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                        \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                         \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                               \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                           \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                        \
  WEP_CLASS_GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                         \




#define NEW_UNIFROM_GI(CAMO)                        \
  NORMAL(CAMO,TShirt,Tucked)                       \
  NORMAL(CAMO,TShirt,Untucked)                       \
  NORMAL(CAMO,FieldTop,Full)                       \
  NORMAL(CAMO,FieldTop,HalfRoll)                       \
  NORMAL(CAMO,FieldTop,QuarterRoll)                       \
  NORMAL(CAMO,FieldTop,SlimSleeve)                       \
  NORMAL(CAMO,TacShirt,Full)                       \
  NORMAL(CAMO,TacShirt,HalfRoll)                       \
  NORMAL(CAMO,TacShirt,QuarterRoll)                       \
  NORMAL(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED(CAMO,TShirt,Tucked)                       \
  BLOUSED(CAMO,TShirt,UnTucked)                       \
  BLOUSED(CAMO,FieldTop,Full)                       \
  BLOUSED(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED(CAMO,TacShirt,Full)                       \
  BLOUSED(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED(CAMO,TacShirt,SlimSleeve)                       \
  GLOVES(CAMO,TShirt,Tucked)                       \
  GLOVES(CAMO,TShirt,UnTucked)                       \
  GLOVES(CAMO,FieldTop,Full)                       \
  GLOVES(CAMO,FieldTop,HalfRoll)                       \
  GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  GLOVES(CAMO,TacShirt,Full)                       \
  GLOVES(CAMO,TacShirt,HalfRoll)                       \
  GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED_GLOVES(CAMO,TShirt,Tucked)                       \
  BLOUSED_GLOVES(CAMO,TShirt,UnTucked)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,Full)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED_GLOVES(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,Full)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED_GLOVES(CAMO,TacShirt,SlimSleeve)                       \
  UNZIPPED(CAMO,FieldTop,Full)                       \
  UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  UNZIPPED(CAMO,TacShirt,Full)                       \
  UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                       \
  BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                       \
  BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                       \
  GLOVES_UNZIPPED(CAMO,FieldTop,Full)                                       \
  GLOVES_UNZIPPED(CAMO,FieldTop,HalfRoll)                                   \
  GLOVES_UNZIPPED(CAMO,FieldTop,QuarterRoll)                                \
  GLOVES_UNZIPPED(CAMO,FieldTop,SlimSleeve)                                 \
  GLOVES_UNZIPPED(CAMO,TacShirt,Full)                                       \
  GLOVES_UNZIPPED(CAMO,TacShirt,HalfRoll)                                   \
  GLOVES_UNZIPPED(CAMO,TacShirt,QuarterRoll)                                \
  GLOVES_UNZIPPED(CAMO,TacShirt,SlimSleeve)                                 \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,Full)                               \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,HalfRoll)                           \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,QuarterRoll)                        \
  GLOVES_BLOUSED_UNZIPPED(CAMO,FieldTop,SlimSleeve)                         \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,Full)                               \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,HalfRoll)                           \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,QuarterRoll)                        \
  GLOVES_BLOUSED_UNZIPPED(CAMO,TacShirt,SlimSleeve)                         \




/*
  Defines a no-visor helmet.
  Input:
  - SUFFIX:
    defines the texture name suffix in the `helmets/infantry` folder.
    I.e sets the texture path in this format:
    `twelfth_armor/helmets/infantry/Helm_co_[SUFFIX].paa`
  - DISPLAY:
    the string that gets displayed in the ACE arsenal.
    Provide in quotes.
*/
#define HELM_NV(SUFFIX,DISPLAY)                 \
  class twelfth_helm_##SUFFIX##_nv: twelfth_helm_base { \
    scope=2;                                      \
    author="Weber";                               \
    picture="";                                   \
    scopeArsenal=2;                               \
    displayName=DISPLAY;                          \
    hiddenSelections[] = { "camo", "camo2" };     \
    hiddenSelectionsTextures[] = {                \
      #HELM_TEX_PATH(SUFFIX),                     \
      ""                                          \
    };                                            \
    class ItemInfo: HeadgearItem {                \
      uniformModel="\halo_marine\halo_helm_01";   \
      mass=40;                                    \
      picture="";                                 \
      modelSides[]={6};                           \
      passThrough=0.1;                            \
      class HitpointsProtectionInfo {             \
        class Head {                              \
          hitpointName="HitHead";                 \
          armor=20;                               \
          passThrough=0.1;                        \
        };                                        \
      };                                          \
      hiddenSelections[]= { "camo", "camo2" };    \
      hiddenSelectionsTextures[]= {               \
        #HELM_TEX_PATH(SUFFIX),                   \
        ""                                        \
      };                                          \
    };                                            \
  };

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
#define HELM_CH43A(SUFFIX,DISPLAY)                 \
  class twelfth_helmCH43A_##SUFFIX##: twelfth_helmCH43A_base {    \
  scope=2;                                      \
  author="Weber";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  hiddenSelections[] = { "camo","decals" };              \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH_CH43A(SUFFIX),				\
	  #HELM_DEC_PATH								\
  }; 											\
	class TCP_uniformDecals: TCP_uniformDecals		\
	{												\
		decalColor = "white";						\
	};  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\h_helmet_CH43A.p3d";   \
    picture="";                                 \
    mass=40;                                    \
    modelSides[]={6};                           \
    passThrough=0.1;                            \
    class HitpointsProtectionInfo {             \
      class Head {                              \
        hitpointName="HitHead";                 \
        armor=20;                               \
        passThrough=0.1;                        \
      };                                        \
    };                                          \
    hiddenSelections[]= {"camo","decals"};      \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH_CH43A(SUFFIX),				\
	    #HELM_DEC_PATH	  						\
    };                                          \
  };                                            \
};   

#define HELM_ECH43A(SUFFIX,DISPLAY)                 \
  class twelfth_helmECH43A_##SUFFIX##: twelfth_helmECH43A_base {    \
  scope=2;                                      \
  author="Weber";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  hiddenSelections[]= {"camo","camo1","decals"};             \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH_CH43A(SUFFIX),				\
    "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\default\helmet_ECH43A_Visor_CO.paa",\
	  #HELM_DEC_PATH								\
  }; 											\
	class TCP_uniformDecals: TCP_uniformDecals		\
	{												\
		decalColor = "white";						\
	};  											\
  class ItemInfo: HeadgearItem {                \
    uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_DP.p3d";   \
    picture="";                                 \
    mass=40;                                    \
    modelSides[]={6};                           \
    passThrough=0.1;                            \
    class HitpointsProtectionInfo {             \
      class Head {                              \
        hitpointName="HitHead";                 \
        armor=20;                               \
        passThrough=0.1;                        \
      };                                        \
    };                                          \
    hiddenSelections[]= {"camo","camo1","decals"};      \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH_CH43A(SUFFIX),				\
      "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\default\helmet_ECH43A_Visor_CO.paa",\
	    #HELM_DEC_PATH	  						\
    };                                          \
  };                                            \
};  

#define HELM_SV(SUFFIX,DISPLAY)                 \
class twelfth_helm_##SUFFIX##: twelfth_helm_base {    \
  scope=2;                                      \
  author="Weber";                                \
  picture="";                                   \
  scopeArsenal=2;                               \
  displayName=DISPLAY;                          \
  hiddenSelections[] = { "camo" };              \
  hiddenSelectionsTextures[] = {                \
    #HELM_TEX_PATH(SUFFIX)                      \
  };                                            \
  class ItemInfo: HeadgearItem {                \
    uniformModel="\halo_marine\halo_helm_01";   \
    picture="";                                 \
    mass=40;                                    \
    modelSides[]={6};                           \
    passThrough=0.1;                            \
    class HitpointsProtectionInfo {             \
      class Head {                              \
        hitpointName="HitHead";                 \
        armor=20;                               \
        passThrough=0.1;                        \
      };                                        \
    };                                          \
    hiddenSelections[]= { "camo" };             \
    hiddenSelectionsTextures[]= {               \
      #HELM_TEX_PATH(SUFFIX)                    \
    };                                          \
  };                                            \
};

// this is shoved into here so that it need not be repeated 20x for different variants

#define ALL_HELM(CAMO)                                                  \
  HELM_CH43A(##CAMO##,         "[12th][Inf] Helmet")                       \
  HELM_CH43A(##CAMO##_med,     "[12th][Inf] Helmet (Corpsman)")            \
  HELM_CH43A(##CAMO##_1pl,     "[12th][Inf][1Plt] Helmet")                 \
  HELM_CH43A(##CAMO##_1pl_ftl, "[12th][Inf][1Plt] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_1pl_sl,  "[12th][Inf][1Plt] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_1pl_psg, "[12th][Inf][1Plt] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_1pl_pl,  "[12th][Inf][1Plt] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_1pl_med, "[12th][Inf][1Plt] Helmet (Corpsman)")      \
  HELM_CH43A(##CAMO##_2pl,     "[12th][Inf][2Plt] Helmet")                 \
  HELM_CH43A(##CAMO##_2pl_ftl, "[12th][Inf][2Plt] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_2pl_sl,  "[12th][Inf][2Plt] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_2pl_psg, "[12th][Inf][2Plt] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_2pl_pl,  "[12th][Inf][2Plt] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_2pl_med, "[12th][Inf][2Plt] Helmet (Corpsman)")      \
  HELM_CH43A(##CAMO##_hq,      "[12th][Inf][HQ] Helmet")                   \
  HELM_CH43A(##CAMO##_hq_ftl,  "[12th][Inf][HQ] Helmet (FTL)")             \
  HELM_CH43A(##CAMO##_hq_sl,   "[12th][Inf][HQ] Helmet (SL)")              \
  HELM_CH43A(##CAMO##_hq_psg,  "[12th][Inf][HQ] Helmet (PSG)")             \
  HELM_CH43A(##CAMO##_hq_pl,   "[12th][Inf][HQ] Helmet (PL)")              \
  HELM_CH43A(##CAMO##_hq_med,  "[12th][Inf][HQ] Helmet (Corpsman)")        \
  HELM_CH43A(##CAMO##_lpl,     "[12th][Inf][Logi] Helmet")                 \
  HELM_CH43A(##CAMO##_lpl_ftl, "[12th][Inf][Logi] Helmet (FTL)")           \
  HELM_CH43A(##CAMO##_lpl_sl,  "[12th][Inf][Logi] Helmet (SL)")            \
  HELM_CH43A(##CAMO##_lpl_psg, "[12th][Inf][Logi] Helmet (PSG)")           \
  HELM_CH43A(##CAMO##_lpl_pl,  "[12th][Inf][Logi] Helmet (PL)")            \
  HELM_CH43A(##CAMO##_lpl_med, "[12th][Inf][Logi] Helmet (Corpsman)")      \
  HELM_SV(##CAMO##,         "[12th][Inf] Helmet")                       \
  HELM_SV(##CAMO##_med,     "[12th][Inf] Helmet (Corpsman)")            \
  HELM_SV(##CAMO##_1pl,     "[12th][Inf][1Plt] Helmet")                 \
  HELM_SV(##CAMO##_1pl_ftl, "[12th][Inf][1Plt] Helmet (FTL)")           \
  HELM_SV(##CAMO##_1pl_sl,  "[12th][Inf][1Plt] Helmet (SL)")            \
  HELM_SV(##CAMO##_1pl_psg, "[12th][Inf][1Plt] Helmet (PSG)")           \
  HELM_SV(##CAMO##_1pl_pl,  "[12th][Inf][1Plt] Helmet (PL)")            \
  HELM_SV(##CAMO##_1pl_med, "[12th][Inf][1Plt] Helmet (Corpsman)")      \
  HELM_SV(##CAMO##_2pl,     "[12th][Inf][2Plt] Helmet")                 \
  HELM_SV(##CAMO##_2pl_ftl, "[12th][Inf][2Plt] Helmet (FTL)")           \
  HELM_SV(##CAMO##_2pl_sl,  "[12th][Inf][2Plt] Helmet (SL)")            \
  HELM_SV(##CAMO##_2pl_psg, "[12th][Inf][2Plt] Helmet (PSG)")           \
  HELM_SV(##CAMO##_2pl_pl,  "[12th][Inf][2Plt] Helmet (PL)")            \
  HELM_SV(##CAMO##_2pl_med, "[12th][Inf][2Plt] Helmet (Corpsman)")      \
  HELM_SV(##CAMO##_hq,      "[12th][Inf][HQ] Helmet")                   \
  HELM_SV(##CAMO##_hq_ftl,  "[12th][Inf][HQ] Helmet (FTL)")             \
  HELM_SV(##CAMO##_hq_sl,   "[12th][Inf][HQ] Helmet (SL)")              \
  HELM_SV(##CAMO##_hq_psg,  "[12th][Inf][HQ] Helmet (PSG)")             \
  HELM_SV(##CAMO##_hq_pl,   "[12th][Inf][HQ] Helmet (PL)")              \
  HELM_SV(##CAMO##_hq_med,  "[12th][Inf][HQ] Helmet (Corpsman)")        \
  HELM_SV(##CAMO##_lpl,     "[12th][Inf][Logi] Helmet")                 \
  HELM_SV(##CAMO##_lpl_ftl, "[12th][Inf][Logi] Helmet (FTL)")           \
  HELM_SV(##CAMO##_lpl_sl,  "[12th][Inf][Logi] Helmet (SL)")            \
  HELM_SV(##CAMO##_lpl_psg, "[12th][Inf][Logi] Helmet (PSG)")           \
  HELM_SV(##CAMO##_lpl_pl,  "[12th][Inf][Logi] Helmet (PL)")            \
  HELM_SV(##CAMO##_lpl_med, "[12th][Inf][Logi] Helmet (Corpsman)")      \
  HELM_NV(##CAMO##,         "[12th][Inf][NV] Helmet")                   \
  HELM_NV(##CAMO##_med,     "[12th][Inf][NV] Helmet (Corpsman)")        \
  HELM_NV(##CAMO##_1pl,     "[12th][Inf][NV][1Plt] Helmet")             \
  HELM_NV(##CAMO##_1pl_ftl, "[12th][Inf][NV][1Plt] Helmet (FTL)")       \
  HELM_NV(##CAMO##_1pl_sl,  "[12th][Inf][NV][1Plt] Helmet (SL)")        \
  HELM_NV(##CAMO##_1pl_psg, "[12th][Inf][Nv][1Plt] Helmet (PSG)")       \
  HELM_NV(##CAMO##_1pl_pl,  "[12th][Inf][NV][1Plt] Helmet (PL)")        \
  HELM_NV(##CAMO##_1pl_med, "[12th][Inf][NV][1Plt] Helmet (Corpsman)")  \
  HELM_NV(##CAMO##_2pl,     "[12th][Inf][NV][2Plt] Helmet")             \
  HELM_NV(##CAMO##_2pl_ftl, "[12th][Inf][NV][2Plt] Helmet (FTL)")       \
  HELM_NV(##CAMO##_2pl_sl,  "[12th][Inf][NV][2Plt] Helmet (SL)")        \
  HELM_NV(##CAMO##_2pl_psg, "[12th][Inf][NV][2Plt] Helmet (PSG)")       \
  HELM_NV(##CAMO##_2pl_pl,  "[12th][Inf][NV][2Plt] Helmet (PL)")        \
  HELM_NV(##CAMO##_2pl_med, "[12th][Inf][NV][2Plt] Helmet (Corpsman)")  \
  HELM_NV(##CAMO##_hq,      "[12th][Inf][NV][HQ] Helmet")               \
  HELM_NV(##CAMO##_hq_ftl,  "[12th][Inf][NV][HQ] Helmet (FTL)")         \
  HELM_NV(##CAMO##_hq_sl,   "[12th][Inf][NV][HQ] Helmet (SL)")          \
  HELM_NV(##CAMO##_hq_psg,  "[12th][Inf][NV][HQ] Helmet (PSG)")         \
  HELM_NV(##CAMO##_hq_pl,   "[12th][Inf][NV][HQ] Helmet (PL)")          \
  HELM_NV(##CAMO##_hq_med,  "[12th][Inf][NV][HQ] Helmet (Corpsman)")    \
  HELM_NV(##CAMO##_lpl,     "[12th][Inf][NV][Logi] Helmet")             \
  HELM_NV(##CAMO##_lpl_ftl, "[12th][Inf][NV][Logi] Helmet (FTL)")       \
  HELM_NV(##CAMO##_lpl_sl,  "[12th][Inf][NV][Logi] Helmet (SL)")        \
  HELM_NV(##CAMO##_lpl_psg, "[12th][Inf][NV][Logi] Helmet (PSG)")       \
  HELM_NV(##CAMO##_lpl_pl,  "[12th][Inf][NV][Logi] Helmet (PL)")        \
  HELM_NV(##CAMO##_lpl_med, "[12th][Inf][NV][Logi] Helmet (Corpsman)")  \
  HELM_ECH43A(##CAMO##,         "[12th][Clsd] Helmet")                       \
  HELM_ECH43A(##CAMO##_med,     "[12th][Clsd] Helmet (Corpsman)")            \
  HELM_ECH43A(##CAMO##_1pl,     "[12th][Clsd][1Plt] Helmet")                 \
  HELM_ECH43A(##CAMO##_1pl_ftl, "[12th][Clsd][1Plt] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_1pl_sl,  "[12th][Clsd][1Plt] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_1pl_psg, "[12th][Clsd][1Plt] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_1pl_pl,  "[12th][Clsd][1Plt] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_1pl_med, "[12th][Clsd][1Plt] Helmet (Corpsman)")      \
  HELM_ECH43A(##CAMO##_2pl,     "[12th][Clsd][2Plt] Helmet")                 \
  HELM_ECH43A(##CAMO##_2pl_ftl, "[12th][Clsd][2Plt] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_2pl_sl,  "[12th][Clsd][2Plt] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_2pl_psg, "[12th][Clsd][2Plt] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_2pl_pl,  "[12th][Clsd][2Plt] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_2pl_med, "[12th][Clsd][2Plt] Helmet (Corpsman)")      \
  HELM_ECH43A(##CAMO##_hq,      "[12th][Clsd][HQ] Helmet")                   \
  HELM_ECH43A(##CAMO##_hq_ftl,  "[12th][Clsd][HQ] Helmet (FTL)")             \
  HELM_ECH43A(##CAMO##_hq_sl,   "[12th][Clsd][HQ] Helmet (SL)")              \
  HELM_ECH43A(##CAMO##_hq_psg,  "[12th][Clsd][HQ] Helmet (PSG)")             \
  HELM_ECH43A(##CAMO##_hq_pl,   "[12th][Clsd][HQ] Helmet (PL)")              \
  HELM_ECH43A(##CAMO##_hq_med,  "[12th][Clsd][HQ] Helmet (Corpsman)")        \
  HELM_ECH43A(##CAMO##_lpl,     "[12th][Clsd][Logi] Helmet")                 \
  HELM_ECH43A(##CAMO##_lpl_ftl, "[12th][Clsd][Logi] Helmet (FTL)")           \
  HELM_ECH43A(##CAMO##_lpl_sl,  "[12th][Clsd][Logi] Helmet (SL)")            \
  HELM_ECH43A(##CAMO##_lpl_psg, "[12th][Clsd][Logi] Helmet (PSG)")           \
  HELM_ECH43A(##CAMO##_lpl_pl,  "[12th][Clsd][Logi] Helmet (PL)")            \
  HELM_ECH43A(##CAMO##_lpl_med, "[12th][Clsd][Logi] Helmet (Corpsman)")      \


/* Stands for helm, no visor, gear info. */
#define HELM_NV_GI(CSFX,CAMO,EL,ROLE) \
class twelfth_helm_##CSFX##_nv {         \
  model="twelfth_base_helms";            \
  camo=#CAMO;                         \
  element=#EL;                        \
  role=#ROLE;                         \
  visor="No";                         \
};

/* Stands for helm, no visor, gear info. */
#define HELM_SV_GI(CSFX,CAMO,EL,ROLE) \
class twelfth_helm_##CSFX## {            \
  model="twelfth_base_helms";            \
  camo=#CAMO;                         \
  element=#EL;                        \
  role=#ROLE;                         \
  visor="Yes";                         \
};

#define HELM_CH43A_GI(CSFX,CAMO,EL,ROLE)  \
class twelfth_helmCH43A_##CSFX## {              \
  model="twelfth_base_ch43a";            \
  camo=#CAMO;                       	  \
  element=#EL;                     		   \
  role=#ROLE;                      		   \
};




#define ALL_HELM_GI(CAMO)       \
    HELM_NV_GI(##CAMO##,##CAMO##,na,na)       \
    HELM_NV_GI(##CAMO##_med,##CAMO##,na,med)        \
    HELM_NV_GI(##CAMO##_1pl,##CAMO##,1pl,na)        \
    HELM_NV_GI(##CAMO##_1pl_ftl,##CAMO##,1pl,ftl)       \
    HELM_NV_GI(##CAMO##_1pl_sl,##CAMO##,1pl,sl)       \
    HELM_NV_GI(##CAMO##_1pl_psg,##CAMO##,1pl,psg)       \
    HELM_NV_GI(##CAMO##_1pl_pl,##CAMO##,1pl,pl)       \
    HELM_NV_GI(##CAMO##_1pl_med,##CAMO##,1pl,med)       \
    HELM_NV_GI(##CAMO##_2pl,##CAMO##,2pl,na)        \
    HELM_NV_GI(##CAMO##_2pl_ftl,##CAMO##,2pl,ftl)       \
    HELM_NV_GI(##CAMO##_2pl_sl,##CAMO##,2pl,sl)       \
    HELM_NV_GI(##CAMO##_2pl_psg,##CAMO##,2pl,psg)       \
    HELM_NV_GI(##CAMO##_2pl_pl,##CAMO##,2pl,pl)       \
    HELM_NV_GI(##CAMO##_2pl_med,##CAMO##,2pl,med)       \
    HELM_NV_GI(##CAMO##_hq,##CAMO##,hq,na)        \
    HELM_NV_GI(##CAMO##_hq_ftl,##CAMO##,hq,ftl)       \
    HELM_NV_GI(##CAMO##_hq_sl,##CAMO##,hq,sl)       \
    HELM_NV_GI(##CAMO##_hq_psg,##CAMO##,hq,psg)       \
    HELM_NV_GI(##CAMO##_hq_pl,##CAMO##,hq,pl)       \
    HELM_NV_GI(##CAMO##_hq_med,##CAMO##,hq,med)       \
    HELM_NV_GI(##CAMO##_lpl,##CAMO##,lpl,na)        \
    HELM_NV_GI(##CAMO##_lpl_ftl,##CAMO##,lpl,ftl)       \
    HELM_NV_GI(##CAMO##_lpl_sl,##CAMO##,lpl,sl)       \
    HELM_NV_GI(##CAMO##_lpl_psg,##CAMO##,lpl,psg)       \
    HELM_NV_GI(##CAMO##_lpl_pl,##CAMO##,lpl,pl)       \
    HELM_NV_GI(##CAMO##_lpl_med,##CAMO##,lpl,med)       \
    HELM_SV_GI(##CAMO##,##CAMO##,na,na)       \
    HELM_SV_GI(##CAMO##_med,##CAMO##,na,med)        \
    HELM_SV_GI(##CAMO##_1pl,##CAMO##,1pl,na)        \
    HELM_SV_GI(##CAMO##_1pl_ftl,##CAMO##,1pl,ftl)       \
    HELM_SV_GI(##CAMO##_1pl_sl,##CAMO##,1pl,sl)       \
    HELM_SV_GI(##CAMO##_1pl_psg,##CAMO##,1pl,psg)       \
    HELM_SV_GI(##CAMO##_1pl_pl,##CAMO##,1pl,pl)       \
    HELM_SV_GI(##CAMO##_1pl_med,##CAMO##,1pl,med)       \
    HELM_SV_GI(##CAMO##_2pl,##CAMO##,2pl,na)        \
    HELM_SV_GI(##CAMO##_2pl_ftl,##CAMO##,2pl,ftl)       \
    HELM_SV_GI(##CAMO##_2pl_sl,##CAMO##,2pl,sl)       \
    HELM_SV_GI(##CAMO##_2pl_psg,##CAMO##,2pl,psg)       \
    HELM_SV_GI(##CAMO##_2pl_pl,##CAMO##,2pl,pl)       \
    HELM_SV_GI(##CAMO##_2pl_med,##CAMO##,2pl,med)       \
    HELM_SV_GI(##CAMO##_hq,##CAMO##,hq,na)        \
    HELM_SV_GI(##CAMO##_hq_ftl,##CAMO##,hq,ftl)       \
    HELM_SV_GI(##CAMO##_hq_sl,##CAMO##,hq,sl)       \
    HELM_SV_GI(##CAMO##_hq_psg,##CAMO##,hq,psg)       \
    HELM_SV_GI(##CAMO##_hq_pl,##CAMO##,hq,pl)       \
    HELM_SV_GI(##CAMO##_hq_med,##CAMO##,hq,med)       \
    HELM_SV_GI(##CAMO##_lpl,##CAMO##,lpl,na)        \
    HELM_SV_GI(##CAMO##_lpl_ftl,##CAMO##,lpl,ftl)       \
    HELM_SV_GI(##CAMO##_lpl_sl,##CAMO##,lpl,sl)       \
    HELM_SV_GI(##CAMO##_lpl_psg,##CAMO##,lpl,psg)       \
    HELM_SV_GI(##CAMO##_lpl_pl,##CAMO##,lpl,pl)       \
    HELM_SV_GI(##CAMO##_lpl_med,##CAMO##,lpl,med)       \
	


#define CH43A_HELM_GI(CAMO)       \
	HELM_CH43A_GI(##CAMO##,##CAMO##,na,na)       \
    HELM_CH43A_GI(##CAMO##_med,##CAMO##,na,med)        \
    HELM_CH43A_GI(##CAMO##_1pl,##CAMO##,1pl,na)        \
    HELM_CH43A_GI(##CAMO##_1pl_ftl,##CAMO##,1pl,ftl)       \
    HELM_CH43A_GI(##CAMO##_1pl_sl,##CAMO##,1pl,sl)       \
    HELM_CH43A_GI(##CAMO##_1pl_psg,##CAMO##,1pl,psg)       \
    HELM_CH43A_GI(##CAMO##_1pl_pl,##CAMO##,1pl,pl)       \
    HELM_CH43A_GI(##CAMO##_1pl_med,##CAMO##,1pl,med)       \
    HELM_CH43A_GI(##CAMO##_2pl,##CAMO##,2pl,na)        \
    HELM_CH43A_GI(##CAMO##_2pl_ftl,##CAMO##,2pl,ftl)       \
    HELM_CH43A_GI(##CAMO##_2pl_sl,##CAMO##,2pl,sl)       \
    HELM_CH43A_GI(##CAMO##_2pl_psg,##CAMO##,2pl,psg)       \
    HELM_CH43A_GI(##CAMO##_2pl_pl,##CAMO##,2pl,pl)       \
    HELM_CH43A_GI(##CAMO##_2pl_med,##CAMO##,2pl,med)       \
    HELM_CH43A_GI(##CAMO##_hq,##CAMO##,hq,na)        \
    HELM_CH43A_GI(##CAMO##_hq_ftl,##CAMO##,hq,ftl)       \
    HELM_CH43A_GI(##CAMO##_hq_sl,##CAMO##,hq,sl)       \
    HELM_CH43A_GI(##CAMO##_hq_psg,##CAMO##,hq,psg)       \
    HELM_CH43A_GI(##CAMO##_hq_pl,##CAMO##,hq,pl)       \
    HELM_CH43A_GI(##CAMO##_hq_med,##CAMO##,hq,med)       \
    HELM_CH43A_GI(##CAMO##_lpl,##CAMO##,lpl,na)        \
    HELM_CH43A_GI(##CAMO##_lpl_ftl,##CAMO##,lpl,ftl)       \
    HELM_CH43A_GI(##CAMO##_lpl_sl,##CAMO##,lpl,sl)       \
    HELM_CH43A_GI(##CAMO##_lpl_psg,##CAMO##,lpl,psg)       \
    HELM_CH43A_GI(##CAMO##_lpl_pl,##CAMO##,lpl,pl)       \
    HELM_CH43A_GI(##CAMO##_lpl_med,##CAMO##,lpl,med)       \
	

#define CAP_B(SUFFIX,DISPLAY)                         \
class twelfth_cap_##SUFFIX: H_Cap_oli {               \
  picture="";                                         \
  scope=2;                                            \
  scopeArsenal=2;                                     \
  displayname=DISPLAY;                                \
  hiddenselectionstextures[]={#CAP_TEX_PATH(SUFFIX)}; \
};

/*
For those of you peeking around, sorry, couldn't
have made this macro work cleanly without carrying
a local copy of the base textures from UNSCF around here.
*/

/*
  A Macro for the IAHDS Pilot helmet.
  Input:
  * SUFFIX - A class name suffix, to avoid clashing.
  * DISPLAY - What gets displayed in the Arsenal, format "like this".
  * C1 through 5 - Arguments that define from which folder a specific
                   hidden selection is going to be pulling from.
*/
#define PILOT_HELM(SUFFIX,DISPLAY,C1,C2,C3,C4,C5)                         \
  class twelfth_pilot_h_##SUFFIX : H_HelmetB {                                 \
  author="Weber";                                                          \
  scope=2;                                                                \
  scopeArsenal=2;                                                         \
  picture="";                                                             \
  ace_hearing_protection=1;                                               \
  ace_hearing_lowerVolume=0.30000001;                                     \
  optreVarietys[] = {"", "", "_broken"};                                  \
  optreHUDStyle = "ODST_1";                                               \
  displayName=DISPLAY;                                                    \
  hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4", "camo5"};     \
  model="\DMNS\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01";          \
  hiddenSelectionsTextures[]={                                            \
      #PILOT_H_TEX(C1,Addons_co.paa),                                     \
      #PILOT_H_TEX(C2,EXT_co.paa),                                        \
      #PILOT_H_TEX(C3,INT_co.paa),                                        \
      #PILOT_H_TEX(C4,MID_co.paa),                                        \
      #PILOT_H_TEX(C5,Visor_co.paa)                                       \
  };                                                                      \
  class ItemInfo : HeadgearItem {                                         \
    mass = 25;                                                            \
    modelSides[]={6};                                                     \
    uniformModel="\DMNS\DMNS_Units\Armour\Pilot_Helm_01\Pilot_Helmet_01"; \
    hiddenSelections[]={"camo1", "camo2", "camo3", "camo4", "camo5"};     \
    hiddenSelectionsTextures[]={                                          \
      #PILOT_H_TEX(C1,Addons_co.paa),                                     \
      #PILOT_H_TEX(C2,EXT_co.paa),                                        \
      #PILOT_H_TEX(C3,INT_co.paa),                                        \
      #PILOT_H_TEX(C4,MID_co.paa),                                        \
      #PILOT_H_TEX(C5,Visor_co.paa)                                       \
    };                                                                    \
    class HitpointsProtectionInfo {                                       \
      class Head {                                                        \
        hitpointName = "HitHead";                                         \
        armor = 20;                                                       \
        passThrough = 0.2;                                                \
      };                                                                  \
      class Face {                                                        \
        hitpointName = "HitFace";                                         \
        armor = 8;                                                        \
        passThrough = 0.3;                                                \
      };                                                                  \
      class Neck {                                                        \
        hitpointName = "HitNeck";                                         \
        armor = 15;                                                       \
        passThrough = 0.1;                                                \
      };                                                                  \
    };                                                                    \
  };                                                                      \
};

#define BOONIE_WEP(CAMO)                                    \
  class twelfth_boonie_##CAMO: H_HelmetB {                  \
    scope=2;                                                \
    scopeArsenal=2;                                         \
    author="Sammy, Waylen";                                 \
    picture="";                                             \
    displayName="[12th][Caps] Boonie Hat";                  \
    model = "\a3\characters_f\Common\booniehat";            \
    hiddenSelections[] = {"camo"};                          \
    hiddenSelectionsTextures[] = {                          \
      QP(helmets\boonie_hat\##CAMO\boonie_co.paa)           \
    };                                                      \
    class ItemInfo: HeadgearItem {                          \
        mass = 5;                                           \
        uniformModel = "\a3\characters_f\Common\booniehat"; \
        modelSides[] = {6};                                 \
        hiddenSelections[] = {"camo"};                      \
    };                                                      \
  };                                                        \

#define BOONIE_GI(CAMO)\
  class twelfth_boonie_##CAMO## {\
    model = "twelfth_boonies";\
    camo = #CAMO;\
  };\

#define PATROLCAP_WEP(CAMO) \
  class twelfth_cap_##CAMO: OPTRE_UNSC_PatrolCap_Marines {  \
    author="Waylen";                                  \
    picture="";                                       \
    displayName="[12th][Caps] Patrol Cap";            \
    hiddenSelections[] = { "camo1", "hide_army" };    \
    hiddenSelectionsTextures[] = {                    \
      QP(helmets\patrol_caps\##CAMO\cap_co.paa)       \
    };                                                \
    class ItemInfo: ItemInfo {                        \
      hiddenSelections[] = { "camo1", "hide_army" };  \
      hiddenSelectionsTextures[] = {                  \
        QP(helmets\patrol_caps\##CAMO\cap_co.paa)     \
      };                                              \
    };                                                \
  };                                                  \
  
#define PATROLCAP_GI(CAMO) \
  class twelfth_cap_##CAMO { \
    model = "twelfth_patrolcaps"; \
    camo = #CAMO; \
  }; \
