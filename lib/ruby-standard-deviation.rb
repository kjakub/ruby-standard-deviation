require 'ruby-standard-deviation/StandardDeviation'

class Array
  
  include StandardDeviation
  
  def stdev
    native_sample_standard_deviation(self)
  end
  
  def stdevs
    native_sample_standard_deviation(self)
  end
  
  def stdevp
    native_population_standard_deviation(self)
  end
  
end