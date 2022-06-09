#pragma once

#include <iostream>
#include <vector>
#include "Game.hpp"
#include "League.hpp"

using namespace std;

class Schedule {
    vector<Game*> games;
    public:
        Schedule(League lea) {
            for(auto &home_team : lea.get_teams()) {
                for(auto &away_team : lea.get_teams()) {
                    if(home_team.name != away_team.name) {
                        games.push_back(new Game(home_team, away_team));
                    }
                }
            }
        }
        ~Schedule() {
            for(size_t i = 0; i < games.size(); i++) {
                delete games.at(i);
            }
        }
};