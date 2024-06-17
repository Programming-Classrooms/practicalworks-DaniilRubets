#include "../Deque/Deque.hpp"


int main()
{
    try
    {
        TDeque<int> deque; // Создаем дек целых чисел

        // Вставляем элементы в начало
        deque.InsFront(1);
        deque.InsFront(2);
        deque.InsFront(3);

        // Вставляем элементы в конец
        deque.InsRear(4);
        deque.InsRear(5);
        deque.InsRear(6);


        // Удаляем элементы из начала и выводим их
        int info;
        while (deque.DelFront(info)) {
            std::cout << "Начало: " << info << std::endl;
        }
    }

    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }

    catch(std::invalid_argument in)
    {
        std::cerr << in.what();
    }

    return 0;
}