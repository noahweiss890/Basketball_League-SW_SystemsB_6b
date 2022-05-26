#include <iostream>

using namespace std;

class Team {
    public:
        string name;
        int talent;
    public:
        Team(string name, int talent) {
            this->name = name;
            this->talent = talent;
        }
};