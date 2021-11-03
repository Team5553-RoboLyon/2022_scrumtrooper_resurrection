#include "commands/scoring/AdjustHood.h"

#include <networktables/NetworkTableInstance.h>

AdjustHood::AdjustHood(AdjustableHood* padjustableHood,std::function<double()> hood) : m_pAdjustableHood(padjustableHood) 
{
  AddRequirements(m_pAdjustableHood);
  m_hood = hood;
  
}

void AdjustHood::Initialize() 
{ 
  //m_pTurret->Turn(); 
}

void AdjustHood::Execute() 
{
  m_pAdjustableHood->Turn(m_hood());
}

void AdjustHood::End(bool interrupted) 
{
 //m_pTurret->Stop();
}

bool AdjustHood::IsFinished() { return false; }