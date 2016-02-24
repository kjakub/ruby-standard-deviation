# Ruby Standard Deviation

This is a native extension to Ruby that adds a standard deviation calculation to the Array class. It is much more performant than calculating the standard deviation with pure Ruby. For a comparison, run the benchmarks with rake.

    bench_native_extension    0.057660  0.048161  0.054150  0.049357  0.048524
    bench_pure_ruby           0.267613  0.269168  0.289011  0.271467  0.279694

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
