#pragma once

#include <iostream>
#include "Team.hpp"

#define MAX_SCORE 100
#define MIN_HOME_SCORE 55
#define MIN_AWAY_SCORE 50
#define MAX_TALENT_POINTS 10

using namespace std;

class Game {
    Team* home;
    Team* away;
    int home_score;
    int away_score;
    public:
        Game(Team* home, Team* away) {
            if(home == NULL || away == NULL) {
                throw invalid_argument("cannot send null ptrs as teams");
            }
            this->home = home;
            this->away = away;
            // calculate teams points for this game
            this->home_score = rand() % (MAX_SCORE - MIN_HOME_SCORE + 1) + MIN_HOME_SCORE + (int)(home->get_talent() * MAX_TALENT_POINTS);
            this->away_score = rand() % (MAX_SCORE - MIN_AWAY_SCORE + 1) + MIN_AWAY_SCORE + (int)(away->get_talent() * MAX_TALENT_POINTS);
            string win = this->winner(); // declare the winner
            if(win == this->home->get_name()) {
                this->home->update_streak(1); // home won
                this->away->update_streak(0); // away lost
            }
            else {
                this->home->update_streak(0); // home lost
                this->away->update_streak(1); // away won
            }
            // update the teams points stats
            this->home->update_points(this->home_score, this->away_score, win);
            this->away->update_points(this->away_score, this->home_score, win);
        }
        Team* get_home();
        Team* get_away();
        string winner();
};
