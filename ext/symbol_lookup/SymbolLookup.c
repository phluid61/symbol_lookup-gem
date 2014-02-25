/*
 * Copyright (c) 2013, Matthew Kerwin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ruby.h"

 /*
  *  call-seq:
  *     Symbol.find str => Symbol or nil
  *     Symbol[str] => Symbol or nil
  *
  *  Returns an extant symbol, which is the .to_sym of +str+, or
  *  nil if no such symbol exists.
  *
  *     Symbol.find 'Object' #=> :Object
  *     Symbol.find 'none such' #=> nil
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
 *     str.interned?  -> symbol
 *
 *  Returns the <code>Symbol</code> corresponding to <i>str</i>, returning
 *  nil if it did not previously exist.  See <code>Symbol[str]</code>.
 *
 *     x = :banana
 *     "banana".interned?         #=> :banana
 *     "mango".interned?          #=> nil
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
VALUE
str_interned_dep(VALUE str)
{
	rb_warn("String#interned is deprecated; use #interned? instead");
	return str_interned(str);
}
VALUE
sym_interned_dep(VALUE sym)
{
	rb_warn("Symbol#interned is deprecated; use #interned? instead");
	return sym;
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
    rb_define_singleton_method(rb_cSymbol, "find", sym_lookup, 1);
    rb_define_method(rb_cSymbol, "interned", sym_interned_dep, 0);
    rb_define_alias(rb_cSymbol, "interned?", "intern");
    rb_define_alias(rb_cSymbol, "to_existing_sym", "to_sym");

    rb_define_method(rb_cString, "interned", str_interned_dep, 0);
    rb_define_method(rb_cString, "interned?", str_interned, 0);
    rb_define_method(rb_cString, "to_existing_sym", str_to_existing_sym, 0);
}
