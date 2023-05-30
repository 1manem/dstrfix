// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// using namespace std;

// struct Node {
//     string data;
//     struct Node* next;
//     struct Node* prev;
// };

// void printList(struct Node* node)
// {
//     cout << "Sorted list:" << endl;
//     while (node != NULL) {
//         cout << node->data << endl;
//         node = node->next;
//     }
// }

// struct Node* getTail(struct Node* cur)
// {
//     while (cur != NULL && cur->next != NULL)
//         cur = cur->next;
//     return cur;
// }

// struct Node* partition(struct Node* head, struct Node* end,
//                        struct Node** newHead,
//                        struct Node** newEnd)
// {
//     struct Node* pivot = end;
//     struct Node *prev = NULL, *cur = head, *tail = pivot;

//     while (cur != pivot) {
//         if (cur->data < pivot->data) {
//             if ((*newHead) == NULL)
//                 (*newHead) = cur;

//             prev = cur;
//             cur = cur->next;
//         }
//         else {
//             if (prev)
//                 prev->next = cur->next;
//             struct Node* tmp = cur->next;
//             cur->next = NULL;
//             cur->prev = NULL;
//             tail->next = cur;
//             cur->prev = tail;
//             tail = cur;
//             cur = tmp;
//         }
//     }

//     if ((*newHead) == NULL)
//         (*newHead) = pivot;

//     (*newEnd) = tail;

//     return pivot;
// }

// struct Node* quickSortRecur(struct Node* head, struct Node* end)
// {
//     if (!head || head == end)
//         return head;

//     Node* newHead = NULL, * newEnd = NULL;
//     struct Node* pivot = partition(head, end, &newHead, &newEnd);

//     if (newHead != pivot) {
//         struct Node* tmp = newHead;
//         while (tmp->next != pivot)
//             tmp = tmp->next;
//         tmp->next = NULL;

//         newHead = quickSortRecur(newHead, tmp);

//         tmp = getTail(newHead);
//         tmp->next = pivot;
//         pivot->prev = tmp;
//     }

//     pivot->next = quickSortRecur(pivot->next, newEnd);
//     if (pivot->next != NULL)
//         pivot->next->prev = pivot;

//     return newHead;
// }

// void quickSort(struct Node** headRef)
// {
//     (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
//     return;
// }