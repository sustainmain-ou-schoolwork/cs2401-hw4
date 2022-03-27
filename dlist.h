#ifndef DLIST_H
#define DLIST_H

#include "dnode.h"
#include "node_iterator.h"

template<class T>
class dlist {
    public:
        typedef node_iterator<T> iterator;

        /**
         * @brief Construct a new dlist object.
         */
        dlist() {head = tail = NULL;}

        /**
         * @brief Destroy the dlist object.
         */
        ~dlist();

        /**
         * @brief Construct a new dlist object from an existing dlist object.
         * 
         * @param other the exisiting dlist object to copy values from
         */
        dlist(const dlist& other);

        /**
         * @brief Set the values of a dlist object based on the values of an existing dlist object.
         * 
         * @param other the exisiting dlist object to copy values from
         */
        void operator = (const dlist& other);


        /**
         * @brief Inserts an item at the front of the dlist.
         * 
         * @param item the item to be inserted
         */
        void front_insert(const T& item);

        /**
         * @brief Inserts an item at the rear of the dlist.
         * 
         * @param item the item to be inserted
         */
        void rear_insert(const T& item);

        /**
         * @brief Removes an item from the front of the dlist.
         */
        void front_remove();

        /**
         * @brief Removes an item from the rear of the dlist.
         */
        void rear_remove();


        /**
         * @brief Output the contents of the dlist to cout.
         */
        void show();

        /**
         * @brief Output the contents of the dlist in reverse order to cout.
         */
        void reverse_show();

    private:
        dnode<T>* head;
        dnode<T>* tail;
};

#include "dlist.template"

#endif