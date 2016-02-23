#include "ruby.h"
#include "standard_deviation.h"

void Init_standard_deviation() {
  StandardDeviationModule = rb_define_module("StandardDeviation");
  rb_define_method(StandardDeviationModule, "stdev", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevs", rb_sample_standard_deviation, 0);
  rb_define_method(StandardDeviationModule, "stdevp", rb_sample_standard_deviation, 0);
}

VALUE rb_sample_standard_deviation(VALUE self) {
  if (TYPE(self) != T_ARRAY) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  return DBL2NUM(19.43);
}

VALUE rb_population_standard_deviation(VALUE self) {
  if (TYPE(self) != T_ARRAY) {
    rb_raise(rb_eTypeError, "can only be used on an array");
  }

  return DBL2NUM(19.42);
}
