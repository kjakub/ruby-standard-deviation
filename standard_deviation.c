#include "ruby.h"
#include "standard_deviation.h"


static VALUE t_summarize(VALUE self)
{
  VALUE arr;

  arr = rb_ary_new();
  rb_iv_set(self, "@arr", arr);
  return self;
}



VALUE cStandardDeviation;


void Init_StandardDeviation() {
  cStandardDeviation = rb_define_class("StandardDeviation", rb_cArray);
  rb_define_method(cStandardDeviation, "summarize", t_summarize, 0);
}
