/*
* Library of misc functions for use in multiple projects
* By: Ronnie Williams
* October 20, 2020
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>


// Displays a vector seperating each value by a delimiter
template <typename T>
void displayVector(std::vector<T> &arr, char delimiter=' ') {

  for(int i=0; i<arr.size(); i++) {
    std::cout << arr[i];
    if(i<(arr.size()-1)) std::cout << delimiter;
  }

  std::cout << "\n";
  return;
}

// Get the max value from a vector
int get_max(std::vector<int> &arr) {

  int max = arr[0];
  for(int i=1; i<arr.size(); i++) if(arr[i]>max) max = arr[i];
  return max;
}

// Cout with specified length & fill
template <typename T>
void print(T t, int spacing, char fill=' ') {

  std::cout << std::left << std::setw(spacing) << std::setfill(fill) << t;
  return;
}

// Cout with specified length & fill including end line 
template <typename T>
void println(T t, int spacing, char fill=' ') {

  std::cout << std::left << std::setw(spacing) << std::setfill(fill) << t << "\n";
  return;
}