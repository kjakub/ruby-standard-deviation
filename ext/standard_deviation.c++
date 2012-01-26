#include "math.h"

double native_sample_standard_deviation(std::vector<float> array){
  unsigned int i;
  double total = 0;
  double mean;
  double result = 0 ;

  for(i = 0; i < array.size(); i++){
    total += array[i];
  }
  if(array.size() <= 1){
    throw -1;
  } else {
    mean = total / array.size();

    double total_distance_from_mean = 0;

    for(i = 0; i < array.size(); i++){
      total_distance_from_mean += pow((array[i] - mean),2);
    }  

    result = sqrt((total_distance_from_mean/(array.size() - 1)));
  }
  return result;
}

double native_population_standard_deviation(std::vector<float> array){
  unsigned int i;
  double total = 0;
  double mean;
  double result = 0 ;

  for(i = 0; i < array.size(); i++){
    total += array[i];
  }
  if(array.size() < 1){
    throw -1;
  } else {
    mean = total / array.size();

    double total_distance_from_mean = 0;

    for(i = 0; i < array.size(); i++){
      total_distance_from_mean += pow((array[i] - mean),2);
    }  

    result = sqrt((total_distance_from_mean / array.size()));
  }
  return result;
}