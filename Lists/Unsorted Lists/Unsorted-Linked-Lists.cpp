#include <iostream>
using namespace std;

struct node
{
int data;
node* next;
node(int Data): data(Data), next(nullptr){};
};

class linkedList
{
private:
node* head = nullptr;

public: 
// Destructor
 ~linkedList()
{
    node* temp = head;
    while (temp != nullptr)
    {
        node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}

// insertAtHead
void insertAtHead(int data)
{
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

// insertAtEnd
void insertAtEnd(int data)
{
    node* newNode = new node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// deleteNode
void deleteNode(int target)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->data == target)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr && temp->next->data != target)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        return;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// display
void display()
{
    node* temp = head; 
    if (temp == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        while(temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

// isIn
bool isIn(int target) 
{
    node* temp = head;
    while (temp != nullptr)
    {
        if (temp->data == target) 
        {
            return true; 
        }
        temp = temp->next; 
    }
    return false; 
}

// size
int size()
{
    node* temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
};

int main() {
    linkedList list;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete a node\n";
        cout << "4. Display list\n";
        cout << "5. Check if a value is in the list\n";
        cout << "6. Get the size of the list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter the number to insert at head: ";
                cin >> num;
                list.insertAtHead(num);
                break;
            }
            case 2: {
                int num;
                cout << "Enter the number to insert at end: ";
                cin >> num;
                list.insertAtEnd(num);
                break;
            }
            case 3: {
                int num;
                cout << "Enter the number to delete: ";
                cin >> num;
                list.deleteNode(num);
                break;
            }
            case 4:
                list.display();
                break;
            case 5: {
                int num;
                cout << "Enter the number to check: ";
                cin >> num;
                if (list.isIn(num)) {
                    cout << "The number " << num << " is in the list." << endl;
                } else {
                    cout << "The number " << num << " is not in the list." << endl;
                }
                break;
            }
            case 6:
                cout << "The size of the list is: " << list.size() << endl;
                break;
            case 7:
                running = false;
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
