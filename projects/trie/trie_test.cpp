
#include <iostream>
#include <string>
#include "libs/trie_node.hpp"
#include "../../utils.hpp"


void test_search(TrieNodeTree tree, std::string word) {

  RUTILS::print("Searching for: ");
  RUTILS::print(word);
  RUTILS::print(", Found: ");
  RUTILS::println(tree.search(word));

}

int main(int argc, char *argv[]) {

  // If the command line arguments arent valid
  if(argc!=2) {
    std::cout << "\nUsage: './trie_test <fname>'\nArgs:\n";
    std::cout << "  <fname> - The file containing words to create a trie (.txt)\n\n";
    return 0;
  }

  // Get the file to read words from
  std::string fname = argv[1];

  // Make sure the file provided are an .txt file
  if(!RUTILS::hasSuffix(fname, ".txt")) {

    std::cout << "Incorrect file extension please use .txt\n";
    return 0;
  }

  // Create the Trie Tree Class
  TrieNodeTree trie = TrieNodeTree();

  // Get the words from the file
  std::vector<std::string> words = RUTILS::read_txt_file(fname);

  trie.print();

  for(std::string word: words) trie.insert_word(word);

  trie.print();
  
  test_search(trie, "Hello");
  test_search(trie, "Morning");
  test_search(trie, "I");

  return 0;
}