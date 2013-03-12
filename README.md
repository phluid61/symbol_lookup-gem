Symbol Lookup Gem
=================

A gemified version of the `Symbol[str]` method proposed in https://bugs.ruby-lang.org/issues/7854

```
 call-seq:
    Symbol[str]  => Symbol or nil
    str.interned => Symbol or nil
    str.to_existing_sym => Symbol or ArgumentError
```

Returns an extant symbol, which is the `.to_sym` of _str_, or
nil if no such symbol exists.

```ruby
Symbol['Object'] #=> :Object
Symbol['none such'] #=> nil

'Object'.interned #=> :Object
'none such'.interned #=> nil

'Object'.to_existing_sym #=> :Object
'none such'.to_existing_sym #=> (raises ArgumentError)
```
