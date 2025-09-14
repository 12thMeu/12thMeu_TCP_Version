#pragma hemtt suppress pw3_padded_arg config
#include "config_macros.hpp"

/*
  ==============================================================================
  config.cpp

  This file defines:
    - The 12th MEU custom uniforms (both vehicle display classes and weapon/uniform classes).
    - The 12th MEU custom helmets (standard, NV variants, pilot helmets, etc.).
    - CfgPatches: Lists every uniform & helmet class for Arma’s engine.
    - CfgVehicles: Configures the actual wearable units for uniforms (the “vehicle” class).
    - CfgWeapons: Configures the “inventory” items for these uniforms & helmets.
    - XtdGearModels & XtdGearInfos for extended arsenal integration.

  Key Points:
    - The macros in `config_macros.hpp` generate a large number of uniform & helmet 
      variants: standard, forest, dark (drk), urban, plus roles like medic, HQ, 1PL, 
      2PL, etc.
    - Some items are commented out pending final textures or usage decisions.

  ==============================================================================
*/

class CfgPatches {
  class twelfth_armor {
    /*
      units[]: All the placeable "vehicle" classes for uniforms in the editor 
               or gear lists.  
      weapons[]: The “weapon” (i.e., uniform item) classes.  
    */
    units[]= {
      "twelfth_odst_uniform_veh",
      "twelfth_uni_ng_base_veh",
      "twelfth_uni_ng_std_veh",
      "twelfth_uni_ng_std_med_veh",
      "twelfth_uni_ng_std_1pl_veh",
      "twelfth_uni_ng_std_1pl_med_veh",
      "twelfth_uni_ng_std_2pl_veh",
      "twelfth_uni_ng_std_2pl_med_veh",
      "twelfth_uni_ng_std_lpl_veh",
      "twelfth_uni_ng_std_lpl_med_veh",
      "twelfth_uni_ng_std_hq_veh",
      "twelfth_uni_ng_std_hq_med_veh",
      "twelfth_uni_ng_win_veh",
      "twelfth_uni_ng_win_med_veh",
      "twelfth_uni_ng_win_1pl_veh",
      "twelfth_uni_ng_win_1pl_med_veh",
      "twelfth_uni_ng_win_2pl_veh",
      "twelfth_uni_ng_win_2pl_med_veh",
      "twelfth_uni_ng_win_lpl_veh",
      "twelfth_uni_ng_win_lpl_med_veh",
      "twelfth_uni_ng_win_hq_veh",
      "twelfth_uni_ng_win_hq_med_veh",
      "twelfth_uni_ng_drk_veh",
			"twelfth_uni_ng_drk_med_veh",
			"twelfth_uni_ng_drk_1pl_veh",
			"twelfth_uni_ng_drk_1pl_med_veh",
			"twelfth_uni_ng_drk_2pl_veh",
			"twelfth_uni_ng_drk_2pl_med_veh",
			"twelfth_uni_ng_drk_lpl_veh",
			"twelfth_uni_ng_drk_lpl_med_veh",
			"twelfth_uni_ng_drk_hq_veh",
			"twelfth_uni_ng_drk_hq_med_veh",
      "twelfth_clothes_std_veh",
      "twelfth_clothes_std_rolled_veh",
      "twelfth_clothes_desert_veh",
      "twelfth_clothes_desert_rolled_veh",
      "twelfth_instructor_uniform_veh",
      "twelfth_dress_navy_veh"
    };
    weapons[]= {
      "twelfth_odst_uniform_wep",
      "twelfth_uni_ng_base_wep",
      "twelfth_uni_ng_std_wep",
      "twelfth_uni_ng_std_med_wep",
      "twelfth_uni_ng_std_1pl_wep",
      "twelfth_uni_ng_std_1pl_medweph",
      "twelfth_uni_ng_std_2pl_wep",
      "twelfth_uni_ng_std_2pl_medweph",
      "twelfth_uni_ng_std_lpl_wep",
      "twelfth_uni_ng_std_lpl_medweph",
      "twelfth_uni_ng_std_hq_wep",
      "twelfth_uni_ng_std_hq_med_wep",
      "twelfth_uni_ng_win_wep",
      "twelfth_uni_ng_win_med_wep",
      "twelfth_uni_ng_win_1pl_wep",
      "twelfth_uni_ng_win_1pl_medweph",
      "twelfth_uni_ng_win_2pl_wep",
      "twelfth_uni_ng_win_2pl_medweph",
      "twelfth_uni_ng_win_lpl_wep",
      "twelfth_uni_ng_win_lpl_medweph",
      "twelfth_uni_ng_win_hq_wep",
      "twelfth_uni_ng_win_hq_med_wep",
      "twelfth_uni_ng_drk_wep",
      "twelfth_uni_ng_drk_med_wep",
      "twelfth_uni_ng_drk_1pl_wep",
      "twelfth_uni_ng_drk_1pl_medweph",
      "twelfth_uni_ng_drk_2pl_wep",
      "twelfth_uni_ng_drk_2pl_medweph",
      "twelfth_uni_ng_drk_lpl_wep",
      "twelfth_uni_ng_drk_lpl_medweph",
      "twelfth_uni_ng_drk_hq_wep",
			"twelfth_uni_ng_win_hq_med_wep",
      "twelfth_helm_base",
      "twelfth_helm_std",
      "twelfth_helm_std_med",
      "twelfth_helm_std_1pl_ftl",
      "twelfth_helm_std_1pl_sl",
      "twelfth_helm_std_1pl_pl",
      "twelfth_helm_std_1pl_med",
      "twelfth_helm_std_2pl_ftl",
      "twelfth_helm_std_2pl_sl",
      "twelfth_helm_std_2pl_pl",
      "twelfth_helm_std_2pl_med",
      "twelfth_helm_std_hq_ftl",
      "twelfth_helm_std_hq_sl",
      "twelfth_helm_std_hq_pl",
      "twelfth_helm_std_hq_med",
      "twelfth_helm_std_lpl_ftl",
      "twelfth_helm_std_lpl_sl",
      "twelfth_helm_std_lpl_pl",
      "twelfth_helm_std_lpl_med",
      "twelfth_helm_std_nv",
      "twelfth_helm_std_med_nv",
      "twelfth_helm_std_1pl_ftl_nv",
      "twelfth_helm_std_1pl_sl_nv",
      "twelfth_helm_std_1pl_pl_nv",
      "twelfth_helm_std_1pl_med_nv",
      "twelfth_helm_std_2pl_ftl_nv",
      "twelfth_helm_std_2pl_sl_nv",
      "twelfth_helm_std_2pl_pl_nv",
      "twelfth_helm_std_2pl_med_nv",
      "twelfth_helm_std_hq_ftl_nv",
      "twelfth_helm_std_hq_sl_nv",
      "twelfth_helm_std_hq_pl_nv",
      "twelfth_helm_std_hq_med_nv",
      "twelfth_helm_std_lpl_ftl_nv",
      "twelfth_helm_std_lpl_sl_nv",
      "twelfth_helm_std_lpl_pl_nv",
      "twelfth_helm_std_lpl_med_nv",
      "twelfth_helm_win",
      "twelfth_helm_win_med",
      "twelfth_helm_win_1pl_ftl",
      "twelfth_helm_win_1pl_sl",
      "twelfth_helm_win_1pl_pl",
      "twelfth_helm_win_1pl_med",
      "twelfth_helm_win_2pl_ftl",
      "twelfth_helm_win_2pl_sl",
      "twelfth_helm_win_2pl_pl",
      "twelfth_helm_win_2pl_med",
      "twelfth_helm_win_hq_ftl",
      "twelfth_helm_win_hq_sl",
      "twelfth_helm_win_hq_pl",
      "twelfth_helm_win_hq_med",
      "twelfth_helm_win_lpl_ftl",
      "twelfth_helm_win_lpl_sl",
      "twelfth_helm_win_lpl_pl",
      "twelfth_helm_win_lpl_med",
      "twelfth_helm_win_nv",
      "twelfth_helm_win_med_nv",
      "twelfth_helm_win_1pl_ftl_nv",
      "twelfth_helm_win_1pl_sl_nv",
      "twelfth_helm_win_1pl_pl_nv",
      "twelfth_helm_win_1pl_med_nv",
      "twelfth_helm_win_2pl_ftl_nv",
      "twelfth_helm_win_2pl_sl_nv",
      "twelfth_helm_win_2pl_pl_nv",
      "twelfth_helm_win_2pl_med_nv",
      "twelfth_helm_win_hq_ftl_nv",
      "twelfth_helm_win_hq_sl_nv",
      "twelfth_helm_win_hq_pl_nv",
      "twelfth_helm_win_hq_med_nv",
      "twelfth_helm_win_lpl_ftl_nv",
      "twelfth_helm_win_lpl_sl_nv",
      "twelfth_helm_win_lpl_pl_nv",
      "twelfth_helm_win_lpl_med_nv",
      "twelfth_pilot_helm_Standard",
      "twelfth_pilot_helm_Desert",
      "twelfth_pilot_helm_Jungle",
      "twelfth_pilot_helm_Winter",
      "twelfth_aa_helm",
      "twelfth_cap_std",
      "twelfth_cap_desert",
      "twelfth_cap_twelfth_logo",
      "twelfth_cap_news",
      "twelfth_cap_news_2",
      "twelfth_cap_pale_horse",
      "twelfth_cap_pale_horse_2",
      "twelfth_boonie_std",
	  "twelfth_boonie_desert",
      "twelfth_boonie_forest",
      "twelfth_clothes_std_wep",
      "twelfth_clothes_std_rolled_wep",
      "twelfth_clothes_desert_wep",
      "twelfth_clothes_desert_rolled_wep",
      "twelfth_dress_navy_wep",
      "twelfth_instructor_uniform_wep"
    };
    requiredAddons[]= {
      "A3_Armor_F_Beta",
      "A3_Soft_F",
      "OPTRE_UNSC_Units",
      "DMNS_Units",
      "cba_main",
      "ace_main",
      "19th_Fleet_Armor"
    };
  };
};

