#include <bits/stdc++.h>
using namespace std;

//Design a data structure that follows the constraints of Least Recently Used (LRU) cache
classLRUcache {
    map<int, node*> mpp;
    LRUCache(capacity) {
        capacity = capacity;
        mpp.clear
        head->next = tail;
        tail->prev = head;
    }

    int get(key){
        if(mpp.has(key)) return -1;
        Node* node = mpp[key];
        delete Node(node);
        insert afterHead(node);
        return node.value;
    }

    void put(key, value) {
        if(mpp.has(key)) {
            node * node = mpp[key];
            node.val = value;
            deleteNode(node);
            insert afterHead(node);
        }
        else {
            if(mpp.size == capacity) {
                node* node = tail->prev;
                mpp.delete(node.key);
                deleteNode(node);
            }
        }
    }
    Node* node == new Node(key,val);
    mpp[key] = node;
    insert afterHead(node);
}