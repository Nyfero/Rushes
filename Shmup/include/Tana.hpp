#ifndef TANA_HPP
# define TANA_HPP

# include "IEntity.hpp"
# include "Game.hpp"

class Tana: public IEntity
{
	private:
		vec2i	pos;
		Game 	*game;
	
	public:
		//Constructors
		Tana(Game *gameptr);
		~Tana();
		
		//Functions
		vec2i	getVeloc();
		void	update();
		void	print();
		void	clear();
		vec2i	getPos() const;
};

#endif
