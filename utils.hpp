/*
* Library of misc functions for use in multiple projects
* By: Ronnie Williams
* October 20, 2020
*/

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

namespace RUTILS {

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
  void print(T t, int spacing=1, char fill=' ') {

    std::cout << std::left << std::setw(spacing) << std::setfill(fill) << t;
    return;
  }

  // Cout with specified length & fill including end line 
  template <typename T>
  void println(T t, int spacing=1, char fill=' ') {

    std::cout << std::left << std::setw(spacing) << std::setfill(fill) << t << "\n";
    return;
  }

  // Checks if a string ends with another string
  bool hasSuffix(std::string &str, std::string const ending) {

    // If the ending checked is larger return false
    // The ending cannot be longer than the actual string being checked
    if(str.length() < ending.length()) return false;
    
    // Subtract the length of the ending from the string to get the starting position
    // to compare the rest of the string to the ending
    // If they are equal then the function equals 0, invert it to make it true
    return !str.compare(str.length()-ending.length(), ending.length(), ending);
  }

  // Get words from file
  std::vector<std::string> read_txt_file(std::string &in_file) {

    std::vector<std::string> storage;

    // Open the file to read
    std::ifstream file(in_file);

    // Iterate over every line in the file
    for(std::string line; getline(file, line);) {

      // Create a string to append to for each char of the word
      std::string word = "";

      // Iterate over the line
      for(unsigned int i=0; i<line.size(); i++) {

        // Get the single char at pos i
        char c = line[i];

        // Check if the word has ended
        if(c==' ') {

          // Add the word to the storage vector
          storage.push_back(word);

          // Reset word for the next word to be read
          word = "";
          continue;
        }

        // Add the char to the end of word
        word.push_back(c);

        // If the last char of the file add the word to the storage
        if(i+1==line.size()) storage.push_back(word);
      }
    }

    // Close the file 
    file.close();
    return storage;
  }

  std::string string_tolower(std::string in_word) {
    
    std::string temp = "";

    for(char c: in_word) temp += tolower(c);

    return temp;
  }

  std::string string_toupper(std::string in_word) {

    std::string temp = "";

    for(char c: in_word) temp += toupper(c);

    return temp;
  }

  std::string string_capitalize(std::string in_word) {

    std::string temp = "";

    for(int i=0; i<in_word.size(); i++) {

      if(i==0) temp += toupper(in_word[i]);
      else temp += tolower(in_word[i]);
    }

    return temp;
  }
}