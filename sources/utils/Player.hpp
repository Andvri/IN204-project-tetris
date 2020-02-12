#ifndef PLAYER_CLASS
#define PLAYER_CLASS
#include <SFML/Network.hpp>
#include "../network/Client.hpp"

class Player
{
    private:
        bool mPause;
        bool mRestart;
        bool mMultiplayer;
        int mScore;   
        int mLevel;
        Client mMultiplayerController;
    public:
        Player();
        Player(bool pause, int score, int level);
        ~Player();
        bool getPause();
        int getScore();
        int getLevel();
        int getRestart();
        int getMultiplayer();

        void setRestart(bool pause);
        void setMultiplayer(bool score);
        void setPause(bool pause);
        void setScore(int score);
        void setLevel(int level);

        void establishConnection(bool create);
};
#endif