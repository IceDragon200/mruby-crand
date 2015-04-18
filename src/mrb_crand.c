#include <stdlib.h>
#include <mruby.h>
#include <mruby/class.h>

static mrb_value
crand_rand(mrb_state *mrb, mrb_value mod)
{
  return mrb_fixnum_value(rand());
}

static mrb_value
crand_srand(mrb_state *mrb, mrb_value mod)
{
  mrb_int seed;
  mrb_get_args(mrb, "i", &seed);
  srand(seed);
  return mod;
}

void
mrb_mruby_crand_gem_init(mrb_state *mrb)
{
  struct RClass *crand_module = mrb_define_module(mrb, "Crand");
  mrb_define_class_method(mrb, crand_module, "rand", crand_rand, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, crand_module, "srand", crand_srand, MRB_ARGS_REQ(1));
}

void
mrb_mruby_crand_gem_final(mrb_state *mrb)
{
}
