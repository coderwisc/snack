#include "fruit.h"
#include <time.h>
#include "constant.h"
#include "snack.h"

extern Snack snack;

Fruit::Fruit()
{
	this->setRadius(RADIUS);
	this->setPosition(250,250);
	this->setFillColor(sf::Color(241,98,87));
	this->setOrigin(RADIUS,RADIUS);
}

Fruit::~Fruit()    
{

}
void Fruit::setposition()
{
	float x,y,flag=0;
	int i;
	int a=WIDTH/20,b=HEIGHT/20;
	do
	{
		i=0;
		srand(time(0));
	    x=20*(rand()%a)+X+10;
		y=20*(rand()%b)+Y+10;
		
	}
	while(!snack.compare(sf::Vector2f(x,y))||i==1);

        this->setPosition(x,y);
}
