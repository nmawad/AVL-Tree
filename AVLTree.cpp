//Noah Awad Lab 5
#include <cstdlib>
#include <iostream>
#include "ZNode.hpp"
#include "AVLTree.hpp"

using namespace std;


AVLTree::AVLTree() : AVLflag(false), root(nullptr) {

}

AVLTree::AVLTree(bool flag) : AVLflag(flag), root(nullptr) {

}

// returns the ZNode that contains that zip code in its z_Obj field. If it does not find the zip, it returns NULL
//Note: if you don’t write this recursively, you shouldn’t need the ZNode field

ZNode* AVLTree::findZip(int zip, ZNode *node) {
    if (node->zip->zip == zip) {
        return node;
    }
    
    ZNode *foundNode = nullptr;
    if (node->left != nullptr && zip < node->zip->zip) {
        foundNode = findZip(zip, node->left);
    } 
    
    if (foundNode == nullptr)
    {
        if (node->right != nullptr && zip > node->zip->zip) {
            foundNode = findZip(zip, node->right);
        } 
    }
    
    return foundNode;
}

// adds a new node to the tree. It starts
// traversing the tree at r
// if you don’t do this recursively, you don’t need
// the ZNode field. 

void AVLTree::addNode(Z_Obj *zip, ZNode *node) {
    if (node->zip == zip) {
        //Zip already stored in tree, do nothing
    } else if (zip->lessThan(node->zip)) {
        if (node->left != nullptr)
        {
            addNode(zip, node->left);
        }
        else
        {
            node->left = new ZNode(zip);
            node->left->parent = node;
            adjustBalances(root);//
            
            
            if (AVLflag)
            {
                rebalance(node);
            }
        }
    } else if (node->zip->lessThan(zip)) {
        if (node->right != nullptr)
        {
            addNode(zip, node->right);
        }
        else
        {
            node->right = new ZNode(zip);
            node->right->parent = node;
            adjustBalances(root);
            
            if (AVLflag)
            {
                rebalance(node);
            }
        }
    } 
}

void AVLTree::rebalance(ZNode* node)
{
    ZNode *x = nullptr;
    ZNode *y = nullptr;
    ZNode *z = node;
    
    while (z != nullptr && z->left != nullptr && z->right != nullptr && std::abs(z->left->height - z->right->height) != 2)
    {
        x = y;
        y = z;
        z = z->parent;
    }
    
    if (z == nullptr || y == nullptr)
    {
        return;
    }
    
    if (y == z->left && x == y->left)
    {
        rotateLeft(z);  
    }
    else if (y == z->left && x == y->right)
    {
        rotateRight(z->right);
        rotateLeft(z);
    }
    else if (y == z->right && x == y->right)    
    {
        rotateRight(z);
    }
    else if (y == z->right && x == y->left)
    {
        rotateLeft(z->left);
        rotateRight(z);
    }
}

void AVLTree::printIO(ZNode *node) {
    if (node != nullptr) {
        printIO(node->left);
        cout << node->height << ":";
        node->zip->printZ();
        printIO(node->right);
    }
}

void AVLTree::PrintPre(ZNode* node) {
    if (node != nullptr) {
        cout << node->height << ":";
        node->zip->printZ();
        PrintPre(node->left);
        PrintPre(node->right);
    }
}

void AVLTree::PrintPost(ZNode *node) {
    if (node != nullptr) {
        PrintPost(node->left);
        PrintPost(node->right);
        cout << node->height << ":";
        node->zip->printZ();
    }
}

ZNode* AVLTree::rotateRight(ZNode *y) {
    
    ZNode *x = y->left;
    ZNode *tmp = x->right;
    
    // Perform rotation 
    x->right = y; 
    y->left = tmp;
    
    // Update heights 
    if (y->left->height > y->right->height) { //Height of greatest subtree +1 set on lower node
        y->height = y->left->height + 1;
    } 
    else 
    {
        y->height = y->right->height + 1;
    }
    
    if (x->left->height > x->right->height) {//Height of greatest subtree +1 set on higher node
        x->height = x->left->height + 1;
    } 
    else 
    {
        x->height = x->right->height + 1;
    }
    
    return x; // Return new root 
}

ZNode* AVLTree::rotateLeft(ZNode *y) {
    ZNode *x = y->right;
    ZNode *tmp = x->right;
    
    // Perform rotation 
    tmp->left = y; 
    y->right = x;
    
    // Update heights 
    if (y->left->height > y->right->height) { //Height of greatest subtree +1 set on lower node
        y->height = y->left->height + 1;
    } 
    else 
    {
        y->height = y->right->height + 1;
    }
    
    if (x->left->height > x->right->height) {
        x->height = x->left->height + 1;
    } 
    else 
    {
        x->height = x->right->height + 1;
    }
    
    return x; // Return new root 
}

void AVLTree::adjustBalances(ZNode *node) {
    if (node != nullptr)
    {      
       adjustBalances(node->left);
       adjustBalances(node->right); 
       
       int leftHeight = 0;
       if (node->left != nullptr)
       { 
           leftHeight = node->left->height;
       }
       
       int rightHeight = 0;
       if (node->right != nullptr)
       {
           rightHeight = node->right->height;
       }
       
       if (leftHeight > rightHeight)
       {
           node->height = leftHeight + 1;
       }
       else
       {
           node->height = rightHeight + 1;
       }
    }
}