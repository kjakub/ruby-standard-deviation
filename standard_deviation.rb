require 'ruby-standard-deviation'
require 'benchmark'

class Array
  def sum
    inject(0.0) { |result, el| result + el }
  end

  def mean 
    sum / size
  end
end

a = (1..1000000).to_a

Benchmark.bm do |x|
  x.report("C Extension") {
   a.standard_deviation
  }
  x.report("Native Ruby"){
    avg = a.mean
    distance = a.inject(0.0){|result, element| result + (element - avg)**2}
    Math.sqrt(distance/a.length)
  }
  x.report("Native Ruby #2"){
    avg = a.mean
    distance= 0
    a.each do |element|
      distance += (element - avg)**2
    end
    Math.sqrt(distance/a.length)
  }
end