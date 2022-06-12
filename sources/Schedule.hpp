#pragma once

#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Game.hpp"
#include "League.hpp"

#define LEAGUE_SIZE 20

using namespace std;

class Schedule {
    unordered_map<int, vector<Game*>> rounds;
    vector<Team> rankings;
    public:
        Schedule(League lea) {
            if(lea.get_teams().size() != LEAGUE_SIZE) {
                throw invalid_argument("league must have exactly 20 teams");
            }
            for(size_t i = 1; i <= GAMES_AMOUNT; i++) {
                this->rounds.insert({i, vector<Game*>()});
            }
            for(size_t i = 1; i < LEAGUE_SIZE; i++) {
                for(size_t k = 0; k < LEAGUE_SIZE / 2; k++) {
                    this->rounds[i].push_back(new Game(lea.get_teams().at(k), lea.get_teams().at(LEAGUE_SIZE - 1 - k)));
                    this->rounds[GAMES_AMOUNT + 1 - i].push_back(new Game(lea.get_teams().at(LEAGUE_SIZE - 1 - k), lea.get_teams().at(k)));
                }
                vector<Team*> temp = lea.get_teams();
                rotate(temp.begin() + 1, temp.begin() + 20 - 1, temp.end());
                lea.set_teams(temp);
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
        int longest_winning_streak();
        int longest_losing_streak();
        int more_score_than_lost();
        double avg_win_by();
        double avg_talent_wins();
};