#include "StateManager.hpp"

#include <cassert>


StateManager::StateManager(State::Context context)
: mStack()
, mPendingList()
, mContext(context)
, mFactories()
{
}

StateManager::~StateManager()
{}

void StateManager::update(sf::Time dt)
{
	
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
			break;
	}

	applyPendingChanges();
}

void StateManager::draw()
{
	
	for(State::Ptr& state : mStack)
		state->draw();
}

void StateManager::handleEvent(const sf::Event& event)
{
	
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}

	applyPendingChanges();
}

void StateManager::pushState(States::ID stateID)
{
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateManager::popState()
{
	mPendingList.push_back(PendingChange(Pop));
}

void StateManager::clearStates()
{
	mPendingList.push_back(PendingChange(Clear));
}

bool StateManager::isEmpty() const
{
	return mStack.empty();
}

State::Ptr StateManager::createState(States::ID stateID)
{
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();
}

void StateManager::applyPendingChanges()
{
	for(PendingChange change : mPendingList)
	{
		switch (change.action)
		{
			case Push:
				mStack.push_back(createState(change.stateID));
				break;

			case Pop:
				mStack.pop_back();
				break;

			case Clear:
				mStack.clear();
				break;
		}
	}

	mPendingList.clear();
}

StateManager::PendingChange::PendingChange(Action action, States::ID stateID)
: action(action)
, stateID(stateID)
{
}
