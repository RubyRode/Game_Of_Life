
#include "Rules.h"

Rule::Rule() {
    str_rule = "";
    birth = "";
    survival = "";
}

Rule::Rule(const string& rule_str){
    str_rule = rule_str;
    int i = 4;
    while(rule_str[i] != '/'){
        birth += rule_str[i];
        i++;
    }
    i += 2;
    while(i < str_rule.length()){
        survival += str_rule[i];
        i++;
    }
}



Rule::~Rule() = default;

