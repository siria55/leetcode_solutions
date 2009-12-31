#include <iostream>
#include <vector>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        return getDepth(root);
    }
    int getDepth(Node* node) {
        if (node == nullptr) return 0;
        int child_max = 0;
        for (auto child : node->children) {
            child_max = max(child_max, getDepth(child));
        }
        return child_max + 1;
    }
};

void test(string test_name, Node *root, int expected) {
    int res = Solution().maxDepth(root);
    if (res == expected)
        cout << test_name + " succeed" << endl;
    else
        cout << test_name + " fail" << endl;
}

int main() {
    //      1
    //    / | \
    //   2  3  4
    //  /
    // 5
    Node *root1 = new Node(1);
    root1->children = {new Node(2), new Node(3), new Node(4)};
    root1->children[0]->children = {new Node(5)};
    int expected1 = 3;
    test("test1", root1, expected1);

    return 0;
}