Gem::Specification.new do |s|
  s.name = 'symbol_lookup'
  s.version = '1.1.0'
  s.date = '2013-03-12'
  s.required_ruby_version = '>= 2.0.0'
  s.summary = 'Symbol[str]'
  s.description = 'A gemified version of the Symbol[str] method proposed in https://bugs.ruby-lang.org/issues/7854'
  s.authors = ['Matthew Kerwin']
  s.email = 'matthew@kerwin.net.au'

  s.files = ['ext/symbol_lookup/SymbolLookup.c']
  s.extensions = ['ext/symbol_lookup/extconf.rb']

  s.homepage = 'http://rubygems.org/gems/symbol_lookup'
  s.license = 'Simplified BSD License'

  s.has_rdoc = true
  s.rdoc_options <<
      '--title' << 'Symbol[]' <<
      '--main' << 'Symbol' <<
      '--line-numbers' <<
      '--tab-width' << '2'
end
