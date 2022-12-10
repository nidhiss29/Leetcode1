class TrieNode
{
public:
    unordered_map<char, shared_ptr<TrieNode>> children;
    bool end = false;
};

class Trie
{
public:
    Trie()
    {
        root = make_shared<TrieNode>();
    }

    void insert(string word)
    {
        shared_ptr<TrieNode> cur = root;

        for (auto &c : word)
        {
            if (!cur->children.count(c))
                cur->children[c] = shared_ptr<TrieNode>(new TrieNode);

            cur = cur->children[c];
        }

        cur->end = true;
    }

    bool search(string word)
    {
        shared_ptr<TrieNode> cur = root;

        for (auto &c : word)
        {
            if (!cur->children.count(c))
                return false;

            cur = cur->children[c];
        }

        return cur->end == true;
    }

    bool startsWith(string prefix)
    {
        shared_ptr<TrieNode> cur = root;

        for (auto &c : prefix)
        {
            if (!cur->children.count(c))
                return false;

            cur = cur->children[c];
        }

        return true;
    }

private:
    shared_ptr<TrieNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */