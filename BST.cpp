/* *
* Title : Binary Search Trees
* Author : Mian Usman Naeem Kakakhel
* Description : Creates the binary tree and creates all the helper methods of the binary tree
*/


#include "BST.h"


BST::BST()
{
    this->root = NULL;
}

BST::BST(BST &copy)
{
    copyTree(copy.root, root);
}

void BST::copyTree(BSTNode *treePtr, BSTNode *& newTreePtr) {

		if (treePtr != NULL) {		// copy node
			newTreePtr = new BSTNode(treePtr->item, NULL, NULL);
			copyTree(treePtr->left, newTreePtr->left);
			copyTree(treePtr->right, newTreePtr->right);
		}
		else
			newTreePtr = NULL;	// copy empty tree
}

void BST::insertItem(int key)
{
    insert(root, key); //call helper func
}
void BST::insert(BSTNode* &tI, int item)
{
    
    if (tI != NULL)//if this nod is not null
    {
        if (tI->item >= item)//if this item is smaller or equal to the given item
            insert(tI->left, item);//recurse to left node
        else if(tI->item < item)//if this item is greater to the given item
            insert(tI->right, item);//recurse to right node
    }
    else
    {
        tI = new BSTNode(item);//if we reach a null plce, insert item there
    }
        
}

void BST::deleteItem(int key)
{
    deleteI(root, key);//call helper func
}
void BST::deleteI(BSTNode* &td, int item)
{
    if (td != NULL)
    {
        if (td->item > item)
            deleteI(td->left, item);//either we have to reach item and go left if given item is less than this item
        else if (td->item < item)
            deleteI(td->right, item);//go right if given item is greater than this item
        else
        {
            if (td->left == NULL && td->right == NULL)//case one, it is a leaf node
            {
                delete td;
                td = NULL;//delete it straight away
            }
            else if (td->left == NULL && td->right != NULL)//case 2 it has one child
            {
                BSTNode* del = td;//just bypass the node like a linked list
                td = td->right;
                delete del;//then delete it
                del = NULL;
            }
            else if (td->left != NULL && td->right == NULL)
            {
                BSTNode* del = td;//same as case 2
                td = td->left;
                delete del;
                del = NULL;
            }
            else if (td->left != NULL && td->right != NULL)//case 3, node has 2 children
            {
                BSTNode* toD = td->right;
                getLeftMost(toD);//call helper func, get the immediate bigger number than the one to delete
                int a = td->item;//change the items of those nodes
                td->item = toD->item;
                toD->item = a;
                deleteI(td->right, item);//since we are sure that the new node only has one child, call delete again.
            }
        }
        
    }
}
void BST::getLeftMost(BSTNode* &td)
{
    if (td->left != NULL)
    {
        td = td->left;//find the left most node with no other left children for delete function
        getLeftMost(td);

    }
}


BSTNode* BST::retrieveItem(int key)
{
    BSTNode* a = root;
    getItemNode(a, key);//call helper func
    return a;
}
void BST::getItemNode(BSTNode* &ret, int item)
{
    if (ret != NULL)
    {
        if (ret->item > item)//if item is less then go left
        {
            ret = ret->left;
            getItemNode(ret, item);
        }   
        else if(ret->item < item)//if item is great then go right
        {
            ret = ret->right;
            getItemNode(ret, item);
        }
        else 
        {
            return;//when you get the item, just exit the recursive functions
        }
    }
}

int* BST::inorderTraversal(int& length)
{
    int* arr = NULL;
    length = 0;
    int i = 0;
    BSTNode* a = root;
    findLength(a, length);//call helper func since we do not know how many nodes there are, firat find nodes size
    arr = new int[length];//create an array of that size
    inTraverse(arr, a, i, length);//call helper func put all the items in the array in, inorder.
    return arr;
}
void BST::findLength(BSTNode* tra, int &len)
{
    if (tra != NULL)
    {
        findLength(tra->left, len);//increase length by one on every node
        len++;
        findLength(tra->right, len);
    }
}
void BST::inTraverse(int* arr, BSTNode* tra, int &i, const int len)
{
    if (tra != NULL)
    {
        inTraverse(arr, tra->left, i, len);//put item at i and i++ at every node
        arr[i] = tra->item;
        i++;
        inTraverse(arr, tra->right, i, len);
    }
}


