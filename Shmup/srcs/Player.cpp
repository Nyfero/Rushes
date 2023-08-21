#include "Player.hpp"
#include "Color.hpp"
//					//
//	Constructors	//
//					//

int	Player::maxAmmos = 10;
int Player::maxLife  = 3;


Player::Player(Game *gameptr) { //Initialise le joueur
	game = gameptr;
	pos.x = game->getWidth() / 4;	// Place le joueur au centre de la carte
	pos.y = game->getHeight() / 2;
	life = maxLife;
	bullets = Player::maxAmmos;
	color = Color::Blue;
}

Player::Player(Game *gameptr, Color color_) { //Initialise le joueur
	game = gameptr;
	color = color_;
	pos.x = game->getWidth() / 4;	// Place le joueur au centre de la carte
	pos.y = game->getHeight() / 2 + (color == Color::Purple ? 4 : 0);
	life = maxLife;
	bullets = Player::maxAmmos;
}

Player::~Player() {}

//				//
//	Functions	//
//				//

void	Player::move(int dir) {	// Modifie la position du joueur
	if (dir == 0)
		pos.x--;
	else if (dir == 1)
		pos.x++;
	else if (dir == 2)
		pos.y--;
	else
		pos.y++;
}

vec2i	Player::getPos() const {	// Renvoie la position du joueur dans un struct de 2 int
	return (pos);
}

void	Player::disp(int tick) {	// Affiche le joueur
	if ((tick % 15)/3)
		mvwaddch(game->getWin(), pos.y, pos.x - 1, '>' | COLOR_PAIR(tick%2 ? Color::Yellow : Color::Red));
	else
		mvwaddch(game->getWin(), pos.y, pos.x - 1, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x, '>' | COLOR_PAIR(color) | A_BOLD);
}

void 	Player::clear() {	// Supprime l'ancienne position du joueur
	mvwaddch(game->getWin(), pos.y, pos.x, ' ');
	mvwaddch(game->getWin(), pos.y, pos.x - 1, ' ');
}

void	Player::reload() {	// Recharge 1 balle s'il y en a moins de 10
	if (bullets < Player::maxAmmos)
		bullets++;
}

int		Player::shoot() {	// Renvoie 1 s'il y a 1 balle, sinon renvoie 0
	if (bullets > 0)
	{
		bullets--;
		return (1);
	}
	return (0);
}

int		Player::getLife() const {
	return (life);
}

int		Player::getAmmo() const {
	return (bullets);
}

void	Player::update() {
	life--;
}

void	Player::heal() {
	if (life < 3)
		life++;
}

void	Player::print() {}
