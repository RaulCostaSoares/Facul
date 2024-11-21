#include <iostream>
using namespace std;

template <typename T>
class NodeBT {
public:
    T value;
    NodeBT *left, *right;

    NodeBT(T val) : value(val), left(nullptr), right(nullptr) {}
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

    int sizeFrom(NodeBT<T> *node) {
        if (!node) return 0;
        return 1 + sizeFrom(node->left) + sizeFrom(node->right);
    }

    NodeBT<T> *find(NodeBT<T> *node, T val) {
        if (!node || node->value == val) return node;
        if (val < node->value) return find(node->left, val);
        return find(node->right, val);
    }

public:
    BST() : root(nullptr) {}

    void insert(T val) {
        insert(root, val);
    }

    int sizeFrom(const T &val) {
        NodeBT<T> *node = find(root, val);
        return sizeFrom(node);
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

    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        char ch;
        cin >> ch;
        cout << tree.sizeFrom(ch);
    }
    cout << endl;

    return 0;
}