#include "commands/scoring/AdjustTurretLeftGasp.h"

#include <networktables/NetworkTableInstance.h>

AdjustTurretLeftGasp::AdjustTurretLeftGasp(Turret* pturret) : m_pTurret(pturret) 
{
  AddRequirements(m_pTurret);
  
}

void AdjustTurretLeftGasp::Initialize() 
{ 
  m_pTurret->TurnLeft(); 
}

void AdjustTurretLeftGasp::Execute() 
{
  //m_pTurret->TurnLeft();
}

void AdjustTurretLeftGasp::End(bool interrupted) 
{
 //m_pTurret->Stop();
}

bool AdjustTurretLeftGasp::IsFinished() { return false; }