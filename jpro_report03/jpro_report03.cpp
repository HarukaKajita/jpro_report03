#include "Data.h"

int main(int argc, char* argv[]) {
	char* inputfilename1 = NULL; //接続前部の音声ファイル名
	char* inputfilename2 = NULL; //接続後部の音声ファイル名
	char* outputfilename = NULL; //出力ファイル名
	int startsamplesuu1 = 0; //接続前部を利用する際の開始音声サンプル数
	int endsamplesuu1 = 0; //接続前部を利用する際の終了音声サンプル数(この値は含まず)
	int startsamplesuu2 = 0; //接続後部を利用する際の開始音声サンプル数
	int endsamplesuu2 = 0; //接続後部を利用する際の終了音声サンプル数(この値は含まず)
	string filename; //string に変換するための一時ファイル
	Data inputdata1; //接続前部の音声ファイルのデータの格納場所
	Data inputdata2; //接続後部の音声ファイルのデータの格納場所
	//「report4 -P nitech_jp_atr503_m001_a01.raw 0 19410 -F nitech_jp_atr503_m001_a04.raw 52063 70466 -O output.raw」で実行可能なように、argc = 11 の場合のみ動作し、それ以外の時はエラーを出力するようにする。
	//また、argv から、inputfilename1、inputfilename2、outputfilename、startsamplesuu1、endsamplesuu1、startsamplesuu2、endsamplesuu2 の値の取得を行いなさい。
	//さらに、「report4 -O output.raw -P nitech_jp_atr503_m001_a01.raw 0 19410 -F nitech_jp_atr503_m001_a04.raw 52063 70466」のように、順番を変えても同じ動作になるようにしなさい。
	//作成してください。

		//1 つ目の入力ファイルの読み込み
	filename = inputfilename1;
	inputdata1.readrawfile(filename);
	//2 つ目の入力ファイルの読み込み
	filename = inputfilename2;
	inputdata2.readrawfile(filename);

	//音声データの接続
	Data outputdata; //出力ファイルのデータの格納場所
	if ((inputfilename1 != NULL) && (startsamplesuu1 != endsamplesuu1) && (inputfilename2 != NULL) &&
		(startsamplesuu2 != endsamplesuu2)) {
		//出力データを格納するためのメモリを確保する
		outputdata.memoryalloc(endsamplesuu1 - startsamplesuu1 + endsamplesuu2 - startsamplesuu2);
		//inputdata1 の speechdata の 0 から 19409 までを、
		//outputdata の speechdata の 0 から 19409 にコピーする。
		outputdata.copydata(inputdata1, startsamplesuu1, endsamplesuu1);
		//inputdata2 の speechdata の 52063 から 70466 までを、
		//outputdata の speechdata の最後(=この場合 19410)から 18404 個コピーする。
		outputdata.catdata(inputdata2, startsamplesuu2, endsamplesuu2);
	}
	else {
		cerr << "音声を接続する前部・後部の音声ファイル名および開始サンプル数・終了サンプル数を指定してください¥n";
		exit(EXIT_FAILURE);
	}

	//変更したデータをファイルに保存
	if (outputfilename != NULL) {
		filename = outputfilename;
		outputdata.writerawfile(filename);
	}
	else {
		cerr << "outputfilename を指定してください¥n";
		exit(EXIT_FAILURE);
	}
	return 0;
}