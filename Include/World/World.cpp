
#include "World.h"

World::World() {
    this->field = new bool* [30];
    for (int i = 0; i < 30; i ++){
        this->field[i] = new bool[30];
    }
}

World::World(int& field_size) {
    this->field_size = field_size;
    this->field = new bool* [field_size];
    for (int i = 0; i < field_size; i ++){
        this->field[i] = new bool[field_size];
        for (int j = 0; j < field_size; j++){
            this->field[i][j] = false;
        }
    }

}

World::World(World & new_world) {
    *this = new_world;
}

void World::tick(World & world) {
    int w_size = world.size();
    World world_tmp(w_size);
    int tmp = 0;
    for (int i = 0; i < world.field_size; i++){
        for (int j = 0; j < world.field_size; j++) {
            if (i == 0) {
                if (j == 0){
                    tmp = 1;
                }else if (j == world.field_size - 1){
                    tmp = 2;
                }
            }else if (i == world.field_size) {
                if (j == 0){
                    tmp = 3;
                }else if (j == world.field_size - 1){
                    tmp = 4;
                }
            }
            int flag = check_cell(world, i, j, tmp);
            if (flag == 1){
                world_tmp.field[i][j] = true;
            }else{
                world_tmp.field[i][j] = false;
            }
        }
    }
    world.copy_field(world_tmp);
}

World::World(int field_size, string* cells) {
    this->name = cells[0];
    this->comment = cells[1];
    this->rule = Rule(cells[2]);
    this->field_size = field_size;


    this->field = new bool*[field_size];
    for (int i = 0; i < field_size; i++){
        this->field[i] = new bool[field_size];
        for (int j = 0; j < field_size; j++){
            this->field[i][j] = false;
        }
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

int World::size() const {
    return this->field_size;
}

int World::check_cell(World & world, int& x, int& y, int& flag) {
    bool Moore[9];
    int sum = 0;
    int cnt = 0;
    for (int l = 0; l < 3; l++){
        for (int m = 0; m < 3; m++){
            if (flag == 1) {

            }else {
                Moore[cnt] = world.field[x - 1 + l][y - 1 + m];
                sum += Moore[cnt];
                cnt++;
            }
        }
    }

    if (world.field[x][y]){
        sum --;
        string::size_type check = world.rule.survival.find(sum + '0');
        if (check != -1){
            return 1;
        }
    }else {
        string::size_type check = world.rule.birth.find(sum + '0');
        if (check != -1){
            return 1;
        }
    }
    return 0;
}

void World::copy_field(World & world) {
    this->field = world.field;
}

string World::get_name() const {
    string name = this->name;
    return name;
}
string World::get_comment() const {
    return this->comment;
}

string World::get_rule() const {
    return this->rule.str_rule;
}

ostream &operator<<(ostream & out, const World & world) {
    for (int i = 0; i < world.size(); i++){
        out << "| ";
        for (int j = 1; j < world.size() - 1; j++) {
            if (i == 0 or i == world.size() - 1) {
                out << "--";
            } else {
                out << world.field[i][j] << " ";
            }
        }
        out << " |" << endl;
    }
    return out;
}

ofstream & operator<<(ofstream & out, const World& world){
    out << world.get_name() << endl;
    out << world.get_comment() << endl;
    out << world.get_rule() << endl;
    for (int i = 0; i < world.size(); i++){
        for (int j = 1; j < world.size(); j++) {
            if (world.field[i][j]){
                out << i - (world.size() / 2) << " " << j - (world.size() / 2) << endl;
            }
        }
    }
    return out;
}

//World &World::operator=(World &&) {
//    return <#initializer#>;
//}

World &World::operator=(const World & new_world) = default;

World::~World() = default;
//
//view::view(string & name, string & comment) {
//
//}