// -----------------------------------------------------------------------------
//  CfgVehicles
// -----------------------------------------------------------------------------
class CfgVehicles {
// Base classes from Arma or third-party mods
  class B_Soldier_base_F;
  class B_CTRG_Soldier_2_F;
  class OPTRE_UNSC_Army_Soldier_WDL;
  class OPTRE_UNSC_Army_Soldier_R_WDL;
  class OPTRE_UNSC_Army_Soldier_S_WDL;
  class OPTRE_UNSC_Army_Soldier_DressGray;
  class OPTRE_UNSC_CH252A_Helmet_Base;
  class OPTRE_UNSC_CH252A_Helmet_dp;
  class 19th_ODST;
  
  // ---------------------------------------------------------------------------
  //  twelfth_uni_ng_base_veh
  // ---------------------------------------------------------------------------
  /*
    A base class for your new-gen (ng) armor sets (chest, arms, legs, etc.).
    Other macros or classes inherit from this to create specific camos/roles.
  */
  class twelfth_uni_ng_base_veh: B_Soldier_base_F {
    scope=0;
    scopeArsenal=0;
    author="Waylen";
    displayName="[12th] Armor Base (DON'T USE)";
    model="\19th_H2A_armor\19th_H2A_marines.p3d";
    hiddenSelections[] = {
      "camo",
      "camo1",
      "camo2",
      "camo3",
      "camo4"
    };
    hiddenSelectionsTextures[] = {
      QP(uniforms\armor\std\chest_co.paa),
      QP(uniforms\armor\std\arms_co.paa),
      QP(uniforms\armor\std\legs_co.paa),
      QP(uniforms\armor\std\bdu_co.paa),
      QP(uniforms\armor\std\misc_co.paa)
    };
  };

