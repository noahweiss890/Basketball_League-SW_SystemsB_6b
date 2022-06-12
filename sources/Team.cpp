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

int Team::get_losses() {
    return this->losses;
}

int Team::get_points_scored() {
    return this->points_scored;
}

int Team::get_points_lost() {
    return this->points_lost;
}

void Team::update_streak(int result) {
    if(result != 0 && result != 1) {
        throw invalid_argument("illegal game result");
    }
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

void Team::update_points(int scored, int lost, string winner) {
    if(scored < 0 || lost < 0) {
        throw invalid_argument("illegal game scores");
    }
    this->points_scored += scored;
    this->points_lost += lost;
    if(this->name == winner) {
        this->total_win_by += scored - lost;
        if(scored - lost < (int)(this->get_talent() * MAX_TALENT_POINTS)) {
            this->talent_wins++;
        }
    }
}

bool Team::operator>(const Team& t) const {
    if(this->wins == t.wins) {
        return this->points_scored > t.points_scored;
    }
    return this->wins > t.wins;
}

int Team::get_max_win_streak() {
    return this->max_win_streak;
}

int Team::get_max_lose_streak() {
    return this->max_lose_streak;
}

double Team::get_total_win_by_avg() {
    return this->total_win_by / (double)GAMES_AMOUNT;
}

int Team::get_talent_wins() {
    return this->talent_wins;
}