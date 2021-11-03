#include "commands/scoring/AdjustTurretRightGasp.h"

#include <networktables/NetworkTableInstance.h>

AdjustTurretRightGasp::AdjustTurretRightGasp(Turret* pturret) : m_pTurret(pturret) 
{
  AddRequirements(m_pTurret);
  
}

void AdjustTurretRightGasp::Initialize() 
{ 
  m_pTurret->TurnRight(); 
}

void AdjustTurretRightGasp::Execute() 
{
  //m_pTurret->TurnRight();
}

void AdjustTurretRightGasp::End(bool interrupted) 
{
  // m_pTurret->Stop();
}

bool AdjustTurretRightGasp::IsFinished() { return false; }