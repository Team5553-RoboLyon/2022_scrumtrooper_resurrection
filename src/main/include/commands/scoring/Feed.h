/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Constants.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"

class Feed : public frc2::CommandHelper<frc2::CommandBase, Feed> {
 public:
  Feed(Feeder* pfeeder, Intake* pintake, Shooter* pshooter, bool enable_intake = true);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Feeder* m_pFeeder;
  Intake* m_pIntake;
  Shooter* m_pShooter;
  double m_Timeout;
  bool m_IsIntakeEnabled;
};
