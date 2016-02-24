require "minitest/benchmark"
require "test_helper"

class RubyStandardDeviationBenchmark < Minitest::Benchmark
  def bench_native_extension
    assert_performance_constant 0.99 do |input|
      (1..1000000).to_a.stdev
    end
  end

  def bench_pure_ruby
    assert_performance_constant 0.99 do |input|
      array = (1..1000000).to_a
      total = array.inject(0) {|total, element| total + element }
      mean = total.to_f / array.size
      total_distance_from_mean = array.inject(0){|total, element| total + (element - mean)**2 }
      Math.sqrt(total_distance_from_mean/(array.size-1))
    end
  end
end
