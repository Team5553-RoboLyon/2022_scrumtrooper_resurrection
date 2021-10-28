#pragma once
#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "subsystems/Intake.h"

class ChangeIntakeMode
    : public frc2::CommandHelper<frc2::CommandBase, ChangeIntakeMode> 
{
 public:
  explicit ChangeIntakeMode(Intake* pintake);

  void Initialize() override;
  void End(bool interrupted) override;

 private:
  Intake* m_pIntake;
};
