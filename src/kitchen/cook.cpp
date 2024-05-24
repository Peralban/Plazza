/*
** EPITECH PROJECT, 2024
** cook.cpp
** File description:
** DESCRIPTION
*/

#include "cook.hpp"
#include "kitchen.hpp"
#include <string>

Cook::Cook(std::shared_ptr<MessageQueueThread<std::string>> messageQueue) :
        _messageQueue(messageQueue), _thread(&Cook::cookRoutine, this, messageQueue), _pizzaType(Plazza::NONE), _status(WAITING) {}

void Cook::cookRoutine(std::shared_ptr<MessageQueueThread<std::string>> messageQueue)
{
    while (true) {
        int pizzaTypeTmp =  std::stoi(messageQueue->pop());
        Plazza::PizzaType pizzaType = static_cast<Plazza::PizzaType>(pizzaTypeTmp);
        if (pizzaType == Plazza::Margarita || pizzaType == Plazza::Regina || pizzaType == Plazza::Americana || pizzaType == Plazza::Fantasia) {
            _status = COOKING;
            _pizzaType = pizzaType;
            std::cout << "Cooking pizza" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(pizzaType));
            std::cout << "Pizza : " << pizzaType << " is ready" << std::endl;
            _status = WAITING;
            _pizzaType = Plazza::NONE;
        }
    }
}

Cook::~Cook()
{
    _thread.join();
}
