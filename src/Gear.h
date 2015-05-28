#include <admodel.h>
#include "Catch.h"

#ifndef _GEAR_H
#define _GEAR_H

class Gear{
 private:
  data_int m_syr;
  data_int m_eyr;
  data_int m_sage;
  data_int m_eage;
  // The tac allocation for this gear.
  data_int m_allocation;
  // whether or not this gear is a fishery (i.e. has non-zero catch)
  bool m_is_fishery;
  Catch *catches;
 public:
  Gear();
  Gear(data_int syr, data_int eyr, data_int sage, data_int nage);
  Gear(const Gear& cGear);
  ~Gear();
};

#endif
