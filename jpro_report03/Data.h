#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Data {
	string speechfilename; //データを格納した元の入力ファイル名
	short* speechdata; //データの先頭ポインタ
	int samplesize; //データ数
public:
	Data() {} //コンストラクタ
	void readrawfile(const string&); //音声ファイルからデータを読み speechdata に格納
	void writerawfile(const string&) const; //speechdata をバイナリ形式でファイルに書き込む
	void memoryalloc(const int&); //speechdata のメモリを、short で memorysize 分確保する
	void copydata(const Data&, const int&, const int&);//引数で指定されたデータを speechdata にコピー
	void catdata(const Data&, const int&, const int&);//引数で指定されたデータを speechdata に追加
};