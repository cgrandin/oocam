#include "Stock.h"

#ifndef MAX_YEAR
#define MAX_YEAR 2016
#endif

Stock::Stock(){
  // read in the data variables for this stock
  // m_nsexage is the main sex variable for this model
  // If this is 1, then m_nsexcatch and m_nsexsel
  // are ignored. Must be either 0 (combined), 1 (male),
  // or 2 (female).
  m_nsexage.allocate(adstring("nsexage"));
  // m_nsexcatch tells the model to expect the catch
  // to be split by sex. m_nsexage must be 2 if this is 2
  m_nsexcatch.allocate(adstring("nsexcatch"));
  // If m_nsexsel is 2, tells the model to estimate selectivity
  // for two sexes. m_nsexage must be 2 if this is 2.
  m_nsexsel.allocate(adstring("nsexsel"));
  m_verify_sexes();

  m_syr.allocate(adstring("syr"));
  m_nyr.allocate(adstring("nyr"));
  m_verify_years();

  m_sage.allocate(adstring("sage"));
  m_nage.allocate(adstring("nage"));
  m_verify_ages();

  m_ngear.allocate(adstring("ngear"));

  // Populate gears using standard (doubly-linked) list. Gear class
  // will read in the allocation vector, one by one for
  // each gear. Note: In iscam this vector is normalized.
  for(int i=1; i<=m_ngear; i++){
    m_gear_list.push_back(Gear());
  }
}

void Stock::m_verify_sexes(){
  if(m_nsexage == 1){
    m_nsexcatch = 1;
    m_nsexsel = 1;
  }
  if(m_nsexage < 0 || m_nsexage > 2){
    cout<<"Error: Stock::Stock(), nsexage must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nsexcatch < 0 || m_nsexcatch > 2){
    cout<<"Error: Stock::Stock(), nsexcatch must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nsexsel < 0 || m_nsexsel > 2){
    cout<<"Error: Stock::Stock(), nsexsel must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
}

void Stock::m_verify_years(){
  if(m_syr < 0){
    cout<<"Error: Stock::Stock(), syr must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_syr > MAX_YEAR){
    cout<<"Error: Stock::Stock(), syr must be <= "<<MAX_YEAR<<"."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nyr < 0){
    cout<<"Error: Stock::Stock(), nyr must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nyr > MAX_YEAR){
    cout<<"Error: Stock::Stock(), nyr must be <= "<<MAX_YEAR<<"."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nyr <= m_syr){
    cout<<"Error: Stock::Stock(), syr must be <= nyr."<<endl;
    exit(EXIT_FAILURE);
  }
}

void Stock::m_verify_ages(){
  if(m_sage < 0){
    cout<<"Error: Stock::Stock(), sage must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nage < 0){
    cout<<"Error: Stock::Stock(), nage must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nage <= m_sage){
    cout<<"Error: Stock::Stock(), sage must be < nage."<<endl;
    exit(EXIT_FAILURE);
  }
}

Stock::~Stock(){
}
