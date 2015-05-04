/**
 * ! Class representing a fish stock
 *
 * This class represents a fish stock, including the number of sexes, years for
 * assessment, and a std::list of Gear types.
 */

#include <admodel.h>
#include <list>
#include "Gear.h"

#ifndef _STOCK_H
#define _STOCK_H

using std::list;

class Stock{
 private:
  data_int m_nsexage;
  data_int m_nsexcatch;
  data_int m_nsexsel;
  data_int m_syr;
  data_int m_nyr;
  data_int m_sage;
  data_int m_nage;
  data_int m_ngear;
  data_vector m_gearalloc;
  list <Gear> m_gear_list;
  void m_verify_sexes();
  void m_verify_years();
  void m_verify_ages();
 public:
  Stock();
  ~Stock();
};

#endif
