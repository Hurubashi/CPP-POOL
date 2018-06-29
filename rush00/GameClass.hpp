
#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "MainHeader.hpp"
#include "PlayerClass.hpp"
#include "ControlListClass.hpp"

class Game {

public:
	Game();
	~Game();
	Game(const Game & other);
	Game& operator=(const Game &rhs);

	void		setColors();
	void		viewGameplay();
	void		viewMenu();
	void		viewMenuText();
	void		viewGame();
	void		checkWinwodSize();
	void		wait(unsigned);
	void		gameLoop();
	static const time_t startTime;
	void		getchKeys(int ch);
	void		randomAsteroids(int i);
	void		viewGameOver();
	void		oneOrTwo();
	void		randomEnemy(int i);

private:
	WINDOW				*_gameWindow;
	WINDOW				*_gameMenu;
	Player				**_players;
	ControlListClass	_objs;
	int					_lvl;
	int					_musicTime;
	int					_score;
	int					_numOfPlayers;
	int					_numStartPlayers;
};


#endif
