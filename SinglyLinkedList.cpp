#include <iostream>
using namespace std;

// node class
class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

// Singly Linked List Class
class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    // 1. Check if node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // 2.Append a node  to the list
    void appendeNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node Already exist with Key value " << n->key << ". Append another node with different value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended." << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }
    // 3.Prepend Node - Attach a node at start
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node Already exist with Key value " << n->key << ". Preppend another node with different value" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }
    // 4. Insert a Node after a particular node in the list
    void insertNodedAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists wiht key value " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node Already exist with Key value " << n->key << ". Append another node with different value" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
    // 5.Delete a Node by unique key
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List is already empty. Can't delete" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Unlinked with key value " << k << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node Unlinked with key value " << k << endl;
                }
                else
                {
                    cout << "Node doesn't exists with key value " << k << endl;
                }
            }
        }
    }
    // 6.Update the Node by Key value
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated succesfully" << endl;
        }
        else
        {
            cout << "Node doesn't exists with key value " << k << endl;
        }
    }
    // 7.Printing  SinglyLinkedList
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Singly Linked List " << endl;
        }
        else
        {
            cout << endl
                 << "Singly Linked List Values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << "," << temp->data << " )-->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << endl
             << "What Operation do you want to perform?\nSelect Option number.Enter 0 to exist" << endl;
        cout << "1. Append Node ." << endl;
        cout << "2. PrePend Node ." << endl;
        cout << "3. Insert Node ." << endl;
        cout << "4. Delete Node by key Value ." << endl;
        cout << "5. Update Node by Key Value ." << endl;
        cout << "6. Print list ." << endl;
        // cout << "7. Clear Screen ." << endl;
        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            /* code */
            break;
        case 1:
            cout << "Append Node Operation \nEnter key value & Data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendeNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the node to be Prepended." << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node Operation \nEnter key of existing node after which you want to insert this Node: " << endl;
            cin >> k1;
            cout << "Enter Key and Data of new Node that You are Inserting : " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodedAfter(k1, n1);
            break;
        case 4:
            cout << "Delete Node Operation \nEnter key of node that you want to Delete: " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update Node Operation \nEnter key and new Data to be updated:" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printList();
            break;
        //  case 7:
        //      system("cls");
        //      break;
        default:
            cout << "Enter proper Option Number." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}