  /*class twelfth_dress_navy_veh: OPTRE_UNSC_Army_Soldier_DressGray {
    dlc="OPTRE";
    author="Waylen";
    uniformClass="twelfth_dress_navy_wep";
    hiddenSelections[] = {"camo1", "insignia", "clan", "ODST"};
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_armor\uniforms\dress\dress_uni_navy_co.paa"
    };
  };*/

  //class twelfth_instructor_uniform_veh: B_CTRG_Soldier_2_F
  //{
  //	author = "Sammy";
  //	displayName = "";
  //	uniformClass = "twelfth_instructor_uniform_wep";
  //
  //	model = "\A3\characters_F\BLUFOR\b_soldier_02.p3d";
  //
  //	hiddenSelectionsTextures[]=
  //	{
  //		QP(uniforms\extra\instructor_pants.paa),
  //		QP(uniforms\extra\basic.paa)
  //	};
  //};

  // ---------------------------------------------------------------------------
  //  twelfth_odst_uniform_veh
  // ---------------------------------------------------------------------------
  /*
    A special ODST uniform referencing a 19th ODST base. If you only need 
    one ODST variant, there’s no macro overhead. If you plan many variants, 
    you might consider macros.
  */
  class twelfth_odst_uniform_veh: 19th_ODST {
    scope=1;
    scopeArsenal=0;
    author="Waylen";
    model="ODST\ODST_Uniform_F.p3d";
    hiddenSelections[]={"camo1", "camo2"};
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\odst\odst_top.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\odst\odst_pants.paa"
    };
  };

  /*class twelfth_clothes_std_veh: OPTRE_UNSC_Army_Soldier_WDL {
    uniformClass="twelfth_clothes_std_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };

  class twelfth_clothes_std_short_veh: OPTRE_UNSC_Army_Soldier_S_WDL {
    uniformClass="twelfth_clothes_std_short_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_2_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };

  class twelfth_clothes_std_rolled_veh: OPTRE_UNSC_Army_Soldier_R_WDL {
    uniformClass="twelfth_clothes_std_rolled_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_standard_2_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };

  class twelfth_clothes_desert_veh: OPTRE_UNSC_Army_Soldier_WDL {
    author="Waylen";
    uniformClass="twelfth_clothes_desert_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };

  class twelfth_clothes_desert_short_veh: OPTRE_UNSC_Army_Soldier_S_WDL {
    author="Waylen";
    uniformClass="twelfth_clothes_desert_short_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_2_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };

  class twelfth_clothes_desert_rolled_veh: OPTRE_UNSC_Army_Soldier_R_WDL {
    author="Waylen";
    uniformClass="twelfth_clothes_desert_rolled_wep";
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_co.paa",
      "\x\12thMEU\addons\12th_armor\uniforms\clothes\clothes_desert_2_co.paa"
    };
    hiddenSelections[]= {
      "camo",
      "camo2",
      "insignia",
      "clan",
      "A_BaseLeg"
    };
  };*/ //Waiting textures

