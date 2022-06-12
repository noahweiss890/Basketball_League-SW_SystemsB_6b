#include "Schedule.hpp"

unordered_map<int, vector<Game*>> Schedule::get_rounds() {
    return this->rounds;
}

vector<Team> Schedule::get_rankings() {
    return this->rankings;
}

vector<Team> Schedule::league_leaders(int n) {
    if(n > 20) {
        throw invalid_argument("there are only 20 teams");
    }
    vector<Team> leaders;
    for(size_t i = 0; i < n; i++) {
        leaders.push_back(this->get_rankings().at(i));
    }
    return leaders;
}