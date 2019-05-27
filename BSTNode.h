/* *
* Title : Binary Search Trees
* Author : Mian Usman Naeem Kakakhel
* ID : 21701015
* Section : 02
* Assignment : 02
* Description : description of your code
*/

#ifndef __BSTNode_H
#define __BSTNode_H

#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cstdlib>
using namespace std;

class BSTNode
{
public:
    BSTNode(const int& item, BSTNode *left = NULL, BSTNode *right = NULL);
    int getItem();
private:
    int item;
    BSTNode* left;
    BSTNode* right;

    friend class BST;
};

#endif