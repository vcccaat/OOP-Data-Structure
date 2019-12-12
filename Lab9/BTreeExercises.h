//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"
using namespace std;

template<class T>
int treeHeight(BtreeNode<T> *root)
{
	if(root==NULL) 
		return -1;
    return 1 + max(treeHeight(root->get_left()),treeHeight(root->get_right()));
}

template<class T>
int countNodes(BtreeNode<T> *root)
{
	if(root==NULL) 
		return 0;
    return 1 + (countNodes(root->get_left())+countNodes(root->get_right()));
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root)
{
    if (root == NULL)  
    	return NULL;  
    else
    { 
        // build new root
        BtreeNode<T>* new_node = new BtreeNode<T>(root->get_data(),
        	mirror(root->get_right()),mirror(root->get_left()));

        return new_node;

    } 
}

template<class T>
bool isComplete(BtreeNode<T> *root)
{
	return false;
	// optional, didn't do
}

#endif //LAB9_BTREEEXERCISES_H
