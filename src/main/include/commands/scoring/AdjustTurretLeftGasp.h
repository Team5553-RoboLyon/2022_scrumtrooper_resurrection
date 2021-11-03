
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <networktables/NetworkTableEntry.h>

#include "subsystems/Turret.h"

#define BUFFER_SIZE 3

class AdjustTurretLeftGasp : public frc2::CommandHelper<frc2::CommandBase, AdjustTurretLeftGasp> {
 public:
    AdjustTurretLeftGasp(Turret* pturret);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Turret* m_pTurret;
  
};