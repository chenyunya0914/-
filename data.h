#ifndef _DATA_
#define _DATA_
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;

class Funtion {
public:
	vector<int> columns;
	Funtion();
	Funtion(unsigned int);
	~Funtion(); 
	void showFuntion();
	bool addcolumns(unsigned int);
};

class Data {
	string filePath;         //Ĭ���ļ�·��
	vector<string> path;     //�ļ�·��
	vector<Funtion> funtion; //��ȡ�ķ����б�
	int funtionNum;          //Ĭ�Ϸ���
	int intervalTime;        //���ü��ʱ��
	int count;

	vector<string> abnormal;                //�쳣��Ϣ����
	long long num;                          //��¼�쳣�ļ���
	vector<int> datacar;                    //������ 
	vector<int> vectorTmp;                  //����
	map<int,vector<int>> statistics;        //���� ��Ӧ������
	vector<long long>  Sample;

	void setFilePath();                    //�����ļ�·��
	void setExtractFuntion();              //������ȡ����
	void programExec();                    //����ִ��
	void getFiles(string path, vector<string>& files); //��ȡĿ¼���ļ����б�
	void keyDispose(vector<int> &,bool);                  //�ؼ��ִ����� �ؼ�����������
	void dataCheck(ofstream&,string);      //�쳣��� 
	void greateSamples();
public:
	Data();
	void Meun();
};
#endif