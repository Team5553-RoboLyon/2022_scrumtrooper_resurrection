/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/endgame/DropHook.h"

DropHook::DropHook(TelescopicArm* ptelescopic_arm, Intake* pintake, Drivetrain* pdrivetrain)
    : m_pTelescopicArm(ptelescopic_arm), m_pIntake(pintake), m_pDrivetrain(pdrivetrain) {
  AddRequirements(m_pTelescopicArm);
  AddRequirements(m_pIntake);
}

void DropHook::Initialize() {
  m_pIntake->Open();
  m_pTelescopicArm->GoDown();
}

void DropHook::Execute() {
  m_pTelescopicArm->GoDown();
  if (m_pTelescopicArm->GetEncodeur() < 50) {
    m_pDrivetrain->QuickSpeed();
  }
}

void DropHook::End(bool interrupted) { m_pTelescopicArm->Stop(); }

bool DropHook::IsFinished() { return false; }
