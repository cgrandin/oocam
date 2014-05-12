#include <admodel.h>
#include "AreaContainer.h"

#ifndef _STOCK_H
#define _STOCK_H

class Stock{
 private:
  adstring speciesName;
  AreaContainer areaList;
 public:
  Stock();
  Stock(AreaContainer);
  ~Stock();
  adstring getName();
  void setName(adstring);
  AreaContainer getAreaList();
};

#endif