// Macro expansions for the new-gen armor sets, e.g. standard, drk, forest, urban
  ALL_UNI_VEH(std,std)
  ALL_UNI_VEH(drk,drk)
  ALL_UNI_VEH(forest,std)
  ALL_UNI_VEH(urban,std)
  ALL_UNI_VEH(desert,std)

};

// -----------------------------------------------------------------------------
//  CfgWeapons
// -----------------------------------------------------------------------------
class CfgWeapons {
  class H_Cap_oli;
  class H_Booniehat_oli;
  class UniformItem;
  class ItemInfo;
  class Uniform_Base;
  class H_HelmetB;
  class HeadgearItem;
  class OPTRE_UNSC_PatrolCap_Army;
  class OPTRE_UNSC_PatrolCap_Marines;
  class OPTRE_UNSC_Army_Uniform_WDL;
  class OPTRE_UNSC_Army_Uniform_R_WDL;
  class OPTRE_UNSC_Army_Uniform_S_WDL;
  class OPTRE_UNSC_Dress_Uniform_gray;
  class U_B_CombatUniform_mcam_tshirt;
  // Base uniform item for new-gen armor
  class twelfth_uni_ng_base_wep: Uniform_Base {
    author="Waylen";
    scope=0;
    scopeArsenal=0;
    displayName="[12th] Armor Base Weapon (DON'T USE)";
    model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
    ACE_GForceCoef=0.4;
    class ItemInfo: UniformItem {
      uniformModel="-";
      uniformClass="twelfth_uni_ng_base_veh";
      containerClass="Supply100";
      mass=1;
      uniformType = "Neopren";
      allowedSlots[]={"701","801","901"};
      armor=20;
    };
  };


