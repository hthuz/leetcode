

#include "utils.h"

#define HASH_SIZE 1000
// Chaining hash
class MyHashSet {
private:
    vector<list<int>> vec;
    int hash(int key) {
        return key % HASH_SIZE;
    }

public:
    MyHashSet() {
        this->vec = vector<list<int>>(HASH_SIZE);
    }
    
    void add(int key) {
        int pos = hash(key);
        vec[pos].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))
            return;
        int pos = hash(key);
        vec[pos].remove(key);
    }
    
    bool contains(int key) {
        int pos = hash(key);
        list<int>::iterator itr;
        for(itr = vec[pos].begin(); itr != vec[pos].end(); itr++)
            if (*itr == key)
                return true;
        return false;
    }
};

int main()
{
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    cout << obj->contains(2) << endl;
    obj->remove(2);
    cout << obj->contains(2) << endl;

}
