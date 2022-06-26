class Hmmwv_M1035 extends CarScript
{
	void Hmmwv_M1035()
	{
		m_dmgContactCoef = 0.060;

		m_CarDoorOpenSound 		= "offroad_door_open_SoundSet";
		m_CarDoorCloseSound 	= "offroad_door_close_SoundSet";
	}
	
	override float GetActionDistanceCoolant()
	{
		return 6.0;
	}
	
	override float GetActionDistanceFuel()
	{
		return 4.0;
	}

	override float GetActionDistanceOil()
	{
		return 4.0;
	}
	
	override float GetActionDistanceBrakes()
	{
		return 4.0;
	}
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.SEDAN;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}
	
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(Hmmwv_M1035FrontLight) );
	}
	
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(Hmmwv_M1035RearLight) );
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		string attType = attachment.GetType();
		
		switch( attType )
		{
			case "CarBattery": 
				if ( GetCarDoorsState("Hmmwv_M1035_doors_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			
			case "SparkPlug":
				if ( GetCarDoorsState("Hmmwv_M1035_doors_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;

			case "CarRadiator":
				if ( GetCarDoorsState("Hmmwv_M1035_doors_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			
			case "Hmmwv_M1035_Wheel_spare_1": 
				if ( GetCarDoorsState("") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			
			case "CanisterGasoline":
				if ( GetCarDoorsState("") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
		}

		return true;
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch( slotType )
		{
			case "Hmmwv_M1035_doors_Driver":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "Hmmwv_M1035_Doors_coDriver":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "Hmmwv_M1035_doors_cargo1":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "Hmmwv_M1035_doors_cargo2":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "Hmmwv_M1035_doors_hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "Hmmwv_M1035_doors_trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
		}

		return CarDoorState.DOORS_MISSING;
	}
	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_Driver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "Hmmwv_M1035_Doors_coDriver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 2:
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_cargo1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 3:
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_cargo2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
		}

		return false;
	}

    override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "doors_driver";
		break;
		case 1:
			return "doors_codriver";
		break;
		case 2:
			return "doors_cargo1";
		break;
		case 3:
			return "doors_cargo2";
		break;
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}

	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "Hmmwv_M1035_doors_Driver";
		break;
		case 1:
			return "Hmmwv_M1035_Doors_coDriver";
		break;
		case 2:
			return "Hmmwv_M1035_doors_cargo1";
		break;
		case 3:
			return "Hmmwv_M1035_doors_cargo2";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}

	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;
				
				//-----
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_Driver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "Hmmwv_M1035_Doors_coDriver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_cargo1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "Hmmwv_M1035_doors_cargo2" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetHealthLevel( "WindowFront") == GameConstants.STATE_RUINED )
					newValue -= 0.6;

				//-----
				if ( GetHealthLevel( "WindowBack") == GameConstants.STATE_RUINED )
					newValue -= 0.6;
			
				if ( newValue > 1 )
					newValue = 1;
			
				if ( newValue < 0 )
					newValue = 0;
			
				return newValue;
			break;
		}

		return oldValue;
	}
	
	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}

	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}
	
	
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
			break;
		case 1:
			if ( nextSeat == 0 )
				return true;
			break;
		case 2:
			if ( nextSeat == 3 )
				return true;
			break;
		case 3:
			if ( nextSeat == 2 )
				return true;
			break;
		}
		
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		case 2:
			if (pDoorsSelection == "DoorsCargo1")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		}
		
		return false;		
	}

	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{	
			if (this.GetType() == "Hmmwv_M1035_Green")
			{
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_Driver_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Doors_coDriver_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo1_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo2_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_hood_Green" );
			}

			if (this.GetType() == "Hmmwv_M1035_Gray")
			{
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_Driver_Gray" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Doors_coDriver_Gray" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo1_Gray" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo2_Gray" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_hood_Gray" );
			}

			if (this.GetType() == "Hmmwv_M1035_Black")
			{
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_Driver_Black" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Doors_coDriver_Black" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo1_Black" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo2_Black" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_hood_Black" );
			}

			if (this.GetType() == "Hmmwv_M1035_Green")
			{
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_Driver_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Doors_coDriver_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo1_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo2_Green" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_hood_Green" );
			}
			
			else
			{
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_Driver" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Doors_coDriver" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo1" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_cargo2" );
				entity.GetInventory().CreateInInventory( "Hmmwv_M1035_doors_hood" );
			}

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			
			entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Wheel" );
			entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Wheel" );
			entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Wheel" );
			entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Wheel" );
			entity.GetInventory().CreateInInventory( "Hmmwv_M1035_Wheel" );
		}

		Fill( CarFluid.FUEL, 50 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
}
