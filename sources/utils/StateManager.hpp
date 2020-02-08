#ifndef STATEMANAGER_CLASS
#define STATEMANAGER_CLASS

#include "State.hpp"
#include "StateIdentifiers.hpp"


#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

namespace sf
{
	class Event;
	class RenderWindow;
}

class StateManager
    : private sf::NonCopyable
{
private:
    /* data */
public:
    StateManager(/* args */);
    ~StateManager();
};



#endif