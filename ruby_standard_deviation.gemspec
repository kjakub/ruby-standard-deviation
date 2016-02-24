# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'ruby-standard-deviation/version'

Gem::Specification.new do |spec|
  spec.name          = "ruby-standard-deviation"
  spec.version       = RubyStandardDeviation::VERSION
  spec.authors       = ["Cory Buecker"]
  spec.email         = ["email@corybuecker.com"]

  spec.summary       = "This is a native extension to Ruby that adds a standard deviation calculation to the Array class."
  spec.homepage      = "https://github.com/corybuecker/ruby-standard-deviation"

  if spec.respond_to?(:metadata)
    spec.metadata['allowed_push_host'] = "https://rubygems.org"
  else
    raise "RubyGems 2.0 or newer is required to protect against public gem pushes."
  end

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.require_paths = ["lib"]

  spec.extensions << "ext/standard_deviation/extconf.rb"

  spec.add_development_dependency "bundler", "~> 1.11"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "minitest", "~> 5.0"
  spec.add_development_dependency "rake-compiler", "~> 0.9"
end
