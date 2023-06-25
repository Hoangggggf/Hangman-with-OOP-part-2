#include "Game.h"

Game::Game()
{
	hintLimit = failLimit = wordLimit = 0;
	hintCount = failCount = wordCount = 0;
	wordBank.clear();
}

Game::~Game()
{
	wordBank.clear();
}

int Game::getHint()
{
	return hintLimit;
}

void Game::setHint(int h)
{
	this->hintLimit = h;
}

void Game::menuSetHint()
{
	system("cls");
	while (true) {
		cout << "Set number of hints allowed:";
		int h;
		cin >> h;
		try {
			if (cin.fail()) {
				throw "Invalid Input";
			}
			else {
				this->hintLimit = h;
				cout << "Set hint successful!" << endl;
				return;
			}
		}
		catch (const char* err) {
			cin.clear();
			cin.ignore();
			cout << "Error: " << err << endl;
		}
	}
}
void Game::menuSetFail()
{
	while (true)
	{
		int temp;
		cout << "Enter max fail: ";
		cin >> temp;
		try
		{
			if (cin.fail())
			{
				throw "Invalid input";
			}
			else
			{
				this->failLimit = temp;
				system("cls");
				return;
			}
		}
		catch (const char* err)
		{
			cin.clear();
			cin.ignore();
			cout << "Error: " << err << endl;
		}
	}
}
void Game::menuAddWord()
{
	system("cls");
	if (wordLimit == wordCount)
	{
		cout << "Word bank is full\n";
		system("pause");
		return;
	}
	string W;
	cout << "Enter word: ";
	cin >> W;
	string H;
	cout << endl << "Enter hint:" << endl;
	cin.ignore();
	getline(cin, H);
	Word aWord(W, H);
	wordBank.push_back(aWord);
	wordCount++;
}
void Game::menuSetWord()
{
	system("cls");
	int temp = 0;
	cout << "Enter word limit: ";
	cin >> temp;
	this->setWord(temp);
}
int Game::getFail()
{
	return failLimit;
}
void Game::setFail(int f)
{
	failLimit = f;
}
int Game::getWord()
{
	return wordLimit;
}
void Game::setWord(int w)
{
	this->wordLimit = w;
}
void Game::start()
{
	system("cls");
	if (wordCount >= 1)
	{
		cout << "Game started!" << endl;
		cout << "There will be " << wordCount << " words in this game" << endl;
		cout << "Fail limit is: " << failLimit << endl;
		system("pause");
		system("cls");
		for (int i = 0; i < wordCount; i++)
		{
			currentWord = wordBank[i];
			failCount = 0;
			cout << endl << "Word number " << i + 1 << ": " << endl;
			currentWord.displayWord();
			cout << endl;
			cout << "Hint of this word is: ";
			currentWord.displayHint();
			while (true)
			{
				cout << endl;
				char temp;
				cout << "Guest a character: ";
				cin >> temp;
				if (makeAGuest(temp, currentWord) == true)
					{
						cout << "Correct character!" << endl;
						cout << "Progress: ";
						currentWord.displayWord();
						system("pause");
					}
				else
					{
						cout << "Incorect\n";
						failCount++;
					}
				if (failCount == failLimit)
				{
						cout << "You failed!" << endl;
						system("pause");
						return;
				}
				if (currentWord.checkCorrect())
				{
					cout << "Word " << i+1<<  " passed! \n";
					system("pause");
					system("cls");
					false;
					break;
				}
			}
		}
	}
	else
	{
		cout << "Word bank is empty\n";
	}
}
bool Game::makeAGuest(char n, Word& w)
{
	if (w.checkGuess(n) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Game::reset()
{
	if (wordCount != 0)
	{
		for (int i = 0; i < wordCount; i++)
		{
			wordBank[i].reset();
		}
		wordBank.clear();
	}
	wordCount = 0;
}