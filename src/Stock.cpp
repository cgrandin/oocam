#include "Stock.h"

Stock::Stock(){
  setName("Uninitialized");
}

Stock::Stock(AreaContainer ac){
  //setName(name);
  areaList = ac;
}

Stock::~Stock(){
}

adstring Stock::getName(){
  return(speciesName);
}

void Stock::setName(adstring name){
  speciesName = name;
}

AreaContainer Stock::getAreaList(){
  return(areaList);
}
