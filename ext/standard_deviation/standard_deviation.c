#include "ruby.h"
#include "standard_deviation.h"

void Init_standard_deviation() {
  StandardDeviationModule = rb_define_module("StandardDeviation");
  rb_define_method(StandardDeviationModule, "stdev", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevs", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevp", rb_population_standard_deviation, 0);
}

double calculate_total_distance_from_mean(VALUE array, unsigned long array_length){
  unsigned long i;
  double total = 0;
  double mean = 0;
  double total_distance_from_mean = 0;

  for(i = 0; i < array_length; i++){
    total += rb_num2dbl(rb_ary_entry(array, i));
  }

  mean = total / array_length;

  for(i = 0; i < array_length; i++){
    total_distance_from_mean += pow((rb_num2dbl(rb_ary_entry(array, i)) - mean), 2);
  }

  return total_distance_from_mean;
}

VALUE rb_sample_standard_deviation(VALUE self) {
  unsigned int array_length = rb_long2int(RARRAY_LEN(self));

  if (RB_TYPE_P(self, T_ARRAY) == 0) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  if (array_length <= 1) {
    rb_raise(rb_eRangeError, "array must have more than one element");
  }

  return DBL2NUM(sqrt((calculate_total_distance_from_mean(self, array_length)/(array_length - 1))));
}

VALUE rb_population_standard_deviation(VALUE self) {
  unsigned int array_length = rb_long2int(RARRAY_LEN(self));

  if (RB_TYPE_P(self, T_ARRAY) == 0) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  if (array_length <= 1) {
    rb_raise(rb_eRangeError, "array must have more than one element");
  }

  return DBL2NUM(sqrt(calculate_total_distance_from_mean(self, array_length) / array_length));
}
