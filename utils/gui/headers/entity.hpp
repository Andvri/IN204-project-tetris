
#ifndef ENTITY_CLASS
#define ENTITY_CLASS
#include <SFML/System/Vector2.hpp>
class Entity
{
private:
    sf::Vector2f position;
    short gravity;
public:
    Entity();
    Entity(short gravity, sf::Vector2f position);
    Entity(short gravity, float positionX, float positionY);
    Entity(Entity &e);

    ~Entity();

    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void setGravity(short gravity);
    sf::Vector2f getPosition() const;
    short getGravity() const;
};

#endif