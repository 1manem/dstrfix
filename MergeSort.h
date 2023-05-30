#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
    template<class Node>
    Node* Merge(Node* left, Node* right) {
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        Node* result = nullptr;
        if (left->rank >= right->rank) {
            result = left;
            result->nextAdd = Merge(left->nextAdd, right);
            result->nextAdd->prevAdd = result;
        }
        else {
            result = right;
            result->nextAdd = Merge(left, right->nextAdd);
            result->nextAdd->prevAdd = result;
        }

        return result;
    }
    template<class Node>
    Node* MergeSort(Node* head) {
        if (head == nullptr || head->nextAdd == nullptr)
            return head;

        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->nextAdd;

        middle->nextAdd = nullptr;
        nextToMiddle->prevAdd = nullptr;

        Node* left = MergeSort(head);
        Node* right = MergeSort(nextToMiddle);

        return Merge(left, right);
    }
    template<class Node>
    Node* getMiddle(Node* head) {
        if (head == nullptr)
            return head;

        Node* slow = head;
        Node* fast = head;

        while (fast->nextAdd != nullptr && fast->nextAdd->nextAdd != nullptr) {
            slow = slow->nextAdd;
            fast = fast->nextAdd->nextAdd;
        }

        return slow;
    };
