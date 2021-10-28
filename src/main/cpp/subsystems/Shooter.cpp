/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {
  m_RightMotor.RestoreFactoryDefaults();
  m_LeftMotor.RestoreFactoryDefaults();
  m_LeftMotor.Follow(m_RightMotor, true);
  m_RightMotor.SetInverted(true);
  //m_RightMotor.ConfigVoltageCompSaturation(12.5);
  //m_LeftMotor.ConfigVoltageCompSaturation(12.5);
  //m_RightMotor.EnableVoltageCompensation(6.0);
  //m_LeftMotor.EnableVoltageCompensation(6.0);
  m_Timer.Reset();
  m_Timer.Stop();
}

void Shooter::Shoot(double power) {

  m_RightMotor.Set(power);
}

void Shooter::SetRamp(double seconds_from_neutral_to_full) {
  m_RightMotor.SetOpenLoopRampRate(seconds_from_neutral_to_full);
  m_LeftMotor.SetOpenLoopRampRate(seconds_from_neutral_to_full);
}

double Shooter::GetTimer() { return m_Timer.Get(); }

void Shooter::ResetTimer() {
  m_Timer.Reset();
  m_Timer.Start();
}

void Shooter::StopTimer() {
  m_Timer.Reset();
  m_Timer.Stop();
}

bool Shooter::isReady(){
  std::cout << m_RightMotor.GetEncoder().GetVelocity() << std::endl;
  if ((m_RightMotor.GetEncoder().GetVelocity() >= READY_SPEED) && (m_LeftMotor.GetEncoder().GetVelocity() >= READY_SPEED)){
    return true;
  }else{
    return false;
  }
}

void Shooter::Periodic() {}
