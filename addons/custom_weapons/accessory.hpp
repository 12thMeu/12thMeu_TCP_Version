class ACE_optic_LRPS_2D;
class ItemCore;
class InventoryMuzzleItem_Base_F;
class InventoryItem_Base_F;
class InventoryOpticsItem_Base_F;
class PrototypeBarrel: ItemCore
	{
		scope = 2;
		displayName = "Heavy barrel";
		picture="x\12thMEU\addons\Custom_Weapons\data\BarrelPreview.paa";
		model = "x\12thMEU\addons\Custom_Weapons\data\PrototypeBarrel.p3d";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=10;
			
			class MagazineCoef
			{
				initSpeed 		= 1.2;
			};
			
			class AmmoCoef
			{
				// bullet ballistic modifiers
				hit				= 10;
				typicalSpeed	= 1;
				airFriction		= 1;
			}; 
			soundTypeIndex		= 1; /// defines the position in sound[] array in the rifle
			muzzleEnd = "zaslehPoint";
			alternativeFire = "Zasleh2";
			class MuzzleCoef
			{
				dispersionCoef = "1.0f";
				artilleryDispersionCoef = "1.0f";
				fireLightCoef = "1f";
				recoilCoef = "1.0f";
				recoilProneCoef = "1.0f";
				minRangeCoef = "1.0f";
				minRangeProbabCoef = "1.0f";
				midRangeCoef = "1.0f";
				midRangeProbabCoef = "1.0f";
				maxRangeCoef = "1.0f";
				maxRangeProbabCoef = "1.0f";
			};
		};
	};

class PrototypeOptics: ACE_optic_LRPS_2D
{
	scope = 2;
	author = "SamanthaNix";
	displayName = "Tri-Sight Prototype Optics";
	descriptionShort = "Tri-sight developed in conjunction with the prototype Laser";
	picture="x\12thMEU\addons\Custom_Weapons\data\SightPreview.paa";
	model = "x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
	class ItemInfo: InventoryOpticsItem_Base_F
	{
		mass = 2;
		opticType = 1;
		optics = 1;
		modelOptics = "x\12thMEU\addons\Custom_Weapons\data\PrototypeScope.p3d";
		class OpticsModes
		{
			class PrototypeScope
			{
				ACE_ScopeAdjust_Horizontal[] = {-8,8};
				ACE_ScopeAdjust_HorizontalIncrement = 0.1;
				ACE_ScopeAdjust_Vertical[] = {0,27};
				ACE_ScopeAdjust_VerticalIncrement = 0.1;
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.0555;			
				opticsZoomMax = 1;
				opticsZoomInit = 0.5;
				discreteinitIndex = 0;
				discreteDistance[] = {100,300,400,500,600,700,800,900,1000,1500,2000};
				discreteDistanceInitIndex = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 10000;
				discreteFov[] = {0.1,0.01};
				modelOptics[] = {"x\12thMEU\addons\Custom_Weapons\data\Scope_2x.p3d"};
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal","NVG","Ti"};
				thermalMode[]={1,0};
			};
		};
	};
	intertia = 0.1;
};