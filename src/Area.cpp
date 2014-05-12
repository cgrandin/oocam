#include "Area.h"

Area::Area(){
  setSexStructure(SexStructure());
}

Area::Area(SexStructure s){
  setSexStructure(s);
}

Area::~Area(){
}

void Area::setSexStructure(SexStructure s){
  sexStruct = s;
}

SexStructure Area::getSexStructure(){
  return(sexStruct);
}

