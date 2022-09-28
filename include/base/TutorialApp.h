#pragma once

#include "MooseApp.h"

class TutorialApp : public MooseApp
{
public:
  static InputParameters validParams();

  TutorialApp(InputParameters parameters);
  virtual ~TutorialApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};
