#ifndef __WORDLE_H_INCL__
#define __WORDLE_H_INCL__
#include <vector>
#include <map>
#include <initializer_list>
#include <iostream>
#include <fstream>
#include <set>
#include "Word.h"

/**
 * TODO: Add class description
 * 
 * @author   sayre
 */
class Wordle {
public:
    // Constructor
    Wordle();

    // Destructor
    virtual ~Wordle();

    static vector<Wordstr> full_word_list;
    static vector<Wordstr> valid_wordle_guesses;
    static vector<Wordstr> valid_wordle_answers;

    void run();

protected:
    void process_menu_item_1();      
    void process_menu_item_2() const;
    void process_menu_item_3();
    void score_guesses(int menu_item, string letters);
    void rebuild_char_freq_map();
    void printmenu() const;

    // Copy constructor
    // TODO: Uncomment the copy constructor when you need it.
    //Wordle(const Wordle& src);

    // Assignment operator
    // TODO: Uncomment the assignment operator when you need it.
    //Wordle& operator=(const Wordle& src);
private:
    set<Wordstr> words_so_far;
    vector<Guess> m_guesses;
    vector<vector<Wordstr>> m_possibilities;
    map<char, int> m_freq;
    set<char> m_letters_in_solution;
    set<char> m_letters_already_guessed;
};

// Constructor implementation
inline Wordle::Wordle() {
}

// Destructor implementation
inline Wordle::~Wordle() {
}

// TODO: Uncomment the copy constructor when you need it.
//inline Wordle::Wordle(const Wordle& src)
//{
//   // TODO: copy
//}

// TODO: Uncomment the assignment operator when you need it.
//inline Wordle& Wordle::operator=(const Wordle& rhs)
//{
//   if (this == &rhs) {
//      return *this;
//   }
//
//   // TODO: assignment
//
//   return *this;
//}

#endif // __WORDLE_H_INCL__
