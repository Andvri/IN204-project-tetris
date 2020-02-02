#ifndef PLAYER_CLASS
#define PLAYER_CLASS


class Player{
public:
    Player();
    ~Player(){};

    int getScore();
    int getLines();
    int getLevel();

    void updateScore(int checkLines);
    void updateLines(int countLines);
    void updateLevel(int countLevel);

protected:
    int score, lines, level;

public:
    bool levelUp;
};
#endif