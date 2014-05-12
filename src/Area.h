#include <admodel.h>
#include "SexStructure.h"

#ifndef _AREA_H
#define _AREA_H

class Area{
 private:
  SexStructure sexStruct;
 public:
  Area();
  Area(SexStructure);
  ~Area();
  void setSexStructure(SexStructure);
  SexStructure getSexStructure();
};

#endif
