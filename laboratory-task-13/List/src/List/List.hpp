/*Создать класс «линейный однонаправленный список», в котором будут
храниться данные заданного типа. В классе должны быть реализованы
следующие методы:
o конструктор без параметров, создающий пустой список;
o конструктор копирования;
o перегрузка оператора присваивания;
o деструктор;
o вставка нового элемента в начало списка;
o вставка нового элемента в конец списка;
o удаление первого элемента списка;
o удаление последнего элемента списка;
o удаление элемента по значению;
o поиск элемента по значению с подсчетом числа сравнений,
выполненных в процессе поиска;
o просмотр списка с изменением всех значений;
o просмотр списка с вызовом callback-функции, которая не
изменяет хранящееся значение.
В головной программе продемонстрировать работу всех методов с выдачей на
экран пояснения всей действий (см. этот пример). Типы данных для
реализации проекта получить у преподавателя.*/

#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    /*####### Конструкторы #######*/
    LinkedList();
    LinkedList(const LinkedList<T>& list);

    /*####### Деструктор #######*/
    ~LinkedList();

    /*####### Оператор присваивания #######*/
    LinkedList<T>& operator=(const LinkedList<T>& list);

    /*####### Методы #######*/
    void insertAtBeginning(T data);
    void insertAtEnd(T data);
    void deleteFirst();
    void deleteLast();
    void deleteByValue(T data);
    int search(T data);
    void viewAndModifyAll(T(*modifyFunc)(T));
    void viewWithCallback(void (*callbackFunc)(T));
};
template class LinkedList<int>;
template class LinkedList<double>;

#include "ListFunctions.inl"

#endif
