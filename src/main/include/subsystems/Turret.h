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

class Turret/* : public frc2::PIDSubsystem */{
 public:
  Turret();

  void UseOutput(double output, double setpoint);
  double GetMeasurement();
  void SetClampedSetpoint(double setpoint);

  void Stop();
  void TurnLeft();
  void TurnRight();

 private:
  //frc::VictorSP m_Motor{TURRET_MOTOR};
  //frc::DutyCycleEncoder m_Encoder{TURRET_ENCODER};
  ctre::phoenix::motorcontrol::can::VictorSPX m_TurretMotor{TURRET_MOTOR};
};
