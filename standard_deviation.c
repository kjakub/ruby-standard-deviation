#include "ruby.h"


static VALUE t_summarize(VALUE self)
{
  double total;
  double value;
  total = 0;
  while (value = rb_each(self)) {
    printf("%f\n",NUM2DBL(value));
    total = NUM2DBL(value);
  }
  return rb_float_new(total);
}



VALUE cStandardDeviation;


void Init_StandardDeviation() {
  cStandardDeviation = rb_define_class("StandardDeviation", rb_cArray);
  rb_define_method(cStandardDeviation, "summarize", t_summarize, 0);
}
