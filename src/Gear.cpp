#include "Gear.h"

Gear::Gear(){
  static int m_gearcount = 1;
  adstring gearalloc = adstring("gearalloc") + str(m_gearcount);
  m_allocation.allocate(gearalloc);
  m_is_fishery = m_allocation > 0 ? true : false;
  m_gearcount++;
}

Gear::~Gear(){
}
