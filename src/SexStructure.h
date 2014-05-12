#include <admodel.h>

#ifndef _SEXSTRUCTURE_H
#define _SEXSTRUCTURE_H

class SexStructure{
 private:
  int sexCode;
 public:
  SexStructure();
  SexStructure(int);
  ~SexStructure();
  adstring getStatus();
  int getCode();
  void setCode(int);
};

#endif
