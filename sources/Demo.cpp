#include <iostream>
#include <unordered_map>
#include "League.hpp"
#include "Schedule.hpp"

using namespace std;
 
int main() {
    srand(time(0));
    // for (size_t i = 0; i < 10; i++)
    // {
    //     cout << (double) rand() / RAND_MAX << endl;
    // }
    
    League nba;
    for(auto team : nba.get_teams()) {
        cout << team->get_name() << "   talent: " << team->get_talent() << endl;;
    }

    // Game g(nba.get_teams().at(0), nba.get_teams().at(1));
    // cout << "home: " << g.get_home()->get_name() << "      away: " << g.get_away()->get_name() << "     winner: " << g.winner() << endl;

    Schedule sc(nba);
    cout << "done" << endl;

    unordered_map<int, vector<Game*>> rounds = sc.get_rounds();

    for(auto rou : rounds) {
        for(size_t k = 0; k < rounds[rou.first].size(); k++) {
            cout << "home: " << rounds[rou.first].at(k)->get_home()->get_name() << "\taway: " << rounds[rou.first].at(k)->get_away()->get_name() << "\twinner: " << rounds[rou.first].at(k)->winner() << endl;
        }
    }

    cout << "\n\nRankings:" << endl;
    for(auto team : sc.get_rankings()) {
        cout << "\tteam: " << team.get_name() << " wins: " << team.get_wins() << " scored: " << team.get_points_scored() << endl;
    }

    cout << "\n\n League Leaders:" << endl;
    for(auto team : sc.league_leaders(5)) {
        cout << "\tteam: " << team.get_name() << " wins: " << team.get_wins() << " scored: " << team.get_points_scored() << endl;
    }

    // for(auto r : rounds) {
    //     cout << "\t******* Round " << r.first << endl;
    //     for(auto game : r.second) {
    //         cout << "home: " << game->get_home()->get_name() << "\taway: " << game->get_away()->get_name() << "\twinner: " << game->winner() << endl;
    //     }
    // }

    // Schedule sc(nba);

// A, B, C, D

// ~A->B , ~A->C , ~A->D , ~B->A , ~B->C , ~B->D , ~C->A , ~C->B , ~C->D , ~D->A , D->B , D->C

// ROUND 1: A->B, C->D
// ROUND 2: A->C, B->C
// ROUND 3: A->D, C->B
// ROUND 4: B->A
// ROUND 5: B->D, C->A
// ROUND 6: D->A

    return 0;
}