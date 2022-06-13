#pragma once
#include "ADKernelGrad.h"

/*compute the residual contribution: kappa *grad_test*grad_T*/
class FrompTemperature : public ADKernelGrad
{

public:
  static InputParameters validParams();
  FrompTemperature(const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
  const Real _thermal_conductivity;
};
