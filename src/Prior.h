#include <admodel.h>

#ifndef _PRIOR_H
#define _PRIOR_H

class Prior{
 private:
  data_int m_type; // 0=uni,1=norm,2=lognorm,3=beta,4=gamma
  data_number m_p1; // paramter 1
  data_number m_p2; // parameter 2
 public:
  Prior();
  void allocate(adstring name);
  ~Prior();
};

#endif
