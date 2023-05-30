// #include <iostream>

// // Node class represents a single node in the linked list
// template <class Node>
// // SingleLinkedList class represents the singly linked list
// class SingleLinkedList {
// public:
// 	Node* head;
//     Node* tail;
//     SingleLinkedList() {
//         head = nullptr;
//     }

//     // Insert at the front
//     void insertFront(Node * newNode) {
// 		if (head == NULL)
// 		{
// 			head = newNode;
// 		}
// 		else
// 		{
// 			newNode->nextAdd = head;
// 			head = newNode;
// 		}

// 		size++;
// 	}

//     // Insert at the end
// 	void insertEnd(Node * newNode) {
// 		if (head == NULL)
// 		{
// 			head = newNode;
// 		}
// 		else
// 		{
// 			Node* current = head;
// 			while (current->nextAdd != NULL)
// 			{
// 				current = current->nextAdd;
// 			}

// 			current->nextAdd = newNode;
// 		}

// 		size++;
// 	}
//     // Display the elements in the list
//     void display() {
//         Node* current = head;
//         while (current != nullptr) 
//         {
//             current->display();
// 			cout << endl;
// 			current = current->nextAdd;
//         }
//         std::cout << "List ends" << std::endl;
//     }

// private:
//     int size;
// };