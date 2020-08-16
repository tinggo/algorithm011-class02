#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int pKey, int pVal)
    :key(pKey), val(pVal), prev(nullptr), next(nullptr) {
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_head = nullptr;
        m_tail = nullptr;
        m_keyMap.clear();
    }

    void updateList(Node* node) {
        if (node == m_head)
            return;
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev) {
            node->prev->next = node->next;
            if (m_tail == node)
                m_tail = node->prev;
        }
        node->next = m_head;
        node->prev = nullptr;
        if (m_head)
            m_head->prev = node;
        m_head = node;
        if (m_tail == nullptr)
            m_tail = m_head;
        m_keyMap[node->key] = node;
        if (m_keyMap.size() > m_capacity)
            removeTail();
    }

    void removeTail() {
        Node* tail = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        m_keyMap.erase(tail->key);
        delete tail;
    }

    int get(int key) {
        if (m_keyMap.find(key) == m_keyMap.end())
            return -1;
        Node* n = m_keyMap[key];
        updateList(n);
        return n->val;
    }

    void put(int key, int value) {
        Node* node;
        if (m_keyMap.find(key) == m_keyMap.end())
            node = new Node(key, value);
        else {
            node = m_keyMap[key];
            node->val = value;
        }
        updateList(node);
    }

private:
    Node* m_head;
    Node* m_tail;
    unordered_map<int, Node*> m_keyMap;
    int m_capacity;
};

int main() {
    LRUCache lruCache(2);
    lruCache.put(1,1);
    lruCache.put(2,2);
    lruCache.get(1);
    lruCache.put(3,3);
    lruCache.get(2);
    lruCache.put(4,4);
    lruCache.get(1);
    lruCache.get(3);
    lruCache.get(4);
    return 0;
}