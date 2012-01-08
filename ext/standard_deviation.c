#include "ruby.h"
#include "math.h"
double get_mean(double array[], long array_length)
{
  double total = 0;
  int i = 0;

  while (i < array_length){
    total += array[i++];
  }
  if(array_length == 0){
    return 0.0;
  } else {
    return total / array_length;
  }
}

VALUE standard_deviation(VALUE ary)
{
  int i = 0;
  
  long array_length = RARRAY_LEN(ary);
  VALUE* array_pointer = RARRAY_PTR(ary);
  double array[array_length];
  while (i < array_length){
    array[i] = NUM2DBL(array_pointer[i++]);
  }
  double mean = get_mean(array, array_length);
  double total_distance_from_mean = 0;
  
  i = 0;
  while (i < array_length){
    total_distance_from_mean = total_distance_from_mean + pow((array[i++] - mean),2);
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
