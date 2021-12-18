#include<bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int data) {
            val = data;
            next = NULL;
        }
    };

    Node* head;
    int size = 0;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        Node* temp = head;
        int i = 0;

        while (temp != NULL) {
            if (i == index) return temp->val;
            ++i;
            temp = temp->next;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            ++size;
            //print();
            return;
        }

        newNode->next = head;
        head = newNode;
        ++size;

        //print();
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            ++size;
            //print();
            return;
        }

        Node* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = newNode;
        ++size;

        //print();
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        int i = 0;
        Node* temp = head, * prev = NULL;
        Node* newNode = new Node(val);

        while (temp != NULL) {
            if (i == index) {
                assert(prev != NULL);
                prev->next = newNode;
                newNode->next = temp;
                ++size;
                //print();
                return;
            }
            ++i;
            prev = temp;
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            free(temp);
            --size;
            return;
        }

        Node* temp = head, * prev = NULL;
        int i = 0;

        while (temp != NULL) {
            if (i == index) {
                assert(prev != NULL);
                cout << temp->val << " " << "data\n";
                Node* temp1 = temp;
                prev->next = temp->next;
                --size;
                free(temp1);
                return;
            }
            ++i;
            prev = temp;
            temp = temp->next;
        }
    }

    void print() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    cout << myLinkedList.get(1) << endl;              // return 2
    myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
    cout << myLinkedList.get(1) << endl;              // return 3

    return 0;
}

