/* *
* Title : Binary Search Trees
* Author : Mian Usman Naeem Kakakhel
* Description : description of your code
*/

#include "BSTNode.h"

BSTNode::BSTNode(const int& item, BSTNode *left, BSTNode *right)
{
    this->item = item;
    this->left = left;
    this->right = right;
}

int BSTNode::getItem(){return item;}
