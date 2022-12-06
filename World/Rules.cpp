
#include "Rules.h"

Rule::Rule() {
    str_rule = "";
    birth = NULL;
    survival = "";
}

Rule::Rule(const string& rule_str){
    str_rule = rule_str;

    for(int i = 1; i < 8; i ++){
        if (str_rule[i-1] == 'B'){
            birth = (int)(str_rule[i] - 48);
        }
        if (str_rule[i-1] == 'S'){
            while (i < str_rule.length()){
                survival += char(str_rule[i]);
                i++;
            }
        }
    }
}

Rule::~Rule() = default;

