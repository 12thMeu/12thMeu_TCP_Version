#pragma hemtt suppress pw3_padded_arg config
#include "spawn_info.hpp"
#include "config_macros.hpp"


class CfgPatches {
  class twelfth_vehicles_marshall {
    units[] = {
      "twelfth_marshall",
    };
    weapons[] = {};
    requiredVersion=0.1;
  };
};

class CfgVehicles {

  class B_APC_Wheeled_01_cannon_F;


  //-MARSHALL---------------------------------------------------------

  /*class twelfth_marshall: B_APC_Wheeled_01_cannon_F {
    scope=2;
    scopeCurator=2;
    author="Waylen";
    displayName="[12th] Marshall IFV";
    faction="twelfth_MEU";
    editorCategory="twelfth_MEU";
    editorSubcategory="twelfth_MEU_Armor";
    crew="OPTRE_UNSC_Army_Soldier_Crewman_WDL";
    typicalCargo[]= { "" };
    class TransportItems {};
    class TransportMagazines {};
    class TransportWeapons {};
    hiddenSelections[]= {
      "camo1",
      "camo2",
      "camo3",
      "CamoNet",
      "CamoSlat"
    };
    hiddenSelectionsTextures[]={
      QP(marshall\default\base_co.paa),
      QP(marshall\default\adds_co.paa),
      QP(marshall\default\tows_co.paa),
      "a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
      "a3\Armor_F\Data\cage_olive_CO.paa"
    };
    MARSHALL_SP_INFO(0,Base)
    class textureSources {
      class default {
        displayName="Default";
        author="Waylen";
        textures[] = {
          QP(marshall\default\base_co.paa),
          QP(marshall\default\adds_co.paa),
          QP(marshall\default\tows_co.paa),
          "a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
          "a3\Armor_F\Data\cage_olive_CO.paa"
        };
      };
      class winter {
        displayName="Winter";
        author="Waylen";
        textures[] = {
          QP(marshall\winter\base_co.paa),
          QP(marshall\winter\adds_co.paa),
          QP(marshall\winter\tows_co.paa),
          QP(marshall\winter\camonet_co.paa),
          "a3\Armor_F\Data\cage_olive_CO.paa"
        };
      };
    };
  };
*/
}; 
