#pragma once
#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/Intake.h"

class ChangeIntakeMode
    : public frc2::CommandHelper<frc2::InstantCommand, ChangeIntakeMode> 
{
 public:
  explicit ChangeIntakeMode(Intake* pintake);

  void Initialize() override;
  void End(bool interrupted) override;

 private:
  Intake* m_pIntake;
};
