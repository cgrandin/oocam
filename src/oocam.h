#if !defined(_OOCAM_H)
#define _OOCAM_H

class model_data : public ad_comm{
  data_int nsexage, nsexcatch, nsexsel, syr, nyr, nage, sage, ngear;
  data_int nobs;
  data_vector Y;
  data_vector x;
  ~model_data();
  model_data(int argc,char * argv[]);
  friend class model_parameters;
};

class model_parameters : public model_data , public function_minimizer{
public:
  ~model_parameters();
  void preliminary_calculations(void);
  void set_runtime(void);
  virtual void * mycast(void) {return (void*)this;}
  static int mc_phase(void){
    return initial_params::mc_phase;
  }
  static int mceval_phase(void){
    return initial_params::mceval_phase;
  }
  static int sd_phase(void){
    return initial_params::sd_phase;
  }
  static int current_phase(void){
    return initial_params::current_phase;
  }
  static int last_phase(void){
    return (initial_params::current_phase >= initial_params::max_number_phases);
  }
  static prevariable current_feval(void){
    return *objective_function_value::pobjfun;
  }
private:
  ivector integer_control_flags;
  dvector double_control_flags;
  param_init_number a;
  param_init_number b;
  param_vector pred_Y;
  param_number prior_function_value;
  param_number likelihood_function_value;
  objective_function_value f;
public:
  virtual void userfunction(void);
  virtual void report(const dvector& gradients);
  virtual void final_calcs(void);
  model_parameters(int sz,int argc, char * argv[]);
  virtual void initializationfunction(void){}
};
#endif
