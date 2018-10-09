//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef TUTORIALAPP_H
#define TUTORIALAPP_H

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

#endif /* TUTORIALAPP_H */
