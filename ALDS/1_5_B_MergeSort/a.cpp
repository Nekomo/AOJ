#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <sstream>      // std::ostringstream
#include<climits>
using namespace std;
int merge(vector<int> &a,int left,int mid,int right);
int mergeSort(vector<int> &a, int left, int right);
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
vector<int> split_i(const string &str)
{
  return split_i(str, ' ');
}
int main()
{
  string line;
  getline(cin, line);
  int size=stoi(line);
  vector<int> a;
  getline(cin, line);
  a = split_i(line, ' ');
  int hikakucnt=mergeSort(a, 0, size);
  line = "";
  for (int i = 0; i < a.size();i++)
  {
    line+=to_string(a[i]);
    if (i==a.size()-1)
    {
      break;
    }
    line += " ";
  }

  printf("%s",line.c_str());
  printf("\n");
  printf("%d", hikakucnt);
  printf("\n");
}
//文字列を分割して取得
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
  stringstream ss(str);
  string buffer;
  while( getline(ss, buffer, sep) ) {
    veci.push_back(stoi(buffer));
  }
  return veci;
}
int merge(vector<int> &a,int left,int mid,int right)
{
  //printf("left,mid,right = %d,%d,%d  before : \n", left, mid, right);
  /*
  for(int i:a)
  {
    printf("%d ", i);
  }
  printf("\n");
  */
  vector<int> l;
  //l.resize(mid-left+1);
  for (int a_index = left; a_index < mid;a_index++)
  {
    //printf("l,a=%d,%d", l[a_index - left], a[a_index]);
    l.push_back(a[a_index]);
  }
    vector<int> r;
  //r.resize(right - mid+1);
  for (int a_index = mid; a_index < right; a_index++)
  {
    r.push_back(a[a_index]);
  }
  //copy(a.begin() + left, a.begin() + mid, l.begin());
  //copy(a.begin() + mid,a.begin()+right,r.begin());
  //printf("%d",INT_MAX);//2147483647
  l.push_back(INT_MAX);
  r.push_back(INT_MAX);
  /*
  for(int l_ :l)
  {
    printf("%d ", l_);
  }
  printf("\n");
  for(int l_ :r)
  {
    printf("%d ", l_);
  }
  printf("\n");
  */
  int l_i = 0;
  int r_i = 0;
  int hikakucnt = 0;
  for (int i = left; i < right; i++)
  {
    int min;
    hikakucnt++;
    if (l.at(l_i) < r.at(r_i))
    {
      min = l.at(l_i);
      l_i++;
    }
    else
    {
      min = r.at(r_i);
      r_i++;
    }
    a[i] = min;
  }
  //printf("left,mid,right = %d,%d,%d  after : \n", left, mid, right);
  /*
  for(int i:a)
  {
    printf("%d ", i);
  }
  printf("\n");
  */
  return hikakucnt;
}
int mergeSort(vector<int> &a, int left,int right)
{
  int hikakucnt = 0;
  if (right - left > 1)
  {
    int mid = (left + right) / 2;
    //printf("left,mid,right = %d,%d,%d\n ", left, mid, right);
    hikakucnt+=mergeSort(a, left, mid);
    hikakucnt+=mergeSort(a,mid,right);
    hikakucnt+=merge(a, left, mid, right);
  }
  return hikakucnt;
}
