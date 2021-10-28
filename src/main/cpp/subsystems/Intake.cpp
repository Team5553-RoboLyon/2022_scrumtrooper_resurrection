/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() 
{
  m_Motor.SetInverted(true);//inverse le sens du moteur
  Close();
}

void Intake::Open() 
{
  Stop();
  m_Solenoid.Set(frc::DoubleSolenoid::Value::kForward);//descend l'intake
  m_Position = IntakePosition::kOpened;//met m_Position à 0
}

void Intake::Close() 
{
  Stop();
  m_Solenoid.Set(frc::DoubleSolenoid::Value::kReverse);//remonte l'intake
  m_Position = IntakePosition::kClosed;//met m_Position à 1
}



void Intake::ChangePosition() // change la position de l'intake
{ 
  if (m_Position == IntakePosition::kOpened) //si m_Position = 0
  { 
    Close();
  } 
  else 
  {
    Open();
  }
}

void Intake::Activate() 
{
  if (m_Position == IntakePosition::kOpened) //si m_Position = 0
  {
    m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,INTAKE_OPENED_SPEED);//lance les moteurs
  } 
  else 
  {
    m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,INTAKE_OPENED_SPEED);//?????
  }
}

void Intake::Stop() { m_Motor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0.0); }//arrete les moteurs
