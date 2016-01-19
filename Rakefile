#!/usr/bin/env rake
require 'bundler/gem_tasks'
require 'rake/testtask'
task :default => %i[build test]
Rake::TestTask.new do |tt|
	tt.verbose = true
end

task :build => %w[lib/symbol_lookup.so]
file 'lib/symbol_lookup.so' => 'ext/symbol_lookup/symbol_lookup.so' do |t|
	sh "cp #{t.source} #{t.name}"
end
file 'ext/symbol_lookup/symbol_lookup.so' do |t|
	sh 'cd ext/symbol_lookup && ruby extconf.rb && make'
end

