#include <iostream>

using namespace std;

template <class Node>
Node* midNode(Node* front, Node* back){
	if(front == NULL){
		return NULL;
	}
	Node* left = front;
	Node* right = front->nextAdd;
	
	while(right != back){
		right = right->nextAdd;
		if(right != back && right != NULL){
			left = left->nextAdd;
			right = right->nextAdd;
		}
	}
	return left;
}


template <class Node> 
Node* NormalBinarySearch(Node* head, string target) {
	Node* begin = head;
	Node* finish = NULL;
	while (begin != finish) {
		Node* mid = midNode(begin, finish);
		if (stoi(target) == mid->rank) {
            return mid;
		}
		else if (mid->rank > stoi(target)) {
			finish = mid->prevAdd;
		}
		else {
			begin = mid->nextAdd;
		}
	}
	return NULL;
};

template <class Node>
Node* MemberBinarySearch(Node* head, string target, int type) {
    Node* begin = head;
    Node* finish = nullptr;
    switch (type) {
        case 1:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (stoi(target) == mid->rank) {
                    return mid;
                }
                else if (mid->rank > stoi(target)) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;

        case 2:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (target.compare(mid->institution) == 0) {
                    return mid;
                }
                else if (mid->institution.compare(target) > 0) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;
            
        case 3:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (target.compare(mid->LocationCode) == 0) {
                    return mid;
                }
                else if (mid->LocationCode.compare(target) > 0) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;
            
        case 4:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (target.compare(mid->Location) == 0) {
                    return mid;
                }
                else if (mid->Location.compare(target) > 0) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;
        
        case 5:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (stoi(target) == mid->ArRank) {
                    return mid;
                }
                else if (mid->ArRank > stoi(target)) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;
            
        case 6:
            while (begin != finish) {
                Node* mid = midNode(begin, finish);
                if (stoi(target) == mid->ErRank) {
                    return mid;
                }
                else if (mid->ErRank > stoi(target)) {
                    finish = mid;
                }
                else {
                    begin = mid->nextAdd;
                }
            }
            break;
            
        

        default:
            return nullptr;
    }

    return nullptr;
}