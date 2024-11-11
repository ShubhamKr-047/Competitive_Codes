struct Node
{
    Node* links[26];
    int count = 0;
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void incrementCount() { count++; }
    int getCount() { return count; }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->incrementCount();
    }

    bool search(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->getCount() > 0;
    }

    bool starts_with(string &prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }

    int word_count(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getCount();
    }

};
