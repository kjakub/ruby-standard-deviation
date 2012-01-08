require 'StandardDeviation'
require 'benchmark'

class Array
  def sum
    inject(0.0) { |result, el| result + el }
  end

  def mean 
    sum / size
  end
end


Benchmark.bm do |x|
  x.report("C Extension") {
   (1..5000).to_a.standard_deviation
  }
  x.report("Native Ruby"){
    a = (1..5000).to_a
    avg = a.mean
    distance = a.inject(0.0){|result, element| result + (element - avg)**2}
    Math.sqrt(distance/a.length)
  }
end