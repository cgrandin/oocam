#include <admodel.h>

#ifndef _GEAR_H
#define _GEAR_H

class Gear{
 private:
  // The tac allocation for this gear.
  data_int m_allocation;
  // whether or not this gear is a fishery (i.e. has non-negligible catch)
  bool m_is_fishery;
 public:
  Gear();
  ~Gear();
};

#endif
