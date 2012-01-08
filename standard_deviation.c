#include "ruby.h"
#include "math.h"
double total;
double mean;
double total_distance_from_mean;

VALUE sum(VALUE self)
{
  total = total + NUM2DBL(self);
  return Qnil;
}
VALUE distance_from_mean(VALUE self)
{
  total_distance_from_mean = total_distance_from_mean + pow((NUM2DBL(self) - mean),2);
  return Qnil;
}
double get_mean(VALUE ary)
{
  rb_iterate(rb_each, ary, sum, 0); 
  if(RARRAY_LEN(ary) == 0){
    return 0.0;
  } else {
    return total/RARRAY_LEN(ary);
  }
}

static VALUE standard_deviation(VALUE self)
{
  mean = get_mean(self);
  total_distance_from_mean = 0;
  rb_iterate(rb_each, self, distance_from_mean, 0);
  if (RARRAY_LEN(self)==0){
    return rb_float_new(0);
  } else {
    return rb_float_new(sqrt((total_distance_from_mean/RARRAY_LEN(self))));
  }
    
}





void Init_StandardDeviation()
{
  total = 0;
  rb_define_method(rb_cArray, "standard_deviation", standard_deviation, 0);
}
