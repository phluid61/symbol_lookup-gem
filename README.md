Symbol Lookup Gem
=================

A gemified version of the Symbol[str] method proposed in https://bugs.ruby-lang.org/issues/7854


 call-seq:
    Symbol[str] => Symbol or nil

 Returns an extant symbol, which is the `.to_sym` of _str_, or
 nil if no such symbol exists.

    Symbol['Object'] #=> :Object
    Symbol['none such'] #=> nil

