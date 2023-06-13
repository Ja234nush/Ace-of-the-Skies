#include "Player.h"
#include<iostream>

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::Init(const sf::Texture& texture)
{

	this->setTexture(texture);
	this->setTextureRect(sf::IntRect(0, 0, 99, 99));
	this->setPosition(100, 100);
}

void Player::Animate(sf::Time DeltaTime)
{
	accumulatedtime += DeltaTime.asSeconds();
	if (accumulatedtime >= frameTime)
	{
		frame++;
		frame %= 4;
		//std::cout << Del << std::endl;
		this->setTextureRect(sf::IntRect(frame * 99 , 0, 99, 99));
		accumulatedtime = 0;
        acceleration.y += 1;
        if (frame % 10 == 0)
        {
            score += 1;
        }
	}
	}

void Player::Movement(sf::Time DeltaTime, sf::FloatRect bounds,sf::Vector2u window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        direction.y = -1.0;
        acceleration.y = 4.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        direction.y = 1.0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction.x = -1.0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction.x = 1.0;
    }
    
    this->move(direction.x * speed.x * DeltaTime.asSeconds(), direction.y * speed.y * DeltaTime.asSeconds());
    this->borders(bounds, window);
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction.y = 0;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction.x = 0;
    }
    this->move(acceleration.x, acceleration.y * DeltaTime.asSeconds());
   
        
    
    }

void Player::borders(sf::FloatRect bounds,sf::Vector2u window)
{
    
    

        if (bounds.left <= 0)
        {
            setPosition(1,this->getPosition().y);
        }
        else if (bounds.left + bounds.width >= window.x )
        {
            setPosition((window.x)-100, getPosition().y);
        }
        if (bounds.top <= 0)
        {
            setPosition(getPosition().x, 1);
        }
        else if (bounds.top + bounds.height >= window.y-50 )
        {
            setPosition(getPosition().x, window.y-150);
        }
    
}

void Player::setLives(int i)
{
    lives += i;
}

void Player::setFuel(int i)
{
    fuel += i;
}

void Player::setScore(int i)
{
    score += i;
}

int Player::getLives()
{
    return lives;
}

int Player::getFuel()
{
    return fuel;
}

int Player::getScore()
{
    return score;
}




