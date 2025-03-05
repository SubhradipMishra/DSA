#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node* construct(int arr[], int n) {
    if (n == 0) return NULL;

    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    while (i < n) {
        Node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != INT_MIN) {
            temp->left = new Node(arr[i]);
            q.push(temp->left);
        } else {
            temp->left = NULL;
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        } else {
            temp->right = NULL;
        }
        i++;
    }

    return root;
}

void level_order_queue(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, INT_MIN, INT_MIN, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);
    level_order_queue(root);

    return 0;
}
