#include "Glaive.hpp"
#include "Game.hpp"
#include "Color.hpp"

//					//
//	Constructors	//
//					//

Glaive::Glaive(Game *gameptr) { //Initialise le boss
	game = gameptr;
	pos.x = 80;
	pos.y = game->getHeight() / 2;
	life = 20;
	int i = rand() % 2;
	if (i == 0)
		velocity = -1;
	else
	 	velocity = 1;
}

Glaive::~Glaive() {}

//				//
//	Functions	//
//				//

void	Glaive::print() {
	Color	bossLife = Color::Green;
	
	if (life < 14 && life > 7)
		bossLife = Color::Orange;
	else if (life <= 7)
		bossLife = Color::Red;
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 3, '<' | COLOR_PAIR(Color::Yellow) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 2, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 1, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 2, pos.x - 1, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 2, pos.x, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 1, pos.x + 2, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 1, pos.x + 1, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y - 1, pos.x, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x - 1, '(' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x, 'X' | COLOR_PAIR(bossLife) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x + 2, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x + 3, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x + 4, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x + 5, '~' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y, pos.x + 6, '~' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 1, pos.x, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 1, pos.x + 1, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 1, pos.x + 2, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 2, pos.x, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 2, pos.x - 1, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 1,'&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 2, '&' | COLOR_PAIR(Color::Blue) | A_BOLD);
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 3, '<' | COLOR_PAIR(Color::Yellow) | A_BOLD);
}

void	Glaive::clear() {
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 3, ' ');
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 2, ' ');
	mvwaddch(game->getWin(), pos.y - 3, pos.x - 1, ' ');
	mvwaddch(game->getWin(), pos.y - 2, pos.x - 1, ' ');
	mvwaddch(game->getWin(), pos.y - 2, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y - 1, pos.x + 2, ' ');
	mvwaddch(game->getWin(), pos.y - 1, pos.x + 1, ' ');
	mvwaddch(game->getWin(), pos.y - 1, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x - 1, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x + 2, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x + 3, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x + 4, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x + 5, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x + 6, ' ');
	mvwaddch(game->getWin(), pos.y + 1, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y + 1, pos.x + 1, ' ');
	mvwaddch(game->getWin(), pos.y + 1, pos.x + 2, ' ');
	mvwaddch(game->getWin(), pos.y + 2, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y + 2, pos.x - 1, ' ');
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 1,' ');
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 2, ' ');
	mvwaddch(game->getWin(), pos.y + 3, pos.x - 3, ' ');
}

void	Glaive::update() {
	if (pos.x > 70)
		pos.x--;
	else
	{
		if ((pos.y - 3) + velocity < 0 || (pos.y + 3) + velocity > game->getHeight() + 1)
			velocity *= -1;
		pos.y += velocity;
	}
}

vec2i	Glaive::getPos() const {
	return (pos);
}

int		Glaive::getLife() const {
	return (life);
}

vec2i	Glaive::getUpWeapon() const {
	vec2i	tmp;
	
	tmp.x = pos.x - 4;
	tmp.y = pos.y - 3;
	return (tmp);
}

vec2i	Glaive::getDownWeapon() const {
	vec2i	tmp;
	
	tmp.x = pos.x - 4;
	tmp.y = pos.y + 3;
	return (tmp);
}

void	Glaive::hit() {
	life--;
}

void	Glaive::heal() {
	life = 20;
}
