#include "LeadingParameter.h"

LeadingParameter::LeadingParameter(){
  m_name = adstring("default");
  m_ival = 0.0;
  m_lb = 0.0;
  m_ub = 0.0;
  m_phz = 1;
}

void LeadingParameter::allocate(adstring name){
  // Read in the leading parameter variables from the control file
  m_name = name;
  m_ival.allocate(name + adstring("_ival"));
  m_lb.allocate(name + adstring("_lb"));
  m_ub.allocate(name + adstring("_ub"));
  m_phz.allocate(name + adstring("_phz"));
  m_prior = new Prior();
  m_prior->allocate(name);
  cout<<name<<" ival:"<<m_ival<<endl;
  cout<<name<<" lb:"<<m_lb<<endl;
  cout<<name<<" ub:"<<m_ub<<endl;
  cout<<name<<" phz:"<<m_phz<<endl;
}
/*
dvariable LeadingParameter::get_ival(){return(m_ival);}
void LeadingParameter::set_ival(dvariable ival){m_ival = ival;}
dvariable LeadingParameter::get_lb(){return(m_lb);}
void LeadingParameter::set_lb(dvariable lb){m_lb = lb;}
dvariable LeadingParameter::get_ub(){return(m_ub);}
void LeadingParameter::set_ub(dvariable ub){m_ub = ub;}
int LeadingParameter::get_phz(){return(m_phz);}
void LeadingParameter::set_phz(int phz){m_phz = phz;}
*/
LeadingParameter::~LeadingParameter(){
  delete m_prior;
}
