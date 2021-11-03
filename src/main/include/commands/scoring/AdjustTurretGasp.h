
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <networktables/NetworkTableEntry.h>

#include "subsystems/Turret.h"

#define BUFFER_SIZE 3

class AdjustTurretGasp : public frc2::CommandHelper<frc2::CommandBase, AdjustTurretGasp> {
 public:
    AdjustTurretGasp(Turret* pturret,std::function<double()> turn);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Turret* m_pTurret;
  std::function<double()> m_turn;
  
};