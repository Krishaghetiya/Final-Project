#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    int count;

    LinkedList()
    {
        this->head = NULL;
        count = 0;
    }

    void addAtBeginning(int data)
    {
        Node *newNode = new Node(data); // 1
        newNode->next = this->head;     // 2
        this->head = newNode;           // 3
        this->count++;
    }

    void addAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node *ptr = this->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        this->count++;
    }

    void addAtAnyPosition(int data, int position)
    {
        Node *newNode = new Node(data);

        if (position == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
        }

        else
        {
            Node *ptr = head;
            for (int i = 0; i < position - 1 && ptr != NULL; i++)
            {
                ptr = ptr->next;
            }

            if (ptr == NULL)
            {
                cout << "Position out of range!" << endl;
                return;
            }

            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        this->count++;
    }

    void viewAllNodes()
    {
        Node *ptr = this->head;
        cout << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void update(int data, int position)
    {
        if (position < 0 || position > this->count)
        {
            cout << "Position is out of range!" << endl;
            return;
        }

        else
        {
            Node *ptr = this->head;
            for (int i = 0; i < position; i++)
            {
                ptr = ptr->next;
            }
            ptr->data = data;
        }
    }

    void deleteAtBeginning()
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }

        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        temp = NULL;

        this->count--;
    }

    void deleteAtEnd()
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }

        Node *ptr = this->head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL;
        ptr = NULL;

        this->count--;
    }

    void deleteAtAnyPosition(int position)
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is already empty" << endl;
            return;
        }

        if (position < 0 || position >= this->count)
        {
            cout << "Position is out of range!" << endl;
            return;
        }

        if (position == 0)
        {
            deleteAtBeginning();
            return;
        }

        Node *prev = this->head;
        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }

        Node *current = prev->next;
        prev->next = current->next;
        delete current;

        this->count--;
    }
};

int main()
{
    LinkedList list;
    int choice;
    int element;
    int position;

    do
    {
        cout << endl;
        cout << "Press 0 to Exit" << endl;
        cout << "Press 1 to insert a node at the beginning of the list" << endl;
        cout << "Press 2 to insert a node at the end of the list" << endl;
        cout << "Press 3 to insert a node at any position in the list" << endl;
        cout << "Press 4 to view the linked list " << endl;
        cout << "Press 5 to update the linked list" << endl;
        cout << "Press 6 to delete a node from beginning" << endl;
        cout << "Press 7 to delete a node from end" << endl;
        cout << "Press 8 to delete a node from any position" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the data: ";
            cin >> element;
            list.addAtBeginning(element);
            cout << "Data Added Successfully." << endl;
            break;
        case 2:
            cout << "Enter the data: ";
            cin >> element;
            list.addAtEnd(element);
            cout << "Data Added Successfully." << endl;
            break;
        case 3:
            cout << "Enter the data: ";
            cin >> element;
            cout << "Enter the position: ";
            cin >> position;
            list.addAtAnyPosition(element, position);
            cout << "Data Added Successfully." << endl;
            break;
        case 4:
            list.viewAllNodes();
            break;

        case 5:
            cout << "Enter the data: ";
            cin >> element;
            cout << "Enter the position: ";
            cin >> position;
            list.update(element, position);
            cout << "Data Updated Successfully!"<<endl;
            break;
        case 6:
            list.deleteAtBeginning();
            cout << "Node deleted succesfully!"<<endl;
            break;
        case 7:
            list.deleteAtEnd();
            cout << "Node deleted succesfully!" <<endl;
            break;
        case 8:
            cout << "Enter the position: ";
            cin >> position;
            list.deleteAtAnyPosition(position);
            cout << "Node deleted succesfully!"<<endl;
            break;
        default:
            cout << "Please Enter a valid choice."<<endl;
        }
    } while (choice != 0);

    return 0;
}