
#include "utils.h"

#define NO_USER 0
class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locking;
    int size;
    void get_descedants(int num, vector<int>& descedants, int& has_locked_descedant) {
        for(vector<int>::iterator itr = children[num].begin(); itr != children[num].end(); itr++)
        {
            descedants.push_back(*itr);
            if(locking[*itr] != NO_USER)
                has_locked_descedant = 1;
            get_descedants(*itr, descedants, has_locked_descedant);
        }
        return;
    }
public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        size = parent.size();
        locking = vector<int>(size, NO_USER);
        children = vector<vector<int>>(size, vector<int>());
        for(int i = 1; i < size; i++) {
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if(locking[num] != NO_USER)
            return false;
        locking[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(locking[num] != user)
            return false;
        locking[num] = NO_USER;
        return true;
    }
    
    bool upgrade(int num, int user) {
        // The node is unlocked
        if(locking[num] != NO_USER)
            return false;
        // it doesn't have any locked ancestors
        int par = parent[num];
        while(par != -1)
        {
            if(locking[par] != NO_USER)
                return false;
            par = parent[par];
        }
        // it has at least one locked descendant 
        vector<int> descendants;
        int has_locked_descedant = 0;
        get_descedants(num, descendants, has_locked_descedant);
        if(!has_locked_descedant)
            return false;

        for(int descendant : descendants)
            locking[descendant] = NO_USER;
        locking[num] = user;
        return true;
    }
};

int main()
{
    vector<int> parent = {-1,4,9,0,6,1,0,6,3,1};
    LockingTree* obj = new LockingTree(parent);
    cout << obj->upgrade(9,43) << endl;

}

