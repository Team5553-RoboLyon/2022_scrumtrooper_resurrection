/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DriverStation.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/POVButton.h>

#include "subsystems/AdjustableHood.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Feeder.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/TelescopicArm.h"
#include "subsystems/Turret.h"
#include "subsystems/Winch.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  Drivetrain m_Drivetrain;
  Feeder m_Feeder;
  AdjustableHood m_AdjustableHood;
  Intake m_Intake;
  Shooter m_Shooter;
  TelescopicArm m_TelescopicArm;
  Turret m_Turret;
  Winch m_Winch;

 private:
  frc::Joystick m_DriverControllerLeft{0};
  frc::Joystick m_DriverControllerRight{1};
  // frc::XboxController m_DriverController{0};
  frc2::JoystickButton m_IntakeModeButton{&m_DriverControllerLeft, 1};
  frc2::JoystickButton m_BButton{&m_DriverControllerLeft, 2};
  frc2::JoystickButton m_XButton{&m_DriverControllerLeft, 3};
  frc2::JoystickButton m_YButton{&m_DriverControllerLeft, 4};
  frc2::JoystickButton m_BumperLeftButton{&m_DriverControllerLeft, 11};// etait 5 mis à 11 test
  frc2::JoystickButton m_BumperPositionButton{&m_DriverControllerLeft, 6};//Intake : Change Intake position
  frc2::JoystickButton m_BackButton{&m_DriverControllerLeft, 7};
  frc2::JoystickButton m_StartButton{&m_DriverControllerLeft, 8};
  frc2::JoystickButton m_StickLeftButton{&m_DriverControllerLeft, 9};
  frc2::JoystickButton m_StickRightButton{&m_DriverControllerLeft, 10};
  frc2::JoystickButton m_ShooterSimplifiedButton{&m_DriverControllerLeft, 5};


  frc::Joystick m_DriverPanel{2};
  frc2::JoystickButton m_YellowButton{&m_DriverPanel, 2};
  frc2::JoystickButton m_RedButton{&m_DriverPanel, 1};
  frc2::JoystickButton m_WhiteButton{&m_DriverPanel, 3};
 

  //TODO checker si c'est bon 
  frc2::Trigger m_AxisLeftTrigger{[this] {
    return m_DriverControllerLeft.GetThrottle() > 0.2;
    // return m_DriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.2;
  }};
  frc2::Trigger m_AxisRightTrigger{[this] {
    return m_DriverControllerRight.GetThrottle() > 0.2;
    // return m_DriverController.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.2;
  }};

  // frc2::POVButton m_Pov0Deg{&m_DriverController, 0};
  // frc2::POVButton m_Pov90Deg{&m_DriverController, 90};
  // frc2::POVButton m_Pov180Deg{&m_DriverController, 180};
  // frc2::POVButton m_Pov270Deg{&m_DriverController, 270};

  frc2::Trigger m_EndgameTrigger{
      [this] { return frc::DriverStation::GetInstance().GetMatchTime() < 40; }};

  frc::SendableChooser<frc2::Command*> m_AutoChooser;
  
  void ConfigureControls();
  void ConfigureTestControls();
};
