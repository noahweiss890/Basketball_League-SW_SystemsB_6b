#include "Game.hpp"

Team* Game::get_home() {
    return this->home;
}

Team* Game::get_away() {
    return this->away;
}

// declares the winner based off of the points, if tie then whoever has a lower talent wins
string Game::winner() {
    if(home_score > away_score) {
        return this->home->get_name();
    }
    if(home_score < away_score) {
        return this->away->get_name();
    }
    // theres a tie
    if(away->get_talent() <= home->get_talent()) { // they should win because they are the underdogs and still won
        return this->away->get_name();
    }
    return this->home->get_name();
}