#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_
#include "ZNode.hpp"

class AVLTree {
    friend class ZDatabase;
    ZNode *root;
    bool AVLflag;
    
    void rebalance(ZNode* node);
public:
    AVLTree(); // constructor, sets AVLflag to false
    AVLTree(bool flag); // constructor, sets AVLflag to flag
    ZNode *findZip(int z, ZNode *n); 
    // returns the ZNode that contains
    //that zip code in its z_Obj field. If it does not
    //find the zip, it returns NULL
    //Note: if you don’t write this recursively, you
    //shouldn’t need the ZNode field
    void addNode(Z_Obj *n, ZNode *r); 
    // adds a new node to the tree. It starts
    // traversing the tree at r
    // if you don’t do this recursively, you don’t need
    // the ZNode field.
    
    void adjustBalances(ZNode *n); // adjusts the heights and checks balances
    ZNode *rotateRight(ZNode *n); // rotates right around n
    ZNode *rotateLeft(ZNode *n); // rotates left around n
    void printIO(ZNode *root); // print tree in order
    void PrintPre(ZNode *root); // print tree in preorder
    void PrintPost(ZNode *root); // print tree in postorder


};
#endif 