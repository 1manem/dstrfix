#pragma once
#include "DoubleLinkedList.h"
#include <fstream>

template <class T>
typename DoubleLinkedList<T>::Node* merge(typename DoubleLinkedList<T>::Node* left, typename DoubleLinkedList<T>::Node* right) {
    // Merge two sorted lists (left and right) into a single sorted list
    typename DoubleLinkedList<T>::Node* result = nullptr;

    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge<T>(left->next, right);
        result->next->prev = result;
    } else {
        result = right;
        result->next = merge<T>(left, right->next);
        result->next->prev = result;
    }

    return result;
}

template <class T>
void mergeSort(DoubleLinkedList<T>& dll) {
    // Perform merge sort on the DoubleLinkedList
    typename DoubleLinkedList<T>::Node* head = dll.getHead();

    if (head == nullptr || head->next == nullptr)
        return;

    typename DoubleLinkedList<T>::Node* mid = dll.getMiddle();
    typename DoubleLinkedList<T>::Node* nextToMid = mid->next;

    // Set the previous node of mid to nullptr
    mid->next = nullptr;
    nextToMid->prev = nullptr;

    DoubleLinkedList<T> leftHalf;
    DoubleLinkedList<T> rightHalf;

    leftHalf.setHead(head);
    leftHalf.setTail(mid);
    rightHalf.setHead(nextToMid);
    rightHalf.setTail(dll.getTail());

    mergeSort<T>(leftHalf);
    mergeSort<T>(rightHalf);

    dll.setHead(merge<T>(leftHalf.getHead(), rightHalf.getHead()));
    dll.setTail(merge<T>(leftHalf.getTail(), rightHalf.getTail()));
}