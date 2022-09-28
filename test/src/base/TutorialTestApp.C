#include "TutorialTestApp.h"
#include "TutorialApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<TutorialTestApp>()
{
  InputParameters params = validParams<TutorialApp>();
  return params;
}

TutorialTestApp::TutorialTestApp(InputParameters parameters) : MooseApp(parameters)
{
  TutorialTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TutorialTestApp::~TutorialTestApp() {}

void
TutorialTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TutorialApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TutorialTestApp"});
    Registry::registerActionsTo(af, {"TutorialTestApp"});
  }
}

void
TutorialTestApp::registerApps()
{
  registerApp(TutorialApp);
  registerApp(TutorialTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TutorialTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TutorialTestApp::registerAll(f, af, s);
}
extern "C" void
TutorialTestApp__registerApps()
{
  TutorialTestApp::registerApps();
}
