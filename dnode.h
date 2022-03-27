#ifndef DNODE_H
#define DNODE_H

template<class T>
class dnode {
    public:
        /**
         * @brief Construct a new dnode object.
         * 
         * @tparam T the data type of the value to be stored by the dnode
         * @param d the value to be stored by dnode
         * @param p the pointer to the previous dnode
         * @param n the pointer to the next dnode
         */
        dnode(T d = T(), dnode<T>* p = NULL, dnode<T>* n = NULL) {data_field = d; prev_field = p; next_field = n;}


        /**
         * @brief Set the data stored by the dnode.
         * 
         * @param d the new value to store
         */
        void set_data(T d) {data_field = d;}

        /**
         * @brief Set the pointer to the previous dnode.
         * 
         * @param n the dnode to point to
         */
        void set_prev(dnode<T>* p) {prev_field = p;}

        /**
         * @brief Set the pointer to the next dnode.
         * 
         * @param n the dnode to point to
         */
        void set_next(dnode<T>* n) {next_field = n;}


        /**
         * @return the value of the data stored by the dnode
         */
        T data() const {return data_field;}

        /**
         * @return the address of the previous dnode
         */
        dnode<T>* prev() const {return prev_field;}

        /**
         * @return the address of the next dnode
         */
        dnode<T>* next() const {return next_field;}

    private:
        T data_field;          // the value stored by the dnode
        dnode<T>* prev_field;  // the pointer to the previous dnode
        dnode<T>* next_field;  // the pointer to the next dnode
};

#endif