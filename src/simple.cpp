#include "Stock.h"
#include "Gear.h"
#include "SexStructure.h"

#include <admodel.h>
#include <contrib.h>

extern "C"  {
  void ad_boundf(int i);
}

#include <simple.htp>

model_data::model_data(int argc,char * argv[]) : ad_comm(argc,argv){
  Stock stock;
  nobs.allocate("nobs");
  Y.allocate(1,nobs,"Y");
  x.allocate(1,nobs,"x");
}

model_parameters::model_parameters(int sz,int argc,char * argv[]) :
 model_data(argc,argv) , function_minimizer(sz){
  initializationfunction();
  a.allocate("a");
  b.allocate("b");
  pred_Y.allocate(1,nobs,"pred_Y");
  #ifndef NO_AD_INITIALIZE
    pred_Y.initialize();
  #endif
  f.allocate("f");
  prior_function_value.allocate("prior_function_value");
  likelihood_function_value.allocate("likelihood_function_value");
}

void model_parameters::userfunction(void){
  f = 0.0;
  //SexStructure sexstruct(1); //Split sex model
  //Area area(sexstruct);
  //AreaContainer *ac = new AreaContainer(area);
  //ac.addArea(ar);
  //Stock stock(ac);
  //SexStructure sexStruct(0); // Both combined
  //stock.setSexStruct(0);
  //stock.setName("Test Stock");
  //cout<<"Sex structure is '"<<sexStruct.getStatus()<<"'"<<endl;
  //cout<<stock.getName()<<endl;
  pred_Y = a*x+b;
  f = norm2(pred_Y-Y);
  f = nobs/2.*log(f);
}

void model_parameters::preliminary_calculations(void){
#if defined(USE_ADPVM)
  admaster_slave_variable_interface(*this);
#endif
}

model_data::~model_data(){}

model_parameters::~model_parameters(){}

void model_parameters::report(const dvector& gradients){}

void model_parameters::final_calcs(void){}

void model_parameters::set_runtime(void){}

#ifdef __ZTC__
  extern unsigned int _stack = 10000U;
#endif

long int arrmblsize = 0;

int main(int argc,char * argv[]){
  ad_set_new_handler();
  ad_exit=&ad_boundf;
  gradient_structure::set_NO_DERIVATIVES();
  gradient_structure::set_YES_SAVE_VARIABLES_VALUES();
  if (!arrmblsize){
    arrmblsize = 15000000;
  }
  model_parameters mp(arrmblsize,argc,argv);
  mp.iprint = 10;
  mp.preliminary_calculations();
  mp.computations(argc,argv);
  return 0;
}

extern "C"  {
  void ad_boundf(int i){
    exit(i);
  }
}
