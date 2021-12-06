//
// Created by Eli Segovia on 12/6/21.
//

#ifndef TWO_PHASE_LOCKING_LOCKMANAGER_H
#define TWO_PHASE_LOCKING_LOCKMANAGER_H

#include <vector>


class LockManager {

public:
    LockManager(); // TODO implement with args


    int Request(int t_id, int k, bool is_s_lock);

    int ReleaseAll(int t_id);

    std::vector< std::pair<int, bool> > ShowLocks(int t_id);



};


#endif //TWO_PHASE_LOCKING_LOCKMANAGER_H
