require 'test_helper'

class TestClass
  include StandardDeviation
end

class RubyStandardDeviationTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::RubyStandardDeviation::VERSION
  end

  def test_exception_for_non_array
    assert_raises TypeError do
      TestClass.new.stdev
    end

    assert_raises TypeError do
      TestClass.new.stdevs
    end

    assert_raises TypeError do
      TestClass.new.stdevp
    end
  end

  def test_sample_standard_deviation
    assert_in_delta 3.027650354, (1..10).to_a.stdev, 0.001
  end
end
