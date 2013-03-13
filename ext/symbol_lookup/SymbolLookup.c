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

/*
 *  call-seq:
 *     str.interned   -> symbol
 *
 *  Returns the <code>Symbol</code> corresponding to <i>str</i>, returning
 *  nil if it did not previously exist.  See <code>Symbol[str]</code>.
 *
 *     x = :banana
 *     "banana".interned          #=> :banana
 *     "mango".interned           #=> nil
 *
 */

VALUE
str_interned(VALUE str)
{
    ID id;

    if (id = rb_check_id(&str)) {
        return ID2SYM(id);
    }
    return Qnil;
}

/*
 *  call-seq:
 *     str.to_existing_sym   -> symbol
 *
 *  Returns the <code>Symbol</code> corresponding to <i>str</i>, raising an
 *  ArgumentError if it did not previously exist.
 *  See <code>Symbol[str]</code>
 *
 *     x = :banana
 *     "banana".to_existing_sym   #=> :banana
 *     "mango".to_existing_sym    #=> (raises ArgumentError)
 *
 */

VALUE
str_to_existing_sym(VALUE str)
{
    ID id;

    if (id = rb_check_id(&str)) {
        return ID2SYM(id);
    }
    rb_raise(rb_eArgError, "undefined symbol :'%s'", StringValuePtr(str));
    return Qnil;
}


void Init_symbol_lookup() {
    rb_define_singleton_method(rb_cSymbol, "[]", sym_lookup, 1);
    rb_define_alias(rb_cSymbol, "interned", "intern");
    rb_define_alias(rb_cSymbol, "to_existing_sym", "to_sym");

    rb_define_method(rb_cString, "interned", str_interned, 0);
    rb_define_method(rb_cString, "to_existing_sym", str_to_existing_sym, 0);
}
