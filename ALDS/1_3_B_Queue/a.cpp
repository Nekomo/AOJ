#include <iostream>
#include <queue>
#include <regex>
#include <vector>
#include <string>
#include <sstream>      // std::ostringstream
using namespace std;
vector<string> split(const string &str, char sep);

//queue
queue<int> qi;
queue<string> qs;
int main(void)
{
  string line = "";
  //改行も含めてfirstlineにブチ込む
  getline(cin, line);
  vector<string> linevec = split(line,' ');
  int rowsize = stoi(linevec[0]);
  int p = stoi(linevec[1]);
  //cout << "rowsize:" << rowsize << endl;
  //cout << "p:" << p << endl;
  for (int i = 0; i < rowsize;i++)
  {
    getline(cin, line);
    vector<string> linevec = split(line,' ');
    qs.push(linevec[0]);
    int process_time = stoi(linevec[1]);
    qi.push(process_time);
  }
  int tmptime = 0;
  while (qi.size() > 0)
  {
    //実行する
    int processing_time = qi.front();
    qi.pop();
    string processing_name = qs.front();
    qs.pop();
    if (processing_time<=p)
    {
      tmptime += processing_time;
      cout <<processing_name<<' '<< tmptime << endl;
    }
    else
    //この実行ではプロセス実行を完了できない
    {
      tmptime += p;
      processing_time -= p;
      qi.push(processing_time);
      qs.push(processing_name);
    }
  }
}
vector<string> split(const string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}