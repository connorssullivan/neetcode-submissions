#include <string>
#include <vector>

struct Node {
    char m_letter {'.'};
    bool m_isWord {false};
    Node* m_children[26]= {nullptr};

    Node(char l, bool isWord) : m_letter {l}, m_isWord {isWord}
    {
        
    }

    ~Node()
    {
        for (int i {}; i < 26; i++)
        {
            delete m_children[i];
            m_children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    Node* head;
    bool dfs(std::string word, int index, Node* root)
    {

        if (index == word.size())
            return root->m_isWord;
        
        if (word[index] == '.')
        {
            for (auto child : root->m_children)
                if (child && dfs(word, index+1, child))
                    return true;
            
            return false;
        }

        else
        {
            int idx = word[index] - 'a';
            if (!root->m_children[idx])
                return false;

            else 
            {
                return root->m_children[idx] && dfs(word, index+1, root->m_children[idx]);
            }
        }
        

        
    }

public:
    WordDictionary() {
        head = new Node('.', false);
    }

    ~WordDictionary() {
        delete head;
        head = nullptr;
    }
    
    void addWord(std::string word) {
        Node* curr = head;
        for (const char c : word)
        {
            int index = c - 'a';
            if (curr->m_children[index])
                curr = curr->m_children[index];
            else
            {
                curr->m_children[index] = new Node(c, false);
                curr = curr->m_children[index];
            }
        }

        curr->m_isWord = true;
    }
    
    bool search(std::string word) {
        return dfs(word,0,head);
    }
};