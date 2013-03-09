#include "ruby.h"

 /*
  *  call-seq:
  *     Symbol[str] => Symbol or nil
  *
  *  Returns an extant symbol, which is the .to_sym of +str+, or
  *  nil if no such symbol exists.
  *
  *     Symbol['Object'] #=> :Object
  *     Symbol['none such'] #=> nil
  */

VALUE
sym_lookup(VALUE cls, VALUE str)
{
    st_data_t id;
    if (id = rb_check_id(&str)) {
	return ID2SYM(id);
    }
    return Qnil;
}

void Init_symbol_lookup() {
    rb_define_singleton_method(rb_cSymbol, "[]", sym_lookup, 1);
}
