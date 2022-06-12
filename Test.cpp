#include <iostream>
#include "doctest.h"
#include <stdexcept>
#include <string>
#include <vector>
#include "Team.hpp"
#include "Schedule.hpp"
using namespace std;

TEST_CASE("checking constructors") {
    Team team("JLEM ZIONS", 0.9);
    CHECK_EQ("JLEM ZIONS", team.get_name());
    CHECK_EQ(0.9, team.get_talent());
    CHECK_THROWS(Team t("aaa", -1));
    CHECK_THROWS(Team t("aaa", 2));

    League nba1;
    CHECK_EQ(nba1.get_teams().size(), LEAGUE_SIZE);
    vector<Team*> teams1;
    Team a("AAA", 1);
    Team b("BBB", 0.6);
    Team c("CCC", 0.3);
    Team d("DDD", 0.8);
    Team e("EEE", 0.2);
    teams1.push_back(&a);
    teams1.push_back(&b);
    teams1.push_back(&c);
    teams1.push_back(&d);
    teams1.push_back(&e);
    League nba2(teams1);
    CHECK_EQ(nba2.get_teams().size(), LEAGUE_SIZE);
    
    vector<Team*> teams2;
    for(int i = 0; i < LEAGUE_SIZE + 5; i++) {
        teams2.push_back(new Team("TLV JLM", 0.5));
    }
    CHECK_THROWS(League nba3(teams2));

    Team t1("aaa", 0.5);
    Team t2("aaa", 0.8);
    CHECK_EQ(t1.get_points_scored(), 0);
    CHECK_EQ(t2.get_points_scored(), 0);
    Game g(&t1, &t2);
    CHECK(t1.get_points_scored() > 0);
    CHECK(t1.get_points_scored() > 0);
    CHECK((g.winner() == t1.get_name() || g.winner() == t2.get_name()));
    CHECK((t1.get_wins() == 1 || t2.get_wins() == 1));
    CHECK_EQ(t1.get_name(), g.get_home()->get_name());
    CHECK_EQ(t2.get_name(), g.get_away()->get_name());
    CHECK_THROWS(Game ga(NULL, &t1));
    CHECK_THROWS(Game ga(&t1, NULL));

    CHECK_NOTHROW(Schedule sc(nba2));
}

TEST_CASE("checking schedule stats") {
    League nba;
    Schedule sc(nba);
    CHECK_EQ(sc.get_rankings().size(), LEAGUE_SIZE);
    CHECK_EQ(sc.league_leaders(5).size(), 5);
    CHECK_THROWS(sc.league_leaders(-5));
    CHECK_THROWS(sc.league_leaders(25));
    CHECK_EQ(sc.get_rounds().size() , GAMES_AMOUNT);
    CHECK(sc.longest_winning_streak() < GAMES_AMOUNT);
    CHECK(sc.longest_losing_streak() < GAMES_AMOUNT);
    CHECK(sc.avg_talent_wins() < GAMES_AMOUNT);
    CHECK(sc.more_score_than_lost() < LEAGUE_SIZE);
    unordered_map<int, vector<Game *>> rounds = sc.get_rounds();
    for(auto round : rounds) {
        CHECK_EQ(round.second.size(), 10);
    }
}