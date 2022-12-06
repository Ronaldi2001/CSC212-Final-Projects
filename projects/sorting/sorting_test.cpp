/*
* Project to test multiple sorting algorithms with
* various types of number orders and number amounts
* By: Ronnie Williams
* October 20, 2020
*/

#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include "../../utils.hpp"
#include "libs/sorting_algorithms.hpp"


void test_sorts(std::vector<int> &orig, const std::string &name) {

  const static int name_space = 12, time_space = 15;
  std::vector<int> arr;
  clock_t time;

  // Test title
  std::cout << "\nSorting " << name << " numbers with length " << orig.size() << "\n";

  // Header
  RUTILS::print("Name", name_space);
  RUTILS::print("Asc. (µs)", time_space);
  RUTILS::println("Dec. (µs)", time_space);
  RUTILS::println("", ((time_space*2)+name_space), '-');

  RUTILS::print("Insertion", name_space);

  // Test insertion asc.
  arr = orig;
  time = clock();
  insertion_sort(arr);
  time = clock() - time;
  RUTILS::print(time, time_space);

  // Test insertion dec.
  arr = orig;
  time = clock();
  insertion_sort(arr, false);
  time = clock() - time;
  RUTILS::println(time, time_space);

  RUTILS::print("Merge", name_space);

  // Test merge asc.
  arr = orig;
  time = clock();
  merge_sort(arr);
  time = clock() - time;
  RUTILS::print(time, time_space);

  // Test merge dec.
  arr = orig;
  time = clock();
  merge_sort(arr, false);
  time = clock() - time;
  RUTILS::println(time, time_space);

  RUTILS::print("Quick", name_space);

  // Test quick asc.
  arr = orig;
  time = clock();
  quick_sort(arr, 0, arr.size()-1);
  time = clock() - time;
  RUTILS::print(time, time_space);

  // Test quick dec.
  arr = orig;
  time = clock();
  quick_sort(arr, 0, arr.size()-1, false);
  time = clock() - time;
  RUTILS::println(time, time_space);

  RUTILS::print("Radix", name_space);

  // Test radix asc.
  arr = orig;
  time = clock();
  radix_sort(arr);
  time = clock() - time;
  RUTILS::print(time, time_space);

  // Test radix dec.
  arr = orig;
  time = clock();
  radix_sort(arr, false);
  time = clock() - time;
  RUTILS::println(time, time_space);

  return;
}

void generate_tests(int num_amt) {

  std::vector<int> sort_nums, rev_nums, rand_nums, part_sort_nums;

  // Generate numbers to test
  for(int i=0; i<num_amt; i++) {

    int rnum = std::rand()%100+1;

    sort_nums.push_back(i);
    rev_nums.push_back(num_amt-i);
    rand_nums.push_back(rnum);
    part_sort_nums.push_back(rnum<75 ? i : rnum);

  }

  // Test the sorts based on the generated numbers
  test_sorts(sort_nums, "sorted");
  test_sorts(rev_nums, "reversed");
  test_sorts(rand_nums, "random");
  test_sorts(part_sort_nums, "partially sorted");

  return;
}


int main(int argc, char *argv[]) {

  // If the command line arguments arent valid
  if(argc!=2) {
    std::cout << "\nUsage: './sorting_test <seed>'\nArgs:\n";
    std::cout << "  <seed> - An integer for generating multiple tests with same random numbers\n\n";
    return 0;
  }

  std::srand(std::stoi(argv[1]));

  // Tests all sorts 3 times with different sizes
  int num_amt = 2000;
  generate_tests(num_amt);
  generate_tests(num_amt*2);
  generate_tests(num_amt*10);

  // End program
  return 0;
}

