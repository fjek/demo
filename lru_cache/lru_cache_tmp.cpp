#include <bits/stdc++.h>

using namespace std;

// template <class K,class T>
struct Node {
    K key;
    T data;
    Node *prev,*next;
};

// template <class K,class T>
class LRUCache {
    int cap;
    list<pair<int,int>> cacheList;
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap;
public:
    LRUCache(int size):cap(size){};
    ~LRUCache();
    void put(int key, int data);
    int get(int key);
};

void LRUCache::put(int key,int val){
    auto iter = cacheMap.find(key);

    if (iter == cacheMap.end()) {
        // add current elemt
        cacheList.push_front({key,val});
        cacheMap.insert({key,cacheList.begin()});
        if (cacheMap.size() > cap) {
            cacheList.erase(cacheList.back());
            cacheList.pop_back();
        }
    } else {
        // update current node , and move it to front
        iter->second->second = val;
        cacheList.splice(cacheList.begin(),cacheList,iter->second);
    }
}