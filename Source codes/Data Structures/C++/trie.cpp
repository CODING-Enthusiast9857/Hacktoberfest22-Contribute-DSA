#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    // every trie node has an array child of size 26 corresponding to lower case alphabet
    Trie *child[26] = {NULL};
    // isEnd denotes if that node is ending of a word
    bool isEnd = false;

    void insert(string s)
    {
        Trie *curr = this;
        for (char c : s)
        {
            // if node (c) is null create new node
            if (curr->child[c - 'a'] == NULL)
                curr->child[c - 'a'] = new Trie();
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    bool isPresent(string s)
    {
        Trie *curr = this;
        for (char c : s)
        {
            if (curr->child[c - 'a'] == NULL)
                return false;
            curr = curr->child[c - 'a'];
        }
        return curr->isEnd;
    }
};

int main()
{
    Trie *root = new Trie();
    // vector dic contains word to be inserted in dictionary
    vector<string> dic = {"can", "cash", "stop", "stopped", "hello"};
    for (string s : dic)
    {
        root->insert(s);
    }
    // vector query contains word you are searching
    vector<string> query = {"stop", "cashed"};
    for (string s : query)
    {
        if (root->isPresent(s))
            cout << s << " is present in dictionary." << endl;
        else
            cout << s << " is NOT present in dictionary." << endl;
    }
    return 0;
}
