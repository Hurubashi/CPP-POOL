
#include "GameClass.hpp"
#include "AsteroidClass.hpp"

const time_t Game::startTime = time(0);

Game::Game(void) {
	this->setColors();
	this->_lvl = 1;
	this->_musicTime = 0;
	this->_score = 0;
}

Game::~Game() {}

Game::Game(const Game &other) {
	*this = other;
}

Game& Game::operator= (const Game &rhs) {
	this->_gameWindow = rhs._gameWindow;
	this->_gameMenu = rhs._gameMenu;
	this->_players = rhs._players;
	this->_objs = rhs._objs;
	this->_lvl = rhs._lvl;
	this->_musicTime = rhs._score;
	this->_score = rhs._score;
	this->_numOfPlayers = rhs._numStartPlayers;
	this->_numStartPlayers = rhs._numStartPlayers;
	return *this;
}

void Game::checkWinwodSize() {
	if (COLS < MAP_WIDTH + 20 || LINES < MAP_HEIGHT + 5)
	{
		endwin();
		std::cout << "\033[1;32mToo small window\033[0m" << std::endl;
		exit(0);
	}
}

void Game::viewGameplay() {
	refresh();
	this->_gameWindow = newwin(MAP_HEIGHT, MAP_WIDTH - MENU_WIDTH,
							   (LINES - MAP_HEIGHT) / 2, (COLS - MAP_WIDTH + MENU_WIDTH) / 2);
	wattron(this->_gameWindow, COLOR_PAIR(4));
	box(this->_gameWindow, 0, 0);
	wrefresh(this->_gameWindow);
}

void Game::viewMenuText() {
	refresh();

	static time_t		t;
	static struct tm	*local_time;

	t = time(0);
	t -= this->startTime;
	local_time = localtime(&t);

	if (((local_time->tm_sec + local_time->tm_min * 60) / 11 + 1) > this->_musicTime){
		this->_musicTime = (local_time->tm_sec + local_time->tm_min * 60) / 11 + 1;
		system("afplay ./sounds/music.mp3&");
	}
	if (((local_time->tm_sec + local_time->tm_min * 60) / 15 + 1) > this->_lvl)
		system("afplay ./sounds/lvlup.wav&");
	if (local_time->tm_sec) { this->_lvl = (local_time->tm_sec + local_time->tm_min * 60) / 15 + 1; }
	this->_score = this->_score + _lvl;
	attron(COLOR_PAIR(this->_players[0]->getPlayerNb()));
	mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 6) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s%d%s %d%s", "PLAYER ", this->_players[0]->getPlayerNb(), " HP: ", this->_players[0]->getHp(), " ");
	if (this->_numOfPlayers > 1) {
		attron(COLOR_PAIR(this->_players[1]->getPlayerNb()));
		mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 10) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s%d%s %d%s", "PLAYER ", this->_players[1]->getPlayerNb(), " HP: ", this->_players[1]->getHp(), " ");
	}
	else if(this->_numOfPlayers < this->_numStartPlayers) {
		attron(COLOR_PAIR(3));
		mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 10) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s ", "PLAYER DEAD        ");
	}
	attron(COLOR_PAIR(4));
	mvprintw((LINES - MAP_HEIGHT + INDENT_TOP) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s %d", "Level : ", this->_lvl);
	mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 20) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s %d", "SCORE : ", this->_score);
	mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 25) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s", "TIME :      ");
	mvprintw((LINES - MAP_HEIGHT + INDENT_TOP + 25) / 2, (COLS - MAP_WIDTH - INDENT_LEFT) / 2, "%s %d %d", "TIME   : ",
			 local_time->tm_min, local_time->tm_sec);
	wrefresh(this->_gameWindow);
}

void Game::viewGameOver() {
	system("afplay ./sounds/gameover.wav&");
	wattron(this->_gameWindow, COLOR_PAIR(3));
	for (int j = 10; j < 15; ++j){
		for (int i = 30; i < 80; i += 10)
		{
			mvwaddstr(this->_gameWindow, j, i, "GAME OVER");
			delay_output(10);
			wrefresh(this->_gameWindow);
		}
	}
}

