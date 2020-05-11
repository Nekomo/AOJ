#include <iostream>
#include<vector>
#include<string>
#include <sstream>      // std::ostringstream
using namespace std;
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
const int NOT_FOUND = -1;
int binary_search(vector<int> v, int target);
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
  for (int t : T)
  {
    //cout << "debug : "<<t << endl;
    totalcnt += binary_search(S, t)==NOT_FOUND? 0:1 ;
  }
  cout<<totalcnt<<endl;
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
//二分探索
//startpointとendpointをちょこちょこ更新していく
int binary_search(vector<int> list,int target)
{
  int listsize = list.size();
  int divpoint = listsize / 2;
  int startpoint = 0;
  int endpoint = listsize-1;
  while (true)
  {
    int halfpoint=(startpoint + endpoint) / 2;

    int tmpval = list[halfpoint];
    //cout<<"debug startpoint,endpoint,tmpval :"<<startpoint<<","<< endpoint<< ","<<halfpoint<<endl;
    if (target < tmpval)
    {
      //左側にある
      endpoint = halfpoint;
    }
    else if (target==tmpval)
    {
      //探索終了
      return halfpoint;
    }
    else
    {
      //右側にある
      startpoint = halfpoint;
    }
    //探索範囲が残り1
    if(startpoint==endpoint)
    {
      if (target==list[startpoint])
      {
        //探索終了
        return startpoint;
      }
      return NOT_FOUND;
    }
    //探索範囲が残り2
    else if (endpoint-startpoint==1)
    {
      if (target==list[startpoint])
      {
        //探索終了
        return startpoint;
      }
      if (target==list[endpoint])
      {
        //探索終了
        return endpoint;
      }
      return NOT_FOUND;
    }
  }
}