#include <iostream>
#include "League.hpp"

using namespace std;

int main() {
    League nba;
    for(auto team : nba.get_teams()) {
        cout << team.name << endl;;
    }

    for(int i = 0; i < 20; i++) {
        cout << (rand() % 10) << endl;
    }

    return 0;
}