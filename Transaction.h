//
// Created by Eli Segovia on 12/6/21.
//

#ifndef TWO_PHASE_LOCKING_TRANSACTION_H
#define TWO_PHASE_LOCKING_TRANSACTION_H
#include "Database.h"
#include <vector>
#include <string>
#include <stack>

enum Operation {
    DB_READ,
    DB_WRITE,
    DB_PRINT,
    LOCAL_ADD,
    LOCAL_SUB,
    LOCAL_CPY,
    LOCAL_CMB,
    NO_OP

};

class OperationEntry {
public:
    OperationEntry(Operation operation, int x, int y) {
        this->operation = operation;
        this->x = x;
        this->y = y;
    }
    Operation operation;
    int x;
    int y;
};

class Transaction {
private:



    std::vector<int> local;

    unsigned int instructionCount = 0;


public:
    std::stack<OperationEntry> operations;

    int t_id = -1;

    Transaction(int k);


    void Read(Database & db, int source, int dest);

    void Write(Database & db, int source, int dest);

    void Add(int source, int v);

    void Sub(int source, int v);

    void Copy(int s1, int s2);

    void Combine(int s1, int s2);

    void Display();

    void setId(int id);

    void setInstructionCount(const int count);


    OperationEntry getNextOperation();


    friend class TransactionBuilder;

};

#include <sstream>
#include <fstream>
#include <set>

class TransactionBuilder {
private:
    static OperationEntry buildOperation(char op, int x, int y) {
        switch (op) {
            case 'R':
                return OperationEntry(DB_READ, x, y);
            case 'W':
                return OperationEntry(DB_WRITE, x, y);
            case 'A':
                return OperationEntry(LOCAL_ADD, x, y);
            case 'S':
            case 'M':
                return OperationEntry(LOCAL_SUB, x, y);
            case 'C':
                return OperationEntry(LOCAL_CPY, x, y);
            case 'O':
                return OperationEntry(LOCAL_CMB, x, y);
            case 'P':
                return OperationEntry(DB_PRINT, x, y);
            default:
                throw std::exception();

        }
    }
    TransactionBuilder();

public:
    static Transaction build(std::ifstream &inFile) {
        std::string line;
        int transactionCount = 0;
        int localVarCount = 0;
        inFile >> transactionCount;
        inFile >> localVarCount;

        std::vector<OperationEntry> ops;

        Transaction builtTransaction(localVarCount);
        std::getline(inFile, line);
        for(int i = 0; i < transactionCount; i++) {
            char opType;
            int x, y;
            std::getline(inFile, line);
            std::stringstream ss(line);

            ss >> opType;
            ss >> x;
            ss >> y;
            OperationEntry op = buildOperation(opType, x, y);
            ops.push_back(op);

        }

        for(int i = ops.size() - 1; i >= 0; i--) {
            builtTransaction.operations.push(ops[i]);
        }
        return builtTransaction;
    }

};

#endif //TWO_PHASE_LOCKING_TRANSACTION_H
