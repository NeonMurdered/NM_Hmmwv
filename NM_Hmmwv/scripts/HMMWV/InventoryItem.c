class Hmmwv_M1035_Wheel extends CarWheel
{
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "Hmmwv_M1035_Wheel":
				newWheel = "Hmmwv_M1035_Wheel_destroyed";
			break;
		}
		if ( newWheel != "" )
		{
			ReplaceWheelLambda lambda = new ReplaceWheelLambda ( this, newWheel, NULL);
			lambda.SetTransferParams(true, true, true);
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
		}
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
}

class Hmmwv_M1035_Wheel_destroyed extends ItemBase {};

class Hmmwv_M1035tent extends Container_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttachOnSelection);
		AddAction(ActionDetach);
	}
}

class Hmmwv_M1035_doors_Driver extends CarDoor {};
class Hmmwv_M1035_Doors_coDriver extends CarDoor {};
class Hmmwv_M1035_doors_cargo1 extends CarDoor {};
class Hmmwv_M1035_doors_cargo2 extends CarDoor {};
class Hmmwv_M1035_doors_hood extends CarDoor {};

class Hmmwv_M1151_doors_Driver extends CarDoor {};
class Hmmwv_M1151_Doors_coDriver extends CarDoor {};
class Hmmwv_M1151_doors_cargo1 extends CarDoor {};
class Hmmwv_M1151_doors_cargo2 extends CarDoor {};
class Hmmwv_M1151_doors_trunk extends CarDoor {};
