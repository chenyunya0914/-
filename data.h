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
	string filePath;         //默认文件路径
	vector<string> path;     //文件路径
	vector<Funtion> funtion; //提取的方法列表
	int funtionNum;          //默认方法
	int intervalTime;        //设置间隔时间
	int count;

	vector<string> abnormal;                //异常信息容器
	long long num;                          //记录异常文件名
	vector<int> datacar;                    //年月日 
	vector<int> vectorTmp;                  //格子
	map<int,vector<int>> statistics;        //车道 对应车流量
	vector<long long>  Sample;

	void setFilePath();                    //设置文件路径
	void setExtractFuntion();              //设置提取方法
	void programExec();                    //程序执行
	void getFiles(string path, vector<string>& files); //获取目录下文件名列表
	void keyDispose(vector<int> &,bool);                  //关键字处理函数 关键字容器生成
	void dataCheck(ofstream&,string);      //异常检查 
	void greateSamples();
public:
	Data();
	void Meun();
};
#endif