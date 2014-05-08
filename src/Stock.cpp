#include "Stock.h"

Stock::Stock(){
  setName("Uninitialized");
  SexStructure sex;
  setSexStruct(sex);
}

adstring Stock::getName(){
  return(speciesName);
}

void Stock::setName(adstring name){
  speciesName = name;
}

SexStructure Stock::getSexStruct(){
  return(sexStruct);
}

void Stock::setSexStruct(SexStructure sex){
  sexStruct = sex;
}
