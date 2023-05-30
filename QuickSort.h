#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

template <class Node>
void swapNodes(Node* a, Node* b) {
    if (a == nullptr || b == nullptr)
        return;

    // Swap the next pointers
    Node* temp = a->nextAdd;
    a->nextAdd = b->nextAdd;
    b->nextAdd = temp;

    // Swap the prev pointers
    temp = a->prevAdd;
    a->prevAdd = b->prevAdd;
    b->prevAdd = temp;

    // Update the next node's prev pointer
    if (a->nextAdd != nullptr)
        a->nextAdd->prevAdd = a;
    if (b->nextAdd != nullptr)
        b->nextAdd->prevAdd = b;

    // Update the prev node's next pointer
    if (a->prevAdd != nullptr)
        a->prevAdd->nextAdd = a;
    if (b->prevAdd != nullptr)
        b->prevAdd->nextAdd = b;
}

template <class Node>
Node* partition(Node* low, Node* high) {
    double pivot = high->ScoreScaled;
    Node* i = low->prevAdd;

    for (Node* j = low; j != high; j = j->nextAdd) {
        if (j->ScoreScaled <= pivot) {
            i = (i == nullptr) ? low : i->nextAdd;
            swapNodes(i, j);
        }
    }

    i = (i == nullptr) ? low : i->nextAdd;
    swapNodes(i, high);
    return i;
}

template <class Node>
void SortAscending(DoubleLinkedList<Node>& univDLL) {
    quickSort(univDLL, univDLL.head, univDLL.tail, true);
}

template <class Node>
void SortDescending(DoubleLinkedList<Node>& univDLL) {
    quickSort(univDLL, univDLL.head, univDLL.tail, false);
}

template <class Node>
void quickSort(DoubleLinkedList<Node>& univDLL, Node* low, Node* high, bool ascending) {
    if (low != nullptr && high != nullptr && low != high && high->nextAdd != low) {
        Node* pivot = partition(low, high, ascending);
        quickSort(univDLL, low, pivot->prevAdd, ascending);
        quickSort(univDLL, pivot->nextAdd, high, ascending);
    }
}

template <class Node>
void quickSort(univDLL.head, Node* low, Node* high) {
    if (low != nullptr && high != nullptr && low != high && high->nextAdd != low) {
        University* pivot = partition(low, high);
        quickSort(univDLL, low, pivot->prevAdd);
        quickSort(univDLL, pivot->nextAdd, high);
    }
};