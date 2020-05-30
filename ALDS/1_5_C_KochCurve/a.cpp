#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <sstream>      // std::ostringstream
using namespace std;
vector<string> split_s(const string &str, char sep);
vector<int> split_i(const string &str, char sep);
void draw_kochcurve(double x1, double y1, double x2, double y2, int restdrawtimes);
void draw_kochcurve_rec(double x1, double y1, double x2, double y2, int restdrawtimes);
const double ROOT3 = 1.7320508;
int main()
{
  string line="";
  cin >> line;
  int drawtimes = stoi(line);

  vector<double> startx;
  startx.reserve(2);
  vector<double> starty;
  starty.reserve(2);

  //始点
  startx.push_back(0.0);
  starty.push_back(0.0);
  
  //終点
  startx.push_back(100.0);
  starty.push_back(0.0);

  //再帰によりコッホ曲線を描画
  //draw_kochcurve(startx, starty, drawtimes);
  draw_kochcurve(0, 0, 100, 0, drawtimes);
}
void draw_kochcurve(double x1,double y1,double x2,double y2,int restdrawtimes)
{
  draw_kochcurve_rec(x1, y1, x2, y2, restdrawtimes);
  printf("%f %f\n", x2,y2);
}
//2辺に対し，内部にコッホ曲線をn回描いたとき，曲線を構成する頂点群を出力するメソッド
void draw_kochcurve_rec(double x1,double y1,double x2,double y2,int restdrawtimes)
{
  if (restdrawtimes == 0)
  {
      //前エッジのみ描画する(後ろエッジまで描画すると描画がダブってしまう)ことに注意！
      printf("%f %f\n", x1,y1);
  }
  else
  {
    //前エッジ
    double x_1 = (x1 * 2 + x2) / 3;
    double y_1 = (y1 * 2 + y2) / 3;
    //後エッジ
    double x_3 = (x1 + 2 * x2) / 3;
    double y_3 = (y1 + 2 * y2) / 3;
    //中エッジ
    double x_2=(x_1 + x_3 - ROOT3  * (y_3 - y_1))/2;
    double y_2=(y_1+ y_3+ ROOT3 * (x_3 - x_1))/2;

/*
      printf("{1,_1,_2,_3,2} = {\n%f %f\n%f %f\n%f %f\n%f %f\n%f %f\n }\n\n", 
      x1,y1,
      x_1,y_1,
      x_2,y_2,
      x_3,y_3,
      x2,y2
      );
*/

    //各エッジ間に対して再帰的にコッホ曲線を描く
    draw_kochcurve_rec(x1,y1,x_1,y_1, restdrawtimes - 1);
    draw_kochcurve_rec(x_1,y_1,x_2,y_2, restdrawtimes - 1);
    draw_kochcurve_rec(x_2,y_2,x_3,y_3, restdrawtimes - 1);
    draw_kochcurve_rec(x_3,y_3,x2,y2, restdrawtimes - 1);
  }
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