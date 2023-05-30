#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// template <class node>

struct Node {
    string data;
    struct Node* next;
};

void push(struct Node** head_ref, string new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    cout << "Sorted list:" << endl;
    while (node != NULL) {
        cout << node->data << endl;
        node = node->next;
    }
}

struct Node* getTail(struct Node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

struct Node* partition(struct Node* head, struct Node* end,
                       struct Node** newHead,
                       struct Node** newEnd)
{
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

struct Node* quickSortRecur(struct Node* head, struct Node* end)
{
    if (!head || head == end)
        return head;

    Node* newHead = NULL, * newEnd = NULL;
    struct Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct Node** headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

void readCSVQuickSort(const string& filename)
{
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    const int MAX_SIZE = 100;
    string values[MAX_SIZE];
    string line;
    int i = 0;

    while (getline(file, line) && i < MAX_SIZE) {
        stringstream ss(line);
        string value;

        getline(ss, value, ',');
        values[i] = value;

        i++;
    }

    file.close();

    struct Node* head = NULL;

    for (int j = i - 1; j >= 0; j--)
        push(&head, values[j]);

    cout << "\nSorted array is:" << endl;
    printList(head);
}