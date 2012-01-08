#include "ruby.h"
#include "math.h"

double get_mean(VALUE ary)
{
  VALUE* array_pointer = RARRAY_PTR(ary);
  double total = 0;
  int i = 0;
  long array_length = RARRAY_LEN(ary);
  while (i < array_length){
    total += NUM2DBL(array_pointer[i++]);
  }
  if(array_length == 0){
    return 0.0;
  } else {
    return total / array_length;
  }
}

VALUE standard_deviation(VALUE ary)
{
  double mean = get_mean(ary);
  double total_distance_from_mean = 0;
  VALUE* array_pointer = RARRAY_PTR(ary);
  int i = 0;
  long array_length = RARRAY_LEN(ary);
  while (i < array_length){
    total_distance_from_mean = total_distance_from_mean + pow((NUM2DBL(array_pointer[i++]) - mean),2);
  }
  
  if (array_length == 0){
    return rb_float_new(0);
  } else {
    return rb_float_new(sqrt((total_distance_from_mean/array_length)));
  }
    
}





void Init_StandardDeviation()
{
  rb_define_method(rb_cArray, "standard_deviation", standard_deviation, 0);
}
