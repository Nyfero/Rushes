#ifndef SPACE_HPP
# define SPACE_HPP

# include "IEntity.hpp"
# include "Game.hpp"
# include "Bullet.hpp"
# include "Star.hpp"
# include "Player.hpp"
# include <vector>

template <typename T>
class Space
{
	private:
		std::vector<T>	lst;
		Game			*game;

	public:
		//Constructors
		Space(Game * gameptr) : lst() { game = gameptr; };
		~Space() {};
		
		//Functions
		void	update(Player & player, Player * player2) {
			for (size_t i = 0; i < lst.size(); i++) {
				if (!std::is_same<T, Star>::value && (
				(player.getPos() == lst.at(i).getPos() || player.getPos() == lst.at(i).getPos() + lst.at(i).getVeloc()) ||
				(player2 != NULL && (player2->getPos() == lst.at(i).getPos() || player2->getPos() == lst.at(i).getPos()+lst.at(i).getVeloc()))))
				{
					player.update();
					lst.erase(lst.begin() + i);
				}
				else if (lst.at(i).getPos().y > game->getHeight() + 1 || lst.at(i).getPos().y < 0 || lst.at(i).getPos().x <= 0 )
					lst.erase(lst.begin() + i);
				else
					lst.at(i).update();
			}
		};
		
		void	create() {
			T entity(game);
			lst.push_back(entity);
		};
		
		void	remove(size_t index) {
			lst.at(index).clear();
			lst.erase(lst.begin() + index);
		};

		std::vector<T> getData() const { return lst; };
};

template <>
class Space<Bullet>
{
	private:
		std::vector<Bullet>	lst;
		Game			*game;

	public:
		//Constructors
		Space(Game * gameptr) : lst(), game(gameptr) { }
		~Space() {};
		
		//Functions
		void	update(Source source) {
			for (size_t i = 0; i < lst.size(); i++) {
				if (lst.at(i).getPos().x > game->getWidth() || lst.at(i).getPos().x < 0 )
					lst.erase(lst.begin() + i);
				else if (lst.at(i).getSource() == source)
					lst.at(i).update();
			}
		};

		void	create(Source source, vec2i velocity, vec2i pos) {
			Bullet entity(game, source, velocity, pos);
			lst.push_back(entity);
		};

		void	remove(size_t index) {
			lst.at(index).clear();
			lst.erase(lst.begin() + index);
		};


		std::vector<Bullet> & getData() { return lst; };
};

#endif
