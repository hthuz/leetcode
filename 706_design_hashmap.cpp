
#include "utils.h"

class MyHashMap {
private:
    vector<list<pair<int,int>>> vec;
    int hash_size = 1000;
    int hash(int key) {
        return key % hash_size;
    }
public:
    MyHashMap() {
        this->vec = vector<list<pair<int,int>>>(hash_size);
    }
    
    void put(int key, int value) {
        int pos = hash(key);
        // Update
        list<pair<int,int>>::iterator itr;
        for(itr = vec[pos].begin(); itr != vec[pos].end(); itr++)
            if(itr->first == key) {
                itr->second = value;
                return;
            }
        // Insert
        vec[pos].push_back({key,value});

    }
    
    int get(int key) {
        int pos = hash(key);
        list<pair<int,int>>::iterator itr;
        for(itr = vec[pos].begin(); itr != vec[pos].end(); itr++)
            if(itr->first == key)
                return itr->second;
        return -1;
    }
    
    void remove(int key) {
        int pos = hash(key);
        list<pair<int,int>>::iterator itr;
        for(itr = vec[pos].begin(); itr != vec[pos].end(); itr++)
            if(itr->first == key) {
                vec[pos].erase(itr);
                break;
            }
    }
};


int main()
{
    MyHashMap* obj = new MyHashMap();
    obj->put(1,100);
    obj->put(1,102);
    obj->remove(1);
    cout << obj->get(1) << endl;

}
