#include "./headers/entity.hpp"


Entity::Entity(): 
    gravity(0),
    position(sf::Vector2f())
{}

Entity::Entity(short gravity, sf::Vector2f position):
    gravity(gravity),
    position(position)
{}

Entity::Entity(short gravity, float positionX, float positionY):
    gravity(gravity),
    position(sf::Vector2f(positionX, positionY))
{}

Entity::Entity(Entity &entityCopy):
    gravity(entityCopy.getGravity()),
    position(entityCopy.getPosition())
{}

void Entity::setGravity(short gravity)
{
    this->gravity = gravity;
}

void Entity::setPosition(sf::Vector2f position)
{
    this->position = position;
}

void Entity::setPosition(float x, float y)
{
    this->setPosition(sf::Vector2f(x,y));
}

sf::Vector2f Entity::getPosition() const
{
    return this->position;
}


short Entity::getGravity() const
{
    return this->gravity;
}

Entity::~Entity()
{}

