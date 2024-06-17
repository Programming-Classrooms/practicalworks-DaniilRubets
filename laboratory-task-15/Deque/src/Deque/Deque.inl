#include "../Deque/Deque.hpp"

template <typename TInfo>
void TDeque<TInfo>::Erase() 
{
    while (size > 0) 
    {
            DeleteItem(front);
    }
}

template <typename TInfo>
void TDeque<TInfo>::Clone(const TDeque& other) 
{
    for (TDequeItem* item = other.front; item != nullptr; item = item->next) 
    {
            InsRear(item->Info);
    }
}

template <typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* item) 
{
    if (item == front) 
    {
            front = item->next;
    } 

    else 
    {
            item->prev->next = item->next;
    }

    if (item == rear) 
    {
        rear = item->prev;
    } 

    else 
    {
        item->next->prev = item->prev;
    }

        delete item;
        size--;
}

template <typename TInfo>
void* TDeque<TInfo>::PtrByIndex(unsigned index) const 
{
    TDequeItem* item = front;
        while (index-- > 0 && item != nullptr) 
        {
            item = item->next;
        }
        return item;
}

template <typename TInfo>
TDeque<TInfo>::TDeque(): front(nullptr), rear(nullptr), size(0) {}

template <typename TInfo>
TDeque<TInfo>::TDeque(const TDeque &other) : front(nullptr), rear(nullptr), size(0) 
{
        Clone(other);
}

template <typename TInfo>
TDeque<TInfo>::~TDeque() 
{
     Erase();
}

template <typename TInfo>
void TDeque<TInfo>::InsFront(TInfo info) 
{
    TDequeItem* item = new TDequeItem{info, front, nullptr};
        if (front != nullptr) 
        {
            front->prev = item;
        }

        front = item;

        if (rear == nullptr) 
        {
            rear = item;
        }
        size++;
}

template <typename TInfo>
void TDeque<TInfo>::InsRear(TInfo info) 
{
    TDequeItem* item = new TDequeItem{info, nullptr, rear};
    if (rear != nullptr) 
    {
        rear->next = item;
    }

    rear = item;

    if (front == nullptr) 
    {
        front = item;
    }

    size++;
}

template <typename TInfo>
bool TDeque<TInfo>::DelFront(TInfo &info) 
{
    if (front == nullptr) 
    {
        return false;
    }

    info = front->Info;
    DeleteItem(front);
    return true;
}


template <typename TInfo>
bool TDeque<TInfo>::DelRear(TInfo &info) 
{
    if (rear == nullptr) 
    {
        return false;
    }

    info = rear->Info;
    DeleteItem(rear);
    return true;
}

template <typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator = (const TDeque &other) 
{
    if (this != &other) 
    {
        Erase();
        Clone(other);
    }

    return *this;
}


template <typename TInfo>
const TInfo& TDeque<TInfo>::GetByIndex(unsigned index) const 
{
    TDequeItem* item = PtrByIndex(index);
    if (item == nullptr) 
    {
        throw std::out_of_range("Index out of range");
    }

    return item->Info;
}

template <typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo info, unsigned index) 
{
    TDequeItem* item = PtrByIndex(index);
    if (item == nullptr) 
    {
        throw std::out_of_range("Index out of range");
    }

    item->Info = info;
}

template <typename TInfo>
void TDeque<TInfo>::Browse(void(*action)(TInfo&)) 
{
    for (TDequeItem* item = front; item != nullptr; item = item->next) 
    {
        action(item->Info);
    }
}

template <typename TInfo>
void TDeque<TInfo>::Browse(void(*action)(TInfo)) const 
{
    for (TDequeItem* item = front; item != nullptr; item = item->next) 
    {
        action(item->Info);
    }
}