#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Data {
	string speechfilename; //�f�[�^���i�[�������̓��̓t�@�C����
	short* speechdata; //�f�[�^�̐擪�|�C���^
	int samplesize; //�f�[�^��
public:
	Data() {} //�R���X�g���N�^
	void readrawfile(const string&); //�����t�@�C������f�[�^��ǂ� speechdata �Ɋi�[
	void writerawfile(const string&) const; //speechdata ���o�C�i���`���Ńt�@�C���ɏ�������
	void memoryalloc(const int&); //speechdata �̃��������Ashort �� memorysize ���m�ۂ���
	void copydata(const Data&, const int&, const int&);//�����Ŏw�肳�ꂽ�f�[�^�� speechdata �ɃR�s�[
	void catdata(const Data&, const int&, const int&);//�����Ŏw�肳�ꂽ�f�[�^�� speechdata �ɒǉ�
};