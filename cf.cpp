//  SORT A LINKED LIST WHICH IS ALREADY SORTED IN ABSOLUTE VALUES

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define all v.begin(), v.end()

#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node *next;
    int data;
};

// Utility function to insert a node at the
// beginning
void push(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void sortList(Node **head)
{
    Node *temp = *head;
    Node *positive = new Node;
    positive->data = -1;
    Node *negative;
    Node *temporary = *head;
    while (temporary != NULL)
    {
        if (temporary->data >= 0)
            break;
        temporary = temporary->next;
    }
    negative = temporary;
    while (temp != NULL)
    {
        Node *curr = temp;
        if (temp->data >= 0)
        {
            positive->next = curr;
            positive = curr;
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
            curr->next = negative;
            negative = curr;
        }
    }
    positive->next = NULL;
    *head = negative; // Your Code Here
}
int main()
{
    Node *head = NULL;
    push(&head, -5);
    // push(&head, 5);
    push(&head, 4);
    push(&head, -3);
    push(&head, -2);
    push(&head, 1);
    // push(&head, 0);

    cout << "Original list :\n";
    printList(head);

    sortList(&head);

    cout << "\nSorted list :\n";
    printList(head);

    return 0;
}
