#include <iostream>
#include "League.hpp"

using namespace std;
 
int main() {
    League nba;
    for(auto team : nba.get_teams()) {
        cout << team.name << endl;;
    }

    return 0;
}