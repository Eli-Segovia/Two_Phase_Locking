#include <iostream>
#include "LockManager.h"
#include "Transaction.h"

void readTransactions(std::vector<Transaction>& transactions, int argc, char*argv[]) {
    for(int i = 2; i < argc; i++ ) {
        ifstream inFile;
        inFile.open(argv[i]);
        Transaction t = TransactionBuilder::build(inFile);
        t.setId(i -1);
        transactions.push_back(t);
        inFile.close();
    }
}
void performDatabaseOperation(OperationEntry operationEntry, Database& db, Transaction & transaction){
    if (operationEntry.operation == DB_READ) {
        transaction.Read(db, operationEntry.x, operationEntry.y);
    }
    else if (operationEntry.operation == DB_WRITE) {
        transaction.Write(db, operationEntry.x, operationEntry.y);
    }
    else if (operationEntry.operation == DB_PRINT) {
        db.Print();
    }
}

void performLocalOperation(OperationEntry operationEntry, Transaction & transaction){
    if (operationEntry.operation == LOCAL_CMB) {
        transaction.Combine(operationEntry.x, operationEntry.y);
    }
    else if (operationEntry.operation == LOCAL_CPY) {
        transaction.Copy(operationEntry.x, operationEntry.y);
    }
    else if (operationEntry.operation == LOCAL_SUB) {
        transaction.Sub(operationEntry.x, operationEntry.y);
    }
    else if (operationEntry.operation == LOCAL_ADD) {
        transaction.Add(operationEntry.x, operationEntry.y);
    }
}

int main(int argc, char* argv[]) {
    /* Administrative stuff
     *
     * ----------------------------------------------------------------------------------------------
     */
    /* Just translation for operationCode to String  */
    const std::vector<std::string> getOperation ={ "READ",
                                             "WRITE",
                                             "PRINT",
                                             "ADD",
                                             "SUB",
                                             "COPY",
                                             "COMBINE",
                                             "NO_OP"};
    // seed rand()
    srand (time(NULL));

    // vector to hold transactions
    std::vector<Transaction> transactions;

    if (argc < 3) {
        std:: cout << "Invalid arguments provided" << std::endl;

        if(argc < 2) {
            std::cout << "Please Provide amount items in the database" << std::endl;
        }
        if(argc == 2) {
            std::cout << "Please provide file for Transactions" << std::endl;
        }
        std::cout << std::endl;
        return -1;
    }

    const int dbSize = std::atoi(argv[1]);
    const int transactionCount = argc - 2;

    readTransactions(transactions, argc, argv);


    /* End Adminstrative stuff ----------------------------------------------------------------*/



    /* Main Program  */


    Database db(dbSize, true);
    LockManager lockManager(dbSize+1, transactionCount);

    while(!transactions.empty()) {
        int idx = rand() % transactions.size();                  // get random value in idx

        Transaction & selectedTransaction = transactions[idx];   // get random Transaction

        // Get next Operation to execute
        OperationEntry nextOp = selectedTransaction.operations.top();


        const bool is_s_lock = nextOp.operation == DB_READ || nextOp.operation == DB_PRINT;
        const bool transactionRequiresLock = is_s_lock || nextOp.operation == DB_WRITE;

        // print current operation to be executed
        std::cout << "T" << selectedTransaction.t_id << " executes " << getOperation[nextOp.operation] << std::endl;

        // if transaction needs to access the database, we need to do some extra checks.
        if( transactionRequiresLock ) {

            const char lockType = is_s_lock ? 'S' : 'X';

            std::cout << "T" << selectedTransaction.t_id << " requests " << lockType << "-lock on item " << nextOp.x << " :";

            // check with lock manager if request can be granted...
            int requestGrantCode = lockManager.Request(selectedTransaction.t_id, nextOp.x, is_s_lock);

            // if request is granted, perform the operation and clear all the boolean flags
            if (requestGrantCode == 1) {
                std::cout << "G" << std::endl;
                performDatabaseOperation(nextOp, db, selectedTransaction);
                lockManager.UnblockAllTransactions();
                selectedTransaction.operations.pop();
            }

            // else the operation does not get granted
            else {
                lockManager.BlockTransaction(selectedTransaction.t_id);
                std::cout << "D" << std::endl;
                if (lockManager.GetBlockedCount() == transactions.size()) {
                    std::cout << "Deadlock..." << std::endl;
                    break;
                }
            }
        }

        // If transaction does not need lock, then we simply do the local update
        else {
            lockManager.UnblockAllTransactions();
            performLocalOperation(nextOp, selectedTransaction);
            selectedTransaction.operations.pop();
        }
        std::cout << std::endl;


        // remove empty Transactions
        if (selectedTransaction.operations.empty()) {
            lockManager.ReleaseAll(selectedTransaction.t_id);
            std::swap(transactions[idx], transactions.back());
            transactions.erase(transactions.end());
        }
    }

    // if all transaction execute we print the db
    if (transactions.empty()) {
        db.Print();
    }



    return 0;
}
