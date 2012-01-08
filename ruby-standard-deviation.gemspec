
require "rake"



Gem::Specification.new do |s|
  s.name        = "ruby-standard-deviation"
  s.version     = "1.0.0"
  s.authors     = "Cory Buecker"
  s.date        = Time.now.strftime("%Y-%m-%d")
  s.email       = "email@corybuecker.com"
  s.homepage    = "http://github.com/thegreyjoy/ruby-standard-deviation"
  s.summary     = "Adds a method to the Array class to perform standard deviation calculations"
  s.description = "Adds a method to the Array class to perform standard deviation calculations"

s.files = FileList['ext/*', 'lib/*', '[A-Z]*', '.gitignore'].to_a
s.extensions << 'ext/extconf.rb'
s.require_paths = ["lib"]
end