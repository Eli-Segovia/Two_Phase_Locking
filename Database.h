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
    Database(int k, bool nonzero) {
        for (int i = 0; i < k; i++)
            if (nonzero)
                data.push_back(i+1);
            else
                data.push_back(0);
    }
    int Read(int k) {
        return data[k];
    }
    void Write(int k, int w) {
        data[k] = w;
    }
    void Print() {
        for (int i = 0; i < data.size(); i++)
            cout << data[i] << " ";
    }
private:
    vector<int> data;
};



#endif //TWO_PHASE_LOCKING_DATABASE_H
