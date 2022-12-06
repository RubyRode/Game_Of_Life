#include <iostream>
#include <string>
#include "Utility/Input_parser.h"
#include "World/Rules.h"
#include "World/World.h"
using namespace std;

int main(int argc, char **argv) {

    input_parser input(argc, argv);
    input = input_parser::parsed_args(input);

    ifstream ifs;
    if (input.file_path.empty()){
        ifs.open(R"(C:\Users\dimas\CLionProjects\Game_of_Life\test.lif)"); // выбрать случайное поле
    } else {
        ifs.open(input.file_path);
    }

    string lines[100] = {"NULL"};

    read_field_file(ifs, lines);


    World world(8, lines);
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << world.field[i][j] << " ";
        }
        cout << endl;
    }

}
