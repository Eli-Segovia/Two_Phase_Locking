#include <iostream>
#include "LockManager.h"
#include "Transaction.h"

int main(int argc, char* argv[]) {
    srand (time(NULL));
    std::vector<Transaction> transactions;

    if (argc < 3) {
        std:: cout << "Invalid arguments provided" << std::endl;

        if(argc < 2) {
            std::cout << "Please Provide amount items in the database" << std::endl;
        }
        if(argc == 2) {
            std::cout << "Please provide file for Transactions" << std::endl;
        }
        return -1;
    }


    for(int i = 2; i < argc; i++ ) {
        std::cout << "Hello" << std::endl;
        ifstream inFile;
        inFile.open(argv[i]);
        Transaction t = TransactionBuilder::build(inFile);
        t.setId(i -1);
        transactions.push_back(t);
        inFile.close();
    }

    for(auto t : transactions) {
        std::cout << t.t_id << std::endl;
    }

    int i = 0;
    while(!transactions.empty()) {
        int idx = rand() % transactions.size();
        Transaction & selectedTransaction = transactions[idx];
        if (selectedTransaction.operations.empty()) {
            std::swap(transactions[idx], transactions.back());
            transactions.erase(transactions.end());
            continue;
        }
        OperationEntry nextOp = selectedTransaction.operations.top();
        std::cout << "T" << selectedTransaction.t_id << " execute " << nextOp.operation << std::endl;
        selectedTransaction.operations.pop();


        if (i == 10)
            break;
        i++;

    }



//    Database db();
//
//    std::cout << "Hello, World!" << std::endl;
//
//    LockManager lm(10, 4);
//
//    lm.Request(1, 2, false);
//
//    lm.ShowLocks(1);
//
//    lm.ReleaseAll(1);
//
//    lm.ShowLocks(1);

    return 0;
}
