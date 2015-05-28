#include "Parameters.h"

Parameters::Parameters(){
}

Parameters::~Parameters(){
}

void Parameters::allocate(){
  m_ro.allocate(adstring("ro"));
  m_h.allocate(adstring("h"));
  m_m.allocate(adstring("m"));
  m_rinit.allocate(adstring("rinit"));
  m_rbar.allocate(adstring("rbar"));
  m_rho.allocate(adstring("rho"));
  m_vartheta.allocate(adstring("vartheta"));
}
