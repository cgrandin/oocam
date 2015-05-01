#include <admodel.h>

#ifndef _SEXSTRUCTURE_H
#define _SEXSTRUCTURE_H

class SexStructure{
 private:
  data_int m_sex_code;
  adstring m_description;
 public:
  SexStructure();
  SexStructure(data_int);
  ~SexStructure();
  adstring getDescription();
  data_int getCode();
  void setCode(data_int);
};

#endif
