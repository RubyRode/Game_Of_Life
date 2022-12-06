#ifndef GAME_OF_LIFE_INPUT_PARSER_H
#define GAME_OF_LIFE_INPUT_PARSER_H

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class input_parser{
public:
    string file_path;
    string dump;
    bool endgame;
    bool help;
    int tick;
    int itr;

    input_parser();
    input_parser(int argc, char** argv);
    ~input_parser();
    input_parser& operator=(input_parser const&);

    const string& get_option(const string& option);
    bool option_exists(const string& option);
    static input_parser& parsed_args(input_parser& prs);
    static input_parser& clear_parser(input_parser& prs);
private:
    vector<string> tokens;
};

string* read_field_file(ifstream&, string*);

#endif //GAME_OF_LIFE_INPUT_PARSER_H
