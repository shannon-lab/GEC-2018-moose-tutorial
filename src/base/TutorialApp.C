#include "TutorialApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<TutorialApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

TutorialApp::TutorialApp(InputParameters parameters) : MooseApp(parameters)
{
  TutorialApp::registerAll(_factory, _action_factory, _syntax);
}

TutorialApp::~TutorialApp() {}

void
TutorialApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"TutorialApp"});
  Registry::registerActionsTo(af, {"TutorialApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TutorialApp::registerApps()
{
  registerApp(TutorialApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TutorialApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TutorialApp::registerAll(f, af, s);
}
extern "C" void
TutorialApp__registerApps()
{
  TutorialApp::registerApps();
}
