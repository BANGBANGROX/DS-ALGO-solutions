#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node() {
            key = -1;
            value = -1;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cacheCapacity;
    unordered_map<int, Node*> cache;

    void addNode(Node* node) {
        Node* headNext = head->next;

        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }

    void removeNode(Node* node) {
        Node* nodeNext = node->next;
        Node* nodePrev = node->prev;

        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }

public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cacheCapacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        Node* res = cache[key];
        removeNode(res);
        addNode(res);

        return res->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            node->key = key;
            node->value = value;
            addNode(node);
            cache[key] = node;
        }
        else {
            if (cache.size() == cacheCapacity) {
                cache.erase(tail->prev->key);
                removeNode(tail->prev);
            }
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            addNode(newNode);
            cache[key] = newNode;
        }
    }
};


int main() {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;   // return 3
    cout << lRUCache.get(4) << endl;    // return 4

	return 0;
}