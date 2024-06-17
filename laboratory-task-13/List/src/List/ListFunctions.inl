#include "../List/List.hpp"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) : head(nullptr), tail(nullptr), size(list.size) 
{
    Node<T>* temp = list.head;
    while (temp) {
        this->insertAtEnd(temp->data);
        temp = temp->next;
    }
}


template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list) 
{
    if (this == &list)
        return *this;

    this->~LinkedList();

    Node<T>* temp = list.head;
    while (temp) {
        this->insertAtEnd(temp->data);
        temp = temp->next;
    }

    return *this;
}


template <typename T>
LinkedList<T>::~LinkedList() 
{
    while (size)
        deleteFirst();
}


template <typename T>
void LinkedList<T>::insertAtBeginning(T data) 
{
    Node<T>* newNode = new Node<T>{ data, head };
    head = newNode;
    if (!tail)
        tail = head;
    size++;
}


template <typename T>
void LinkedList<T>::insertAtEnd(T data) 
{
    Node<T>* newNode = new Node<T>{ data, nullptr };
    if (tail)
        tail->next = newNode;
    else
        head = newNode;
    tail = newNode;
    size++;
}


template <typename T>
void LinkedList<T>::deleteFirst() 
{
    if (!head)
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    if (!head)
        tail = nullptr;
    size--;
}


template <typename T>
void LinkedList<T>::deleteLast() 
{
    if (!head)
        return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<T>* temp = head;
        while (temp->next != tail)
            temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    size--;
}


template <typename T>
void LinkedList<T>::deleteByValue(T data) 
{
    if (!head)
        return;

    if (head->data == data) {
        deleteFirst();
        return;
    }

    Node<T>* temp = head;
    while (temp->next && temp->next->data != data)
        temp = temp->next;

    if (temp->next) {
        Node<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        if (toDelete == tail)
            tail = temp;
        delete toDelete;
        size--;
    }
}

template <typename T>
int LinkedList<T>::search(T data) 
{
    Node<T>* temp = head;
    int index = 0;
    while (temp) {
        if (temp->data == data)
            return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

template <typename T>
void LinkedList<T>::viewAndModifyAll(T(*modifyFunc)(T)) 
{
    Node<T>* temp = head;
    while (temp) {
        if (modifyFunc)
            temp->data = modifyFunc(temp->data);
        temp = temp->next;
    }
}


template <typename T>
void LinkedList<T>::viewWithCallback(void (*callbackFunc)(T)) 
{
    Node<T>* temp = head;
    while (temp) {
        if (callbackFunc)
            callbackFunc(temp->data);
        temp = temp->next;
    }
}
