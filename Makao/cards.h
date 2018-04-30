#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

struct cardStruct {
	char val;
	char col;
	std::string img;
};

class Card {

protected:
	std::vector<cardStruct> CardSet;
private:
	void setCreate() {
		char cardVals[12] = { '2', '3', '4', '5', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };
		char cardCols[4] = { 'C', 'D', 'H', 'S' };
		for (char v : cardVals) {
			for (char c : cardCols) {
				cardStruct currentOne;
				currentOne.col = c;
				currentOne.val = v;
				currentOne.img = "Img/cardsPack/";
				currentOne.img += v;
				currentOne.img += c;
				currentOne.img += ".jpg";
				CardSet.push_back(currentOne);
			}
		}
	}

	void Randomize() {
		srand(time(NULL));
		std::vector<cardStruct*> randomized;
		int n = 48;
		while (n > 0) {
			int r = rand() % 48;
			cardStruct* random = &CardSet[r];
			for (int n = 0; n < randomized.size(); n++) {
				if (randomized.at(n) == random) {
					int r = rand() % 48;
					random = &CardSet[r];
					n = 0;
				}
			}
			randomized.push_back(random);
			n--;
		}
		std::vector<cardStruct> Sorted;
		for (auto n : randomized) Sorted.push_back(*n);
		CardSet = Sorted;
	}
public:
	Card() {
		setCreate();
		Randomize();
	}

	void PrintSet() {
		for (auto n : CardSet) {
			std::cout << n.img << "\n";
		}
		std::cout << "Ilosc elementow: " << CardSet.size() << "\n";
	}
	
	std::string PrintAt(int n) {
		return CardSet[n].img;
	}

};


class gamerSets : public Card {
private:
	std::vector <cardStruct> userSet;
	std::vector <cardStruct> botSet;
	std::vector <cardStruct> stockSet;

public:
	gamerSets() {
		for (int n = 0; n < 5; n++) {
			userSet.push_back(CardSet.front());
			CardSet.erase(CardSet.begin());
			botSet.push_back(CardSet.front());
			CardSet.erase(CardSet.begin());
		}
		stockSet.push_back(CardSet.front());
		CardSet.erase(CardSet.begin());
	}

	std::vector <cardStruct> returnUser() { return userSet; };
	std::vector <cardStruct> returnBot() { return botSet; };
	std::vector <cardStruct> returnStock() { return stockSet; };
};