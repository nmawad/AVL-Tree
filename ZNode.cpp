#include <iostream>
#include "ZNode.hpp"
#include "Z_Obj.hpp"

using namespace std;

ZNode::ZNode(Z_Obj *zip) : zip(zip), height(0), left(nullptr), right(nullptr), parent(nullptr) {
    
}

ZNode::ZNode() : zip(nullptr), height(0), left(nullptr), right(nullptr), parent(nullptr) {
}

void ZNode::print()
{
    //H:4::28290, Charlotte, North Carolina, NC, Mecklenburg, -80.8042-35.26
    cout << "H:" << height << "::" << zip->zip << ", " << zip->city << ", " << zip->state << ", " << zip->abbr << ", " << zip->county << ", " << zip->lat << ", " << zip->lon << endl;
}