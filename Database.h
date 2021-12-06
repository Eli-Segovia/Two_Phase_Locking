//
// Created by Eli Segovia on 12/6/21.
//

#ifndef TWO_PHASE_LOCKING_DATABASE_H
#define TWO_PHASE_LOCKING_DATABASE_H


#include <vector>
#include <iostream>
using namespace std;
class Database {
public:
    Database(int k, bool nonzero);


    int Read(int k);
    void Write(int k, int w);
    void Print();
private:
    vector<int> data;
};



#endif //TWO_PHASE_LOCKING_DATABASE_H
