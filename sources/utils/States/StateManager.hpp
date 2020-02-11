#ifndef STATEMANAGER_CLASS
#define STATEMANAGER_CLASS

#include "State.hpp"
#include "StateIdentifiers.hpp"


#include <vector>
#include <utility>
#include <functional>
#include <map>

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
public:
    /**
     * @brief three actions possibles for our management
     * 
     */
    enum Action
    {
        Push,
        Pop,
        Clear,
    };

    /**
     * @brief Construct a new State Manager object
     * 
     * @param context 
     */
    explicit    StateManager(State::Context context);

    /**
     * @brief Polymorphic function to take all contexts as possible to work with
     * 
     * 
     * @param stateID 
     */
    template <typename T>
    void		registerState(States::ID stateID);

    /**
     * @brief Iterate from top to bottom, stop as soon as update() returns false
     * 
     * @param dt 
     */
    void				update(sf::Time dt);

    /**
     * @brief Draw all active states from bottom to top
     * 
     */
    void				draw();

    /**
     * @brief Iterate from top to bottom, stop as soon as handleEvent() returns false
     * 
     * @param event 
     */
    void				handleEvent(const sf::Event& event);

    /**
     * @brief Performing the status change for selected views
     * 
     * @param stateID 
     */
    void				pushState(States::ID stateID);

    /**
     * @brief Putting stored views on the waiting list to active
     * 
     */
    void				popState();

    /**
     * @brief clears all storage states
     * 
     */
    void				clearStates();

    /**
     * @brief Check if the battery is empty or not
     * 
     * @return true 
     * @return false 
     */
    bool				isEmpty() const;

    ~StateManager();


private:
    /**
     * @brief Create a State object
     * 
     * @param stateID 
     * @return second copie of object
     */
    State::Ptr			createState(States::ID stateID);

    /**
     * @brief Interprets the information from the ENUM, performing the steel in the pile of views
     * 
     */
    void				applyPendingChanges();

private:
    struct PendingChange
    {
        explicit			PendingChange(Action action, States::ID stateID = States::None);

        Action				action;
        States::ID			stateID;
    };

private:
    std::vector<State::Ptr>                             mStack;
    std::vector<PendingChange>							mPendingList;
    State::Context										mContext;
    std::map<States::ID, std::function<State::Ptr()>>	mFactories;

};


template <typename T>
void StateManager::registerState(States::ID stateID)
{
	mFactories[stateID] = [this] ()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

#endif