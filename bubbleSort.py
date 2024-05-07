#include <iostream>

using std::cout;

struct Node {
    int data;
    Node* next;
};

void addElement(Node** head, int val);
void showList(Node* head);
void bubbleSort(Node* head);

void addElement(Node** head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* lastNode = *head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void showList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void bubbleSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = nullptr;
    Node* lastNode = nullptr;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (current->next != lastNode) {
            if (current->data > current->next->data) {
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

int main() {

    Node* head = nullptr;

    addElement(&head, 5);
    addElement(&head, 3);
    addElement(&head, 8);

    std::cout << "Initial list: ";
    showList(head);

    // Perform bubble sort
    bubbleSort(head);

    std::cout << "Sorted list: ";
    showList(head);

    return 0;
}