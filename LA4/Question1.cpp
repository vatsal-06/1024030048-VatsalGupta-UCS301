
#include <iostream>
using namespace std;

class Queue
{
    int front, rear, size, capacity;
    int *arr;

public:
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
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
        rear = (rear + 1) % capacity;
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
        front = (front + 1) % capacity;
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
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
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
    cout << "Enter queue capacity: ";
    cin >> cap;
    Queue q(cap);
    int choice, val;

    do
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;
        case 4:
            cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;
        case 5:
            q.display();
            break;
        case 6:
            q.peek();
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