bool BST::containsSequence(int* seq, int length)
{
    bool a = true;//the boolean to return
    int i = 0;//counter
    findNewSeq(seq, root, i, seq[length - 1], seq[0], a);//call helper func

    return a;
}


void BST::findNewSeq(int* &arr, BSTNode* tra, int &i, const int high, const int low, bool &found)
{
    if (tra != NULL)
    {
        cout << "The Node being traversed:  " << tra->item << endl;
        if (tra->item > high)//if the node seen is bigger than the highest number in the list, branch left
            findNewSeq(arr, tra->left, i, high, low, found);
        else if (tra->item < low)//if the node seen is smaller than the lowest number in the list, branch right
            findNewSeq(arr, tra->right, i, high, low, found);
        else//we come here if the current node is between the high low range of the list
        {
            if (tra->item != low)//go left only if current item is not the lowest in the list
                findNewSeq(arr, tra->left, i, high, low, found);
            if (tra->item != arr[i])//check the current item with the next item in the list
                found = false;//if not the same then we do not have a sublist
            i++;
            if (tra->item != high)//go right only if current item is not the highest in the list
                findNewSeq(arr, tra->right, i, high, low, found);
        }
    }
}

int BST::countNodesDeeperThan(int level)
{
    int lev = 1;
    int i = 0;
    nodeCount(root, i, lev, level);
    return i;
}

void BST::nodeCount(BSTNode* tra, int &i, int &lev, const int level)
{
    if (tra != NULL)
    {
        lev++;//increase level if entering left node
        nodeCount(tra->left, i, lev, level);
        
        if (lev >= level)//increase the number of nodes if current level equals or greater than given level
            i++;
        lev++;//increase level if entering right node
        nodeCount(tra->right, i, lev, level); 
    }
    
    lev--;//decrease level if node goes up  
}


int BST::maxBalancedHeight()
{
    BST a(*this);
    int h = 1;//the height iterator
    int result = 0;//the max balanced height possible
    balance(a.root, result, h);//calc the balanced height
    
    h = 1;
    result = 0;//the max balanced height possible
    calcHeight(a.root, h, result);//calc the max hieght of root
    return result;
}
void BST::balance(BSTNode* &tra, int &result, int &h)
{
    if (tra != NULL)
    {
        h++;
        balance(tra->left, result, h);
        
        h++;
        balance(tra->right, result, h);
        
        int height = 1;
        int maxHeightLeft = 0;
        int maxHeightRight = 0;
        calcHeight(tra->left, height, maxHeightLeft);//calc the height of the left sub tree
        height = 1;
        calcHeight(tra->right, height, maxHeightRight);//calc the height of the right sub tree
        
        if ((maxHeightLeft - maxHeightRight > 1) || (maxHeightLeft - maxHeightRight < -1))
        {
            if (maxHeightLeft > maxHeightRight)
                result = h + 1 + maxHeightRight;//if the difference of left height and right height is more than 1, decrese the max height
    
            else if (maxHeightLeft < maxHeightRight)
                result = h + 1 + maxHeightLeft;//if the difference of left height and right height is more than 1, decrese the max height    
            
            int he = h;
            deleteLevels(tra, h, result);
            h = he;
        }
    }
    h--;
}

void BST::deleteLevels(BSTNode* &tra, int &h, int lev)
{
    if (tra != NULL)
    {
        h++;
        deleteLevels(tra->left, h, lev);
        h++;
        deleteLevels(tra->right, h, lev);
        if (h > lev)
        {
            delete tra;
            tra = NULL;
        }
    }
    h--;
}

void BST::calcHeight(BSTNode* tra, int &h, int &maxH)
{
    if (tra != NULL)
    {
        h++;//increase level if entering left node
        calcHeight(tra->left, h, maxH);//recurse on left node
        if (maxH < h)//if max height is less than counter then increase
            maxH = h;

        h++;//increase level if entering left node
        calcHeight(tra->right, h, maxH);
    }
    h--;//decrease level if node goes up 
}


BST::~BST()
{
    destroy(root);//call helper func
}
void BST::destroy(BSTNode* tD)
{
    if (tD != NULL)
    {
        destroy(tD->left);//destroy every node you come accross.
        destroy(tD->right);
        delete tD;
        tD = NULL;
    }
}
