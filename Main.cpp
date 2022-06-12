#include <iostream>
#include <unordered_map>
#include "League.hpp"
#include "Schedule.hpp"

using namespace std;
 
int main() {
    srand(time(0)); // for random
    
    League nba; // pick 20 team names from the nba

    cout << endl << "Teams in league:" << endl << endl;
    for(auto team : nba.get_teams()) {
        cout << team->get_name() << "\t\ttalent: " << team->get_talent() << endl;
    }

    Schedule sc(nba);

    unordered_map<int, vector<Game*>> rounds = sc.get_rounds();

    cout << endl << "Results of each round:" << endl;
    for(auto rou : rounds) {
        cout << endl << "***** ROUND " << rou.first << " *****" << endl;
        for(size_t k = 0; k < rou.second.size(); k++) {
            cout << "home: " << rou.second.at(k)->get_home()->get_name() << "\t\taway: " << rou.second.at(k)->get_away()->get_name() << "\t\twinner: " << rou.second.at(k)->winner() << endl;
        }
    }

    cout << endl << "Rankings:" << endl;
    int i = 1;
    for(auto team : sc.get_rankings()) {
        cout << i++ << ". " << team.get_name() << "\t\twins: " << team.get_wins() << "\t\tlosses: " << team.get_losses() << "\t\tpoints scored: " << team.get_points_scored() << endl;
    }

    i = 1;
    cout << endl << "League Leaders:" << endl;
    for(auto team : sc.league_leaders(5)) {
        cout << i++ << ". " << team.get_name() << "\t\twins: " << team.get_wins() << "\t\tscored: " << team.get_points_scored() << endl;
    }

    cout << endl << "Basic Statistics:" << endl;
    cout << "Longest win streak: " << sc.longest_winning_streak() << endl;
    cout << "Longest lose streak: " << sc.longest_losing_streak() << endl;

    cout << "Amount of teams that scored more total points than lost: " << sc.more_score_than_lost() << endl;

    cout << endl << "My Statistics:" << endl;
    cout << "Average amount of points games were won by: " << sc.avg_win_by() << endl;
    cout << "Average amount of games that were won because of the talent bonus: " << sc.avg_talent_wins() << endl;
    
    return 0;
}