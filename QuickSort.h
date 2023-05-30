template <class Node>
Node* Partition(Node* low, Node* high) {
        int pivot = high->rank;
        Node* i = low->prevAdd;

        for (Node* j = low; j != high; j = j->nextAdd) {
            if (j->rank >= pivot) {
                i = (i == nullptr) ? low : i->nextAdd;
                std::swap(i->rank, j->rank);
            }
        }

        i = (i == nullptr) ? low : i->nextAdd;
        std::swap(i->rank, high->rank);

        return i;

    }

    // Quicksort algorithm for linked list
    template <class Node>
    void QuickSort(Node* low, Node* high) {
        if (high != nullptr && low != high && low != high->nextAdd) {
            Node* pivot = Partition(low, high);
            QuickSort(low, pivot->prevAdd);
            QuickSort(pivot->nextAdd, high);
        }
    }
    // template <class Node>
    // void Quick_Sort() {
    //     QuickSort(head, tail);
    // }