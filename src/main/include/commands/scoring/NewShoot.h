/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <networktables/NetworkTableEntry.h>

#include "subsystems/Shooter.h"

class NewShoot : public frc2::CommandHelper<frc2::CommandBase, NewShoot> {
 public:
  explicit NewShoot(Shooter* pshooter);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


 private:
  Shooter* m_pShooter;

  //nt::NetworkTableEntry m_ChameleonPitchEntry;
  //nt::NetworkTableEntry m_ChameleonIsValidEntry;
};
