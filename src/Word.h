#ifndef __WORD_H_INCL__
#define __WORD_H_INCL__

using namespace std;
#include <string>
#include <iostream>

/**
 * One five-letter word in the Wordle game
 * 
 * @author   sayre
 */

struct Wordstr {
    char b[5];
    Wordstr() { }
    Wordstr(const char s[]) {
        for (int i = 0; i < 5; ++i) {
            b[i] = std::tolower(s[i]);
        }
    }
    Wordstr(string s) {
        for (int i = 0; i < 5 && i < s.length(); ++i) {
            b[i] = std::tolower(s.data()[i]);
        }
    }

    void print() const {
        cout << b[0] << b[1] << b[2] << b[3] << b[4] << "   " << flush;
    }

    int count(char c) const {
        int c_count = 0;
        for (int i = 0; i < sizeof(b); ++i) {
            if (c == b[i]) {
                ++c_count;
            }
        }
        return c_count;
    }

    bool operator <(const Wordstr &rhs) const {
        for (int i = 0; i < sizeof(b); ++i) {
            if (b[i] < rhs.b[i]) {
                return true;
            } else if (b[i] > rhs.b[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator ==(const Wordstr &rhs) const {
        for (int i = 0; i < sizeof(b); ++i) {
            if (b[i] != rhs.b[i]) {
                return false;
            }
        }
        return true;
    }

};

struct Guess {
    Wordstr letters;
    Wordstr colors;
    Guess();
    Guess(Wordstr l, Wordstr c) : letters(l), colors(c) {
    }
    Guess(string l, string c) : letters(l), colors(c) {
    }
    void print() const {
        letters.print();
        cout << " ";
        colors.print();
        cout << endl;
    }   
};

class Word {
public:
    // Constructor
    Word();

    Word(const Wordstr new_word) : m_word(new_word) {
    }

    // Destructor
    virtual ~Word();

    // Copy constructor
    // TODO: Uncomment the copy constructor when you need it.
    //Word(const Word& src);

    // Assignment operator
    // TODO: Uncomment the assignment operator when you need it.
    //Word& operator=(const Word& src);
private:
    Wordstr m_word;

public:
    bool test(const Guess &guess) const;
};


// Default Constructor implementation
//inline Word::Word() {
//}

// Destructor implementation
inline Word::~Word() {
}

// TODO: Uncomment the copy constructor when you need it.
//inline Word::Word(const Word& src)
//{
//   // TODO: copy
//}

// TODO: Uncomment the assignment operator when you need it.
//inline Word& Word::operator=(const Word& rhs)
//{
//   if (this == &rhs) {
//      return *this;
//   }
//
//   // TODO: assignment
//
//   return *this;
//}

#endif // __WORD_H_INCL__
