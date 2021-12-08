//
// Created by Eli Segovia on 12/6/21.
//

#include "LockManager.h"
#include <iostream>

/*
 * k -> the total amount of items in the database
 * t -> the total amount of transactions in the system
 *
 * This take k and t and creates a table that keeps track of which
 * transaction holds what type of lock on which resource.
 * We initialize to NO_LOCK upon start up.
 */
LockManager::LockManager(int k, int t) {

    // keeps track of the most upgraded version of lock on a resource.
    // For example, if there is an s-lock on a resource, we don't need to check which transaction has that,
    // we just need to know that there is a lock there.

    // initialize everything to NO_LOCK
    this->resourceLocks = std::vector<std::pair<LockType, int>>(k);
    for (int i = 0; i < k; i++) {
        this->resourceLocks[i] = std::pair<LockType, int>(NO_LOCK, 0);
    }

    this->locks = std::vector< std::vector<LockType>>(t);
    for(int i = 0; i < this->locks.size(); i++) {
        this->locks[i] = std::vector< LockType >(k);
        for(int j = 0; j < k; j++) {
            this->locks[i][j] = NO_LOCK;
        }
    }


}



int LockManager::Request(int t_id, int k, bool is_s_lock) {

    LockType requestedLockType = is_s_lock? S_LOCK : X_LOCK;

    LockType & currentTransactionLockStatus = this->locks[t_id - 1][k - 1];

    LockType currentHighestLockOnResource = this->resourceLocks[k - 1].first;


    if (currentHighestLockOnResource == NO_LOCK) {
        // automatically grant
        currentTransactionLockStatus = requestedLockType;
        this->resourceLocks[k-1] = std::pair<LockType, int>(requestedLockType, 1);
        return 1;
    }
    else if (currentHighestLockOnResource == S_LOCK && requestedLockType != X_LOCK) {
        currentTransactionLockStatus = requestedLockType;
        int lockCount = this->resourceLocks[k-1].second;
        this->resourceLocks[k-1] = std::pair<LockType, int>(requestedLockType, lockCount + 1);
        return 1;
    }

    return 0;
}

int LockManager::ReleaseAll(int t_id) {
    std::vector<LockType> & currTransactionLocks = this->locks[t_id - 1];
    int count = 0;

    for(int i = 0; i < currTransactionLocks.size(); i++ ){
        if(currTransactionLocks[i] != NO_LOCK) {
            currTransactionLocks[i] = NO_LOCK;
            this->resourceLocks[i] = std::pair<LockType, int>(this->resourceLocks[i].first,
                                                              this->resourceLocks[i].second - 1);

            if (this->resourceLocks[i].second == 0) {
                this->resourceLocks[i] = std::pair<LockType, int>(NO_LOCK, 0);
            }
            count++;
        }
    }
    return 0;
}

std::vector< std::pair<int, bool> > LockManager::ShowLocks(int t_id) {
    std::vector< std::pair<int,bool>> returnedVals;
    std::vector< LockType > transactionLocks = this->locks[t_id - 1];

    for (int i = 0; i < transactionLocks.size(); i++) {
        LockType lock = transactionLocks[i];
        if (lock != NO_LOCK) {
            returnedVals.push_back(std::pair<int, bool> (i + 1, lock == S_LOCK));
        }

        std::cout << i+1 << ":   ";
        switch (lock) {
            case NO_LOCK:
                std::cout << "No Lock";
                break;
            case S_LOCK:
                std::cout << "S Lock";
                break;
            case X_LOCK:
                std::cout << "X Lock";
                break;
            default:
                std::cout << "No Lock";
        }

        std::cout << std::endl;

    }
    return returnedVals;
}