//
// Created by Eli Segovia on 12/6/21.
//

#include "LockManager.h"

/*
 * k -> the total amount of items in the database
 * t -> the total amount of transactions in the system
 *
 * This take k and t and creates a table that keeps track of which
 * transaction holds what type of lock on which resource.
 * We initialize to NO_LOCK upon start up.
 */
LockManager::LockManager(int k, int t) {

    // keeps track of resources
    this->resourceLocks = std::vector<LockType>(k);
    for (int i = 0; i < k; i++) {

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
    return 0;
}

int LockManager::ReleaseAll(int t_id) {
    return 0;
}

std::vector< std::pair<int, bool> > LockManager::ShowLocks(int t_id) {
    return {std::pair<int, bool> (0, false)};
}