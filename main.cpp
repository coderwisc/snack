#include <iostream>
#include "snack.h"
#include "fruit.h"
#include<SFML/Audio.hpp>
#include <stdlib.h>
#include <string>
enum PAGE {GAME,GAMEOVER};

using namespace std;
sf::RenderWindow  window(sf::VideoMode(1000,600),"snack");
sf::Vector2f towards=sf::Vector2f(-1,0);
Fruit fruit;
Snack snack;

sf::Clock myclock;
sf::Time time1;
sf::Time time2;


int isplaying=0;
int restart;
sf::Vector2f pause;
int main()
{
	PAGE page=GAME;
	sf::RectangleShape background(sf::Vector2f(WIDTH,HEIGHT));
	background.setPosition(X,Y);
	background.setFillColor(sf::Color(244,126,62));
	sf::Texture texture;texture.loadFromFile("back.jpg");
	sf::Sprite back(texture);
	sf::Font font;font.loadFromFile("comic.TTF");
	sf::Text text;text.setFont(font);text.setString("Score:");text.setCharacterSize(30);
	sf::Text score;score.setFont(font);score.setCharacterSize(30);
	text.setPosition(sf::Vector2f(600,50));
	score.setPosition(sf::Vector2f(750,50));
	char a[3];
  
   sf::Texture page_p;
   page_p.loadFromFile("gameover.jpg");
   sf::Sprite gameover(page_p);

	
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(15);
	int i=0;
	int isplaying=1;
	int eat=0;
	while(window.isOpen())
	{
       sf::Event  event;
	   while(window.pollEvent(event))
	   {    
		   if(event.type==sf::Event::Closed||!isplaying)
			   window.close();
		   if(page==GAME)
		   {
		   if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		   { snack.Turnup();}
		   if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		   {snack.Turndown();}
		   if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		   {snack.Turnleft();}
		   if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		   {snack.Turnright();}
		    if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{snack.reset();eat=0;
			page=GAME;
			}
		   
		   		  		   
		    if(snack.Touchethewall())
	   {
		   towards=sf::Vector2f(0,0);
		   std::cout<<"touch"<<std::endl;
	   }
	}  
           

		   if(page==GAMEOVER)
		   {
			    if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					eat=0;
					snack.reset();
					page=GAME;

				}
				if(event.type==sf::Event::KeyPressed&&sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					isplaying=0;
				}
            }
		   	
	   }

	 
	   if(page==GAME)
	  {
	   	    if(snack.Touchethewall())
	   {
		   towards=sf::Vector2f(0,0);
		   page=GAMEOVER;
		   std::cout<<"touch"<<std::endl;
	   }

      
	   if(snack.Touchself())
	   {
		   towards=sf::Vector2f(0,0);
		   std::cout<<"touch"<<std::endl;
		   page=GAMEOVER;
	   }
	  
	   if(snack.eat(fruit.getPosition()))
	   {  
			  snack.lengthing();
		  std::cout<<"eat "<<++eat<<std::endl;
		   fruit.setposition();
		   
		 }
	   
	   itoa(eat,a,10);
	   score.setString(a);
	  
	  srand(time(0));
	  
	 
		 
		   snack.move();
	       window.clear(sf::Color(204,255,153));
		   window.draw(back);
		 
		   window.draw(text);
		   window.draw(score);
		   snack.draw(window);
		   window.draw(fruit);
		   window.display();
	   }
	 
	   if(page==GAMEOVER)
	   {
		   window.clear();
		   window.draw(gameover);
		   window.display();
	   }
	}
		return 0;
}


	

