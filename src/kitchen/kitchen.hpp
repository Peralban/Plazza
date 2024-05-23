/*
** EPITECH PROJECT, 2024
** kitchen.hpp
** File description:
** DESCRIPTION
*/

#pragma once

#include <iostream>
#include <list>
#include <thread>
#include <map>
#include "messageQueue/messageQueueIPC.hpp"


/**
 * @class Kitchen
 * @brief Main class for managing the kitchen operations.
 */
class Kitchen {
    public:

        /**
         * @brief Constructor for the Kitchen class.
         * @param nbCooks The number of cooks.
         * @param time The time to restock ingredients.
        */
        Kitchen(size_t nbCooks, size_t time);

        /**
         * @brief Destructor for the Kitchen class.
         */
        ~Kitchen();

        /**
         * @brief Checks if there are available commands.
         * @return true if commands are available, false otherwise.
         */
        bool commandAreAvailable();

        /**
         * @brief Creates a new cook.
         */
        void createCook();

    private:
        /**
         * @class Stock
         * @brief Inner class for managing the stock of ingredients.
         */
        class Stock {
        public:
            /**
             * @brief Constructor for the Stock class.
             */
            Stock();

            /**
             * @brief Destructor for the Stock class.
             */
            ~Stock();

            /**
             * @enum Ingredients
             * @brief Enum for the different types of ingredients.
             */
            enum Ingredients {
                Dough,
                Tomato,
                Gruyere,
                Ham,
                Mushroom,
                Steak,
                Eggplant,
                Goatcheese,
                ChiefLove
            };

            /**
             * @enum Pizza
             * @brief Enum for the different types of pizzas.
             */
            enum Pizza {
                Regina,
                Margarita,
                Americana,
                Fantasia
            };

            /**
             * @brief Restocks the ingredients.
             */
            void restock();

            /**
             * @brief Checks if there are enough ingredients for a specific pizza.
             * @param pizza The type of pizza to check for.
             * @return true if there are enough ingredients, false otherwise.
             */
            bool hasEnoughIngredient(Pizza pizza);

            /**
             * @brief Takes the ingredients for a specific pizza.
             * @param pizza The type of pizza to take ingredients for.
             */
            void takeIngredient(Pizza pizza);

        private:
            size_t _dough; ///< Amount of dough in stock.
            size_t _tomato; ///< Amount of tomato in stock.
            size_t _gruyere; ///< Amount of gruyere in stock.
            size_t _ham; ///< Amount of ham in stock.
            size_t _mushroom; ///< Amount of mushroom in stock.
            size_t _steak; ///< Amount of steak in stock.
            size_t _eggplant; ///< Amount of eggplant in stock.
            size_t _goatCheese; ///< Amount of goat cheese in stock.
            size_t _chiefLove; ///< Amount of chief love in stock.

            /**
             * @brief Map for storing the ingredients required for each type of pizza.
             */
            std::map<Kitchen::Stock::Pizza, std::map<Ingredients, size_t>> _pizzaIngredients = {
                {Regina, {{Dough, 1}, {Tomato, 1}, {Gruyere, 1}, {Ham, 1}, {Mushroom, 1}}},
                {Margarita, {{Dough, 1}, {Tomato, 1}, {Gruyere, 1}}},
                {Americana, {{Dough, 1}, {Tomato, 1}, {Gruyere, 1}, {Steak, 1}}},
                {Fantasia, {{Dough, 1}, {Tomato, 1}, {Eggplant, 1}, {Goatcheese, 1}, {ChiefLove, 1}}}
            };
        };
        size_t _nbCooks; ///< Number of cooks.
        size_t _commandNumber; ///< Number of commands.
        std::list<std::thread> _cooks; ///< List of cook threads.
        size_t _timeToRestock; ///< Time to restock ingredients.
        Stock _stock; ///< Stock of ingredients.

        /**
         * @brief Message queue for receiving commands.
         */
        MessageQueueIPC<std::string> _kitchenQueue;

        /**
         * @brief Thread for receiving commands.
         */
        MessageQueueIPC<std::string> _receptionQueue;
};