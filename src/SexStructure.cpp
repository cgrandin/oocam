#include "SexStructure.h"

SexStructure::SexStructure(){
  setCode(0);
}

SexStructure::SexStructure(int code){
  sexCode = code;
}

void SexStructure::setCode(int code){
  sexCode = code;
}

int SexStructure::getCode(){
  return(sexCode);
}

adstring SexStructure::getName(){
  if(sexCode == 0){
    return("Combined");
  }
  if(sexCode == 1){
    return("Female");
  }
  if(sexCode == 2){
    return("Male");
  }
  return("Uninitialized");
}
