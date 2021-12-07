//
// Created by Eli Segovia on 12/6/21.
//

#ifndef TWO_PHASE_LOCKING_TRANSACTION_H
#define TWO_PHASE_LOCKING_TRANSACTION_H
#include "Database.h"


class Transaction {
private:

public:
    Transaction(int k);


    void Read(Database & db, int source, int dest);

    void Write(Database & db, int source, int dest);

    void Add(int source, int v);

    void Sub(int source, int v);

    void Copy(int s1, int s2);

    void Combine(int s1, int s2);

    void Display();



};


#endif //TWO_PHASE_LOCKING_TRANSACTION_H
