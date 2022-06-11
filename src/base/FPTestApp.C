#include "FPTestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FPTestApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

FPTestApp::FPTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FPTestApp::registerAll(_factory, _action_factory, _syntax);
}

FPTestApp::~FPTestApp() {}

void
FPTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"FPTestApp"});
  Registry::registerActionsTo(af, {"FPTestApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FPTestApp::registerApps()
{
  registerApp(FPTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FPTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FPTestApp::registerAll(f, af, s);
}
extern "C" void
FPTestApp__registerApps()
{
  FPTestApp::registerApps();
}
