#include <iostream>
#include <string>
#include "Include//Utility/Input_parser.h"
#include "Include/World/Rules.h"
#include "Include/World/World.h"
using namespace std;

int main(int argc, char **argv) {

    input_parser input(argc, argv);
    input = input_parser::parsed_args(input);

    ifstream ifs;

    if (input.input_path.empty()){
        ifs.open("/home/dimasik/CLionProjects/OOP/Game_of_Life/test.lif");
        input.input_path = "/home/dimasik/CLionProjects/OOP/Game_of_Life/test.lif";
    } else {
        ifs.open(input.input_path);
    }

    string lines[100] = {"NULL"};

    read_field_file(ifs, lines);

    World world(30, lines);

    for (int i = 0; i < input.tick; i++) {
        World::tick(world);
    }

    cout << world << endl;

    while(!input.endgame){

        string input_string;

        getline(cin,input_string);
        input_parser::clear_parser(input);
        input.parse_str(input_string);
        if (input.help){
            cout << "This is the Conways Game of Life.\nYou can \"dump\" your epoch, evoke epochs with \"tick\", show help with \"help\" or \"exit\"" << endl;
        }
        if (input.tick != 0) {
            for (int i = 0; i < input.tick; i++) {
                World::tick(world);
            }
            cout << world << endl;
        }
        if (!input.dump.empty()){
            ofstream out_file;
            out_file.open(input.dump);
            if (out_file.is_open()){
                out_file << world << endl;
                out_file.close();
            }
        }
        if (input.endgame){
            break;
        }
    }
    return 0;
}
