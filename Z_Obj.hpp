/* 
 * File:   Z_Obj.hpp
 * Author: NoahAwad
 *
 * Created on April 15, 2017, 7:20 AM
 */

#ifndef Z_OBJ_HPP_
#define Z_OBJ_HPP_

#include <string>

using namespace std;

class Z_Obj {
    friend class ZNode;
    friend class AVLTree;
    int zip;
    string city;
    string state;
    string abbr;
    string county;
    float lat;
    float lon;
public:
    Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo);
    void printZ();
    // friend ostream& operator<<(ostream& os, const Z_Obj& z);
    // If you want to override << so you can just use cout to print your Z_Objs.
    bool lessThan(Z_Obj *z);
};

#endif