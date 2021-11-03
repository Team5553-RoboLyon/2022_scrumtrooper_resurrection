#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <networktables/NetworkTableEntry.h>

#include "subsystems/AdjustableHood.h"

#define BUFFER_SIZE 3

class AdjustHood : public frc2::CommandHelper<frc2::CommandBase, AdjustHood> {
 public:
    AdjustHood(AdjustableHood* padjustableHood,std::function<double()> hood);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  AdjustableHood* m_pAdjustableHood;
  std::function<double()> m_hood;
  
};