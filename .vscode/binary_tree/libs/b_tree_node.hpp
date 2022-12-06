/*
* Library for a node in a binary tree
* By: Ronnie Williams
* October 20, 2020 // TODO
*/

#pragma once

#include <string>

class BinaryTreeNode {

  public:

    // TODO
    BinaryTreeNode() {

    }

    BinaryTreeNode(std::string &word) {

      _value = word;
    }

  private:
    std::string _value = "";
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;

};