#include "Prior.h"

Prior::Prior(){}

void Prior::allocate(adstring name){
  // Read in the prior information from the control file
  m_type.allocate(name + adstring("_prior_type"));
  m_p1.allocate(name + adstring("_prior_p1"));
  m_p2.allocate(name + adstring("_prior_p2"));
  cout<<name<<" prior_type:"<<m_type<<endl;
  cout<<name<<" prior_p1:"<<m_p1<<endl;
  cout<<name<<" prior_p2:"<<m_p2<<endl;
}

Prior::~Prior(){}
