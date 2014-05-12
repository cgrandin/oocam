#include "AreaContainer.h"

AreaContainer::AreaContainer(){
}

AreaContainer::~AreaContainer(){
}

void AreaContainer::addArea(Area area){
  areaList.push_back(area);
}
