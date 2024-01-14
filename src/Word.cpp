#include "Word.h"

bool Word::test(const Guess &guess) const {
    bool ok = true;
    for (int i = 0; ok && i < sizeof(Wordstr); ++i) {
        // first check that greens align and yellows do not align
        switch (guess.colors.b[i]) {
        case 'Y':
            if (m_word.b[i] == guess.letters.b[i]) {
                ok = false;
            }
            else {
                bool got_yellow = false;
                // to be ok the guessed yellow square must be present in m_word
                // and it cannot be on a square that is green in the guessed square
                for (int j = 0; got_yellow == false && j < sizeof(Wordstr); ++j) {
                    if (i != j && m_word.b[j] == guess.letters.b[i] && guess.colors.b[j] != 'G') {
                        got_yellow = true;
                    }
                }
                if (got_yellow == false) {
                    ok = false;
                }
            }
            break;
        case 'G':
            if (m_word.b[i] != guess.letters.b[i]) {
                ok = false;
            }
            break;
        case 'B':
            for (int j = 0; ok && j < sizeof(Wordstr); ++j) {
                if (m_word.b[j] == guess.letters.b[i]) {
                    ok = false;
                }
            }
            break;
        default:
            throw ("Invalid color");
            break;
        }
    }
    return ok;
}