  /*class twelfth_dress_navy_wep: OPTRE_UNSC_Dress_Uniform_gray {
    dlc="OPTRE";
    author="Waylen";
    displayName="[12th] Dress Uniform (Navy)";
    picture="";
    class ItemInfo: ItemInfo {
      uniformClass="twelfth_dress_navy_veh";
    };
  };*/ //Awaiting textures

  //class twelfth_instructor_uniform_wep: U_B_CombatUniform_mcam_tshirt {
  //  author = "Sammy";
  //  displayName = "[12th] AIC Instructor Uniform";
  //  picture = "";
  //  scope = 2;
  //  scopeArsenal = 2;
  //  model = "\A3\Characters_F\Common\Suitpacks\suitpack_original_F.p3d";
 	//	hiddenSelections[]=
 	//	{
 	//		"camo"
 	//	};
 	//	hiddenSelectionsTextures[]=
 	//	{
 	//		QP(uniforms\extra\basic.paa)
 	//	};
  //  class ItemInfo: ItemInfo {
  //    uniformModel = "-";
  //    uniformClass = "twelfth_instructor_uniform_veh";
  //    containerClass = "Supply100";
  //    mass = 1;
  //    uniformType = "Neopren";
  //    allowedSlots[] = {"701","801","901"};
  //    armor=20;
  //  };
  //};

  // Example ODST uniform item referencing twelfth_odst_uniform_veh
  class twelfth_odst_uniform_wep: Uniform_Base {
    scope=2;
    scopeArsenal=2;
    author="Waylen";
    picture="";
    model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
    displayName="[12th][ODST] Armor";
    ACE_GForceCoef = 0.4;
    class ItemInfo: UniformItem {
      uniformModel="-";
      uniformClass="twelfth_odst_uniform_veh";
      containerClass="Supply100";
      mass=1;
      uniformType = "Neopren";
      allowedSlots[]={"701","801","901"};
      armor=20;
    };
  };
  // Army Aviator helmet example: CH252AA
  class twelfth_aa_helm: OPTRE_UNSC_CH252A_Helmet_Base {
    scope=2;
    scopeArsenal=2;
    author="Waylen & A2S";
    picture="";
    displayName="[12th][CH252AA] Helmet";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0;
    model="\OPTRE_UNSC_Units\Army\aa_helmet.p3d";
    optreHUDStyle = "ODST_1";
    class ItemInfo: HeadgearItem{
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      uniformModel="\OPTRE_UNSC_Units\Army\aa_helmet.p3d";
      hiddenSelections[]={ "camo" };
      hiddenSelectionsTextures[]={
        "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
      };
      class HitpointsProtectionInfo{
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
    hiddenSelections[]={ "camo" };
    hiddenSelectionsTextures[]={
      "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
    };
  };

