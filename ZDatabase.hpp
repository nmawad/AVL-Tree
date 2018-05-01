#ifndef ZDATABASE_HPP_
#define ZDATABASE_HPP_

#include <string>
#include "AVLTree.hpp"

using namespace std;

class ZDatabase {
    string ifile;
    string ofile;
    AVLTree *ztree;
public:
    ZDatabase(string filename, bool flag);
    void readFile();
    void getZips();
};

#endif /* ZDATABASE_HPP_ */