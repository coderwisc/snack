#include <SFML/Graphics.hpp>


class Fruit : public sf::CircleShape
{

public:
	Fruit();
	~Fruit();
	void setposition();
};