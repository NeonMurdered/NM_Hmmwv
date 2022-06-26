modded class PlayerBase extends ManBase
{
	 override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) 
		{
			DayzPlayerItemBehaviorCfg heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
			heavyItemBehaviour.SetHeavyItems();

			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_Wheel", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					        "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_Wheel_destroyed", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_doors_Driver", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_Doors_coDriver", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_doors_cargo1", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_doors_cargo2", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1035_doors_hood", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,			            "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1151_doors_trunk", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,			            "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1151_doors_Driver", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1151_Doors_coDriver", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1151_doors_cargo1", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("Hmmwv_M1151_doors_cargo2", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					    "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		}
        super.Init();
    }
}
