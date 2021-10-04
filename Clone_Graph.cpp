#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* src) {
    if (src == NULL) return NULL;

    map<Node*, Node*> m;
    queue<Node*> q;
    Node* node = new Node();

    node->val = src->val;
    m[src] = node;
    q.push(src);

    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        vector<Node*> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            if (m[v[i]] == NULL) {
                node = new Node();
                node->val = v[i]->val;
                m[v[i]] = node;
                q.push(v[i]);
            }
            m[u]->neighbors.push_back(m[v[i]]);
        }
    }

    return m[src];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* src = new Node();
        Node* res = cloneGraph(src);
        cout << res << endl;
    }
    return 0;
}