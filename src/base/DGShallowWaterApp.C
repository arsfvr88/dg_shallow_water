#include "DGShallowWaterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<DGShallowWaterApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

DGShallowWaterApp::DGShallowWaterApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DGShallowWaterApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DGShallowWaterApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DGShallowWaterApp::registerExecFlags(_factory);
}

DGShallowWaterApp::~DGShallowWaterApp() {}

void
DGShallowWaterApp::registerApps()
{
  registerApp(DGShallowWaterApp);
}

void
DGShallowWaterApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"DGShallowWaterApp"});
}

void
DGShallowWaterApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"DGShallowWaterApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
DGShallowWaterApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
DGShallowWaterApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
DGShallowWaterApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DGShallowWaterApp__registerApps()
{
  DGShallowWaterApp::registerApps();
}

extern "C" void
DGShallowWaterApp__registerObjects(Factory & factory)
{
  DGShallowWaterApp::registerObjects(factory);
}

extern "C" void
DGShallowWaterApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DGShallowWaterApp::associateSyntax(syntax, action_factory);
}

extern "C" void
DGShallowWaterApp__registerExecFlags(Factory & factory)
{
  DGShallowWaterApp::registerExecFlags(factory);
}
