/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Reception
*/

#pragma once

#include "kitchen/kitchen.hpp"
#include "Arguments/Arguments.hpp"
#include "messageQueue/messageQueueIPC.hpp"

#include <vector>
#include <memory>
#include <string>

namespace Plazza {
    /**
     * @class Reception
     * @brief The Reception class represents the reception area of a restaurant.
     * The Reception class is responsible for managing incoming orders and assigning them to available kitchens.
     * It maintains a list of kitchens and their corresponding message queues for inter-process communication.
     */
    class Reception {
    public:
        /**
         * @brief Constructs a Reception object with the given arguments.
         * @param args The arguments for configuring the reception.
         */
        Reception(Arguments &args);

        /**
         * @brief Destroys the Reception object.
         */
        ~Reception();

        /**
         * @brief Adds an order to the reception.
         * @param order The order to be added.
         */
        void addOrder(const std::string &order);

        /**
         * @brief Creates a new kitchen and adds it to the list of kitchens.
         */
        void createKitchen();

    private:
        Arguments _args; /**< The arguments for configuring the reception. */
        MessageQueueIPC<std::string> _receiverQueue; /**< The message queue for receiving orders. */
        std::vector<MessageQueueIPC<std::string>> _kitchenQueues; /**< The message queues for sending orders to kitchens. */

        /**
         * @brief Gets the index of an available kitchen.
         * @return The index of an available kitchen, or -1 if no kitchen is available.
         */
        int getAvailableKitchen();
    };
}