/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/NewShoot.h"

#include <networktables/NetworkTableInstance.h>

NewShoot::NewShoot(Shooter* pshooter, Feeder* pfeeder)   {
  /*m_ChameleonPitchEntry = nt::NetworkTableInstance::GetDefault()
                              .GetTable("chameleon-vision")
                              ->GetEntry("turret/targetPitch");
  m_ChameleonIsValidEntry = nt::NetworkTableInstance::GetDefault()
                                .GetTable("chameleon-vision")
                                ->GetEntry("turret/isValid");*/
  m_pShooter = pshooter;
  m_pFeeder = pfeeder;
  AddRequirements(m_pShooter);
  AddRequirements(m_pFeeder);
}

void NewShoot::Initialize() 
{ 
  m_pShooter->SetRamp(1.0);
  m_pShooter->Shoot(1.0);  
  m_state = NewShoot::state::starting;
  


}

void NewShoot::Execute() {
  switch (NewShoot::m_state)
  {
  case NewShoot::state::starting:
    if (m_pShooter->isReady()){
      NewShoot::m_state=NewShoot::state::running;
      m_pFeeder->Activate();
    }
    break;
  case NewShoot::state::running:
    if (!m_pShooter->isReady()){
      m_state=NewShoot::state::starting;
      m_pFeeder->Stop();
    }
  break;
  default:
    break;
}
}

void NewShoot::End(bool interrupted)
 {
  m_pShooter->Shoot(0.0); 
  m_pFeeder->Stop();
}

bool NewShoot::IsFinished() { return false; }
