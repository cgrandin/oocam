#include <admodel.h>

#ifndef _CATCH_H
#define _CATCH_H

class Catch{
 private:
  data_int m_syr;
  data_int m_eyr;
  data_int m_nsex;
  data_int m_type; // 1=weight,2=numbers
  data_int m_nobs; // number of catch observations
  data_number m_sd_first_phase;
  data_number m_sd_last_phase;
  ivector m_years;
  data_matrix m_data;
 public:
  Catch();
  Catch(int syr, int );
  void allocate(adstring name);
  ~Catch();
};

#endif
