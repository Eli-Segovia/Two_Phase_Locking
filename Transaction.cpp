//
// Created by Eli Segovia on 12/6/21.
//

#include "Transaction.h"

Transaction::Transaction(int k) {
    this->local = std::vector<int>(k);

    for(int i = 0; i < this->local.size(); i++) {
        this->local[i] = 0;
    }

}


void Transaction::Read(Database & db, int source, int dest) {
    this->local[dest] = db.Read(source);
    return;
}

void Transaction::Write(Database& db, int source, int dest) {
    return;
}

void Transaction::Add(int source, int v) {
    return;
}

void Transaction::Sub(int source, int v) {
    return;
}

void Transaction::Copy(int s1, int s2) {
    this->local[s1] = this->local[s2];
    return;
}

void Transaction::Combine(int s1, int s2) {
    this->local[s1] = this->local[s1] + this->local[s2];
    return;
}

void Transaction::Display() {
    for(int nth_local : this->local) {
        std::cout << nth_local << " ";
    }
    std::cout << std::endl;
    return;
}

void Transaction::setInstructionCount(const int count) {
    this->instructionCount = count;
}

OperationEntry Transaction::getNextOperation() {
    if (this->operations.empty()) {
        return OperationEntry(NO_OP, -1, -1);
    }
    else {
        OperationEntry op = this->operations.top();
        return this->operations.top();
    }
}

void Transaction::setId(int id) {
    this->t_id = id;
}

