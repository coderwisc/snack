#ifndef BODY_H
#define BODY_H
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "constant.h"

class BODY:public sf::CircleShape
{
    int pos; 
public:
	BODY()
	{
		pos=0;
		this->setRadius(RADIUS);
		this->setFillColor(sf::Color(32,96,79));
		this->setOrigin(RADIUS,RADIUS);
		this->setPointCount(4);
	}
	void setpos(int i)
	{
		pos=i;
	}
	~BODY()
	{
	
	}
};

#endif