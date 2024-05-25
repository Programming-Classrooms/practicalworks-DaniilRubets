#include "../List/List.hpp"


int main() 
{
    try
    {
        // Создаем список целых чисел
        LinkedList<int> intList;

        // Добавляем элементы в начало списка
        intList.insertAtBeginning(10);
        intList.insertAtBeginning(20);
        intList.insertAtBeginning(30);

        // Добавляем элементы в конец списка
        intList.insertAtEnd(40);
        intList.insertAtEnd(50);

        // Удаляем первый элемент
        intList.deleteFirst();

        // Удаляем последний элемент
        intList.deleteLast();

        // Поиск элемента
        int searchResult = intList.search(20);
        if (searchResult != -1) {
            std::cout << "Элемент 20 найден на позиции " << searchResult << std::endl;
        } else {
            std::cout << "Элемент 20 не найден" << std::endl;
        }    
    }
    
    catch(std::invalid_argument in)
    {
        std::cerr << in.what();
    }

    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }
    
    return 0;
}
