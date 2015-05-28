// oocam.cpp
// This is the main model code, which creates the objects and
//  minimizes the model.

// Singleton logger class, can be accessed through any other class
#include "Logger.h"

// include oocam-related header files
#include "Stock.h"

// include ADMB-related header files
#include <admodel.h>
#include <contrib.h>

// required for proper implementation of ad_exit
extern "C"  {
  void ad_boundf(int i);
}

#include <oocam.h>

// Must put Stock object at global scope due to ADMB's non-OO
// design. This way, it can be referenced in the model_data and
// model_parameter classes and in model_parameters::userfunction.
Stock stock;
//Logger* logger = Logger::Instance();

model_data::model_data(int argc,char * argv[]) : ad_comm(argc,argv){
  stock.allocate();
  //parameters.allocate();

  // Old remnants of simple.cpp
  //nobs.allocate("nobs");
  //Y.allocate(1,nobs,"Y");
  //x.allocate(1,nobs,"x");
}

model_parameters::model_parameters(int sz,int argc,char * argv[]) :
 model_data(argc,argv) , function_minimizer(sz){
  initializationfunction();

  // Old remnants of simple.cpp
  // a.allocate("a");
  // b.allocate("b");
  // pred_Y.allocate(1,nobs,"pred_Y");
  // #ifndef NO_AD_INITIALIZE
  //   pred_Y.initialize();
  // #endif
  // f.allocate("f");
  // prior_function_value.allocate("prior_function_value");
  // likelihood_function_value.allocate("likelihood_function_value");
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

  // Old remnants of simple.cpp
  // pred_Y = a*x+b;
  // f = norm2(pred_Y-Y);
  // f = nobs/2.*log(f);
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
  ad_exit = &ad_boundf;
	arrmblsize = 200000000;
	gradient_structure::set_GRADSTACK_BUFFER_SIZE(1.e7);
	gradient_structure::set_CMPDIF_BUFFER_SIZE(1.e7);
	gradient_structure::set_MAX_NVAR_OFFSET(5000);
	gradient_structure::set_NUM_DEPENDENT_VARIABLES(5000);
  gradient_structure::set_NO_DERIVATIVES();
  gradient_structure::set_YES_SAVE_VARIABLES_VALUES();
  model_parameters mp(arrmblsize,argc,argv);
  mp.iprint = 10;
  mp.preliminary_calculations();
  mp.computations(argc,argv);
  return 0;
}

// required for proper implementation of ad_exit
extern "C"  {
  void ad_boundf(int i){
    exit(i);
  }
}
