#include "Data.h"
//filename からデータを読み speechdata に格納
void Data::readrawfile(const string& filename) {
	speechfilename = filename;
	ifstream fin(filename.c_str(), ios_base::binary); //バイナリ形式で filename を開く
	if (!fin) { //エラー処理
		cerr << "エラー：ファイルを開けません" << filename << "¥n";
		exit(EXIT_FAILURE);
	}
	fin.seekg(0, ios_base::end); //ファイルポインタをファイル末尾に動かす
	int samplesuu = fin.tellg() / sizeof(short); //データは 1 サンプル当たり short で詰まっているため、ファイルサイズを short のサイズで割ることによりデータの個数を算出する
	memoryalloc(samplesuu); //speechdata を samplesuu 個だけ short のメモリを確保する
	//これまでの処理でファイルに含まれるデータの個数を計算し、メモリを確保した
	//以下でファイルからデータを読み speechdata に格納する
	fin.seekg(0, ios_base::beg); //読み込みを行うため、ファイルポインタをファイル冒頭に戻す
	fin.read((char*)speechdata, sizeof(short) * samplesuu);//ファイルから speechdata 配列に samplesuu の個数分、データを読み込む
}
//speechdata の格納データを filename にバイナリ形式で書き込む
void Data::writerawfile(const string& filename) const {
	ofstream fout(filename.c_str(), ios_base::binary);//バイナリ形式で filename を開く
	if (!fout) { //エラー処理
		cerr << "エラー：ファイルを開けません" << filename << "¥n";
		exit(EXIT_FAILURE);
	}
	fout.write((char*)speechdata, sizeof(short) * samplesize);//speechdata を samplesize の個数分ファイルに書き込む
}
//speechdata のメモリを、short で memorysize 分確保する
void Data::memoryalloc(const int& memorysize) {
	//作成してください
}

//第 1 引数で指定された Data クラスのオブジェクト copymoto のデータメンバ speechdata[start]から
//speechdata[end-1]までを、呼び出し元の speechdata[0]から speechdata[end-start-1]へコピーする。
void Data::copydata(const Data& copymoto, const int& start, const int& end) {
	//end 自身は含まない。つまり start=0,end=10 であれば、コピーされるのは 0 から 9 番目のデータまでである。
	//作成してください。
}
//第 1 引数で指定された Data クラスのオブジェクト catmoto のデータメンバ speechdata[start]から
//speechdata[end-1]までを、speechdata[samplesize]以降に追加する。
void Data::catdata(const Data& catmoto, const int& start, const int& end) {
	//end 自身は含まない。つまり start=0,end=10 であれば、コピーされるのは 0 から 9 番目のデータまでである。
	//作成してください。
}