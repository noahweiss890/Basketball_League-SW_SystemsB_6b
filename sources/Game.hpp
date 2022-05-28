#include <iostream>
#include "Team.hpp"

using namespace std;

class Game {
    Team home;
    Team away;
    int home_score;
    int away_score;
    public:
        Game(Team &home, Team &away) {
            this->home = home;
            this->away = away;
            this->home_score = 55 + (rand() % 46) + home.talent;
            this->away_score = 50 + (rand() % 51) + away.talent;
        }
};