  // Depolarized variant of the AA helmet
  class twelfth_aa_helm_dp: OPTRE_UNSC_CH252A_Helmet_dp {
    scope=2;
    scopeArsenal=0;
    author="Waylen & A2S";
    picture="";
    displayName="[12th][CH252AA] Helmet DP";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
         model="\OPTRE_UNSC_Units\Army\aa_helmet_dp.p3d";
    optreHUDStyle = "ODST_1";
    class ItemInfo: HeadgearItem{
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      uniformModel="\OPTRE_UNSC_Units\Army\aa_helmet_dp.p3d";
      hiddenSelections[]={ "camo" };
      hiddenSelectionsTextures[]={
        "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
      };
      class HitpointsProtectionInfo{
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
    hiddenSelections[]={ "camo" };
    hiddenSelectionsTextures[]={
      "\x\12thMEU\addons\12th_armor\helmets\aa\AA_Helmet_12th_CO.paa"
    };
  };

  // TODO: CLEAN THIS (the clothes section) UP

  /*class twelfth_clothes_std_wep: OPTRE_UNSC_Army_Uniform_WDL {
    author="Waylen";
    displayName="[12th][Clothes] Uniform";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_std_veh";
    };
  };

  class twelfth_clothes_std_short_wep: OPTRE_UNSC_Army_Uniform_S_WDL {
    author="Waylen";
    displayName="[12th][Clothes] Uniform Short";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_std_short_veh";
    };
  };

  class twelfth_clothes_std_rolled_wep: OPTRE_UNSC_Army_Uniform_R_WDL {
    author="Waylen";
    displayName="[12th][Clothes] Uniform Rolled";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_std_rolled_veh";
    };
  };

  class twelfth_clothes_desert_wep: OPTRE_UNSC_Army_Uniform_WDL {
    author="Waylen";
    displayName="[12th][Clothes][Desert] Uniform";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_desert_veh";
    };
  };

  class twelfth_clothes_desert_short_wep: OPTRE_UNSC_Army_Uniform_S_WDL {
    author="Waylen";
    displayName="[12th][Clothes][Desert] Uniform Short";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_desert_short_veh";
    };
  };

  class twelfth_clothes_desert_rolled_wep: OPTRE_UNSC_Army_Uniform_R_WDL {
    author="Waylen";
    displayName="[12th][Clothes][Desert] Uniform Rolled";
    picture="";
    class ItemInfo: ItemInfo {
      containerClass="Supply100";
      mass=40;
      uniformClass="twelfth_clothes_desert_rolled_veh";
    };
  };

  //-CAPS-------------------------------------------------------------

  class twelfth_cap_std: OPTRE_UNSC_PatrolCap_Army {
    author="Waylen";
    picture="";
    displayName="[12th][Caps] Patrol Cap";
    hiddenSelections[] = { "camo1", "hide_army" };
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_armor\helmets\cap\cap_standard_co.paa"
    };
    class ItemInfo: ItemInfo {
      hiddenSelections[] = { "camo1", "hide_army" };
      hiddenSelectionsTextures[] = {
        "\x\12thMEU\addons\12th_armor\helmets\cap\cap_standard_co.paa"
      };
    };
  };

  class twelfth_cap_desert: OPTRE_UNSC_PatrolCap_Marines {
    author="Waylen";
    picture="";
    displayName="[12th][Caps][Desert] Patrol Cap";
    hiddenSelections[] = { "camo1", "hide_army" };
    hiddenSelectionsTextures[] = {
      "\x\12thMEU\addons\12th_armor\helmets\cap\cap_desert_co.paa"
    };
    class ItemInfo: ItemInfo {
      hiddenSelections[] = { "camo1", "hide_army" };
      hiddenSelectionsTextures[] = {
        "\x\12thMEU\addons\12th_armor\helmets\cap\cap_desert_co.paa"
      };
    };
  };
*/

  /*
    Boonie Hat macro expansions. 
    BOONIE_WEP(std)
    BOONIE_WEP(forest)

    Patrol Cap expansions.
    PATROLCAP_WEP(std)
    PATROLCAP_WEP(forest)
  */
  BOONIE_WEP(std)
  BOONIE_WEP(forest)
  BOONIE_WEP(desert)

