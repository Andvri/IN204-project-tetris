#include "State.hpp"

State::Context::Context(sf::RenderWindow& window, Player& player)
: window(&window)
, player(&player)
{
}

State::State(StateStack& stack, Context context)
: mStack(&stack)
, mContext(context)
{
}

State::~State()
{
}

State::Context State::getContext() const
{
	return mContext;
}
