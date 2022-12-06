
#include "World.h"

World::World() {
    this->field = new bool* [30];
    for (int i = 0; i < 30; i ++){
        this->field[i] = new bool[30];
    }
}

World::World(int& field_size) {
    this->field = new bool* [field_size];
    for (int i = 0; i < field_size; i ++){
        this->field[i] = new bool[field_size];
    }
}

World::World(World & new_world) {
    *this = new_world;
}

World& World::tick(World & world) {
    return world;
}

World::World(int field_size, string* cells) {
    this->name = cells[0];
    this->comment = cells[1];
    this->rules = Rule(cells[2]);

    this->field = new bool*[field_size];
    for (int i = 0; i < field_size; i++){
        this->field[i] = new bool[field_size];
    }

    for (int i = 3; !cells[i].empty(); i ++){
        int j;
        string x_str;
        string y_str;
        int x, y;
        for (j = 0; cells[i][j] != ' '; j++){
            x_str += cells[i][j];

        }
        x = stoi(x_str);
        for (j++; j != cells[i].length(); j ++){
            y_str += cells[i][j];

        }
        y = stoi(y_str);
        this->field[x + (field_size / 2)][y + (field_size / 2)] = true;
    }
}

World &World::operator=(const World & new_world) = default;

World::~World() = default;

