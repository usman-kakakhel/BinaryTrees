/* *
* Title : Binary Search Trees
* Author : Mian Usman Naeem Kakakhel
* Description : The main method where the methods of the binary tree are tested
*/


#include "BST.h"

void printTree(BST* tr)
{
    int lenA;
    int* listA = tr->inorderTraversal(lenA);//get the inorder of the tree


    for (int i = 0; i < lenA - 1; i++)
    {
        cout << listA[i] << ", ";//print the inorder
    }
    cout << listA[lenA-1] << endl;

    delete[] listA;
}

int main()
{
    int list[] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};

    BST myTree;
    for (int i = 0; i < 16; i++)
    {
        myTree.insertItem(list[i]);//insert the list into the tree
    }

    printTree(&myTree);

    myTree.deleteItem(5);
    printTree(&myTree);
 

    myTree.deleteItem(7);
    printTree(&myTree);

    myTree.deleteItem(3);
    printTree(&myTree);

    myTree.deleteItem(2500);
    printTree(&myTree);

    cout << "---------------------------------------------------------------------------------"<< endl;

    BSTNode* a = myTree.retrieveItem(10);
    if (a != NULL)
        cout << "item of retrieved node is:  " << a->getItem() << endl;
    else
        cout << "item of retrieved node is:  The node was not found" << endl;

    a = myTree.retrieveItem(2);
    if (a != NULL)
        cout << "item of retrieved node is:  " << a->getItem() << endl;
    else
        cout << "item of retrieved node is:  The node was not found" << endl;

    a = myTree.retrieveItem(2500);
    
    if (a != NULL)
        cout << "item of retrieved node is:  " << a->getItem() << endl;
    else
        cout << "item of retrieved node is:  The node was not found" << endl;
    

    cout << "---------------------------------------------------------------------------------"<< endl;
    int listNew[] = {8, 4, 13, 3, 6, 12, 15, 1, 5, 10, 14, 2};
    //int listNew[] = {8, 5, 13, 3, 7, 15, 1, 4, 6, 14, 2};
    BST myTree1;
    for (int i = 0; i < 12; i++)
    {
        myTree1.insertItem(listNew[i]);
    }

    printTree(&myTree1);
    cout << "---------------------------------------------------------------------------------"<< endl;

    int checkList[] = {1,2,3,4,5,6};
    int checkList1[] = {10,12,13,15};
    int checkList2[] = {10,11,12};
    cout << "0 is false and 1 is true"<< endl;
    cout << "Is 1,2,3,4,5,6 a subarray: " <<myTree1.containsSequence(checkList, 6) << endl<< endl;

    cout << "Is 10,12,13,15 a subarray: " <<myTree1.containsSequence(checkList1, 4) << endl<< endl;

    cout << "Is 10,11,12 a subarray: " <<myTree1.containsSequence(checkList2, 3) << endl<< endl;

    cout << "---------------------------------------------------------------------------------"<< endl;

    cout << "nodes on a level deeper than 1 are:   " << myTree1.countNodesDeeperThan(1) << endl;
    cout << "nodes on a level deeper than 2 are:   " << myTree1.countNodesDeeperThan(2) << endl;
    cout << "nodes on a level deeper than 3 are:   " << myTree1.countNodesDeeperThan(3) << endl;
    cout << "nodes on a level deeper than 4 are:   " << myTree1.countNodesDeeperThan(4) << endl;
    cout << "nodes on a level deeper than 5 are:   " << myTree1.countNodesDeeperThan(5) << endl;

    cout << "---------------------------------------------------------------------------------"<< endl;

    cout << "tree height-balanced: " << myTree1.maxBalancedHeight() << endl;


    cout << "---------------------------------------------------------------------------------"<< endl;
    int list2[] = {7, 3, 12, 13, 1, 9, 15, 0, 11, 14, 2, 8, 10};

    BST myTree2;
    for (int i = 0; i < 13; i++)
    {
        myTree2.insertItem(list2[i]);//insert the list into the tree
    }

    printTree(&myTree2);
    cout << "---------------------------------------------------------------------------------"<< endl;

    cout << "New tree height-balanced: " << myTree2.maxBalancedHeight() << endl;

    return 0;
}


