//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DGShallowWaterTestApp.h"
#include "DGShallowWaterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<DGShallowWaterTestApp>()
{
  InputParameters params = validParams<DGShallowWaterApp>();
  return params;
}

DGShallowWaterTestApp::DGShallowWaterTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DGShallowWaterApp::registerObjectDepends(_factory);
  DGShallowWaterApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DGShallowWaterApp::associateSyntaxDepends(_syntax, _action_factory);
  DGShallowWaterApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DGShallowWaterApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    DGShallowWaterTestApp::registerObjects(_factory);
    DGShallowWaterTestApp::associateSyntax(_syntax, _action_factory);
    DGShallowWaterTestApp::registerExecFlags(_factory);
  }
}

DGShallowWaterTestApp::~DGShallowWaterTestApp() {}

void
DGShallowWaterTestApp::registerApps()
{
  registerApp(DGShallowWaterApp);
  registerApp(DGShallowWaterTestApp);
}

void
DGShallowWaterTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
DGShallowWaterTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
DGShallowWaterTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DGShallowWaterTestApp__registerApps()
{
  DGShallowWaterTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
DGShallowWaterTestApp__registerObjects(Factory & factory)
{
  DGShallowWaterTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
DGShallowWaterTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DGShallowWaterTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
DGShallowWaterTestApp__registerExecFlags(Factory & factory)
{
  DGShallowWaterTestApp::registerExecFlags(factory);
}
