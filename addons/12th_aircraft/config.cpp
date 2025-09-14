#include "config_macros.hpp"

/*
  ==============================================================================
  config.cpp

  This file defines all the 12th MEU aircraft classes. It references base
  classes from OPTRE, the Splits Pelican mod, and vanilla Arma. The macros
  in config_macros.hpp apply additional textures, set up hiddenSelections,
  and define spawn info (AIR_SP_INFO) used by your vehicle spawner script.

  Key Points:
    - CfgPatches: Registers these classes so Arma recognizes them.
    - CfgVehicles: Actual aircraft classes with references to new textures,
      macros for additional texture sets, and custom factions (twelfth_MEU).
    - Macros for each aircraft type handle texture sources, hidden selections,
      and spawner info definitions.

  Expand or comment out sections as needed for future updates or newly added
  aircraft.
  ==============================================================================
*/

class CfgPatches {
  class twelfth_aircraft {
    units[] = {
      "twelfth_d77_tc_pelican",
      "twelfth_hornet",
      "twelfth_falcon_unarmed",
      "twelfth_falcon_armed",
      "twelfth_falcon_s_unarmed",
      "twelfth_falcon_s_armed",
      "twelfth_sparrowhawk_m",
      "twelfth_sparrowhawk_l",
      "twelfth_sparrowhawk_ml",
      "twelfth_sparrowhawk",
      "twelfth_wyvern_inf",
      "twelfth_wyvern_veh",
      "twelfth_prime",
      "twelfth_blackfish_inf",
      "twelfth_blackfish_veh",
      "twelfth_blackfish_armed"
    };
    weapons[] = {};
    requiredVersion = 0.1;
    requiredAddons[] = {
      "A3_Air_F",
      "A3_Air_F_Beta",
      "A3_Weapons_F",
      "OPTRE_Core",
      "OPTRE_Vehicles_Air",
      "Splits_Functions"
    };
  };
};

/*
  ==============================================================================
  CfgVehicles
  ==============================================================================
  Each custom aircraft class inherits from a base class (e.g., Splits_Pelican_base),
  modifies textures, sets faction, and includes macros for more complex logic
  like extended spawn info or texture sets.
*/

class CfgVehicles {
  // -------------------------- Base Classes --------------------------
  class Splits_Pelican_base;

  class OPTRE_UNSC_hornet;

  class OPTRE_UNSC_falcon;
  class OPTRE_UNSC_falcon_armed;
  class OPTRE_UNSC_falcon_S;
  class OPTRE_UNSC_falcon_armed_S;

  class OPTRE_AV22_Sparrowhawk_Base;
  class OPTRE_AV22_Sparrowhawk;
  class OPTRE_AV22A_Sparrowhawk;
  class OPTRE_AV22B_Sparrowhawk;
  class OPTRE_AV22C_Sparrowhawk;

  // Wyvern
  class O_T_VTOL_02_infantry_dynamicLoadout_F;
  class O_T_VTOL_02_vehicle_dynamicLoadout_F;

  // AL-6
  class B_UAV_06_F;

  // blackfish
  class B_T_VTOL_01_infantry_F;
  class B_T_VTOL_01_vehicle_F;
  class B_T_VTOL_01_armed_F;

