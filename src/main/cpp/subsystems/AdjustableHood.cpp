#include "subsystems/AdjustableHood.h"

AdjustableHood::AdjustableHood()
{
    //: frc2::PIDSubsystem(frc2::PIDController(TURRET_P_GAIN, TURRET_I_GAIN, TURRET_D_GAIN)) {
  //m_Encoder.SetDistancePerRotation(TURRET_POSITION_CONVERSION_FACTOR);
  //m_Encoder.Reset();
  m_AdjustMotor.SetInverted(true);
  //SetSetpoint(0);
  //Disable();
}


void AdjustableHood::Stop() 
{
  m_AdjustMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,0.0);
}
void AdjustableHood::Turn(double speed) 
{
  m_AdjustMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,speed*TURRET_SPEED);
}
