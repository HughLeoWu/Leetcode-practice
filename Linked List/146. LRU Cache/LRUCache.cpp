#include <iostream>
#include <unordered_map>

using namespace std;

// we can design to "head <-> a <-> b <-> c <-> tail" and c is the most RU, a is the Least RU
struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache; 
    struct Node *head = new Node(-1, -1);
    struct Node *tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add(Node *node) { // to insert the newest node and the linked list should be "head <-> old nodes <-> the newest node <-> tail"
        Node *temp = tail->prev;
        temp->next = node;
        node->prev = temp;
        node->next = tail;
        tail->prev = node;
    }
                              //                                           | <----------------------> |       
    void remove(Node *node) { // to remove the indicate node "head <-> old nodes <-> deletnode <-> new nodes <-> tail"
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) { // the original linked list is "a <-> b <-> c", after get(b) and then update to the linked list to "a <-> c <-> b"
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node *node = cache[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) { // to put the new node and check the capacity, if it larger than the capacity, it should remove the LRU node
        if(cache.find(key) != cache.end()) { // head <-> a <-> b <-> c <-> tail, put(a), if a in hashmap remove a and add a;
            Node *oldNode = cache[key];
            remove(oldNode);
        }
        Node *node = new Node(key, value);
        add(node);
        cache[key] = node;
        if(cache.size() > cap) {
            Node *deletNode = head->next;
            remove(deletNode);
            cache.erase(deletNode->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() { 
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1);                 // cache is {1=1}
    lRUCache.put(2, 2);                 // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3);                 // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4);                 // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;;   // return 4
    return 0;
}

