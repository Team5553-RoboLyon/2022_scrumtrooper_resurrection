#include "commands/intake/ChangeIntakeMode.h"

ChangeIntakeMode::ChangeIntakeMode(Intake* pintake) : m_pIntake(pintake) {
  AddRequirements(m_pIntake);
}

void ChangeIntakeMode::Initialize() 
{ 
  //m_pIntake->ChangePosition();
  std::cout << "init" << std::endl;
  m_pIntake->Activate(); 
}// change la position de l'intake

void ChangeIntakeMode::End(bool interrupted) 
{ 
  //m_pIntake->ChangePosition();
   std::cout << "end" << std::endl;
  m_pIntake->Stop(); 
}// change la position de l'intake