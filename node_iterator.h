#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H

#include "dnode.h"

template<class T> class dlist;

template<class T>
class node_iterator {
    public:
        friend class dlist<T>;

        /**
         * @brief Construct a new node iterator object.
         * 
         * @param c the node that the iterator will start pointing at
         */
        node_iterator(dnode<T>* c = NULL) {current = c;}


        /**
         * @brief Checks if the node iterator is pointing to the same node as another node iterator.
         * 
         * @param other the other node iterator
         * @return true if the node_iterators are pointing at the same node
         */
        bool operator == (const node_iterator other) const {return current == other.current;}

        /**
         * @brief Checks if the node iterator is pointing to the same node as another node iterator.
         * 
         * @param other the other node iterator
         * @return true if the node_iterators aren't pointing at the same node
         */
        bool operator != (const node_iterator other) const {return current != other.current;}

        /**
         * @return the data value of the current node
         */
        T operator * () const {return current -> data();}

        /**
         * @brief Make the iterator point to the next node and return the new current node.
         * 
         * @return the new current node
         */
        node_iterator operator ++ ();

        /**
         * @brief Make the iterator point to the next node and return the old current node.
         * 
         * @return the old current node
         */
        node_iterator operator ++ (int);

        /**
         * @brief Make the iterator point to the previous node and return the new current node.
         * 
         * @return the new current node
         */
        node_iterator operator -- ();

        /**
         * @brief Make the iterator point to the previous node and return the old current node.
         * 
         * @return the old current node
         */
        node_iterator operator -- (int);

    private:
        dnode<T>* current;  // the node that the iterator is currently pointing to
};

#include "node_iterator.template"

#endif