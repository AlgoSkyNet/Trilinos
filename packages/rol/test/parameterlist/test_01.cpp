#include "ROL_ParList.hpp"
#include <iostream>

int main( int argc, char* argv[] ) {

  auto os_ptr = ROL::makeStreamPtr(std::cout, argc);
  auto& os = *os_ptr;
  int errorFlag = 0;

  try {

    auto parlist = ROL::ParList();

    auto& genlist = parlist.sublist("General");
    genlist.set("Inexact Objective Function",false);
    genlist.set("Inexact Gradient",false);
    genlist.set("Inexact Hessian-Times-A-Vector",false);

    auto& secant = genlist.sublist("Secant");
    secant.set("Type","Limited-Memory BFGS");
    secant.set("Use as Preconditioner",true);
    secant.set("Use as Hessian",false);
    secant.set("Maximum Storage",10);
    
    auto& krylov = genlist.sublist("Krylov");
    krylov.set("Type","Conjugate Gradients");
    krylov.set("Absolute Tolerance",1.e-4);
    krylov.set("Relative Tolerance",1.e-2);
    krylov.set("Iteration Limit",100);

    auto& step = parlist.sublist("Step");
    auto& ls = step.sublist("Line Search");
    ls.set("Function Evaluation Limit", 20);
    ls.set("Sufficient Decrease Tolerance", 1.e-4);

    auto& dm = ls.sublist("Descent Method");
    dm.set("Type","Newton-Krylov");

    auto& cc = ls.sublist("Curvature Condition");
    cc.set("Type","Strong Wolfe Conditions");
    cc.set("General Parameter","0.9");
    cc.set("Generalized Wolfe Parameter","0.6");

    auto& lsm = ls.sublist("Line-Search Method");
    lsm.set("Type","Cubic Interpolation");
    lsm.set("Backtracking Rate","0.5");
    os << parlist; 

  } catch( std::exception& e ) {
    errorFlag = -1000;
    os << e.what() << std::endl;
  };
  
  if( errorFlag ) std::cout << "End Result: TEST FAILED\n";
  else            std::cout << "End Result: TEST PASSED\n"; 

  return 0;
}

