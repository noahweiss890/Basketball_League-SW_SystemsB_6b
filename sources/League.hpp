#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Team.hpp"

constexpr int LEAGUE_SIZE = 20;
constexpr int NBA_SIZE = 30;

using namespace std;

class League {
    vector<Team*> teams;
    public:
        League() {
            league_constructor(LEAGUE_SIZE);
        }
        League(vector<Team*> const &teams) {
            if(teams.size() > LEAGUE_SIZE) {
                throw invalid_argument("too many teams for the league");
            }
            for(Team* team : teams) {
                this->teams.push_back(new Team(team->get_name(), team->get_talent()));
            }
            // fill the rest in with NBA team names
            league_constructor(LEAGUE_SIZE - (int)teams.size());
        }
        vector<Team*> get_teams();
        void set_teams(vector<Team*> const &teams);
    private:
        void league_constructor(int amount);
};
