#include "Catch.h"

Catch::Catch(){
  cout<<"In Catch::allocate"<<endl;
}

void Catch::allocate(adstring name){
  // Read in the catch data for the
  m_nsex.allocate(name + adstring("_nsex"));
  m_type.allocate(name + adstring("_catch_type"));
  m_nobs.allocate(name + adstring("_catch_nobs"));
  m_data.allocate(1, m_nobs, 1, 3, name + adstring("_catch_data"));
  cout<<name<<", m_nsex = "<<m_nsex<<endl;
  cout<<name<<", m_type = "<<m_type<<endl;
  cout<<name<<", m_nobs = "<<m_nobs<<endl;
  cout<<name<<", m_data = "<<m_data<<endl;
}

Catch::~Catch(){
}
