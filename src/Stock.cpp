#include "Stock.h"
#include "Logger.h"

#ifndef MAX_YEAR
#define MAX_YEAR 2020
#endif

#define DATA_FILE "oocam.dat"
#define CONTROL_FILE "oocam.ctl"
#define PROJECTION_FILE "oocam.pfc"

Stock::Stock(){}

void Stock::allocate(){
  m_allocate_data();
  m_allocate_controls();
}

void Stock::m_allocate_data(){
  ad_comm::change_datafile_name(DATA_FILE);
  // Read in the data variables for this stock
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
  m_eyr.allocate(adstring("eyr"));
  m_verify_years();

  m_sage.allocate(adstring("sage"));
  m_eage.allocate(adstring("eage"));
  m_verify_ages();

  m_ngear.allocate(adstring("ngear"));

  *Logger::Instance()->get_logger()<<"OOCAM - runtime log"<<endl;
  *Logger::Instance()->get_logger()<<"Stock: nsexage = "<<m_nsexage<<endl;
  LOG<<"Stock: nsexcatch = "<<m_nsexcatch<<endl;
  LOG<<"Stock: nsexsel = "<<m_nsexsel<<endl;
  LOG<<"Stock: syr = "<<m_syr<<endl;
  LOG<<"Stock: eyr = "<<m_eyr<<endl;
  LOG<<"Stock: sage = "<<m_sage<<endl;
  LOG<<"Stock: eage = "<<m_eage<<endl;
  LOG<<"Stock: ngear = "<<m_ngear<<endl;
  LOG<<std::flush;
  // Populate gears using standard vector. Gear class
  // will read in the allocation vector, one by one for
  // each gear. Note: In iscam this vector is normalized, but isn't here.
  m_gear_vector.reserve(m_ngear);
  for(int i=1; i<=m_ngear; i++){
    m_gear_vector.push_back(Gear(m_syr, m_eyr, m_sage, m_eage));
  }
}

void Stock::m_allocate_controls(){
  // Read in the parameter variables from the control file
  ad_comm::change_datafile_name(CONTROL_FILE);
  parameters.allocate();
}

void Stock::m_verify_sexes(){
  if(m_nsexage == 1){
    m_nsexcatch = 1;
    m_nsexsel = 1;
  }
  if(m_nsexage < 0 || m_nsexage > 2){
    LOG<<"Error: Stock::Stock(), nsexage must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nsexcatch < 0 || m_nsexcatch > 2){
    LOG<<"Error: Stock::Stock(), nsexcatch must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_nsexsel < 0 || m_nsexsel > 2){
    LOG<<"Error: Stock::Stock(), nsexsel must be in [0,2]."<<endl;
    exit(EXIT_FAILURE);
  }
}

void Stock::m_verify_years(){
  if(m_syr < 0){
    LOG<<"Error: Stock::Stock(), syr must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_syr > MAX_YEAR){
    LOG<<"Error: Stock::Stock(), syr must be <= "<<MAX_YEAR<<"."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_eyr < 0){
    LOG<<"Error: Stock::Stock(), eyr must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_eyr > MAX_YEAR){
    LOG<<"Error: Stock::Stock(), eyr must be <= "<<MAX_YEAR<<"."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_eyr <= m_syr){
    LOG<<"Error: Stock::Stock(), syr must be <= nyr."<<endl;
    exit(EXIT_FAILURE);
  }
}

void Stock::m_verify_ages(){
  if(m_sage < 0){
    LOG<<"Error: Stock::Stock(), sage must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_eage < 0){
    LOG<<"Error: Stock::Stock(), eage must be >= 0."<<endl;
    exit(EXIT_FAILURE);
  }
  if(m_eage <= m_sage){
    LOG<<"Error: Stock::Stock(), sage must be < eage."<<endl;
    exit(EXIT_FAILURE);
  }
}

Stock::~Stock(){
}
