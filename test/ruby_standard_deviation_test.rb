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
    assert_in_delta 13.65039682, ((1..10).to_a + [-41, 0]).stdev, 0.00001
  end

  def test_sample_standard_deviation_with_non_number
    assert_raises TypeError do
      ((1..10).to_a + [-41, "a", 0]).stdev
    end
  end

  def test_population_standard_deviation
    assert_in_delta 12.55660528, ((1..10).to_a + [-41, 1.32, 0]).stdevp, 0.00001
  end

  def test_population_standard_deviation_with_non_number
    assert_raises TypeError do
      ((1..10).to_a + [-41, "a", 0]).stdev
    end
  end
end
