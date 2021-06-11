class TrieNode
{
    public:
  vector<TrieNode*> child;
    bool is_end;
    TrieNode()
    {
        child = vector<TrieNode*>(26, NULL);
        is_end = false;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp=root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';
            if(temp->child[index] == NULL)
                temp->child[index] = new TrieNode();
            temp = temp->child[index];
        }
        temp->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';
            if(temp->child[index] == NULL)
                return false;
            temp = temp->child[index];
        }
        if(temp->is_end)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';
            if(temp->child[index] == NULL)
                return false;
            temp = temp->child[index];
        }
        return true;
    }
};

