// Hangman with OOP part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "Word.h"

using namespace std;

enum ACTIONTYPE {
	PLAY_GAME,
	EXIT_GAME,
	HINT_SETTING,
	FAIL_SETTING,
	WORD_SETTING,
	ADD_WORD,
	RESET_WORD_BANK,
};
int main() {

	Menu* mainMenu = new Menu("Main menu", "The game main menu");
	Menu* settingMenu = new Menu("Settings", "The game settings menu");
	Menu* wordBankMenu = new Menu("Word Bank", "The game word bank menu");
	Menu* playMenu = new Menu("Play", "Game Over", PLAY_GAME);
	Menu* exitMenu = new Menu("Exit", "Quit playing the game", EXIT_GAME);
	Menu* setHint = new Menu("Hint setting", "Set maximum hints allowed", HINT_SETTING);
	Menu* setFail = new Menu("Fail setting", "Set maximum failures allowed", FAIL_SETTING);
	Menu* setWord = new Menu("Word setting", "Set maximum words in a game", WORD_SETTING);
	Menu* addWord = new Menu("Add new word", "Add a word to word bank", ADD_WORD);
	Menu* resetWordBank = new Menu("Reset", "Reset word bank", RESET_WORD_BANK);
	mainMenu->addSubMenu(settingMenu);
	settingMenu->addSubMenu(wordBankMenu);
	mainMenu->addSubMenu(playMenu);
	mainMenu->addSubMenu(exitMenu);
	settingMenu->addSubMenu(setHint);
	settingMenu->addSubMenu(setFail);
	settingMenu->addSubMenu(setWord);
	wordBankMenu->addSubMenu(addWord);
	wordBankMenu->addSubMenu(resetWordBank);
	Game* currentGame = new Game();
	Menu* currentMenu = mainMenu;


	while (true) {
		currentMenu->displayMenu();
		int opt = currentMenu->pickOption();
		currentMenu = currentMenu->getSubMenu(opt - 1);
		switch (currentMenu->getAction()) {
		case -1:
			break;
		case PLAY_GAME:
			currentGame->start();
			break;
		case EXIT_GAME:
			exit(0);
		case HINT_SETTING:
			currentGame->menuSetHint();
			break;
		case FAIL_SETTING:
			currentGame->menuSetFail();
			break;
		case WORD_SETTING:
			currentGame->menuSetWord();
			break;
		case ADD_WORD:
			currentGame->menuAddWord();
			break;
		case RESET_WORD_BANK:
			currentGame->reset();
			break;
		}
	}
	return 0;
}