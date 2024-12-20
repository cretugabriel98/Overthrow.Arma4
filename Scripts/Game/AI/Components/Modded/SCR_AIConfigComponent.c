
modded class SCR_AIConfigComponent : ScriptComponent
{
	override bool PerformDangerReaction(SCR_AIUtilityComponent utility, AIDangerEvent dangerEvent, int dangerEventCount)
	{
		
		EAIDangerEventType type = dangerEvent.GetDangerType();
		
		if(type == EAIDangerEventType.Danger_WeaponFire)
		{
			IEntity instigator = dangerEvent.GetObject();
			if(instigator)
			{
				OVT_PlayerWantedComponent wanted = OVT_PlayerWantedComponent.Cast(instigator.FindComponent(OVT_PlayerWantedComponent));
				
				if(wanted)
				{
					wanted.SetBaseWantedLevel(2);
				}
			}
		}
		
		
		SCR_AIDangerReaction reaction = m_mDangerReactions[dangerEvent.GetDangerType()];
		if (reaction)
		{
			return reaction.PerformReaction(utility, utility.m_ThreatSystem, dangerEvent, dangerEventCount);
		}
		return false;
	}
}
