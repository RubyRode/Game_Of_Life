#include <string>
#include <iostream>
#include <fstream>
#include "Rules.h"
using namespace std;
#ifndef GAME_OF_LIFE_WORLD_H
#define GAME_OF_LIFE_WORLD_H

class World{
private:
    int field_size;
    string name;
    string comment;
    Rule rule;
public:
    bool** field{};


    World();
    explicit World(int&);
    World(World&);
    World(int, string*);
    static void tick(World&);
    void copy_field(World&);

    World& operator=(const World&);
    [[nodiscard]] string get_name() const;
    [[nodiscard]] string get_comment() const;
    [[nodiscard]] string get_rule() const;
    ~World();

    [[nodiscard]] int size() const;
    static int check_cell(World&, int&, int&, int&);
    //World& operator=(World&&) noexcept ;

};

ostream& operator<<(ostream&, const World&);
ofstream& operator<<(ofstream&, const World&);
//class view{
//private:

//public:
//    view(string&, string&);
//    ~view();
//};

#endif //GAME_OF_LIFE_WORLD_H
