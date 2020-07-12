// FILE: sequence2.h
// CLASS PROVIDED: sequence (a container class for a sequence of items,
// where each sequence may have a designated item called the current item)
//
// TYPEDEF for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and a copy constructor.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_t size( ) const
//     Postcondition: The return value is the number of items on the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the sequence:
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler: The constructors, insert, attach, and the
//   assignment operator.

#ifndef ASSIGNMENT_SEQUENCE2_H
#define ASSIGNMENT_SEQUENCE2_H
#include <cassert> // Provides assert()
#include <cstdlib> // Provides NULL and size_t
#include "node2.h" // Provides linked list toolkit

namespace assignment_sequence2 {
    class sequence {
    public:
        // TYPEDEF
        typedef size_t size_type;
        typedef node::value_type value_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence(); 
        sequence(const sequence& source); /* O(n): Copies by value */
        ~sequence(); /* O(n): Deletes each item individually */
        // MODIFICATION MEMBER FUNCTIONS
        void start(); /* O(1): Puts cursor at the start of the sequence */
        void advance(); /* O(1): Advance cursor by one item */
        void insert(const value_type& entry); /* O(1): Places at item before the cursor */
        void attach(const value_type& entry); /* O(1): Places at item after the cursor */
        void remove_current(); /* O(1): Removes the current item */
        void operator =(const sequence& source); /* O(n): Copies by value */
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const {return many_nodes;}
        bool is_item() const {return cursor != NULL;}
        value_type current() const {return cursor->data();}
    private:
        node *head;            /* First item of the sequence */
        node *tail;            /* Last item of the sequence */
        node *cursor;          /* Current item of the sequence */
        node *precursor;       /* Item prior the current item */
        size_type many_nodes;  /* Total number of nodes */
    };
}

#endif
