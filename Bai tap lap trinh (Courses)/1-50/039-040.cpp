#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node* insert(Node* head, int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if(head == nullptr || value < head->value)
    {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while(current->next != nullptr && current->next->value < value)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

Node* deleteDuplicates(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* current = head->next;
    Node* prev = head;

    while(current!= nullptr)
    {   
        if(prev->value == current->value)
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

void printLinkedList(Node* head)
{
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;
}

void printReverse(Node* head) {
    if (head == nullptr)
        return;
    printReverse(head->next);
    cout << head->value << " ";
}

int main()
{
    Node* head = nullptr;

    head = insert(head, 3);
    head = insert(head, 7);
    head = insert(head, 5);
    head = insert(head, 8);
    head = insert(head, 6);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 7);
    head = deleteDuplicates(head);
    printLinkedList(head);
    printReverse(head);
}