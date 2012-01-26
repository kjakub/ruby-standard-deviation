%module StandardDeviation

%exception native_sample_standard_deviation{
  try {
    $action
  }
  catch (signed int error) {
    SWIG_exception(SWIG_DivisionByZero, "you have to include at least two elements in the array");
  }
}
%exception native_population_standard_deviation{
  try {
    $action
  }
  catch (signed int error) {
    SWIG_exception(SWIG_DivisionByZero, "you have to include at least one element in the array");
  }
}


%{
  #include <vector>
	#include "standard_deviation.c++"
%}

%include <std_vector.i>

namespace std {
   %template(FloatVector) vector<float>;
}

%include "standard_deviation.c++"

