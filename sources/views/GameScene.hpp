#ifndef GAMESCENE_CLASS
#define GAMESCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Grid.hpp"
#include "../game/Tetromino.hpp"
#include "../game/Matrix.hpp"

/**
 * @brief responsible for sampling the main screen of the singleplayer game
 * 
 */
class GameScene
    : public State
{
public:
    /**
     * @brief Construct a new Multiplayer Scene object, standard builder
     * 
     * @param stack stack responsible for managing the views
     * @param context relates all current context
     */
    GameScene(StateManager& stack, Context context);

    /**
     * @brief overwriting the function drawing by adding new elements
     * responsible for sampling new elements added to this view
     */
    virtual void		draw();

    /**
     * @brief overwriting the function update by adding new elements
     * responsible for sampling new elements added to this view
     * @param dt Fraction of time
     * @return true 
     * @return false if have a problem
     */
    virtual bool		update(sf::Time dt);
    
    /**
     * @brief Adds new features to the function responsible for handling the events, adding a specific function for each key depending on the view
     * 
     * @param event getted action
     * @return true 
     * @return false if have a problem
     */
    virtual bool		handleEvent(const sf::Event& event);

    std::string         getHumanTime(sf::Time dt) const;

private: 
    Label			        mTimeInfo;
    Label			        mScoreLabel;
    Label			        mScoreValue;
    Label			        mNextText;
    sf::RectangleShape      mNextRec;
    Background              mBackground;
    Grid                    mGrid;
    sf::Time                timeSinceLastUpdate;
    sf::Time                timeLevel;
    Matrix                  mMatrix;
    Tetromino*              mTetromino;
    Tetromino*              mNextTetromino;
    bool                    mPlayGame;
    bool                    isMultiplayer;
    void descend();
    void handlerCollisionEvent(CollisionDirection cd);
    bool                    mPause;
    bool                    mHardDrop;
    void                    restart(bool firstTime = false);
    void                    updateNextTetromino();
    int                     mPoints;
    sf::Time                mTimeNotification;
    Label                   mNotification;
    Label                   mNotification2;
    int                     mLines;

    sf::Thread                      *thSend;
    sf::Thread                      *thRecv;


    void                    updateScore(int lines);

    Label                   mPlayerInfo;
    std::vector<int>  mOtherPlayer;
    const static int linesPerLevel;
};

#endif