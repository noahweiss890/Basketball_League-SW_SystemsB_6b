#include "Team.hpp"

string Team::get_name() {
    return this->name;
}

double Team::get_talent() {
    return this->talent;
}

int Team::get_wins() {
    return this->wins;
}

int Team::get_points_scored() {
    return this->points_scored;
}

void Team::update_streak(int result) {
    if(result == 1) {
        this->wins++;
        this->win_streak++;
        if(this->lose_streak > this->max_lose_streak) {
            this->max_lose_streak = this->lose_streak;
        }
        this->lose_streak = 0;
    }
    else {
        this->losses++;
        this->lose_streak++;
        if(this->win_streak > this->max_win_streak) {
            this->max_win_streak = this->win_streak;
        }
        this->win_streak = 0;
    }
}

void Team::update_points(int scored, int lost) {
    this->points_scored += scored;
    this->points_lost += lost;
}

bool Team::operator>(const Team& t) const {
    if(this->wins == t.wins) {
        return this->points_scored > t.points_scored;
    }
    return this->wins > t.wins;
}