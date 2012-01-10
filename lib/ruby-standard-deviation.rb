require 'ruby-standard-deviation/StandardDeviation'

class Array
  
  include StandardDeviation
  
  def standard_deviation
    native_standard_deviation(self)
  end
  
end