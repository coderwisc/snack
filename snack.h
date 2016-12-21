#ifndef SNACK_H
#define SNACK_H
#include <vector>
#include "body.h"
using namespace std;
class Snack
{
public:
	sf::CircleShape head;
	std::vector<BODY> body;
	int count;
public:
	Snack();
	~Snack();
	bool Touchself();
	bool Touchethewall();
	void draw(sf::RenderWindow &);
	void move();
	void lengthing();
	void Turnup();
	void Turndown();
	void Turnleft();
	void Turnright();
	bool eat(sf::Vector2f);
	bool compare(sf::Vector2f);
	void shrotening();
	void reset();

};
#endif

