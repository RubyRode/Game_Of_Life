
#include <stdexcept>
#include "Input_parser.h"

input_parser::input_parser(int argc, char **argv) {
    for (int i = 1; i < argc; i++){
        this->tokens.emplace_back(string(argv[i]));
    }
    this->endgame = false;
    this->help = false;
    this->tick = 0;
    this->itr = 0;
    this->dump = "";
}

const string &input_parser::get_option(const string &option) {
    vector<string>::const_iterator it;

    it = find(this->tokens.begin(), this->tokens.end(), option);

    if (it != this->tokens.end() && ++it != this->tokens.end()) {
        return *it;
    }

    static const string empty_string;

    return empty_string;
}

bool input_parser::option_exists(const string& option) {
    return find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end();
}

input_parser& input_parser::parsed_args(input_parser &prs) {
    if (prs.option_exists("-i")) {
        string tmp = prs.get_option("-i");
        prs.itr = stoi(tmp);
    } else if (prs.option_exists("--iterations=")){
        string tmp = prs.get_option("--iterations=");
        prs.itr = stoi(tmp);
    }
    if (prs.option_exists("-in")){
        prs.file_path = prs.get_option("-in");
    } else if (prs.option_exists("--input=")){
        prs.file_path = prs.get_option("--input=");
    }
    if (prs.option_exists("-o")){
        prs.file_path = prs.get_option("-o");
    } else if (prs.option_exists("--output=")){
        prs.file_path = prs.get_option("--output=");
    }
    if (prs.option_exists("dump")){
        prs.dump = prs.get_option("dump");
    }
    if (prs.option_exists("help")){
        prs.help = true;
    }
    if (prs.option_exists("exit")){
        prs.endgame = true;
    }
    return prs;
}

input_parser::input_parser() {
    this->endgame = false;
    this->help = false;
    this->tick = 0;
    this->itr = 0;
    this->dump = "";
    this->file_path = "";
}

input_parser &input_parser::clear_parser(input_parser &prs) {
    input_parser tmp;
    prs = tmp;
    return prs;
};

input_parser& input_parser::operator=(input_parser const&) = default;

input_parser::~input_parser() = default;

string* read_field_file(ifstream& stream, string* lines){
    if (stream.is_open()){
        int i = 0;
        while(getline(stream, lines[i])){
            i++;
        };
    }
    return lines;
}
