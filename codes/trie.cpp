#include <iostream>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

    bool deleteWord(TrieNode *node, string word, int depth)
    {

        // Word does not exist
        if (node == nullptr)
            return false;

        // Reached end of word
        if (depth == word.length())
        {

            if (!node->isEnd)
                return false;

            node->isEnd = false;

            // Delete node if it has no children
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] != nullptr)
                    return false;
            }

            return true;
        }

        int index = word[depth] - 'a';

        if (node->children[index] == nullptr)
            return false;

        bool shouldDelete =
            deleteWord(node->children[index], word, depth + 1);

        if (shouldDelete)
        {
            delete node->children[index];
            node->children[index] = nullptr;

            // Delete current node if it is not end of another word
            // and has no other children
            if (!node->isEnd)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (node->children[i] != nullptr)
                        return false;
                }

                return true;
            }
        }

        return false;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Insert a word
    void insert(string word)
    {

        TrieNode *current = root;

        for (char ch : word)
        {

            int index = ch - 'a';

            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    // Search for a complete word
    bool search(string word)
    {

        TrieNode *current = root;

        for (char ch : word)
        {

            int index = ch - 'a';

            if (current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return current->isEnd;
    }

    // Check whether any word starts with prefix
    bool startsWith(string prefix)
    {

        TrieNode *current = root;

        for (char ch : prefix)
        {

            int index = ch - 'a';

            if (current->children[index] == nullptr)
                return false;

            current = current->children[index];
        }

        return true;
    }

    // Delete a word
    void remove(string word)
    {
        deleteWord(root, word, 0);
    }
};

int main()
{

    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("bat");
    trie.insert("ball");

    // Search
    cout << "Search apple: ";

    if (trie.search("apple"))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Search cat: ";

    if (trie.search("cat"))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    // Prefix search
    cout << "Starts with 'app': ";

    if (trie.startsWith("app"))
        cout << "Yes\n";
    else
        cout << "No\n";

    // Delete
    trie.remove("apple");

    cout << "After deleting apple: ";

    if (trie.search("apple"))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}