Gem::Specification.new do |s|
  s.name = 'symbol_lookup'
  s.version = '1.2.0'
  s.date = '2014-02-26'
  s.required_ruby_version = '~> 2.0.0'
  s.summary = 'Symbol.find'
  s.description = 'A gemified version of the Symbol.find(str) method'
  s.authors = ['Matthew Kerwin']
  s.email = 'matthew@kerwin.net.au'

  s.files = ['ext/symbol_lookup/SymbolLookup.c']
  s.extensions = ['ext/symbol_lookup/extconf.rb']

  s.homepage = 'http://rubygems.org/gems/symbol_lookup'
  s.license = 'ISC'

  s.has_rdoc = true
  s.rdoc_options <<
      '--title' << 'Symbol.find' <<
      '--main' << 'Symbol' <<
      '--line-numbers' <<
      '--tab-width' << '2'
end
