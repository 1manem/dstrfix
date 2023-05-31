#include <iostream>
using namespace std;

template <class Node>
Node* Partition(Node* low, Node* high, bool asc) {
        int pivot = high->rank;
        Node* i = low->prevAdd;


        for (Node* j = low; j != high; j = j->nextAdd) {
            if (asc){
            if (j->rank >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->rank, j->rank);
            }
            }
            else{
                if (j->rank <= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->rank, j->rank);
            }
            }
        }

        i = (i == nullptr) ? low : i->nextAdd;
        std::swap(i->rank, high->rank);

        return i;

    }

    // Quicksort algorithm for linked list
    template <class Node>
    void QuickSort(Node* low, Node* high, bool asc) {
        if (high != nullptr && low != high && low != high->nextAdd) {
            Node* pivot = Partition(low, high,asc);
            QuickSort(low, pivot->prevAdd, asc);
            QuickSort(pivot->nextAdd, high, asc);
        }
    }
    // template <class Node>
    // void Quick_Sort() {
    //     QuickSort(head, tail);
    // }