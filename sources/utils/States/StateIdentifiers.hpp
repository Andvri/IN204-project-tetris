#ifndef STATEIDENTIFIERS_ENUM
#define STATEIDENTIFIERS_ENUM

/**
 * @brief Each view existing in game
 * 
 */
namespace States
{
	enum ID
	{
        None,
		Title,
		Menu,
        Game,
		MultiPlayer,
		Help,
		Pause
	};
}

#endif