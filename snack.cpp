#include "snack.h"
#include<vector>
#include <iostream>
extern sf::Vector2f towards;

 
int x=0;
Snack::Snack()
{
   count=4;
   head.setRadius(RADIUS);
   head.setOrigin(RADIUS,RADIUS);
   head.setFillColor(sf::Color(27,126,62));
   head.setPosition(SX,SY);
   head.setPointCount(10000);
   sf::Texture texture;
   texture.loadFromFile("back.jpg",sf::IntRect(0,0,20,20));
   head.setTextureRect(sf::IntRect(0,0,20,20));
   head.setTexture(&texture);
   head.setOutlineThickness(1);
   head.setOutlineColor(head.getFillColor());
   for(int i=0;i<count;i++)
   {  
	   BODY a;
	   a.setpos(i);
	   a.setPosition(SX+RADIUS*(i+1),SY);
	   body.push_back(a);
   }
  
}

Snack::~Snack(){body.~vector<BODY>();}

bool Snack::Touchself()
{
	sf::Vector2f pos=head.getPosition();
	if(towards==sf::Vector2f(0,-1))
	{   pos.y-=2*RADIUS;
		for(int i=2;i<count-1;i++)
		{
			if(pos==body.at(i).getPosition())
				return true;
		}
		return false;
	}

	else if(towards==sf::Vector2f(0,1))
	{
		pos.y+=2*RADIUS;
		for(int i=2;i<count-1;i++)
		{
			if(pos==body.at(i).getPosition())
				return true;
		}
	}

	else if(towards==sf::Vector2f(-1,0))
	{
		pos.x-=2*RADIUS;
		for(int i=2;i<count-1;i++)
		{
			if(pos==body.at(i).getPosition())
				return true;
		}
	}

	else if(towards==sf::Vector2f(1,0))
	{
		pos.x+=2*RADIUS;
		for(int i=2;i<count-1;i++)
		{
			if(pos==body.at(i).getPosition())
				return true;
		}
	}
		return false;
}

bool Snack::Touchethewall()
{
	sf::Vector2f pos=head.getPosition();

	if(towards==sf::Vector2f(0,-1))
		if(pos.y-RADIUS<=Y)
			return true;

	if(towards==sf::Vector2f(0,1))
		if(pos.y+RADIUS>=Y+HEIGHT)
			return true;

	if(towards==sf::Vector2f(1,0))
		if(pos.x+RADIUS>=X+WIDTH)
			return true;

	if(towards==sf::Vector2f(-1,0))
		if(pos.x-RADIUS<=X)
			return true;

	return false;
}

void Snack::draw(sf::RenderWindow &window)
{
	window.draw(head);
	for(int i=0;i<count;i++)
		window.draw(this->body.at(i));
}
 
void Snack::move()
{   
	sf::Vector2f move=head.getPosition();

	if(towards==sf::Vector2f(0,1))
	head.setPosition(move.x,move.y+RADIUS);

	else if(towards==sf::Vector2f(0,-1))
	head.setPosition(move.x,move.y-RADIUS);

	else if(towards==sf::Vector2f(1,0))
	head.setPosition(move.x+RADIUS,move.y);

	else if(towards==sf::Vector2f(-1,0))
	head.setPosition(move.x-RADIUS,move.y);

	if(towards!=sf::Vector2f(0,0))
	{
		for(int i=count-1;i>0;i--)
	{
		sf::Vector2f to=body.at(i-1).getPosition();
		body.at(i).setPosition(to);

	}
	body.at(0).setPosition(move);
	}
}

void Snack::Turnup()
{
	if(towards!=sf::Vector2f(0,0)&&towards!=sf::Vector2f(0,1))                              
	{
		sf::Vector2f present=head.getPosition();
	head.setPosition(present.x,present.y-RADIUS);
	for(int i=count-1;i>0;i--)
	{
		sf::Vector2f present2=body.at(i-1).getPosition();
		body.at(i).setPosition(present2);
	}
	body.at(0).setPosition(present);
	towards=sf::Vector2f(0,-1);
	}
}

void Snack::Turndown()
{
	if(towards!=sf::Vector2f(0,-1))
	{
	sf::Vector2f present=head.getPosition();
	head.setPosition(present.x,present.y+RADIUS);
	for(int i=count-1;i>0;i--)
	{
		sf::Vector2f present2=body.at(i-1).getPosition();
		body.at(i).setPosition(present2);
	}
	body.at(0).setPosition(present);
	towards=sf::Vector2f(0,1);
	}
}

void Snack::Turnleft()
{
	if(towards!=sf::Vector2f(1,0))
	{sf::Vector2f present=head.getPosition();
	head.setPosition(present.x-RADIUS,present.y);
	for(int i=count-1;i>0;i--)
	{
		sf::Vector2f present2=body.at(i-1).getPosition();
		body.at(i).setPosition(present2);
	}
	body.at(0).setPosition(present);
	towards=sf::Vector2f(-1,0);
	}
}

void Snack::Turnright()
{
	if(towards!=sf::Vector2f(-1,0))
	{sf::Vector2f present=head.getPosition();
	head.setPosition(present.x+RADIUS,present.y);
	for(int i=count-1;i>0;i--)
	{
		sf::Vector2f present2=body.at(i-1).getPosition();
		body.at(i).setPosition(present2);
	}
	body.at(0).setPosition(present);
	towards=sf::Vector2f(1,0);
	}
}

void Snack::lengthing()
{
	BODY _new;
	count++;
	_new.setPosition(body.at(count-2).getPosition());
	body.push_back(_new);

}

bool Snack::eat(sf::Vector2f pos)
{
	if(head.getPosition()+sf::Vector2f(2*RADIUS,0)==pos&&towards==sf::Vector2f(1,0))
		return true;
	else if(head.getPosition()+sf::Vector2f(-2*RADIUS,0)==pos&&towards==sf::Vector2f(-1,0))
		return true;
	else if(head.getPosition()+sf::Vector2f(0,2*RADIUS)==pos&&towards==sf::Vector2f(0,1))
		return true;
	else if(head.getPosition()+sf::Vector2f(0,-2*RADIUS)==pos&&towards==sf::Vector2f(0,-1))
		return true;
	else if(head.getPosition()==pos)
		return true;
	else 
		return false;
}

bool Snack::compare(sf::Vector2f pos)
{
	if(pos==head.getPosition())
		return false;
	for(int i=0;i<count;i++)
		if(body.at(i).getPosition()==pos)
			return false;
	return true;
}

void Snack::shrotening()
{
	body.pop_back();
	count--;
}

void Snack::reset()
{   
	count=4;
	head.setPosition (SX,SY);
	body.clear();
	 for(int i=0;i<count;i++)
   {  
	   BODY a;
	   a.setpos(i);
	   a.setPosition(SX+RADIUS*(i+1),SY);
	   body.push_back(a);
   }
}
