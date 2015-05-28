#include "Gear.h"
#include "Catch.h"

Gear::Gear(){
}

Gear::Gear(data_int syr, data_int eyr, data_int sage, data_int eage){
  static int m_gearcount = 1;

  m_syr = syr;
  m_eyr = eyr;
  m_sage = sage;
  m_eage = eage;
  adstring gearalloc = adstring("gearalloc") + str(m_gearcount);
  m_allocation.allocate(gearalloc);
  m_is_fishery = m_allocation > 0 ? true : false;
  catches = new Catch;
  adstring name = adstring("gear") + str(m_gearcount);
  catches->allocate(name);

  m_gearcount++;
}

Gear::Gear(const Gear& cGear){
  // Const copy constructor required because Gear is kept in a std::vector
  m_syr = cGear.m_syr;
  m_eyr = cGear.m_eyr;
  m_sage = cGear.m_sage;
  m_eage = cGear.m_eage;
  m_allocation = cGear.m_allocation;
  m_is_fishery = cGear.m_is_fishery;
  // Deep pointer copy required to ensure allocation remains when copy
  // constructor is called by std::vector from parent class..
  catches = new Catch(*cGear.catches);
}

Gear::~Gear(){
  delete catches;
}
