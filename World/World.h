#include <string>
using namespace std;
#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

class World{
public:
    bool** field{};
    string name;
    string comment;
    string rules;

    World();
    explicit World(int&);
    World(World&);
    World(int&, string*);
    static World& tick(World&);

    World& operator=(const World&);

    ~World();

};

#endif //GAME_OF_LIFE_WORLD_H
