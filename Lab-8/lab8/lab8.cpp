
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
struct compare
{
    bool operator() (std::pair<std::string,int> a,std::pair<std::string,int> b) const
    {
        return a.second < b.second;
    }
};
void _toLower(std::string &s)
{
    for (char &c : s)
        c = tolower(c);
}
int main(int argc, char* argv[])
{
    std::ifstream file("file.txt");
    std::string s;
    std::string pattern = " ,!?.";
    std::map<std::string,int> map;
    getline(file, s);
    int pos = 0;
    while (pos < s.size())
    {
        int start = s.find_first_not_of(pattern, pos);
        int end = s.find_first_of(pattern, start);
        std::string substring = s.substr(start, end - start);
        _toLower(substring);
        map[substring]++;
        pos = end;
    }
    std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,compare> queue;
    for (auto i:map)
        queue.push({i.first, i.second});
    while (!queue.empty())
    {
        std::cout << queue.top().first <<" => "<< queue.top().second << std::endl;
        queue.pop();
    }
    return 0;
}
