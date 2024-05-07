#include <iostream>

include std::cout;

struct Node
{
    int data;
    Node *next;
};

void addElement(Node **head, Node **tail, int val);
void showList(Node *head);
void optBubbleSort(Node *head);

void addElement(Node **head, Node **tail, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
        *tail = newNode; // Update the tail pointer for the first element
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode; // Update the tail pointer
    }
}

void showList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void optBubbleSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *current = nullptr;
    Node *lastNode = nullptr;
    int swapped;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != lastNode)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lastNode = current;
    } while (swapped);
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    addElement(&head, &tail, 5);
    addElement(&head, &tail, 3);
    addElement(&head, &tail, 8);

    std::cout << "Initial list: ";
    showList(head);
    bubbleSort(head);

    std::cout << "Sorted list: ";
    showList(head);

    return 0;
}