  // Nandao
  class MEU_F29_Nandao_VTOL;
  // ---------------------------------------------------------------------------
  //  Pelican (D77-TC)
  // ---------------------------------------------------------------------------
  class twelfth_d77_tc_pelican: Splits_Pelican_base {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    vehicleClass = "Air";
    author = "Weber";
    faction = "twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    OPTRE_canThrust = 1;
    OPTRE_minVelocity = 1.4;
    OPTRE_maxVelocity = 167;
    OPTRE_velocityMult = 1;
    crew = "OPTRE_UNSC_Marine_Soldier_Rifleman_AR"; // When we make our own faction be sure to change this
    displayName = "[12th] D77-TC Pelican";
    PELICAN_TEXTURESETS
    AIR_SP_INFO(Pelican,0,Troop Transport)
  };
  // ---------------------------------------------------------------------------
  //  AV-14 Hornet
  // ---------------------------------------------------------------------------
  class twelfth_hornet: OPTRE_UNSC_hornet {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    vehicleClass = "Air";
    author="Waylen";
    displayName="[12th] AV-14 Hornet";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    hiddenSelections[]={"camo1"};
    hiddenSelectionsTextures[]={
      "\x\12thMEU\addons\12th_aircraft\hornet\default\hull_co.paa"
    };
    class textureSources {
      class twelfth_hornet_tex_default {
        displayName="Default";
        author="Waylen";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\hornet\default\hull_co.paa"
        };
      };
      class twelfth_hornet_tex_asg {
        displayName="Air Superiority Grey";
        author="Wolfe";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\hornet\asg\hull_co.paa"
        };
      };
    };
    AIR_SP_INFO(Hornet,0,Base)
  };
  // ---------------------------------------------------------------------------
  //  UH-144 Falcon Variants
  // ---------------------------------------------------------------------------
  // Unarmed
  class twelfth_falcon_unarmed: OPTRE_UNSC_falcon {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] UH-144 Falcon Unarmed";
    AIR_SP_INFO(Falcon,0,Unarmed)
    FALCON_TEXTURESETS
  };
  // Armed
  class twelfth_falcon_armed: OPTRE_UNSC_falcon_armed {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] UH-144 Falcon Armed";
    AIR_SP_INFO(Falcon,1,20mm Cannon)
    FALCON_TEXTURESETS
  };
  // S variant (Side Gun) unarmed
  class twelfth_falcon_s_unarmed: OPTRE_UNSC_falcon_S {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] UH-144S Falcon Unarmed";
    AIR_SP_INFO(Falcon,2,Unarmed w/ Side Gun)
    FALCON_TEXTURESETS
  };
  // S variant armed
  class twelfth_falcon_s_armed: OPTRE_UNSC_falcon_armed_S {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] UH-144S Falcon Armed";
    AIR_SP_INFO(Falcon,3,20mm w/ Side Gun)
    FALCON_TEXTURESETS
  };
  // ---------------------------------------------------------------------------
  //  AV-22 Sparrowhawk Variants
  // ---------------------------------------------------------------------------
  class twelfth_sparrowhawk_m: OPTRE_AV22_Sparrowhawk {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AV-22M Sparrowhawk";
    hiddenSelections[] = {
      "camo1",
      "camo2",
      "camo3",
      "camo4",
      "camo5",
      "camo6",
      "camo7",
      "attach_Decal1",
      "attach_Decal2",
      "attach_noseLaser",
      "attach_CannonHeavy"
    };
    AIR_SP_INFO(Sparrowhawk,0,50mm Fixed | Cannon)
    SPARROWHAWK_TEXTURESETS
  };

  class twelfth_sparrowhawk_l: OPTRE_AV22A_Sparrowhawk {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AV-22L Sparrowhawk";
    hiddenSelections[] = {
      "camo1",
      "camo2",
      "camo3",
      "camo4",
      "camo5",
      "camo6",
      "camo7",
      "attach_Decal1",
      "attach_Decal2",
      "attach_noseCannon",
      "attach_CannonLight"
    };
    AIR_SP_INFO(Sparrowhawk,1,30mm Fixed | Laser)
    SPARROWHAWK_TEXTURESETS
  };

  class twelfth_sparrowhawk_ml: OPTRE_AV22B_Sparrowhawk {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AV-22ML Sparrowhawk";
    hiddenSelections[] = {
      "camo1",
      "camo2",
      "camo3",
      "camo4",
      "camo5",
      "camo6",
      "camo7",
      "attach_Decal1",
      "attach_Decal2",
      "attach_noseCannon",
      "attach_CannonHeavy"
    };
    AIR_SP_INFO(Sparrowhawk,2,50mm Fixed | Laser)
    SPARROWHAWK_TEXTURESETS
  };

  class twelfth_sparrowhawk: OPTRE_AV22C_Sparrowhawk {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AV-22 Sparrowhawk";
    hiddenSelections[] = {
      "camo1",
      "camo2",
      "camo3",
      "camo4",
      "camo5",
      "camo6",
      "camo7",
      "attach_Decal1",
      "attach_Decal2",
      "attach_noseLaser",
      "attach_CannonLight"
    };
    AIR_SP_INFO(Sparrowhawk,3,30mm Fixed | Cannon)
    SPARROWHAWK_TEXTURESETS
  };
  // ---------------------------------------------------------------------------
  //  Wyvern (Based on Tigris/VTOL)
  // ---------------------------------------------------------------------------
  // Infantry version
  class twelfth_wyvern_inf: O_T_VTOL_02_infantry_dynamicLoadout_F {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AVD-99IT Wyvern";
    hiddenSelections[]={
      "camo_1",
      "camo_2",
      "camo_3",
      "camo_4",
      "camo_5"
    };
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_01_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_02_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_r_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_l_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
    };
    class TextureSources {
      class twelfth_wyvern_tex_default {
        displayName="Default";
        author="Wolfe";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_01_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_02_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_r_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_l_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
        };
      };
      class twelfth_wyvern_asg_default {
        displayName="Air Superiority Grey";
        author="Wolfe";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\wyvern\asg\ext_01_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\asg\ext_02_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\asg\ext_03_r_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\asg\ext_03_l_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
        };
      };
    };
    AIR_SP_INFO(Wyvern,0,Infantry)
  };
  // Vehicle version
  class twelfth_wyvern_veh: O_T_VTOL_02_vehicle_dynamicLoadout_F {
    author="Waylen";
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    vehicleClass = "Air";
    displayName = "[12th] AVD-99VT Wyvern";
    hiddenSelections[]={
      "camo_1",
      "camo_2",
      "camo_3",
      "camo_4",
      "camo_5"
    };
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_01_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_02_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_l_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_r_co.paa",
      "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
    };
    class TextureSources {
      class twelfth_wyvern_tex_default {
        displayName="Default";
        author="Wolfe";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_01_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_02_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_l_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\ext_03_r_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
        };
      };
      class twelfth_wyvern_tex_asg {
        displayName="Air Superiority Grey";
        author="Wolfe";
        textures[]= {
          "\x\12thMEU\addons\12th_aircraft\asg\default\ext_01_co.paa",
          "\x\12thMEU\addons\12th_aircraft\asg\default\ext_02_co.paa",
          "\x\12thMEU\addons\12th_aircraft\asg\default\ext_03_l_co.paa",
          "\x\12thMEU\addons\12th_aircraft\asg\default\ext_03_r_co.paa",
          "\x\12thMEU\addons\12th_aircraft\wyvern\default\signs_co.paa"
        };
      };
    };
    AIR_SP_INFO(Wyvern,1,Vehicle)
  };

  /*class twelfth_prime: B_UAV_06_F {
    side=1;
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] AL-6 Prime";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Drones";
    crew="B_UAV_AI_F";
    typicalCargo[]={"B_UAV_AI_F"};
    class TransportItems {};
    class TransportMagazines {};
    class TransportWeapons {};
    hiddenSelections[]= {"Camo", "Medical"};
    hiddenSelectionsTextures[] = {
      QP(prime\medical\main_co.paa),
      QP(prime\medical\main_co.paa)
    };
    class TextureSources {
      class twelfth_prime_tex_default {
        displayname="Default";
        author="Waylen";
        factions[] = {"twelfth_MEU"};
        textures[]={
          QP(prime\medical\main_co.paa),
          QP(prime\medical\main_co.paa)
        };
      };
    };
    Camouflage=0;
    AIR_SP_INFO(Prime UAV,0,Base)
  };*/


  // ---------------------------------------------------------------------------
  //  Blackfish Variants
  // ---------------------------------------------------------------------------
  class twelfth_blackfish_inf: B_T_VTOL_01_infantry_F {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Blackfish (Infantry)";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    BLACKFISH_TEXTURESETS
    AIR_SP_INFO(Blackfish,0,Troop Transport)
  };

  class twelfth_blackfish_veh: B_T_VTOL_01_vehicle_F {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Blackfish (Vehicle)";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    BLACKFISH_TEXTURESETS
    AIR_SP_INFO(Blackfish,1,Vehicle Transport)
  };

  class twelfth_blackfish_armed: B_T_VTOL_01_armed_F {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Blackfish (Armed)";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Rotary";
    BLACKFISH_TEXTURESETS
    AIR_SP_INFO(Blackfish,2,Gunship)
  };

  class twelfth_nandao: MEU_F29_Nandao_VTOL {
    scope=2;
    scopeCurator=2;
    author="Weber";
    displayName="[12th] F-29 Nandao";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_FixedWing";
    AIR_SP_INFO(Nandao,0,Base)
  };
};
