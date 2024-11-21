#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class NodeBT {
public:
    T value;
    NodeBT *left, *right;

    NodeBT(T val){
        value = val;
        left = right = nullptr;
    }
};

template <typename T>
class BST {
private:
    NodeBT<T> *root;

    void insert(NodeBT<T> *&node, T val) {
        if (!node) node = new NodeBT<T>(val);
        else if (val < node->value) insert(node->left, val);
        else insert(node->right, val);
    }

    void preorder(NodeBT<T> *node, vector<T> &result) {
        if (!node) return;
        result.push_back(node->value);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    void postorder(NodeBT<T> *node, vector<T> &result) {
        if (!node) return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->value);
    }

    void inorder(NodeBT<T> *node, vector<T> &result) {
        if (!node) return;
        inorder(node->left, result);
        result.push_back(node->value);
        inorder(node->right, result);
    }

    void levelorder(NodeBT<T> *node, vector<T> &result) {
        if (!node) return;
        queue<NodeBT<T> *> q;
        q.push(node);
        while (!q.empty()) {
            NodeBT<T> *current = q.front();
            q.pop();
            result.push_back(current->value);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void insert(T val) {
        insert(root, val);
    }

    vector<T> preorder() {
        vector<T> result;
        preorder(root, result);
        return result;
    }

    vector<T> postorder() {
        vector<T> result;
        postorder(root, result);
        return result;
    }

    vector<T> inorder() {
        vector<T> result;
        inorder(root, result);
        return result;
    }

    vector<T> levelorder() {
        vector<T> result;
        levelorder(root, result);
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    BST<char> tree;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        tree.insert(ch);
    }

vector<char> result;

result = tree.preorder();
for (size_t i = 0; i < result.size(); ++i) cout << result[i];
cout << endl;

result = tree.postorder();
for (size_t i = 0; i < result.size(); ++i) cout << result[i];
cout << endl;

result = tree.inorder();
for (size_t i = 0; i < result.size(); ++i) cout << result[i];
cout << endl;

result = tree.levelorder();
for (size_t i = 0; i < result.size(); ++i) cout << result[i];
cout << endl;

    return 0;
}