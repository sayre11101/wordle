#include "Wordle.h"
#include <iomanip>
#include <algorithm>

void Wordle::printmenu() const {
	cout << endl;
	cout << "1) enter guess and colors - e.g. slate bbgyy" << endl;
	cout << "2) print possibilities" << endl;
	cout << "3) print histogram of letters from all possibilities" << endl;
	cout << "4) print words using most unused letters" << endl;
	cout << "5) print words using most of these letters" << endl;
	cout << "6) print words using most unused no green bonus" << endl;
	cout << "0) quit" << endl;
}

void Wordle::process_menu_item_1() {
	string letters;
	string colors;
	vector<Wordstr> new_possibilities;

	cout << endl << "enter guess and colors: " << flush;
	cin >> letters >> colors;
	Guess guess(letters, colors);
	m_guesses.push_back(guess);
	for (int i = 0; i < sizeof(guess.colors); ++i) {
		m_letters_already_guessed.insert(guess.letters.b[i]);
		if (guess.colors.b[i] != 'B') {
			m_letters_in_solution.insert(guess.letters.b[i]);
		}
	}
	vector<Wordstr> &word_list =
			(m_possibilities.size() == 0) ?
					valid_wordle_answers : m_possibilities.back();
	for (auto wordstr : word_list) {
		Word word(wordstr);
		if (word.test(guess)) {
			new_possibilities.push_back(wordstr);
		}
	}
	m_possibilities.push_back(new_possibilities);
}

void Wordle::rebuild_char_freq_map() {
	m_freq.clear();
	for (auto wordstr : m_possibilities.back()) {
		for (int i = 0; i < sizeof(wordstr); ++i) {
			if (m_freq.count(wordstr.b[i]) == 0) {
				m_freq[wordstr.b[i]] = 1;
			} else {
				++m_freq[wordstr.b[i]];
			}
		}
	}
}

void Wordle::process_menu_item_3() {
	Wordle::rebuild_char_freq_map();
	cout << endl;
	int col = 0;
	for (auto x : m_freq) {
		cout << x.first << " " << setw(4) << x.second << "  " << flush;
		if (++col == 6) {
			cout << endl;
			col = 0;
		}
	}
}

void Wordle::process_menu_item_2() const {
	cout << endl;
	int col = 0;
	if (m_possibilities.size() > 0) {
		for (auto word : m_possibilities.back()) {
			// TODO: create operator<< for Wordstr
			word.print();
			if (++col == 8) {
				cout << endl;
				col = 0;
			}
		}
	}
}

void Wordle::score_guesses(int menu_item, string letters) {
	// make a map of all words that use the unused
	Wordle::rebuild_char_freq_map();
	multimap<double, Wordstr> scores;
	for (auto anyWord : Wordle::full_word_list) {
		double score = 0;
		// loop through the possibilities and calculate scores
		// give bonus scores for greens and
		// for letters in the correct position
		for (auto possibleWord : m_possibilities.back()) {
			for (int i = 0; i < sizeof(anyWord); ++i) {
				if (menu_item == 4 || menu_item == 6) {
					// don't give bonus for letters already guessed
					if (m_letters_already_guessed.count(anyWord.b[i]) == 0) {
						// give a bonus for letters that are in the correct position
						int nbr = anyWord.count(anyWord.b[i]);
						if (anyWord.b[i] == possibleWord.b[i]) {
							if (menu_item == 4 && nbr == 1) {
								score += 2.0;
							} else {
								score += 1.0;
							}
						}
						// but give credit for letters that are in a possible word in the wrong position
						else if (possibleWord.count(anyWord.b[i]) > 0) {
							score += 1.0 / static_cast<double>(nbr);
						}
					}
				} else {
					int nbr = std::count(letters.begin(), letters.end(),
							anyWord.b[i]);
					if (nbr > 0) {
						score += 1.0 / static_cast<double>(nbr);
					}
				}

			}
		}
		if (score > 0.0) {
			scores.insert(pair<double, Wordstr>(score, anyWord));
		}

	}
	cout << endl;
	int col = 0;
	int limit = 0;
	for (auto it = scores.rbegin(); it != scores.rend(); it++) {
		it->second.print();
		cout << " " << it->first << endl;
		if (++limit > 20) {
			break;
		}
	}
}

void Wordle::run() {

	// loop until exit
	m_possibilities.push_back(valid_wordle_answers);
	bool running = true;
	while (running) {
		Wordle::printmenu();
		string letters;
		int menu_item;
		cin >> menu_item;

		switch (menu_item) {
		case 0:
			running = false;
			break;
		case 1:
			try {
				process_menu_item_1();
			} catch (string e) {
				cout << endl << e << endl;
			}
			break;
		case 2:
			process_menu_item_2();
			break;
		case 3:
			process_menu_item_3();
			break;
		case 5:
			cout << endl << "enter letters for search: " << flush;
			cin >> letters;
			score_guesses(menu_item, letters);
			break;
		case 4:
		case 6:
			score_guesses(menu_item, string(""));
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}
	}
}

