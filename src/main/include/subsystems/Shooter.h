/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

#define TOTAL_CHARGE_TIME 1.5

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  void Shoot(double power);
  void SetRamp(double seconds_from_neutral_to_full);
  void Periodic();

  double GetTimer();
  void ResetTimer();
  void StopTimer();

 private:
  rev::CANSparkMax m_RightMotor{SHOOTER_RIGHT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_LeftMotor{SHOOTER_LEFT_MOTOR,rev::CANSparkMax::MotorType::kBrushless};
  frc::Timer m_Timer;
};
