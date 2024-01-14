#ifndef __WORD_LIST_H_INCL__
#define __WORD_LIST_H_INCL__
#include <vector>
#include "Word.h"

/**
 * class to hold vector of words that match the colors of the 
 * guesses 
 * 
 * @author   sayre
 */
class Word_list {
public:
    // Constructor
    Word_list();

    // Destructor
    virtual ~Word_list();

    // Copy constructor
    // TODO: Uncomment the copy constructor when you need it.
    //Word_list(const Word_list& src);

    // Assignment operator
    // TODO: Uncomment the assignment operator when you need it.
    //Word_list& operator=(const Word_list& src);

private:
};

// Constructor implementation
inline Word_list::Word_list() {
}

// Destructor implementation
inline Word_list::~Word_list() {
}

// TODO: Uncomment the copy constructor when you need it.
//inline Word_list::Word_list(const Word_list& src)
//{
//   // TODO: copy
//}

// TODO: Uncomment the assignment operator when you need it.
//inline Word_list& Word_list::operator=(const Word_list& rhs)
//{
//   if (this == &rhs) {
//      return *this;
//   }
//
//   // TODO: assignment
//
//   return *this;
//}

#endif // __WORD_LIST_H_INCL__
