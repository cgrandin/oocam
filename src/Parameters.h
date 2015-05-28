#include <admodel.h>
//#include <vector>
#include "LeadingParameter.h"

#ifndef _PARAMETERS_H
#define _PARAMETERS_H

class Parameters{
 private:
  LeadingParameter m_ro;
  LeadingParameter m_h;
  LeadingParameter m_m;
  LeadingParameter m_rinit;
  LeadingParameter m_rbar;
  LeadingParameter m_rho;
  LeadingParameter m_vartheta;
 public:
  Parameters();
  void allocate();
  ~Parameters();
};

#endif