  PATROLCAP_WEP(std)
  PATROLCAP_WEP(forest)
  PATROLCAP_WEP(desert)


  //-HELMETS----------------------------------------------------------

  class twelfth_odst_helm: H_HelmetB {
    scope=2;
    scopeArsenal=2;
    author="Waylen";
    picture="";
    displayName="[12th][ODST] Helmet";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
    model="\ODST\ODST_helm_F.p3d";
    hiddenSelections[]= { "camo" };
    hiddenSelectionsTextures[]= {
      "\x\12thMEU\addons\12th_armor\helmets\odst\odst_helm.paa"
    };
    class ItemInfo: HeadgearItem {
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
      uniformModel="\ODST\ODST_helm_F.p3d";
      hiddenSelections[]={"camo"};
      hiddenSelectionsTextures[]= {
        "\x\12thMEU\addons\12th_armor\helmets\odst\odst_helm.paa"
      };
    };
  };

  class twelfth_helm_base: H_HelmetB {
    scope=0;
    author="Waylen";
    scopeArsenal=0;
    displayName="[12th] Helmet Base (DON'T USE)";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
    model="\halo_marine\halo_helm_01";
    picture="";
    class ItemInfo: HeadgearItem {
      uniformModel="\halo_marine\halo_helm_01";
      mass=40;
      modelSides[]={6};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };

  class twelfth_pilot_helm_base: H_HelmetB {
    scope=0;
    author="Waylen";
    scopeArsenal=0;
    displayName="[12th] Pilot Helmet Base (DON'T USE)";
    ace_hearing_protection=1;
    ace_hearing_lowerVolume=0.30000001;
    model="A3\Characters_F\Common\headgear_helmet_heli";
    picture="";
    class ItemInfo: HeadgearItem {
      uniformModel="A3\Characters_F\Common\headgear_helmet_heli";
      mass=30;
      modelSides[]={3,1};
      passThrough=0.1;
      class HitpointsProtectionInfo {
        class Head {
          hitpointName="HitHead";
          armor=20;
          passThrough=0.1;
        };
      };
    };
  };
  

  //-MACRO CALLS------------------------------------------------------

  /*CAP_B(twelfth_logo,    "[12th][Caps] Cap (12th Logo)")
  CAP_B(news,         "[12th][Caps] Cap (News)")
  CAP_B(news_2,       "[12th][Caps] Cap (News 2)")
  CAP_B(pale_horse,   "[12th][Caps] Cap (Pale Horse)")
  CAP_B(pale_horse_2, "[12th][Caps] Cap (Pale Horse 2)")*/

  //-UNIFORM-WEPS-----------------------------------------------------
  ALL_UNI_WEP(std)
  ALL_UNI_WEP(forest)
  ALL_UNI_WEP(drk)
  ALL_UNI_WEP(urban)
  ALL_UNI_WEP(desert)

  //-HELMETS----------------------------------------------------------
  ALL_HELM(std)

  // Pilot Helmets
  PILOT_HELM(default, "[12th][Pilot] Helmet",default,default,default,default,default)
};

// -----------------------------------------------------------------------------
//  XtdGearModels & XtdGearInfos
// -----------------------------------------------------------------------------
/*
  These define extended gear categories for UI or ACE arsenal expansions.
  - e.g. "twelfth_base_helms" with options "visor","camo","element","role".
*/
class XtdGearModels {
  class CfgWeapons {
    // Helmets
    class twelfth_patrolcaps {
      label = "12th Patrol Caps";
      options[] = {"camo"};
      class camo {
        alwaysSelectable = 1;
        label = "Camoflauge";
        values[] = {"std", "forest","desert"};
        class forest {label="Standard"; image=XTP(forest);};
        class std {label = "MARPAT"; image=XTP(std);};
		class desert {label = "Desert"; image=XTP(desert);};
      };
    };

