#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node {
    public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node*> m;

    LRUCache(int cap) {
        this->cap = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* temp) {
        node* dummy = head->next;
        head->next = temp;
        temp->next = dummy;
        temp->prev = head;
        dummy->prev = temp;
    }

    void deleteNode(node* temp) {
        node* delNext = temp->next;
        node* delPrev = temp->prev;
        delNext->prev = delPrev;
        delPrev->next = delNext;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* res = m[key];
            m.erase(key);
            int ans = res->value;
            deleteNode(res);
            addNode(res);
            m[key] = head->next;

            return ans;
        }

        return -1;
    }

    void set(int key, int value) {
        if (m.find(key) != m.end()) {
            node* dummy = m[key];
            m.erase(key);
            deleteNode(dummy);
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        m[key] = head->next;

    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache* cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

