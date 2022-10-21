/*
* Library for sorting algorithms
* By: Ronnie Williams
* October 20, 2020
*/

#pragma once

#include <vector>


void insertion_sort(std::vector<int> &arr, bool ascending=true) {

  // Iterate over all the values until in correct sorting direction
  for(int i=1; i<arr.size(); i++) {

    int curr_pos = i;
    int prev_pos = i-1;

    // If the value is out of order depending on sorting direction swap value until in correct position
    while(((arr[curr_pos]<arr[prev_pos] && ascending) || (arr[curr_pos]>arr[prev_pos] && !ascending)) && prev_pos>=0) {
      
      std::swap(arr[curr_pos--], arr[prev_pos--]);
    }
  }

  return;
}

void merge_sort(std::vector<int> &arr, bool ascending=true) {

  int len = arr.size();

  // Base case
  if(len<=1) return;

  std::vector<int> left, right;

  int mid = len/2;
  int r = 0;

  // Iterate over all the values and seperate them to left or right
  for(int l=0; l<len; l++) {

    if(l<mid) left.push_back(arr[l]);
    else {
      right.push_back(arr[l]);
      r++;
    }
  }

  // Call itself for each new vector for left and right
  merge_sort(left, ascending);
  merge_sort(right, ascending);

  // Used for merging left and right
  int i = 0, ml = 0, mr = 0;
  int l_size = left.size(), r_size = right.size();

  // If both left and right have values
  while(ml<l_size && mr<r_size) {

    // Adds the value from left or right depending on sorting direction
    if((left[ml]<right[mr] && ascending) || (left[ml]>right[mr] && !ascending)) arr[i++] = left[ml++];
    else arr[i++] = right[mr++];
  }

  // If there are still values in left
  while(ml<l_size) arr[i++] = left[ml++];
  
  // If there are still values in right
  while(mr<r_size) arr[i++] = right[mr++];

  return;
}

void quick_sort(std::vector<int> &arr, int start, int end, bool ascending=true) {

  // Base case
  if(start>=end) return;

  // Keep track of index and value of the pivot
  int pivotIndex = start, pivotValue = arr[end];

  // Iterate over the vector from start to end
  // If the value isnt in the correct place swap the values and change the location of the pivot
  for(int i=start; i<end; i++) if((arr[i]<pivotValue && ascending) || (arr[i]>pivotValue && !ascending)) {

    std::swap(arr[i], arr[pivotIndex++]);
  }

  // Put the pivot back from the end in the correct position
  std::swap(arr[pivotIndex], arr[end]);

  // Call itself for each side of the pivot
  quick_sort(arr, start, pivotIndex-1, ascending);
  quick_sort(arr, pivotIndex+1, end, ascending);

  return;
}

void count_sort(std::vector<int> &arr, int *div_by, bool ascending=true) {

  // Amount of numbers to sort
  // Stored to not call the function over and over
  int size = arr.size();

  // Array for building output based on the count of digits
  int output[size];

  // Counter for keeping track of each digit
  const int COUNT_SIZE = 10;
  int count[COUNT_SIZE] = {0};

  // Get the count of each digit
  for(int num: arr) count[(num/(*div_by))%10]++;

  // Used if descending
  int count_orig[COUNT_SIZE];

  // If descending then copy count to count_orig
  if(!ascending) for(int c=0; c<COUNT_SIZE; c++) count_orig[c] = count[c];

  // Create positional index from the count
  for(int i=1; i<COUNT_SIZE; i++) count[i] = count[i] + count[i-1];

  // If descending subtract the amount from the orig +1 to make it reversed
  if(!ascending) for(int l=0; l<COUNT_SIZE; l++) {
    if(count_orig[l]>1) count[l] -= count_orig[l]+1;
  }

  // Create the output array from the count that is now positions
  for(int o=size-1; o>=0; o--) {
    
    // Get the digit that is in the count
    int digit = arr[o]/(*div_by)%10;

    // If there is only one count or ascending decrease the count position
    // else increment it to get reversed order
    // Set the output of position of count of the digit from the vector
    if(count_orig[digit]<=1 || ascending) output[--count[digit]] = arr[o];
    else output[++count[digit]] = arr[o];
  }

  // Move the output array back to the vector
  for(int m=0; m<size; m++) arr[m] = ascending ? output[m] : output[size-m-1];

  return;
}

void radix_sort(std::vector<int> &arr, bool ascending=true) {

  // Get the max number in the vector to sort
  // The max number will give the amount of iterations needed
  int max_num = get_max(arr);

  // using multiplication and division we can tell which digit we are in]
  // This is needed to count sort for every digit in the vector
  for(int i=1; max_num/i>0; i*=10) count_sort(arr, &i, ascending);

  return;
}