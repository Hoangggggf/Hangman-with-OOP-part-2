#pragma once
#include <iostream>
#include <string>

using namespace std;

class Word
{
private:
	string text;
	string hint;
	string displayText;
public:
	Word();
	Word(string t, string h);
	~Word();

	string getText();
	void setText(string t);

	string getHint();
	void setHint(string h);

	void displayWord();
	int checkGuess(char guessChar);
	void displayHint();
	void reset();
	bool checkCorrect();//Return true if text == displayText
};

