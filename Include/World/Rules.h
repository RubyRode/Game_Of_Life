
#include <string>
#include <cstdlib>
#ifndef GAME_OF_LIFE_RULES_H
#define GAME_OF_LIFE_RULES_H
using namespace std;
class Rule{
public:
    string str_rule;
    string birth;
    string survival;

    Rule();
    ~Rule();
    Rule(const string&);
};

#endif //GAME_OF_LIFE_RULES_H
