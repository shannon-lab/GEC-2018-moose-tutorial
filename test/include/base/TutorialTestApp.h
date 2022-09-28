#pragma once

#include "MooseApp.h"

class TutorialTestApp;

template <>
InputParameters validParams<TutorialTestApp>();

class TutorialTestApp : public MooseApp
{
public:
  TutorialTestApp(InputParameters parameters);
  virtual ~TutorialTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};
