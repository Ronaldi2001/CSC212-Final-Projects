/*
* Library for sorting algorithms
* By: Ronnie Williams
* December 5, 2020
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../../../utils.hpp"

#define MAX_CHILDREN 26
#define ASCII_LOWERS 97

// Node on the Tree
struct TrieNode {
  bool terminal = false;
  int repeat_count = 0;

  TrieNode *children[MAX_CHILDREN];
};

// Trie Tree
class TrieNodeTree {

  public:

    // Displays the words along with their count in the tree
    void print() {

      // Check if the tree is empty
      if(_root==NULL) {
        std::cout << "Trie Tree is Empty..\n";
        return;
      }

      // Print the tree from the root
      // Helper function
      _print(_root);
    }

    // Inserts a word into the tree
    void insert_word(std::string to_insert) {

      // If there is no root node to insert into, create one
      if(_root==NULL) _root = _create_node();
      
      // Inserts the word into the tree
      // Helper Function
      _insert_word(&_root, to_insert);
    }

    // Searches for a word in the tree
    int search(std::string to_search) {

      // Converts the word to lowercase
      to_search = RUTILS::string_tolower(to_search);

      // Location of current node
      // Start is root
      TrieNode *temp = _root;

      // Itterate over the word
      for(int i=0; i<to_search.size(); i++) {

        //Convert the char to a number that can be used in the lookup table of children
        int num = to_search[i]-ASCII_LOWERS;

        // If there are no more children remaining while letters remaining then the word is not in the tree
        if(temp->children[num]==NULL) return false;
        
        // Set the location of the node to the child node
        temp = temp->children[num];
      }

      // Return if the node is terminal making it found
      // Return the word count
      if(temp->terminal) return temp->repeat_count;
    }
  
  private:

    TrieNode *_root;

    // Creates a new node for the Trie Tree
    TrieNode *_create_node() {

      // Allocate space on the heap for the node
      TrieNode *new_node = new TrieNode();

      // Set all the children to NULL
      for(int i=0; i<MAX_CHILDREN; i++) new_node->children[i] = NULL;

      // Return the pointer of the node
      return new_node;
    }

    // Helper fuction to print trie
    void _print(TrieNode *root, char *prefix=NULL, int len=0) {

      // Display the word at the last letter
      if(root->terminal) {
        RUTILS::print("WORD: ");
        RUTILS::print(RUTILS::string_capitalize(prefix));
        RUTILS::print(", COUNT: ");
        RUTILS::println(root->repeat_count);
      }

      // Create new array with space for new char and null char
      char new_prefix[len+2];

      // Copy the prefix to the new array
      memcpy(new_prefix, prefix, len);

      // Null terminate the last index
      new_prefix[len+1] = 0;

      // Iterate over all the children to get the next letter
      for(int i=0; i<MAX_CHILDREN; i++) {

        // If the child isnt NULL
        if(root->children[i]!=NULL) {

          // Add the letter to the pnew prefix
          new_prefix[len] = i+ASCII_LOWERS;

          // Call the same function with the new prefix and node root
          _print(root->children[i], new_prefix, len+1);
        }
      }
    }

    // Insert a word to the trie tree
    void _insert_word(TrieNode **root, std::string to_insert) {

      // Converts the word to lowercase
      to_insert = RUTILS::string_tolower(to_insert);

      // Temp location to store root location
      TrieNode *temp = *root;

      // Iterate over all the letters in the word
      for(int i=0; i<to_insert.size(); i++) {

        // Get the specific char of the word
        int num = to_insert[i]-ASCII_LOWERS;

        // If the child is NULL then create a new child node
        if(temp->children[num]==NULL) temp->children[num] = _create_node();

        // Change the pointer location to the child node
        temp = temp->children[num];
      }

      // Mark the last letter of the word as terminal
      if(!temp->terminal) temp->terminal = true;

      // Increase the word count
      temp->repeat_count++;
    }
};