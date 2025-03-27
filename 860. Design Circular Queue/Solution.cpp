class Node {
public:
    int val;
    Node* prev;
    Node* next;
    
    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MyCircularQueue {
private:
    int capacity; // Max size of the queue
    int size;     // Current number of elements
    Node* left;   // Dummy head (front marker)
    Node* right;  // Dummy tail (rear marker)

public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        left = new Node(-1);  // Dummy left (front)
        right = new Node(-1); // Dummy right (rear)
        left->next = right;
        right->prev = left;
    }

    ~MyCircularQueue() {
        // Properly delete all allocated nodes
        Node* current = left;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        
        Node* newNode = new Node(value);
        newNode->prev = right->prev;
        newNode->next = right;

        right->prev->next = newNode;
        right->prev = newNode;
        
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        Node* frontNode = left->next;
        left->next = frontNode->next;
        frontNode->next->prev = left;

        delete frontNode;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }

    int Rear() {
        return isEmpty() ? -1 : right->prev->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Usage:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 * delete obj;  // Clean up memory
 */
