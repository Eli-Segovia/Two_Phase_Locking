//
// Created by Eli Segovia on 12/6/21.
//

#include "Database.h"

Database::Database(int k, bool nonzero) {
    for (int i = 0; i < k; i++)
        if (nonzero)
            data.push_back(i+1);
        else
            data.push_back(0);
}
int Database::Read(int k) {
    return data[k];
}
void Database::Write(int k, int w) {
    data[k] = w;
}
void Database::Print() {
    for (int i = 0; i < data.size(); i++)
        cout << data[i] << " ";
}