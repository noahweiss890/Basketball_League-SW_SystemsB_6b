#pragma once

#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Game.hpp"
#include "League.hpp"

using namespace std;

class Schedule {
    unordered_map<int, vector<Game*>> rounds;
    vector<Team> rankings;
    public:
        Schedule(League lea) {
            for(size_t i = 1; i <= 38; i++) {
                this->rounds.insert({i, vector<Game*>()});
            }
            for(size_t i = 1; i < 20; i++) {
                for(size_t k = 0; k < lea.get_teams().size() / 2; k++) {
                    this->rounds[i].push_back(new Game(lea.get_teams().at(k), lea.get_teams().at(lea.get_teams().size() - 1 - k)));
                    this->rounds[this->rounds.size() - i].push_back(new Game(lea.get_teams().at(lea.get_teams().size() - 1 - k), lea.get_teams().at(k)));
                }
                rotate(lea.get_teams().begin() + 1, lea.get_teams().begin() + (long)lea.get_teams().size() - 2, lea.get_teams().end());
            }
            for(auto team : lea.get_teams()) {
                this->rankings.push_back(*team);
            }
            std::sort(this->rankings.begin(), this->rankings.end(), std::greater<Team>());
        }

        ~Schedule() {
            for(auto rou : this->rounds) {
                for(size_t k = 0; k < this->rounds[rou.first].size(); k++) {
                    delete this->rounds[rou.first].at(k);
                }
            }
        }
        unordered_map<int, vector<Game*>> get_rounds();
        vector<Team> get_rankings();
        vector<Team> league_leaders(int n);
};