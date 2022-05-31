#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Team.hpp"

using namespace std;

class League {
    vector<Team> teams;
    public:
        League() {
            league_constructor(20);
        }
        League(vector<Team> teams) {
            for(Team team : teams) {
                this->teams.push_back(team);
            }
            league_constructor(20 - teams.size());
        }
    private:
        void league_constructor(int amount) {
            if(amount == 0) {
                return;
            }
            vector<string> nba;
            nba.push_back("Boston Celtics");
            nba.push_back("Brooklyn Nets");
            nba.push_back("New York Knicks");
            nba.push_back("Philadelphia 76ers");
            nba.push_back("Toronto Raptors");
            nba.push_back("Chicago Bulls");
            nba.push_back("Cleveland Cavaliers");
            nba.push_back("Detroit Pistons");
            nba.push_back("Indiana Pacers");
            nba.push_back("Milwaukee Bucks");
            nba.push_back("Atlanta Hawks");
            nba.push_back("Charlotte Hornets");
            nba.push_back("Miami Heat");
            nba.push_back("Orlando Magic");
            nba.push_back("Washington Wizards");
            nba.push_back("Denver Nuggets");
            nba.push_back("Minnesota Timberwolves");
            nba.push_back("Oklahoma City Thunder");
            nba.push_back("Portland Trail Blazers");
            nba.push_back("Utah Jazz");
            nba.push_back("Golden State Warriors");
            nba.push_back("LA Clippers");
            nba.push_back("Los Angeles Lakers");
            nba.push_back("Phoenix Suns");
            nba.push_back("Sacramento Kings");
            nba.push_back("Dallas Mavericks");
            nba.push_back("Houston Rockets");
            nba.push_back("Memphis Grizzlies");
            nba.push_back("New Orleans Pelicans");
            nba.push_back("San Antonio Spurs");

            srand(time(0));
            vector<int> nums;
            for(int i = 0; i < amount; i++) {
                size_t t_num = rand() % 30;
                // cout << "tnum is: " << t_num << endl;
                while(find(nums.begin(), nums.end(), t_num) != nums.end()) {
                    t_num = rand() % 30;
                    // cout << "again tnum is: " << t_num << endl;
                }
                this->teams.push_back(Team(nba.at(t_num), std::rand() % 2));
                nums.push_back(t_num);
            }
        }
    public:
        vector<Team> get_teams() {
            return this->teams;
        }
};