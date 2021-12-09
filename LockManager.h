//
// Created by Eli Segovia on 12/6/21.
//

#ifndef TWO_PHASE_LOCKING_LOCKMANAGER_H
#define TWO_PHASE_LOCKING_LOCKMANAGER_H

#include <vector>


class LockManager {

private:

    enum LockType {
        NO_LOCK,
        S_LOCK,
        X_LOCK
    };

private:

    std::vector< std::pair<LockType, int> > resourceLocks;
    std::vector< std::vector <LockType > > locks;

    std::vector<bool> transaction_is_blocked;

    int blockedCount = 0;



public:
    LockManager(int k, int t);

    int Request(int t_id, int k, bool is_s_lock);

    int ReleaseAll(int t_id);

    void BlockTransaction(int t_id);

    void UnblockAllTransactions();

    bool TransactionISBlocked(int t_id);

    int GetBlockedCount();

    std::vector< std::pair<int, bool> > ShowLocks(int t_id);



};


#endif //TWO_PHASE_LOCKING_LOCKMANAGER_H
