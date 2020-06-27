#include <memory>
#include <cassert>

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : m_beginIndex(0), m_endIndex(0), m_size(0) {
        m_capacity = k == 0 ? 1 : k;
        m_data = new int[k];
    }

    ~MyCircularDeque() {
        delete []m_data;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if ( isFull() )
            return false;
        m_beginIndex = ( m_beginIndex - 1 + m_capacity ) % m_capacity;
        m_data[m_beginIndex] = value;
        m_size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if ( isFull() )
            return false;
        m_data[m_endIndex] = value;
        m_endIndex = ( m_endIndex + 1 ) % m_capacity;
        m_size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if ( isEmpty() )
            return false;
        m_beginIndex = ( m_beginIndex + 1 ) % m_capacity;
        m_size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if ( isEmpty() )
            return false;
        m_endIndex = ( m_endIndex - 1 + m_capacity ) % m_capacity;
        m_size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if ( isEmpty() )
            return -1;
        return m_data[m_beginIndex];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if ( isEmpty() )
            return -1;
        return m_data[(m_endIndex - 1 + m_capacity ) % m_capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return m_size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return m_size == m_capacity;
    }

private:
    int *m_data;
    int  m_beginIndex;
    int  m_endIndex;
    int  m_capacity;
    int  m_size;
};


int main()
{
    MyCircularDeque* obj = new MyCircularDeque(3);
    bool param_1  = obj->insertLast(1);
    bool param_2  = obj->insertLast(2);
    bool param_3  = obj->insertFront(3);
    bool param_4  = obj->insertFront(4);
    int  param_5  = obj->getRear();
    bool param_6  = obj->deleteFront();
    bool param_7  = obj->deleteLast();
    int param_8   = obj->getFront();
    int param_9   = obj->getRear();
    bool param_10 = obj->isEmpty();
    bool param_11 = obj->isFull();

    system("pause");
    return 0;
}