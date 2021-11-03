/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DutyCycleEncoder.h>
#include <frc/VictorSP.h>
#include <frc2/command/PIDSubsystem.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>


#include "Constants.h"

class Turret : public frc2::SubsystemBase
{
 public:
  Turret();

  void Stop();
  void Turn(double speed);


 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_TurretMotor{TURRET_MOTOR};
};
