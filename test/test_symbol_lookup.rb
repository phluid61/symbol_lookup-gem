require 'test/unit'

$VERBOSE = true
require "#{File.dirname File.dirname(__FILE__)}/lib/symbol_lookup"
class Test_symbol_lookup < Test::Unit::TestCase
	def test_symbol_lookup_success
		syms = Hash[ *Symbol.all_symbols.map{|s| [s.to_s, s] }.flatten ]
		defined_str = syms.keys.first
		defined_sym = syms[defined_str]
		undef_str = 'undefined symbol'
		# ensure the undefined symbol really is undefined
		while syms.has_key? undef_str
			undef_str << 'X'
		end

		assert_equal( defined_sym, Symbol[defined_str] )
		assert_equal( defined_sym, Symbol[defined_sym] )
		assert_nil( Symbol[undef_str] )
	end

	def test_symbol_lookup_failure
		assert_raise(TypeError) { Symbol[1] } # TypeError: 1 is not a symbol
		assert_raise(ArgumentError) { Symbol[] } # ArgumentError: wrong number of arguments (0 for 1)
		assert_raise(ArgumentError) { Symbol['a','b'] } # ArgumentError: wrong number of arguments (2 for 1)
	end

	def test_interned
		syms = Hash[ *Symbol.all_symbols.map{|s| [s.to_s, s] }.flatten ]
		defined_str = syms.keys.first
		defined_sym = syms[defined_str]
		undef_str = 'undefined symbol'
		# ensure the undefined symbol really is undefined
		while syms.has_key? undef_str
			undef_str << 'X'
		end

		assert_equal( defined_sym, defined_str.interned )
		assert_equal( defined_sym, defined_sym.interned )
		assert_nil( undef_str.interned )
	end

	def test_to_existing_sym
		syms = Hash[ *Symbol.all_symbols.map{|s| [s.to_s, s] }.flatten ]
		defined_str = syms.keys.first
		defined_sym = syms[defined_str]
		undef_str = 'undefined symbol'
		# ensure the undefined symbol really is undefined
		while syms.has_key? undef_str
			undef_str << 'X'
		end

		assert_equal( defined_sym, defined_str.to_existing_sym )
		assert_equal( defined_sym, defined_sym.to_existing_sym )
		assert_raise(ArgumentError) { undef_str.to_existing_sym }
	end
end

