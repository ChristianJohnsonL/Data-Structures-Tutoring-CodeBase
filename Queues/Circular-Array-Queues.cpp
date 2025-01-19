#include <iostream>
using namespace std;


struct circularArray
{
private:
int array[10];
int front, rear = -1;
int length = 0;

public:
void enqueue(int num)
{
    if((rear + 1) % 10 == front)
    {
        cout << "Queue full"<<endl;
    }
    else 
    {
        if(front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % 10;
        array[rear] = num;
    }
}

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " <<array[front] << endl;
        front = (front + 1) % 10;
        length--;
    }

bool isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else{
        return false;
    }
}


bool isFull()
{
    if (rear == length - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

};