#include "FrompTemperature.h"

registerMooseObject("FPTestApp", FrompTemperature);

InputParameters
FrompTemperature ::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Temperature ($T$) equation: "
                             "$-\\nabla \\cdot \\kappa \\nabla T = 0$");

  params.addRequiredParam<Real>("thermal_conductivity", "thermal conductivity");
  return params;
}

FrompTemperature::FrompTemperature(const InputParameters & parameters)
  : ADKernelGrad(parameters),

    _thermal_conductivity(getParam<Real>("thermal_conductivity"))
{
}

ADRealVectorValue
FrompTemperature::precomputeQpResidual()
{
  return (_thermal_conductivity * _grad_u[_qp]);
}