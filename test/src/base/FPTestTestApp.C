//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FPTestTestApp.h"
#include "FPTestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
FPTestTestApp::validParams()
{
  InputParameters params = FPTestApp::validParams();
  return params;
}

FPTestTestApp::FPTestTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FPTestTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FPTestTestApp::~FPTestTestApp() {}

void
FPTestTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FPTestApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FPTestTestApp"});
    Registry::registerActionsTo(af, {"FPTestTestApp"});
  }
}

void
FPTestTestApp::registerApps()
{
  registerApp(FPTestApp);
  registerApp(FPTestTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FPTestTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FPTestTestApp::registerAll(f, af, s);
}
extern "C" void
FPTestTestApp__registerApps()
{
  FPTestTestApp::registerApps();
}
