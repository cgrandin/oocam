#include <admodel.h>
#include <list>
#include "Area.h"

#ifndef _AREACONTAINER_H
#define _AREACONTAINER_H

using std::list;

class AreaContainer{
 private:
  list <Area> areaList;
 public:
  AreaContainer();
  ~AreaContainer();

  void addArea(Area);
  //removeArea(Area);
};

#endif
