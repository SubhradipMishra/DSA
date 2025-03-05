#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
public:
    void removeNthNode(Node*& head, int n) {
        int length = 0;
        Node* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

    //     int positionFromStart = length - n;

    //     if (positionFromStart == 0) {
    //         Node* nodeToDelete = head;
    //         head = head->next;
    //         delete nodeToDelete;
    //         return;
    //     }

    //     temp = head;
    //     for (int i = 1; i < positionFromStart; ++i) {
    //         temp = temp->next;
    //     }

    //     Node* nodeToDelete = temp->next;
    //     temp->next = nodeToDelete->next;
    //     delete nodeToDelete;
    // }

    void display(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    }
};

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;

    Node* head = a;

    LinkedList ll;
    ll.display(head);

    ll.removeNthNode(head, 3);

    ll.display(head);

    // while (head != NULL) {
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;
    // }

    return 0;
}
