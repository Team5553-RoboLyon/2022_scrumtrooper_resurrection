/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

Turret::Turret()
{
    //: frc2::PIDSubsystem(frc2::PIDController(TURRET_P_GAIN, TURRET_I_GAIN, TURRET_D_GAIN)) {
  //m_Encoder.SetDistancePerRotation(TURRET_POSITION_CONVERSION_FACTOR);
  //m_Encoder.Reset();
  m_TurretMotor.SetInverted(true);
  //SetSetpoint(0);
  //Disable();
}


void Turret::Stop() 
{
  m_TurretMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0.0);
}
void Turret::Turn(double speed) 
{
  m_TurretMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,speed*TURRET_SPEED);
}

