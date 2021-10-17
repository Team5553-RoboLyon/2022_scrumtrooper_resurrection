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
  m_pShooter->Shoot(0.5); 
  m_pFeeder->Activate();


}

void NewShoot::Execute() {
  /*double power = 1;
   double pitch = m_ChameleonPitchEntry.GetDouble(0.0);
  if (pitch < 2 && pitch > -2) {
    power = 0.96;
  } else {
    power = 1;
    // power = pitch * pitch * 0.0033 + pitch * 0.0358 + 0.96;
    // pitch * pitch * 0.00329 + pitch * 0.0358 + 0.949;
    // pitch * pitch * 0.00215 + pitch * 0.0247 + 0.907
  }
  m_pShooter->Shoot(power);*/
}

void NewShoot::End(bool interrupted)
 {
  m_pShooter->Shoot(0.0); 
  m_pFeeder->Stop();
}

bool NewShoot::IsFinished() { return false; }
