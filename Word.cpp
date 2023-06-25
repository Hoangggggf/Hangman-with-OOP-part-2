#include "Word.h"

Word::Word()
{
	text = "";
	hint = "";
}

Word::Word(string t, string h)
{
	this->hint = h;
	this->setText(t);
}

Word::~Word()
{
}

string Word::getText()
{
	return this->text;
}

void Word::setText(string t)
{
	this->text = t;
	this->displayText = t;
	for (int i = 0; i < t.size(); i++) 
	{
		this->displayText[i] = '_';
	}
}

string Word::getHint()
{
	return this->hint;
}

void Word::setHint(string h)
{
	this->hint = h;
}

void Word::displayWord()
{
	cout << this->displayText << endl;
}

int Word::checkGuess(char guessChar)
{
	int occurence = 0;
	for (int i = 0; i < text.size(); i++) {
		if (guessChar == text[i]) {
			this->displayText[i] = guessChar;
 			occurence++;
		}
	}
	return occurence;
}

void Word::displayHint()
{
	cout << this->hint << endl;
}

void Word::reset()
{
	// reset display text to empty spaces
	for (int i = 0; i < text.size(); i++) {
		this->displayText[i] = '_';
	}
}

bool Word::checkCorrect()
{
	if (text == displayText)
	{
		return true;
	}
	return false;
}

