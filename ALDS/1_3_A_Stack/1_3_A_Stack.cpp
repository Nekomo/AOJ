#include <iostream>
#include <stack>
#include <regex>
#include <vector>
#include <string>
#include <sstream>      // std::ostringstream
using namespace std;
std::vector<std::string> split(const std::string &str, char sep);
int main(void)
{
  stack<int> st;
  regex re(R"(^\d+$)");
  string l;
  getline(cin,l);
  vector<string> lvec = split(l, ' ');
  //cout << lvec.size() << endl;
  for (string c : lvec)
  {
    //数字?
    if(regex_match(c,re))
    {
      int newnum = stoi(c);
      st.push(newnum);
      continue;
    }
    //そうでなければ演算子
    //共通処理
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    if (c=="+")
    {
      st.push(a + b);
    }
    else if (c=="*")
    {
      st.push(a * b);
    }
    else
    {
      st.push(b-a);
    }
  }
  cout << st.top() << endl;
}
std::vector<std::string> split(const std::string &str, char sep)
{
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while( std::getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}