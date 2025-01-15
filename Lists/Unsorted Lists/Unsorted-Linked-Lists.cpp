#include <iostream>

struct Node
{
int data;
Node* next = nullptr;
Node(int Data): data(Data), next(nullptr){}; 
};


class List
{
private:
Node* head = nullptr;

public:
void insertAtEnd()
{

}

void insertAtHead(int data)
{
    Node* temp = head;
    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
    }
    else
    {
        head->next = head;
        head = temp;
    }
}

void deleteElement()
{

}

bool isIn(int target)
{
    Node* temp = head;
    bool found = false;

    while (found != true)
    {
        if(temp->data == target)
        {
        found = true;
        }
    temp = temp->next;
    }
}

void print()
{
Node* temp = head;

while(temp != nullptr)
{
    std::cout <<temp->data;
}
temp = temp->next;
}

void deleteAll()
{
    Node* deleteThis = nullptr;
    Node* temp = head;
    if (head == nullptr)
    {
        deleteThis = temp;
        temp = temp->next;
        delete deleteThis;
    }

    while(temp->next != nullptr)
    {
        deleteThis = temp;
        temp = temp->next;
        delete deleteThis;
    }

}

};



int main()
{



}