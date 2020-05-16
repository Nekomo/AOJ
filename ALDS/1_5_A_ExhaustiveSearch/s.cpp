#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <sstream>      // std::ostringstream
using namespace std;
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
bool exhaustive_searcher(vector<int> list, int subtracted);

int main()
{
  string line;
  getline(cin, line);
  int n = stoi(line);
  getline(cin, line);
  vector<string> Ast = split_s(line, ' ');
  vector<int> A;
  for(string ast:Ast)
  {
    A.push_back(stoi(ast));
  }
  getline(cin, line);
  int q = stoi(line);

  getline(cin, line);
  vector<string> Mst = split_s(line, ' ');
  for(string mst:Mst)
  {
    if (exhaustive_searcher(A,stoi(mst)))
    {
      printf("yes\n");
    }
    else
    {
      printf("no\n");
    }
  } 
}
bool exhaustive_searcher(vector<int> list,int subtracted){
  if (subtracted<0)
  {
    return false;
  }
  if(subtracted==0){
    return true;
  }
  if(list.size()==1){
    if(list[0]==subtracted){
      return true;
    }
    else
    {
      return false;
    }
  }
  vector<int>copied;
  //サイズを合わせないとSegmentation Error
  copied.resize(list.size()-1);
  copy_n(list.begin()+1,list.size()-1, copied.begin());

  //含む
  return exhaustive_searcher(copied,subtracted-list[0])||
  //含まない
  exhaustive_searcher(copied,subtracted);
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