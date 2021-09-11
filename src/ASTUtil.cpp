//
// Created by avram on 11.9.21..
//

#include <string>

bool replaceFormat(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
std::string formatRawStr(std::string s) {
    while(replaceFormat(s, "\\\\", "\\")) {}
    while(replaceFormat(s, "\\n", "\n")) {}
    s = s.substr(1, s.size()-2);
    return s;
}