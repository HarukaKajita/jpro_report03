#include "Data.h"


//filename からデータを読み speechdata に格納
void Data::readrawfile(const string& filename) {
	speechfilename = filename;
	ifstream fin(filename.c_str(), ios::binary);	//バイナリ形式でfilenameを開く
	if (!fin) {				//エラー処理
		cerr << "エラー：ファイルを開けません" << filename << "\n";
		exit(EXIT_FAILURE);
	}
	fin.seekg(0, ios_base::end);		//ファイルポインタをファイル末尾に動かす
	int samplesuu = fin.tellg() / sizeof(short);	//データは1サンプル当たりshortで詰まっているため、ファイルサイズをshortのサイズで割ることによりデータの個数を算出する
	memoryalloc(samplesuu);	//speechdataをsamplesuu個だけshortのメモリを確保する
	//これまでの処理でファイルに含まれるデータの個数を計算し、メモリを確保した
	//以下でファイルからデータを読みspeechdataに格納する
	fin.seekg(0, ios_base::beg);//読み込みを行うため、ファイルポインタをファイル冒頭に戻す
	fin.read((char*)speechdata, sizeof(short) * samplesuu);//ファイルからspeechdata配列にsamplesuuの個数分、データを読み込む
}

//speechdataの格納データをfilenameにバイナリ形式で書き込む
void Data::writerawfile(const string& filename) const {
	ofstream fout(filename.c_str(), ios::binary);	//バイナリ形式でfilenameを開く
	if (!fout) {				//エラー処理
		cerr << "エラー：ファイルを開けません" << filename << "\n";
		exit(EXIT_FAILURE);
	}
	
	fout.write((char*)speechdata, sizeof(short) * samplesize);//speechdataをsamplesizeの個数分ファイルに書き込む
}

//speechdata のメモリを、short で memorysize 分確保する
void Data::memoryalloc(const int& memorysize) {
	delete[] this->speechdata;
	this->speechdata = new short[memorysize];
}

//第 1 引数で指定された Data クラスのオブジェクト copymoto のデータメンバ speechdata[start]から
//speechdata[end-1]までを、呼び出し元の speechdata[0]から speechdata[end-start-1]へコピーする。
void Data::copydata(const Data& copymoto, const int& start, const int& end) {
	//end 自身は含まない。つまり start=0,end=10 であれば、コピーされるのは 0 から 9 番目のデータまでである。
	//作成してください。
	this->samplesize = 0;
	for (int i = start; i < end; i++) {
		this->speechdata[samplesize] = copymoto.speechdata[i];
		this->samplesize++;
	}

}

//第 1 引数で指定された Data クラスのオブジェクト catmoto のデータメンバ speechdata[start]から
//speechdata[end-1]までを、speechdata[samplesize]以降に追加する。
void Data::catdata(const Data& catmoto, const int& start, const int& end) {
	//end 自身は含まない。つまり start=0,end=10 であれば、コピーされるのは 0 から 9 番目のデータまでである。
	//作成してください。

	//後半のデータを詰める
	for (int i = start; i < end; i++) {
		this->speechdata[samplesize] = catmoto.speechdata[i];
		this->samplesize++;
	}
}