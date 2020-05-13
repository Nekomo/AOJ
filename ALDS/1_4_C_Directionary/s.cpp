#include<iostream>
#include<string.h>
#include <stdio.h>
#include<vector>
#include<string>
#include <sstream>      // std::ostringstream

//文字列化演算子
#define STR(str) #str

using namespace std;
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
int hash(string s);
bool find(string *,int, string);
void insert(string *,int, string);

const int HASHDIV = 1046527;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  string line = "";
  getline(cin, line);
  int ordersize =stoi(line);
  string *hashed_data  = new string[HASHDIV];
  for (int i = 0; i < HASHDIV;i++)
  {
    hashed_data[i] = "";
  }
  string order ;
  string target ;
  for (int i = 0; i < ordersize ; i++)
  {
    cin >> order;
    cin >> target;

    if (order=="insert")
    {
      insert(hashed_data,ordersize,target);
    }
    else if (order=="find")
    {
      if(find(hashed_data, ordersize,string(target)))
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
  }
  delete[](hashed_data);
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

int geneToKey(string s)
{
  int key = 0;
  //ATGCを4進数とみて10進数に変換する
  for(char c : s)
  {
    key *= 4;
    if (c == 'A')
    {
      key += 0;
    }
    else if (c=='T')
    {
      key += 1;
    }
    else if (c=='G')
    {
      key += 2;
    }
    else if (c=='C')
    {
      key += 3;
    }
  }
  return key;
}
int h1(int key)
{
  return key % HASHDIV;
}
int h2(int key)
{
  return 1 + key % (HASHDIV-1);
}
int hashnize(int unhashedkey,int i)
{
  return (h1(unhashedkey) + i * h2(unhashedkey)) % HASHDIV;
}
void insert(string * list,int listsize, string target)
{
  int key = geneToKey(target);
  for (int i = 0;i<listsize;i++)
  {
    int hashedkey = hashnize(key,i);
    //cout << hashedkey << endl;
    if (list[hashedkey]=="")
    {
      //cout << endl;
      list[hashedkey] = target;
      return;
    }
  }
  //insert不能
  printf("挿入に失敗しました : 空きスペースがありません！");
  exit(-1);
}
bool find(string *list,int listsize , string target)
{
  int key = geneToKey(target);
  for (int i = 0;i<listsize;i++)
  {
    int hashedkey = hashnize(key,i);
    if (list[hashedkey]==target)
    {
      return true;
    }
    if (list[hashedkey]=="")
    {
      return false;
    }
  }
  return false;
}