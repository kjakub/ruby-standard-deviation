#include "ruby.h"
double total;
static VALUE reject_i(VALUE self)
{
  total = total + NUM2DBL(self);
  return Qnil;
}

static VALUE t_summarize(VALUE self)
{

  VALUE value;
  total = 0;

  rb_iterate(rb_each, self, reject_i, 0); 

  return rb_float_new(total);
}





void Init_StandardDeviation() {
  rb_define_method(rb_cArray, "summarize", t_summarize, 0);
}
