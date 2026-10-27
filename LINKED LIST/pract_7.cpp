#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertBeginning()
{
    int x;
    cout << "Enter value: ";
    cin >> x;

    Node *newNode = new Node;
    newNode->data = x;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}

void insertEnd()
{
    int x;
    cout << "Enter value: ";
    cin >> x;

    Node *newNode = new Node;
    newNode->data = x;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAfter()
{
    int value, x;

    cout << "Enter node value: ";
    cin >> value;

    cout << "Enter new value: ";
    cin >> x;

    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == value)
        {
            Node *newNode = new Node;
            newNode->data = x;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Node not found\n";
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
        temp = temp->next;

    Node *del = head;
    head = head->next;
    temp->next = head;

    delete del;
}

void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    Node *del = temp->next;
    temp->next = head;

    delete del;
}

void deleteAfter()
{
    int value;

    cout << "Enter node value after which to delete: ";
    cin >> value;

    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == value)
        {
            if (temp->next == head)
            {
                cout << "No node after this node\n";
                return;
            }

            Node *del = temp->next;
            temp->next = del->next;

            delete del;
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Node not found\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;

    cout << "List: ";

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << endl;
}
 
int main()
{
    int choice;

    do
    {
        cout << "\n----- CIRCULAR LINKED LIST -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete After\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertAfter();
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            deleteAfter();
            break;

        case 7:
            display();
            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}