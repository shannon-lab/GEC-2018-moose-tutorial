#pragma once

#include "MooseApp.h"

class TutorialApp;

template <>
InputParameters validParams<TutorialApp>();

class TutorialApp : public MooseApp
{
public:
  TutorialApp(InputParameters parameters);
  virtual ~TutorialApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};
