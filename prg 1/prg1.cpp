#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
Node *XOR(Node *x, Node *y)
{
    return (Node *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverse(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    while (curr != nullptr)
    {
        cout << curr->data << " > ";

        next = XOR(prev, curr->link);

        prev = curr;
        curr = next;
    }

    cout << "nullptr\n";
}

void push(Node *&headRef, int data)
{

    Node *newNode = new Node();
    newNode->data = data;

    newNode->link = XOR(headRef, nullptr);

    if (headRef)
    {
        headRef->link = XOR(newNode, XOR(headRef->link, nullptr));
    }

    headRef = newNode;
}

int main()
{

    Node *head = nullptr;

    int n;
    while (1)
    {
        cout << "Choose:\n1.Insert\t2.Display\t3.exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            int a;
            cin >> a;
            push(head, a);
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}