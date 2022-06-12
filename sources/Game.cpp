#include "Game.hpp"

Team* Game::get_home() {
    return this->home;
}

Team* Game::get_away() {
    return this->away;
}

string Game::winner() {
    if(home_score > away_score) {
        return this->home->get_name();
    }
    if(home_score < away_score) {
        return this->away->get_name();
    }
    if(away->get_talent() <= home->get_talent()) { // they should win because they are the underdogs and still one
        return this->away->get_name();
    }
    return this->home->get_name();
}