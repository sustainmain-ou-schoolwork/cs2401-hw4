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
        dlist();

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
         * @return an iterator pointing to the head
         */
        iterator begin() {return iterator(head);}

        /**
         * @return an iterator pointing to NULL
         */
        iterator end() {return iterator(NULL);}

        /**
         * @return an iterator pointing to the tail
         */
        iterator r_begin() {return iterator(tail);}

        /**
         * @return an iterator pointing to NULL
         */
        iterator r_end() {return iterator(NULL);}


        /**
         * @return the number of nodes in the dlist 
         */
        int size() const {return nodeCount;}


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
         * @brief Inserts an item before an iterator.
         * 
         * @param it the iterator
         * @param item the item to be inserted
         */
        void insert_before(iterator it, const T& item);

        /**
         * @brief Inserts an item after an iterator.
         * 
         * @param it the iterator
         * @param item the item to be inserted
         */
        void insert_after(iterator it, const T& item);

        /**
         * @brief Removes an item from the front of the dlist.
         */
        void front_remove();

        /**
         * @brief Removes an item from the rear of the dlist.
         */
        void rear_remove();

        /**
         * @brief Removes an item specified by an iterator from the dlist.
         * 
         * @param it the iterator
         */
        void remove(iterator it);


        /**
         * @brief Output the contents of the dlist to cout.
         */
        void show() const;

        /**
         * @brief Output the contents of the dlist in reverse order to cout.
         */
        void reverse_show() const;

    private:
        dnode<T>* head;
        dnode<T>* tail;
        size_t nodeCount;
};

#include "dlist.template"

#endif