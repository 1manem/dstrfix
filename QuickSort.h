#include <iostream>
using namespace std;

template <class Node>
Node* Partition(Node* low, Node* high, bool asc,string type) {
        int pivot = high->rank;
        Node* i = low->prevAdd;


        for (Node* j = low; j != high; j = j->nextAdd) {
            if (asc){
            if (type == "rank"){
            if (j->rank <= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->rank, j->rank);
            }}
            else if (type == "arRank")
            {if (j->ArRank <= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->ArRank, j->ArRank);
            }}
            else if (type == "fsrScore")
            {if (j->FsrScore <= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->FsrScore, j->FsrScore);
            }}
            else if (type == "erRank")
            {if (j->ErRank <= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->ErRank, j->ErRank);
            }}
            }
            else{
                if (type == "rank"){
                if (j->rank >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->rank, j->rank);
            }}
            else if (type == "arRank")
            {if (j->ArRank >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->ArRank, j->ArRank);
            }}
            else if (type == "fsrScore")
            {if (j->FsrScore >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->FsrScore, j->FsrScore);
            }}
            else if (type == "erRank")
            {if (j->ErRank >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->ErRank, j->ErRank);
            }}
            }
        }

        i = (i == nullptr) ? low : i->nextAdd;
        std::swap(i->rank, high->rank);

        return i;

    }

    // Quicksort algorithm for linked list
    template <class Node>
    void QuickSort(Node* low, Node* high, bool asc, string type) {
        if (high != nullptr && low != high && low != high->nextAdd) {
            Node* pivot = Partition(low, high,asc,type);
            QuickSort(low, pivot->prevAdd, asc,type);
            QuickSort(pivot->nextAdd, high, asc,type);
        }
    }
