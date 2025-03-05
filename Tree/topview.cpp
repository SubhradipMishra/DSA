#include<iostream>
#include<climits>
#include<unordered_map>
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
        }
        i++;

        if (i < n && arr[i] != INT_MIN) {
            temp->right = new Node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}
 
void topview(Node* root) {
    if (!root) return;

    unordered_map<int, int> m;
    queue<pair<Node*, int>> q; 
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        Node* temp = front.first;
        int level = front.second;
        q.pop();  

        if (m.find(level) == m.end()) {
            m[level] = temp->val;
        }

        if (temp->left) {
            q.push({temp->left, level - 1});
        }
        if (temp->right) {
            q.push({temp->right, level + 1});
        }
    }

    int minLevel = INT_MAX;
    int maxLevel = INT_MIN;
    
    for (auto x : m) {
        int level = x.first; 
        minLevel = min(minLevel, level); 
        maxLevel = max(maxLevel, level); 
    }

    for (int i = minLevel; i <= maxLevel; i++) {
        cout << m[i] << " "; 
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = construct(arr, n);
    topview(root);

    return 0;
}
+