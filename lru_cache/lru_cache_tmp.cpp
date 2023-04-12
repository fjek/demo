#include <bits/stdc++.h>

using namespace std;

template <class K,class T>
struct Node {
    K key;
    T data;
    Node *prev,*next;
};

template <class K,class T>
class LRUCache {
    unordered_map<K, list<T>::iterator> ma;
public:
    LRUCache(size_t size);
    ~LRUCache();
    void put(K key, T data);
    T get(K key);
};


LRUCache<class K,class T>::LRUCache(size_t n){
    Node<K,T>* list = new Node<K,T>[n];
}