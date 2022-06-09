#pragma once

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
        string winner() {
            if(home_score > away_score) {
                return home.name;
            }
            if(home_score < away_score) {
                return away.name;
            }
            if(away.talent <= home.talent) { // they should win because they are the underdogs and still one
                return away.name;
            }
            return home.name;
            
        }
};
