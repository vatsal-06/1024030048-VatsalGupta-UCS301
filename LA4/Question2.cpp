
#include <iostream>
using namespace std;

class CircularQueue
{
    int front, rear, size, capacity;
    int *arr;

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    ~CircularQueue()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = x;
        size++;
        cout << x << " enqueued.\n";
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0, idx = front; i < size; i++, idx = (idx + 1) % capacity)
        {
            cout << arr[idx] << " ";
        }
        cout << "\n";
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }
};

int main()
{
    int cap;
    cout << "Enter circular queue capacity: ";
    cin >> cap;
    CircularQueue cq(cap);
    int choice, val;
    do
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            cq.enqueue(val);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cout << (cq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            cout << (cq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;
        case 5:
            cq.display();
            break;
        case 6:
            cq.peek();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
