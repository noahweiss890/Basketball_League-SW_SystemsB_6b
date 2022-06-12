#pragma once

#include <iostream>
#include "Team.hpp"

using namespace std;

class Game {
    Team* home;
    Team* away;
    int home_score;
    int away_score;
    public:
        Game(Team* home, Team* away) {
            this->home = home;
            this->away = away;
            this->home_score = rand() % (100 - 55 + 1) + 55 + (int)(home->get_talent() * 10);
            this->away_score = rand() % (100 - 50 + 1) + 50 + (int)(away->get_talent() * 10);
            // cout << "\nhome score: " << this->home_score << endl;
            // cout << "away score: " << this->away_score << endl;
            string win = this->winner();
            if(win == this->home->get_name()) {
                this->home->update_streak(1);
                this->away->update_streak(0);
            }
            else {
                this->home->update_streak(0);
                this->away->update_streak(1);
            }
            this->home->update_points(this->home_score, this->away_score);
            this->away->update_points(this->away_score, this->home_score);
        }
        Team* get_home();
        Team* get_away();
        string winner();
};
