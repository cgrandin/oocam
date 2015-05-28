#include <admodel.h>
#include "Prior.h"

#ifndef _LEADINGPARAMETER_H
#define _LEADINGPARAMETER_H

class LeadingParameter{
 private:
  adstring m_name;
  data_number m_ival;
  data_number m_lb;
  data_number m_ub;
  data_int m_phz;
  Prior *m_prior;
 public:
  LeadingParameter();
  ~LeadingParameter();
  void allocate(adstring name);
  /*
  dvariable get_ival();
  void set_ival(dvariable ival);
  dvariable get_lb();
  void set_lb(dvariable lb);
  dvariable get_ub();
  void set_ub(dvariable ub);
  int get_phz();
  void set_phz(int phz);
  */
};

#endif
