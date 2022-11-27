
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

World::World(int &field_size, string *cells) {
    this->field = new bool*[field_size];
    for (int i = 0; i < field_size; i++){

    }
    for (int i = 3; i < cells->length(); i ++){

    }
}

World &World::operator=(const World & new_world) = default;

World::~World() = default;

