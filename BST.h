/* *
* Title : Binary Search Trees
* Author : Mian Usman Naeem Kakakhel
* Description : header for the binary tree
*/

#ifndef __BST_H
#define __BST_H


#include "BSTNode.h"

class BST
{
public:
    BST();
    BST(BST &copy);
    void insertItem(int key);
    void deleteItem(int key);
    BSTNode* retrieveItem(int key);
    int* inorderTraversal(int& length);
    bool containsSequence(int* seq, int length);
    int countNodesDeeperThan(int level);
    int maxBalancedHeight();
    ~BST();    
private:
    BSTNode* root;
    void destroy(BSTNode* tD);
    void insert(BSTNode* &tI, int item);
    void deleteI(BSTNode* &td, int item);
    void getLeftMost(BSTNode* &td);
    void getItemNode(BSTNode* &ret, int item);
    void inTraverse(int* arr, BSTNode* tra, int &i, const int len);
    void findLength(BSTNode* tra, int &len);
    void findNewSeq(int* &arr, BSTNode* tra, int &i, const int high, const int low, bool &found);
    void nodeCount(BSTNode* tra, int &i, int &lev, const int level);
    void balance(BSTNode* &tra, int &result, int &h);
    void calcHeight(BSTNode* tra, int &h, int &maxH);
    void deleteLevels(BSTNode* &tra, int &h, int lev);
    void copyTree(BSTNode *treePtr, BSTNode *& newTreePtr);
};

#endif
