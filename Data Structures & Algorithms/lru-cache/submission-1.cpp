#include <map>

struct Node
{
    int key {};
    int value {};
    Node* prev;
    Node* next;

    Node(int k, int v) : key {k}, value {v}, prev {nullptr}, next {nullptr} {};
};


class LRUCache {
private: 
    Node* tail;
    Node* head;
    int cap;
    std::map<int, Node*> mp;
public:
    LRUCache(int capacity) : cap {capacity} {
        head = tail = nullptr;
    }
    
    int get(int key) {
        if (mp.count(key))
        {
             Node* curr = mp[key];
            if (head != curr)
            {
                if (curr->prev)
                {
                    curr->prev->next = curr->next;

                    if (curr->next)
                        curr->next->prev = curr->prev;
                    else 
                        tail = curr->prev;
                    
                    curr->next = head;
                    head->prev = curr;
                    curr->prev = nullptr;
                    head = curr;
                }
            }

            return curr->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cap < 1)
            return;
        
        // If no head 
        else if (!head)
        {
            head = new Node(key, value);
            tail = head;
            mp[key] = head;
        }

        // if key is already in cache
        else if (mp.count(key))
        {
            Node* curr = mp[key];
            curr->value = value;
            

            if (curr->prev)
            {
                curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;
                else   
                    tail = curr->prev;

                curr->next = head;
                head->prev = curr;
                curr->prev = nullptr;
                head = curr;
            }
            
            // Already at brginigng
            else return;
        }

        // If the cache is not full
        else if (mp.size() < cap)
        {
            mp[key] = new Node(key, value);
            Node* curr = mp[key];

            curr->next = head;
            head->prev = curr;
            head = curr;
        }


        // If the cache is full
        else 
        {
            mp[key] = new Node(key, value);
            Node* curr = mp[key];
            curr->next = head;
            head->prev = curr;
            head = curr;

            // Delete tail
            Node* del = tail;
            tail = tail->prev;
            tail->next = nullptr;
            mp.erase(del->key);
            delete del;
            del = nullptr;
        }
    }
};