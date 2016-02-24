#include "ruby.h"
#include "standard_deviation.h"

void Init_standard_deviation() {
  StandardDeviationModule = rb_define_module("StandardDeviation");
  rb_define_method(StandardDeviationModule, "stdev", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevs", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevp", rb_population_standard_deviation, 0);
}

VALUE rb_sample_standard_deviation(VALUE self) {
  if (RB_TYPE_P(self, T_ARRAY) == 0) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  double total = 0;
  double mean = 0;
  double result = 0;
  double total_distance_from_mean = 0;
  unsigned int array_length = rb_long2int(rb_array_len(self));
  unsigned long i;

  if (array_length <= 1) {
    rb_raise(rb_eRangeError, "array must have more than one element");
  }

  for(i = 0; i < array_length; i++){
    total += rb_num2dbl(rb_ary_entry(self, i));
  }

  mean = total / array_length;

  for(i = 0; i < array_length; i++){
    total_distance_from_mean += pow((rb_num2dbl(rb_ary_entry(self, i)) - mean), 2);
  }

  result = sqrt((total_distance_from_mean/(array_length - 1)));

  return DBL2NUM(result);
}

VALUE rb_population_standard_deviation(VALUE self) {
  if (RB_TYPE_P(self, T_ARRAY) == 0) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  double total = 0;
  double mean = 0;
  double result = 0;
  double total_distance_from_mean = 0;
  unsigned int array_length = rb_long2int(rb_array_len(self));
  unsigned long i;

  if (array_length <= 1) {
    rb_raise(rb_eRangeError, "array must have more than one element");
  }

  for(i = 0; i < array_length; i++){
    total += rb_num2dbl(rb_ary_entry(self, i));
  }

  mean = total / array_length;

  for(i = 0; i < array_length; i++){
    total_distance_from_mean += pow((rb_num2dbl(rb_ary_entry(self, i)) - mean), 2);
  }

  result = sqrt(total_distance_from_mean / array_length);

  return DBL2NUM(result);
}
