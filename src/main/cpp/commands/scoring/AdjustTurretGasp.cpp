#include "commands/scoring/AdjustTurretGasp.h"

#include <networktables/NetworkTableInstance.h>

AdjustTurretGasp::AdjustTurretGasp(Turret* pturret,std::function<double()> turn) : m_pTurret(pturret) 
{
  AddRequirements(m_pTurret);
  m_turn = turn;
  
}

void AdjustTurretGasp::Initialize() 
{ 
  //m_pTurret->Turn(); 
}

void AdjustTurretGasp::Execute() 
{
  m_pTurret->Turn(m_turn());
}

void AdjustTurretGasp::End(bool interrupted) 
{
 //m_pTurret->Stop();
}

bool AdjustTurretGasp::IsFinished() { return false; }