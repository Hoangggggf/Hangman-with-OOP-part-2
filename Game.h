#pragma once
#include <iostream>
#include <vector>
#include "Word.h"
#include "Menu.h"
using namespace std;
class Game
{
private:
	int hintLimit, failLimit, wordLimit;
	int hintCount, failCount, wordCount;
	vector<Word> wordBank;
	Word currentWord;
	Menu* SetHintMenu;
	Menu* SetFailMenu;
	Menu* AddWordMenu;
public:
	Game();
	~Game();
	int getHint();
	void setHint(int h);
	void menuSetHint();
	void menuSetFail();
	void menuAddWord();
	void menuSetWord();
	int getFail(); //return the fail limit
	void setFail(int f); //set fail limit
	int getWord(); //Get word limit
	void setWord(int w); //Set word limit
	void start();
	bool makeAGuest(char n, Word& w); //return false if no character is correct
	void reset(); //reset word bank
};

