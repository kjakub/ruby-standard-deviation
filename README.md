# Ruby Standard Deviation [reverted before it got yanked from rubygems]

[![Build Status](https://travis-ci.org/corybuecker/ruby-standard-deviation.svg)](https://travis-ci.org/corybuecker/ruby-standard-deviation)

This is a native extension to Ruby that adds a standard deviation calculation to the Array class.

Check the TravisCI build to see the currently supported versions of Ruby. This list will match whatever versions are specified at https://www.ruby-lang.org/en/downloads/.

It is much more performant than calculating the standard deviation with pure Ruby. For a comparison, run the benchmarks with rake.

    bench_native_extension   0.000573	 0.000507	 0.000616	 0.000606	 0.000528
    bench_pure_ruby          0.004794	 0.004045	 0.002673	 0.002667	 0.003728

## Usage

    require 'ruby-standard-deviation'
    r = [1,3,21,32,42]

    # calculate sample standard deviation, you can also use "stdevs"
    p r.stdev

    # calculate population standard deviation
    p r.stdevp

## Links

This is the second version of this gem, and it is a total rewrite of a SWIG-based design. Lots of thanks to the following resources:

* https://blog.jcoglan.com/2012/07/29/your-first-ruby-native-extension-c/
* https://github.com/andremedeiros/ruby-c-cheat-sheet
* http://silverhammermba.github.io/emberb/c/
* http://docs.ruby-lang.org/en/2.3.0/extension_rdoc.html
