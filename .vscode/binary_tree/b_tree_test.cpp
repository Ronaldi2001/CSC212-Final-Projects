
#include <iostream>
#include <string>

#include "libs/b_tree.hpp"
#include "../../utils.hpp"


int main(int argc, char *argv[]) {

  // If the command line arguments arent valid
  if(argc!=2) {
    std::cout << "\nUsage: './sorting_test <fname>'\nArgs:\n";
    std::cout << "  <fname> - The file containing words to create a btree (.txt)\n\n";
    return 0;
  }

  // Get the file to read words from
  std::string fname = argv[1];

  // Make sure the file provided are an .txt file
  if(!hasSuffix(fname, ".txt")) {

    std::cout << "Incorrect file extension please use .txt\n";
    return 0;
  }

  // Get the words from the file
  std::vector<std::string> words = read_txt_file(fname);

  for(std::string word:words) std::cout << word << " ";
  std::cout << "\n";

  return 0;
}