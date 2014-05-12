DATA_SECTION
  init_int nobs
  init_vector Y(1,nobs)
  init_vector x(1,nobs)
PARAMETER_SECTION
  init_number a   
  init_number b   
  vector pred_Y(1,nobs)
  objective_function_value f
PROCEDURE_SECTION
  SexStructure s(1); //Split sex model
  Area one(s);
  AreaContainer ac;
  ac.addArea(one);
  Stock stock(ac);
  //SexStructure sexStruct(0); // Both combined
  //stock.setSexStruct(0);
  //stock.setName("Test Stock");
  //cout<<"Sex structure is '"<<sexStruct.getStatus()<<"'"<<endl;
  //cout<<stock.getName()<<endl;

  pred_Y=a*x+b;
  f=(norm2(pred_Y-Y)); 
  f=nobs/2.*log(f);    // make it a likelihood function so that
                       // covariance matrix is correct

GLOBALS_SECTION
  #include "Stock.h"
  #include "AreaContainer.h"
  #include "Area.h"
  #include "SexStructure.h"
