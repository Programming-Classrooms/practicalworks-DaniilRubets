#ifndef DEQUE_HPP
#define DEQUE_HPP
#include <iostream>
#include <stdexcept>

template<typename TInfo>

class TDeque /* дек – двустороння очередь */
{
protected:

	struct TDequeItem // элемент дека
	{
		TInfo Info; // данные
		TDequeItem* next; // указатель на следующий элемент
		TDequeItem* prev; // указатель на предыдущий элемент
	};

/* указатели на первый и последний элементы в списке */
TDequeItem *front, *rear;

int size; // количество элементов в деке
void Erase(); // удаление всех элементов
void Clone(const TDeque&);
void DeleteItem(TDequeItem*); // удаление элемента по указателю
void* PtrByIndex(unsigned)const; // указатель на элемент с заданным индексом

public:
/*######## Конструкторы ########*/
TDeque(); 
TDeque(const TDeque &); 

/*######## Деструктор ########*/
virtual ~TDeque(); 

/*######## Методы ########*/
void InsFront(TInfo); // включить элемент в голову дека
void InsRear(TInfo); // включить элемент в хвост дека
bool DelFront(TInfo &); // исключить элемент из головы дека
bool DelRear(TInfo &); // исключить элемент из хвоста дека
const TDeque& operator = (const TDeque &);// оператор присваивания
const TInfo& GetByIndex(unsigned)const; // получить элемент по индексу
void SetByIndex(TInfo, unsigned); // изменить элемент по индексу
void Browse(void(TInfo&)); // просмотр с изменением элементов
void Browse(void(TInfo)) const; // просмотр без изменения элементов
};

#include "../Deque/Deque.inl"
#endif //DEQUE_HPP