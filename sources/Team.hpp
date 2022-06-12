#pragma once

#include <iostream>

using namespace std;

class Team {
    string name;
    double talent;
    int wins;
    int losses;
    int win_streak;
    int lose_streak;
    int max_win_streak;
    int max_lose_streak;
    int points_scored;
    int points_lost;
    public:
        Team(string name, double talent) {
            this->name = name;
            this->talent = talent;
            this->wins = 0;
            this->losses = 0;
            this->win_streak = 0;
            this->lose_streak = 0;
            this->max_win_streak = 0;
            this->max_lose_streak = 0;
            this->points_scored = 0;
            this->points_lost = 0;
        }
        string get_name();
        double get_talent();
        int get_wins();
        int get_points_scored();
        void update_streak(int result);
        void update_points(int scored, int lost);
        bool operator>(const Team& t) const;
};
