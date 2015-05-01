#include "Stock.h"

Stock::Stock(){
  // read in the data variables for this stock
  m_nsexage.allocate(adstring("nsexage"));
  m_nsexcatch.allocate(adstring("nsexcatch"));
  m_nsexsel.allocate(adstring("nsexsel"));
  m_syr.allocate(adstring("syr"));
  m_nyr.allocate(adstring("nyr"));
  m_sage.allocate(adstring("sage"));
  m_nage.allocate(adstring("nage"));
  m_ngear.allocate(adstring("ngear"));

  m_gearalloc.allocate(1, m_ngear, adstring("gearalloc"));
  // Populate gear list using standard list
  for(int i=1; i<=m_ngear; i++){
    m_gear_list.push_back(Gear());
  }

}

Stock::~Stock(){
}
