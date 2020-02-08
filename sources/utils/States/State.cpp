#include "State.hpp"
#include "StateManager.hpp"

State::Context::Context(sf::RenderWindow& window)
: window(&window)
{
}

State::State(StateManager& stack, Context context)
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

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}