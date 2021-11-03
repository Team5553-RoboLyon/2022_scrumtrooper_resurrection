#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <networktables/NetworkTableEntry.h>

#include "subsystems/Turret.h"

class AdjustTurretRightGasp : public frc2::CommandHelper<frc2::CommandBase, AdjustTurretRightGasp> {
 public:
    AdjustTurretRightGasp(Turret* pturret);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Turret* m_pTurret;
  
};