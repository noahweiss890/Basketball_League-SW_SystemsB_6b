#include "Schedule.hpp"

unordered_map<int, vector<Game*>> Schedule::get_rounds() {
    return this->rounds;
}

vector<Team> Schedule::get_rankings() {
    return this->rankings;
}

vector<Team> Schedule::league_leaders(int n) {
    if(n > LEAGUE_SIZE || n < 1) {
        throw invalid_argument("amount must be between 1 to 20");
    }
    vector<Team> leaders;
    for(size_t i = 0; i < n; i++) {
        leaders.push_back(this->get_rankings().at(i));
    }
    return leaders;
}

int Schedule::longest_winning_streak() {
    int ans = 0;
    for(auto const &team : this->rankings) {
        if(team.get_max_win_streak() > ans) {
            ans = team.get_max_win_streak();
        }
    }
    return ans;
}

int Schedule::longest_losing_streak() {
    int ans = 0;
    for(auto const &team : this->rankings) {
        if(team.get_max_lose_streak() > ans) {
            ans = team.get_max_lose_streak();
        }
    }
    return ans;
}

// counts how many teams have scored more points than lost points
int Schedule::more_score_than_lost() {
    int count = 0;
    for(auto const &team : this->rankings) {
        if(team.get_points_scored() > team.get_points_lost()) {
            count++;
        }
    }
    return count;
}

// calculates the average amount of points each game was won by
double Schedule::avg_win_by() {
    double sum = 0;
    for(auto const &team : this->rankings) {
        sum += team.get_total_win_by_avg();
    }
    return sum / LEAGUE_SIZE;
}

// calculates the average amount of games won per team because of the talent bonus
double Schedule::avg_talent_wins() {
    double sum = 0;
    for(auto const &team : this->rankings) {
        sum += team.get_talent_wins();
    }
    return sum / LEAGUE_SIZE;
}
