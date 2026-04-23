#include <string>

using namespace std;

struct TrieNode
{
    TrieNode* m_children[26];
    char m_char;
    bool m_end;

    TrieNode(char c) : m_end {false}, m_char {c}
    {
        for (int i {}; i < 26; i++)
            m_children[i] = nullptr;
        
    }

    ~TrieNode()
    {
        for (int i {}; i < 26; i++)
        {
            delete m_children[i];
            m_children[i] = nullptr;
        }
        
    }
};

class PrefixTree {
private:
    TrieNode* head;
public:
    PrefixTree() {
        head = new TrieNode('0');
    }

    ~PrefixTree() {
        delete head;
    }
    
    void insert(string word) {
        TrieNode* curr = head;
        for (char c : word)
        {
            int index = c - 'a';
            if (curr->m_children[index] != nullptr)
                curr = curr->m_children[index];
            else
            {
                curr->m_children[index] = new TrieNode(c);
                curr = curr->m_children[index];
            }
        }
        curr->m_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = head;

        for (char c : word)
        {
            int index = c - 'a';
            if (curr->m_children[index] == nullptr)
                return false;
            else
                curr = curr->m_children[index];
        }

        if (curr->m_end)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = head;

        for (char c : prefix)
        {
            int index = c - 'a';
            if (curr->m_children[index] == nullptr)
                return false;
            else
                curr = curr->m_children[index];
        }

        return true;
        
    }
};