void Game::viewMenu() {
	refresh();
	this->_gameMenu = newwin(MAP_HEIGHT, MENU_WIDTH - 1, (LINES - MAP_HEIGHT) / 2, (COLS - MAP_WIDTH - MENU_WIDTH + 1) / 2);
	wattron(this->_gameMenu, COLOR_PAIR(4));
	box(this->_gameMenu, 0, 0);
	wrefresh(this->_gameMenu);
}

void Game::viewGame() {
	initscr();
	curs_set(0);
	nodelay(stdscr, true);
	noecho();
	start_color();
	this->setColors();
	keypad(stdscr, TRUE);
	this->viewGameplay();
	this->viewMenu();
	checkWinwodSize();
}

void	Game::setColors() {
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_WHITE , COLOR_BLACK);
	init_pair(6, COLOR_BLACK , COLOR_WHITE);
}

void Game::wait(unsigned time) {
	static time_t time1 = clock();

	time_t cur = clock();
	while (cur - time1 < time)
		cur = clock();
	time1 = cur;
}

void Game::getchKeys(int ch) {
	if (ch == 27){
		endwin();
		system("killall afplay");
		exit(1);
	}
}

void Game::randomAsteroids(int i) {
	int k = 0; 

	while (k++ < this->_lvl * 3)
		this->_objs.pushBack(new Asteroid(MAP_WIDTH - MENU_WIDTH - 2, ((rand() + i) % 25 + 2), 'L', 5));
}

void Game::randomEnemy(int i) {
	int k = 0; 

	while (k++ < this->_lvl * 3)
		this->_objs.pushBack(new Enemy(MAP_WIDTH - MENU_WIDTH - 2, ((rand() + i) % 25 + 2), 3, 3));
}

void Game::oneOrTwo() {
	refresh();
	mvwaddstr(this->_gameWindow, 9, 42, "      STAW WARS");
	mvwaddstr(this->_gameWindow, 10, 43, "LEFT FOR SOLO GAME");
	mvwaddstr(this->_gameWindow, 11, 40, "OR RIGHT FOR MULTIPLAYER");
	wrefresh(this->_gameWindow);
	int				ch;
	while (1){
		ch = getch();
		if (ch == KEY_LEFT) {
			this->_numOfPlayers = 1;
			this->_numStartPlayers = 1;
			break;
		}
		else if (ch == KEY_RIGHT) {
			this->_numOfPlayers = 2;
			this->_numStartPlayers = 2;
			break;
		}
	}
	mvwaddstr(this->_gameWindow, 9, 40, "                   ");
	mvwaddstr(this->_gameWindow, 10, 40, "                        ");
	mvwaddstr(this->_gameWindow, 11, 40, "                        ");
	this->_players = new Player *[this->_numOfPlayers];
	this->_players[0] = new Player(KEY_UP,KEY_RIGHT, KEY_LEFT, KEY_DOWN, 32, 5, MAP_HEIGHT/2, 1, 1, 1);
	if (this->_numOfPlayers > 1)
		this->_players[1] = new Player('w', 'd', 'a', 's', 32, 5, this->_players[0]->getY() + 3, 2, 2, 2);
}

void Game::gameLoop() {
	int				ch;
	unsigned int	i = 0;

	srand(time(0));
	this->viewGame();
	this->oneOrTwo();
	while (1)
	{
		this->viewMenuText();
		this->_objs.moveAllStatic(this->_gameWindow, this->_players, &this->_numOfPlayers);
		if (i % 5 == 0)
			this->_objs.someAI(this->_gameWindow, this->_players, &this->_numOfPlayers);
		ch = getch();
		getchKeys(ch);
		for (int j = 0; j < this->_numOfPlayers; j++) {
			if (this->_players[j] && this->_players[j]->KeyEvent(ch) == 2) {
				this->_objs.pushBack(this->_players[j]->shot());
			}
		}
		/*													*/
		if (i % 100 == 0)
			randomAsteroids(i);
		if (i % 50 == 0)
			randomEnemy(i);
		this->_objs.drawAll(this->_gameWindow);
		/*													*/
		for (int j = 0; j < this->_numOfPlayers; j++) {
			if (this->_players[j]) {
				this->_players[j]->draw(this->_gameWindow);
			}
		}
		if (this->_numOfPlayers == 0)
		{
			this->_objs.clearAll(this->_gameWindow);
			this->viewGameOver();
			while(1) {
				ch = getch();
				getchKeys(ch);
			}
		}
		wait(15000);
		i++;
	}
}



