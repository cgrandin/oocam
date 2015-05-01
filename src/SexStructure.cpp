#include "SexStructure.h"

SexStructure::SexStructure(){
}

SexStructure::~SexStructure(){
}

SexStructure::SexStructure(data_int code){
  m_sex_code = code;
}

void SexStructure::setCode(data_int code){
  m_sex_code = code;
}

data_int SexStructure::getCode(){
  return(m_sex_code);
}

adstring SexStructure::getDescription(){
  return(m_description);
}
