/*
* Library for inserting and searching for words in a binary tree
* By: Ronnie Williams
* October 20, 2020 // TODO
*/

#pragma once

#include <string>
#include <vector>

#include "b_tree_node.hpp"


class BinaryTree {

  public:

    // TODO
    BinaryTree() {

    }
    
    BinaryTree(std::vector<std::string> &in_words) {

      insert(in_words);
    }

    // Inserts strings from a vector to the tree
    void insert(std::vector<std::string> &in_words) {

      // Iterate over every string in the vector
      for(std::string word:in_words) insert(word);
      return;
    }

    // TODO
    // Inserts a word to the tree
    void insert(std::string &word) {

      return;
    }

    // TODO
    // Searches for a word in the tree
    // Returns true or false if the word is in the tree
    bool search(const std::string word) {

      return true;
    }

  private:

};