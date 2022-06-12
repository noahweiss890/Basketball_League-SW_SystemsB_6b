#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Team.hpp"

#define LEAGUE_SIZE 20
#define NBA_SIZE 30

using namespace std;

class League {
    vector<Team*> teams;
    public:
        League() {
            league_constructor(LEAGUE_SIZE);
        }
        League(vector<Team*> teams) {
            if(teams.size() > 20) {
                throw invalid_argument("too many teams for the league");
            }
            for(Team* team : teams) {
                this->teams.push_back(team);
            }
            // fill the rest in with NBA team names
            league_constructor(LEAGUE_SIZE - teams.size());
        }
        vector<Team*> get_teams();
        void set_teams(vector<Team*> teams);
    private:
        void league_constructor(int amount);
};