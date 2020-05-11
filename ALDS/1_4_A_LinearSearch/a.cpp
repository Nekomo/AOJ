#include <iostream>
#include<vector>
#include<string>
#include <sstream>      // std::ostringstream
using namespace std;
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
const int NOT_FOUND = -1;
int linear_search(vector<int> v, int target);
int linear_search_custom(vector<int> list, int target);
int main()
{
  string line;
  //S
  getline(cin, line);
  int ssize = stoi(line);
  getline(cin, line);
  vector<int>S= split_i(line, ' ');
  //T
  getline(cin, line);
  int tsize = stoi(line);
  getline(cin, line);
  vector<int>T= split_i(line, ' ');

  int totalcnt = 0;
  for (int t:T)
  {
    totalcnt += linear_search_custom(S, t)==NOT_FOUND? 0:1 ;
  }
  printf("%d\n", totalcnt);
}
vector<string> split_s(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}
vector<int> split_i(const string &str, char sep)
{
  vector<int> veci;
  vector<string> vecs = split_s(str, sep);
  for(string s:vecs)
  {
    veci.push_back(stoi(s));
  }
  return veci;
}
//list内のfindの数を線形探索
int linear_search(vector<int> list,int target){
  int cnt = 0;
  for (int i : list)
  {
    if (i==target)
    {
      cnt++;
    }
  }
  return cnt;
}
//番兵版．インデックスを返させる
int linear_search_custom(vector<int> list,int target){
  int i= 0;
  //リスト追加
  int listsize = list.size();
  list.push_back(target);
  while (true)
  {
    if(list[i]==target)
      break;
    i++;
  }
  //番兵なら
  if (i==listsize)
  {
    return NOT_FOUND;
  }
  return i;
}