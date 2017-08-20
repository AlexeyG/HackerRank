#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <sstream>
#include <map>

struct Attribute {
    std::string name;
    std::string value;
};

struct Tag {
    std::string name;
    bool is_close;
    std::vector<Attribute> atts;
};

bool is_tag(const std::string &line, int &i, int &j, int n) {
    while (i < n && line[i] != '<')
        ++i;
    while (j >= 0 && line[j] != '>')
        --j;
    ++i, --j;
    return i <= j;
}

bool is_close_tag(const std::string &line, int &i, int j) {
    bool ans = (i < j) && (line[i] == '/');
    if (ans) ++i;
    return ans;
}

std::string get_next_string(const std::string &line, int &i, int j) {
    int i2 = i;
    while (i2 <= j && line[i2] != ' ')
        ++i2;
    std::string ans = line.substr(i, i2 - i);
    i = i2;
    return ans;
}

void strip(const std::string &line, int &i, int &j) {
    while (i <= j && line[i] == ' ')
        ++i;
    while (j >= 0 && line[j] == ' ')
        --j;
}

bool get_attribute(const std::string &line, int &i, int j, Attribute &att) {
    strip(line, i, j);
    if (i >= j)
        return false;
    std::string name = get_next_string(line, i, j);
    strip(line, i, j);
    if (i >= j)
        return false;
    if (line[i++] != '=')
        return false;
    strip(line, i, j);
    std::string value = get_next_string(line, i, j);
    if (value[0] != '"' || value[value.length() - 1] != '"')
        return false;
    value = value.substr(1, value.length() - 2);
    strip(line, i, j);

    att.name = name;
    att.value = value;
    return true;
}

Tag parse_tag(const std::string &line) {
    std::vector<Attribute> atts;
    Attribute att;
    bool is_close;
    std::string tag_name;
    int n = line.length();

    int i = 0, j = n;
    if (is_tag(line, i, j, n)) {
        is_close = is_close_tag(line, i, j);
        tag_name = get_next_string(line, i, j);
        while (get_attribute(line, i, j, att))
            atts.push_back(att);
    } else {
        throw new std::exception();
    }
    Tag tag;
    tag.name = tag_name;
    tag.is_close = is_close;
    tag.atts = atts;
    return tag;
}

std::string construct_prefix(const std::vector<std::string> &open_tags) {
    std::stringstream prefix_stream;
    for (auto it = open_tags.begin(); it != open_tags.end(); ++it) {
        prefix_stream << *it;
        if (it + 1 != open_tags.end())
            prefix_stream << ".";
    }
    return prefix_stream.str();
}

void expand_attributes(const Tag &tag,
                       const std::vector<std::string> &open_tags,
                       std::map<std::string, std::string> &att_map) {
    std::string prefix = construct_prefix(open_tags) + "~";
    for (auto att : tag.atts) {
        std::string key = prefix + att.name;
        att_map[key] = att.value;
        //std::cout << "adding " << key << " = " << att.value << std::endl;
    }
}

std::string parse_query(const std::string &query, std::map<std::string, std::string> att_map) {
    auto it = att_map.find(query);
    if (it == att_map.end())
        return "Not Found!";
    return it->second;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> open_tags;

    std::map<std::string, std::string> att_map;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        Tag tag = parse_tag(line);
        if (!tag.is_close)
            open_tags.push_back(tag.name);
        else {
            if (open_tags.empty() || *(open_tags.end() - 1) != tag.name)
                throw std::exception();
            open_tags.pop_back();
        }
        if (!tag.is_close)
            expand_attributes(tag, open_tags, att_map);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> line;
        std::cout << parse_query(line, att_map) << std::endl;
    }

    return 0;
}
