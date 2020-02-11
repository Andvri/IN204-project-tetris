#ifndef PLAYER_CLASS
#define PLAYER_CLASS
class Player
{
    private:
        bool mPause;
        int mScore;   
        int mLevel;         
    public:
        Player();
        Player(bool pause, int score, int level);
        ~Player();
        bool getPause();
        int getScore();
        int getLevel();

        void setPause(bool pause);
        void setScore(int score);
        void setLevel(int level);
};
#endif