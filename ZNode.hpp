/* 
 * File:   ZNode.hpp
 * Author: NoahAwad
 *
 * Created on April 15, 2017, 7:20 AM
 */

#ifndef ZNODE_HPP_
#define ZNODE_HPP_

#include "Z_Obj.hpp"

class ZNode {
    friend class AVLTree;
    Z_Obj *zip;
    int height; // max(left->height,right->height) + 1
    ZNode *left;
    ZNode *right;
    ZNode *parent;
public:
    ZNode(Z_Obj *z);
    ZNode();
    void print();
};

#endif /* ZNODE_HPP_ */