//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef DG_SHALLOW_WATERTESTAPP_H
#define DG_SHALLOW_WATERTESTAPP_H

#include "MooseApp.h"

class DGShallowWaterTestApp;

template <>
InputParameters validParams<DGShallowWaterTestApp>();

class DGShallowWaterTestApp : public MooseApp
{
public:
  DGShallowWaterTestApp(InputParameters parameters);
  virtual ~DGShallowWaterTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* DG_SHALLOW_WATERTESTAPP_H */