    class twelfth_boonies {
      label = "12th Boonie Hats";
      options[] = {"camo"};
      class camo {
        alwaysSelectable = 1;
        label = "Camoflauge";
        values[] = {"std", "forest","desert"};
        class forest {label="Standard"; image=XTP(forest);};
        class std {label = "MARPAT"; image=XTP(std);};
		class desert {label = "Desert"; image=XTP(desert);};
      };
    };

    class twelfth_base_helms {
      label="12th Infantry Helmets";
      options[] = {"visor","camo","element","role"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"std"};
        class std {label="Standard";};
      };
      class element {
        alwaysSelectable = 1;
        label="Element";
        values[]={"na","hq","1pl","2pl","lpl"};
        class na  {label="None";};
        class hq  {label="HQ";  image=XTP(athena);};
        class 1pl {label="1PLT";image=XTP(1pl);};
        class 2pl {label="2PLT";image=XTP(2pl);};
        class lpl {label="LOGI";image=XTP(chaos);};
      };
      class role {
        alwaysSelectable = 1;
        label="MOS";
        values[]={"na","med","ftl","sl","pl","psg"};
        class na  {label="None";     image=XTP(role);};
        class pl  {label="PLT LDR";  image=XTP(role_pl);};
        class psg {label="PLT SGT";  image=XTP(role_psg);};
        class ftl {label="FTL";      image=XTP(role_ftl);};
        class sl  {label="SQD LDR";  image=XTP(role_sl);};
        class med {label="Corpsman"; image=XTP(med);};
      };
      class visor {
        alwaysSelectable = 1;
        label="Visor";
        values[]={"Yes", "No"};
      };
    };

    // Uniforms
    class twelfth_base_uniforms {
      label="12th Infantry Uniforms";
      options[] = {"camo", "element","role"};
      class camo {
        alwaysSelectable = 1;
        label="Camouflage";
        values[]={"forest", "std", "forest90", "urban", "drk", "desert"};
        class forest {label="Standard";     image=XTP(forest);};
        class std {label="MARPAT"; image=XTP(std);};
        class forest90 {label="Forest90";     image=XTP(forest90);};
        class urban {label="Urban";     image=XTP(urban);}; //maybe winter?? will need to look into new armor pieces
        class drk {label="VBSS";     image=XTP(vbss);};
		class desert {label="Desert";     image=XTP(desert);};
      };
      class element {
        alwaysSelectable = 1;
        label="Element";
        values[]={"na","hq","1pl","2pl","lpl"};
        class na  {label="None";};
        class hq  {label="HQ";  image=XTP(athena);};
        class 1pl {label="1PLT"; image=XTP(1pl);};
        class 2pl {label="2PLT";   image=XTP(2pl);};
        class lpl {label="LOGI";   image=XTP(chaos);};
      };
      class role {
        alwaysSelectable = 1;
        label="MOS";
        values[]={"na","med"};
        class na  {label="None";};
        class med {label="Corpsman"; image=XTP(med);};
      };
    };
  };
};

class XtdGearInfos {
  class CfgWeapons {
    // THIS IS WHERE EXTENDED ARSENAL PULLS INFO FOR THE SELECTIONS FROM
    //-------------------------------------- Uniforms
    
    ALL_UNI_GI(std)
    ALL_UNI_GI(drk)
    ALL_UNI_GI(forest)
    ALL_UNI_GI(urban)
	ALL_UNI_GI(desert)

    // Boonies

    BOONIE_GI(std)
    BOONIE_GI(forest)
	BOONIE_GI(desert)      

    // Patrol caps

    PATROLCAP_GI(std)
    PATROLCAP_GI(forest)
	PATROLCAP_GI(desert)
    //-------------------------------------- Helmets 

    ALL_HELM_GI(std)
    //ALL_HELM_GI(drk)

  };
};
