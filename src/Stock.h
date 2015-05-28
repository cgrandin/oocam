/**
 * ! Class representing a fish stock
 *
 * This class represents a fish stock, including the number of sexes, years for
 * assessment, and a std::list of Gear types.
 */

#include <admodel.h>
#include <vector>
#include "Parameters.h"
#include "Gear.h"

#ifndef _STOCK_H
#define _STOCK_H

class Stock{
 private:
  data_int m_nsexage;
  data_int m_nsexcatch;
  data_int m_nsexsel;
  data_int m_syr;
  data_int m_eyr;
  data_int m_sage;
  data_int m_eage;
  data_int m_ngear;
  data_vector m_gearalloc;
  std::vector<Gear> m_gear_vector;
  void m_verify_sexes();
  void m_verify_years();
  void m_verify_ages();
  void m_allocate_data();
  void m_allocate_controls();
  Parameters parameters;
 public:
  Stock();
  void allocate();
  ~Stock();
};

#endif
