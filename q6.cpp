#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* heap;
    int capacity;
    int size;
    
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }
    
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    
    ~PriorityQueue() {
        delete[] heap;
    }
    
    void push(int value) {
        if (size == capacity) return;
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    
    int pop() {
        if (size == 0) return -1;
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }
    
    int top() {
        if (size == 0) return -1;
        return heap[0];
    }
    
    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq(10);
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    
    cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;
    
    return 0;
}
