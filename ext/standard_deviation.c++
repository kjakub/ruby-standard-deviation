#include "math.h"

double native_standard_deviation(std::vector<float> array)
{
  unsigned int i;
  double total = 0;

  for(i = 0; i < array.size(); i++){
    total += array[i];
  }

  double mean = total / array.size();
  
  double total_distance_from_mean = 0;

  for(i = 0; i < array.size(); i++){
    total_distance_from_mean += pow((array[i] - mean),2);
  }  

  return sqrt((total_distance_from_mean/array.size()));

}

