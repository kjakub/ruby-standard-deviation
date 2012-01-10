%module StandardDeviation

%{
  #include <vector>
	#include "standard_deviation.c++"
%}

%include <std_vector.i>

namespace std {
   %template(FloatVector) vector<float>;
}

%include "standard_deviation.c++"
