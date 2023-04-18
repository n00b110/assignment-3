#include <iostream>
using namespace std;

// Define the queue class
class Queue {
private:
    int *arr;       // Dynamic array to store queue elements
    int capacity;   // Maximum capacity of the queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int size;       // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free the dynamic memory
    ~Queue() {
        delete[] arr;
    }

    // Function to insert a new element at the rear of the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Error: Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = element;
        size++;
    }

    // Function to remove the front element of the queue and return it
    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        int element = arr[front];
        front = (front + 1) % capacity;
        size--;
        return element;
    }

    // Function to return the front element present in the queue without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // Function to return the total number of elements present in the queue
    int getSize() {
        return size;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (size == capacity);
    }
};

// Main function for testing the queue implementation
int main() {
    Queue q(5);
    cout << "Enqueue 1, 2, 3\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue size: " << q.getSize() << "\n";
    cout << "Peek front: " << q.peek() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Enqueue 4, 5\n";
    q.enqueue(4);
    q.enqueue(5);
    cout << "Queue size: " << q.getSize() << "\n";
    cout << "Peek front: " << q.peek() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Queue size: " << q.getSize() << "\n";
    cout << "Peek front: " << q.peek() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Queue size: " << q.getSize() << "\n";
    cout << "Peek front: "
