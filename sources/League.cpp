#include "League.hpp"

vector<Team*> League::get_teams() {
    return this->teams;
}

void League::set_teams(vector<Team*> teams) {
    this->teams = teams;
}

// if 20 teams arent provided then the remaining teams that will
// praticipate in the leage will be real NBA teams :)
void League::league_constructor(int amount) {
    if(amount == 0) {
        return;
    }
    //building vector of real NBA team names
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

    vector<int> nums; // vector for remembering which team where already chosen randomly
    for(int i = 0; i < amount; i++) {
        size_t t_num = rand() % NBA_SIZE;
        while(find(nums.begin(), nums.end(), t_num) != nums.end()) { // while t_num has already been chosen at random
            t_num = rand() % NBA_SIZE;
        }
        this->teams.push_back(new Team(nba.at(t_num), (double) rand() / RAND_MAX));
        nums.push_back(t_num);
    }
}