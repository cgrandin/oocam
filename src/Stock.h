#include <admodel.h>
#include "SexStructure.h"

#ifndef _STOCK_H
#define _STOCK_H

class Stock{
 private:
  adstring speciesName;
  SexStructure sexStruct;
 public:
  Stock();
  adstring getName();
  void setName(adstring);
  SexStructure getSexStruct();
  void setSexStruct(SexStructure);
};

#endif
