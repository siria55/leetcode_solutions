#include <cstdio>
#include <string>
using namespace std;

class Node {
public:
    Node *children[26];
    bool is_end;

    Node(): is_end{false}
    {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
    Node *root;
public:
    Trie(): root{new Node()} {}

    void insert(string word) {
        Node *node = root;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                node->children[idx] = new Node();
            node = node->children[idx];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Node *node = root;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int idx = word[i] - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->is_end;
    }

    bool startsWith(string prefix) {
        Node *node = root;
        int len = prefix.size();
        for (int i = 0; i < len; ++i) {
            int idx = prefix[i] - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void test1()
{
    Trie *trie = new Trie();
    trie->insert("apple");
    bool res1 = trie->search("apple");   // true
    bool res2 = trie->search("app");     // false
    bool res3 = trie->startsWith("app"); // true
    trie->insert("app");
    bool res4 = trie->search("app");     // true
    if (res1 == true
            && res2 == false
            && res3 == true
            && res4 == true)
        printf("test1 succeed\n");
    else
        printf("test1 fail\n");
}

int main()
{
    test1();
    return 0;
}

