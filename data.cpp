#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>
#include  <direct.h>
#include <regex>
#include "data.h"

using namespace std;

Funtion::Funtion(){ 
	//cout << "Funtion()构造" << endl;
}

Funtion::Funtion(unsigned int n) {
	//cout << "Funtion（unsigned int）构造" << endl;
}

Funtion::~Funtion() {
	//cout << "~Funton()" << endl;
}

void Funtion::showFuntion() {
	for (int i = 0; i < columns.size(); i++) {
		cout << columns[i] << " ";
	}
	cout << endl;
}

bool Funtion::addcolumns(unsigned int n) {
	vector<int>::iterator it = columns.begin();
	it = find(columns.begin(), columns.end(), n);
	if (it == columns.end()) {
	//	cout << "funtion（unsigned int）添加成功" << endl;
		columns.push_back(n);
		return true;
	}
	else {
	//	cout << "funtion（unsigned int）添加失败" << endl;
		return false;
	}
}

Data::Data() : funtionNum(0){
	/*读取配置文件 文件路径初始化*/
	string s;
	char arr[1024];

	getcwd(arr, 1024);
	s = arr;

	int index = s.find_last_of("\\");
	s.erase(index);

	for (index = 0; index = s.find("\\", index); index += 2) {
		if (index == string::npos)
			break;
		s.insert(index, "\\");
	}

	s += "//path_peizhi.txt";
	ifstream outfile(s);
	if (outfile.is_open()) {
	//	cout << "读取配置文件path_peizhi成功" << endl;
	}
	else {
	//	cout << "读取配置文件path_peizhi失败" << endl;
	}
	
	filePath = "C:\\Users\\Public\\Documents\\卡口数据";
	path.push_back("C:\\Users\\Public\\Documents\\卡口数据");
	path.push_back("C:\\Users\\Public\\Documents\\高清电警");
	/*filePath = "E:\\库\\我的文档\\卡口数据";
	path.push_back("E:\\库\\我的文档\\卡口数据");
	path.push_back("E:\\库\\我的文档\\高清电警");*/

	funtionNum = 0;              //设置默认方法

	intervalTime = 5;
	num = 0;
	Funtion funt;

	funtion.push_back(funt);
	funtion[0].addcolumns(2);
	funtion[0].addcolumns(3);
	funtion[0].addcolumns(4);

	funtion.push_back(funt);
	funtion[1].addcolumns(1);
	funtion[1].addcolumns(2);
	funtion[1].addcolumns(3);

}

void Data::Meun() {
	char s = '1';
	while (s) {
	//	system("cls");
		cout << "1、设置默认文件路径";
		cout << "\n当前文件路径为 ：" << filePath;
		cout << "\n2、设置提取数据方法";
		cout << "\n当前提取数据方法 ：" << funtionNum << endl;
		funtion[funtionNum].showFuntion();
		cout << "\n3、设置时间间隔";
		cout << "\n当前时间间隔 ：" << intervalTime;
		cout << "\n4、执行";
		cout << "\n5、生成样本";
		cout << "\n0、退出";
		cout << "\n请选择" << endl;
		cin >> s;
		switch (s) {
			cin.clear();
			case '1':
				setFilePath();
				break;
			case '2':
				setExtractFuntion();
				break;
			case '3':
				cout << "请输入间隔时间" << endl;
				cin >> intervalTime;
				break;
			case '4':
				programExec();
				break;
			case '5':
				greateSamples();
				break;
			case '0':
				cout << "退出成功" << endl;
				s = 0;
				break;
			default :
				break;
		}
	}
}

void Data::setFilePath(){
	vector<string>::iterator it = path.begin();
	string s;
	int num = 0;
	int n = 0;
	while (1){
		system("cls");
		cout << "当前默认路径 ：" << filePath << "\n";
		cout << "路径列表\n";
		for (it = path.begin(), num = 0; !path.empty() && it != path.end(); it++) {
			cout << ++num << " ：" << *it << endl;
		}
		cout << "a : 删除路径\n";
		cout << "b : 新建路径\n";
		cout << "c : 返回上一级\n";
		cout << "请选择" << endl;

		cin >> s;
		cin.clear();

		if (s == "a") {
			if (path.empty()) {
				cout << "没有路径可以删除" << endl;
			}
			cout << "请输入删除路径序号" << endl;
			cin >> n;
			path.erase(path.begin() + n - 1);
			continue;
		}
		else if (s == "b") {
			cout << "请输入新的路径" << endl;
			string str;
			cin >> str;
			path.push_back(str);
			cout << "新建路径成功" << endl;
			continue;
		}
		else if (s == "c") {
			break;
		}

		try {
			n = stoi(s);
		} 
		catch (std::invalid_argument& e){
			cout << "参数未被接受" << endl;
			_sleep(1000);
			continue;
		}
	    catch (std::out_of_range& e){
			cout << "数据溢出" << endl;
			_sleep(1000);
			continue;
		}
		n = stoi(s);
		if (n <= 0 || n > num) {
			cout << "没有找到该路径" << endl;
			_sleep(1000);
			continue;
		}
		filePath = path[n-1];
		break;
	}
}

void Data::setExtractFuntion()
{
	string s;
	int n;
	while (1) {
		s.clear();
		for (int i = 0; i < funtion.size(); i++) {
			cout << "方法 : " << i << "\t";
			for (int j = 0; j < funtion[i].columns.size(); j++) {
				cout << funtion[i].columns[j] << " ";
			}
			cout << endl;
		}
		cout << "a、新建方法" << endl;
		cout << "b、删除方法" << endl;
		cout << "c、修改方法" << endl;
		cout << "d、返回上一级" << endl;
		cin >> s;
		cin.clear();
		if(s == "a") {
			cout << "请输入列数" << endl;
			Funtion funt;
			int n;
			while (cin >> n) {
				if (n == -1)
					break;
				funt.addcolumns(n);
			}
			funtion.push_back(funt);
			continue;
		}
		else if(s == "b") {
			if (funtion.empty()) {
				cout << "没有方法可以删除" << endl;
				continue;
			}
			cout << "输入删除序号" << endl;
			int n;
			cin >> n;
			if (n >= 0 && n < funtion.size()) {
				cout << n << "\t" << funtion.size() << endl;
				funtion.erase(funtion.begin() + n);
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
		}
		else if (s == "c") {

		}
		else if (s == "d") {
			return;
		}
		funtionNum = stoi(s);
		return;
	}
}

void Data::programExec() {
	/*清空异常容器*/
	abnormal.clear();
	/*设置格子*/
	vectorTmp.resize(60 * 24 / intervalTime,0);
	/*获取文件列表*/
	vector<string> fileList;
	getFiles(filePath, fileList);
	if (fileList.empty()) {
		cout << "目录下没有找到文件" << endl;
		return;
	}
	/*创建目标目录*/
	string newPath = filePath + "_生成数据";
	mkdir(newPath.c_str());

	string abnormalstr = filePath + "_异常信息";
	mkdir(abnormalstr.c_str());

	ifstream infile;
	ofstream outfile;
	string input;
	vector<string> instr;           //分段
	vector<int> datatemp;
	int index;
	int temp;

	for (vector<string>::iterator it = fileList.begin(); it != fileList.end(); it++) {
		statistics.clear();
		datacar.clear();
		
		infile.open(*it);
		if (infile.is_open()) {
			cout << "打开文件成功" << *it << endl;
		}
		else {
			cout << "打开文件失败" << endl;
			Sleep(1000);
			return;
		}
		abnormal.push_back(*it);

		index = it->rfind("\\");
		it->insert(index, "_生成数据");
		outfile.open(*it);
		if (outfile.is_open()) {
			cout << "打开写入文件成功" << *it << endl;
		}
		else {
			cout << "打开写入文件失败" << endl;
		}

		count = 0;
		int n = 0;
		while (getline(infile, input)) {
			datatemp.clear();
			instr.clear();
			count++;
			/*分段*/
			for (int index = 0, temp = 0; temp = index, index = input.find(",", index); index++) {
				if (index == string::npos) {
					instr.push_back(input.substr(temp));
					break;
				}
				instr.push_back(input.substr(temp, index - temp));
			}
			/*拆分放入vector<int> datatemp*/
			/*2018 6 11 12 58 1.2 570412 4,*/
			for (int i = 0; i < funtion[funtionNum].columns.size(); i++) {
				string &tmp = instr[funtion[funtionNum].columns[i]];
				if (i == 0) {
					for (string::iterator it1 = tmp.begin(); it1 != tmp.end(); it1++) {
						if (*it1 == '/' || *it1 == ':' || *it1 == ' ' || *it1 == '-') {
							tmp.replace(it1, it1 + 1, ",");
						}
					}
					for (int index = 0, temp = 0; temp = index, index = tmp.find(",", index); index++) {
						if (index == string::npos) {
							string &s = tmp.substr(temp);
							for (auto &s : s) {
								if (s > 57 || s < 48) {
									abnormal.push_back("原始数据第" + to_string(count) + "行,存在非法字符");
								}
							}
							datatemp.push_back(stoi(tmp.substr(temp)));
							break;
						}	
						string &s = tmp.substr(temp,index-temp);
						for (auto &s : s) {
							if (s > 57 || s < 48) {
								abnormal.push_back("原始数据第" + to_string(count) + "行,存在非法字符");
							}
						}
						datatemp.push_back(stoi(tmp.substr(temp, index - temp)));
					}
					i++;
					continue;
				}
				datatemp.push_back(stoi(tmp));
			}
			if (datatemp.size() == 8)
				datatemp.erase(datatemp.begin() + 5, datatemp.begin() + 6);

			keyDispose(datatemp,true);                             //传字段
		}
		
		dataCheck(outfile,*it);                                    //异常检查
		
		/*异常信息大于5000条写入文件*/
		if (abnormal.size() > 5000) {
			++num;
			string abnormalFile = abnormalstr + "\\异常信息" + to_string(num) + ".csv";
			ofstream inabnormal(abnormalFile);
			if (inabnormal.is_open()) {
				cout << "异常文件打开成功" << endl;
				for (vector<string>::iterator it = abnormal.begin(); it != abnormal.end(); it++) {
					inabnormal << *it << endl;
				}
			}
			else {
				cout << "异常文件打开失败" << endl;
			}
		}
		infile.close();
		outfile.close();
	}
	++num;
	string abnormalFile = abnormalstr + "\\异常信息" + to_string(num) + ".csv";
	ofstream inabnormal(abnormalFile);
	if (inabnormal.is_open()) {
		cout << "异常文件打开成功" << endl;
		for (vector<string>::iterator it = abnormal.begin(); it != abnormal.end(); it++) {
			inabnormal << *it << endl;
		}
	}
}

void Data::keyDispose(vector<int> &temp,bool on_off)
{
	if (datacar.empty()) {
		datacar.push_back(temp[0]);
		datacar.push_back(temp[1]);
		datacar.push_back(temp[2]);
		datacar.push_back(temp[5]);
	}

	if (temp[1] > 12 || temp[1] < 0 || temp[2] > 31 || temp[2] < 0 || temp[3] > 23 || temp[3] < 0 || temp[4] > 59 || temp[4] < 0 && on_off) {
		abnormal.push_back("原始数据第" + to_string(count) + "行,时间范围异常");
		return ;
	}
	map<int, vector<int>>::iterator it = statistics.begin();
	it = statistics.find(temp[6]);
	if (it == statistics.end())
		statistics.insert(make_pair(temp[6], vectorTmp));

	int datatime =  temp[3] * 60 + temp[4];
	datatime -= datatime %intervalTime;
	statistics[temp[6]][datatime / intervalTime] += 1;

	return ;
}

void Data::dataCheck(ofstream  &outfile,string filename) {
	map<int, vector<int>>::iterator it = statistics.end();
	it--;
	string temp1("车道数分别是,");
	string temp2("车道数可能缺失,");
	
	if (it->first != statistics.size()) {
		if (it->first >= 9)
			abnormal.push_back("存在最大车道数大于或等于9，可能是异常数据");
		vector<bool> lu;
		lu.resize(it->first, false);
		for (map<int, vector<int>>::iterator ie = statistics.begin(); ie != statistics.end(); ie++) {

			lu[ie->first-1] = true;
		}
		int conut = 0;
		for (vector<bool>::iterator ie = lu.begin(); ie != lu.end(); ie++) {
			if (*ie == true) {
				temp1 += to_string(conut+1) + ",";
			}
			else {
				temp2 += to_string(conut+1) + ",";
			}
			conut++;
		}
		abnormal.push_back(temp1);
		abnormal.push_back(temp2);
	}
	vector<long long>::iterator is = Sample.begin();
	vector<double> num;
	int biaozhun;
	for (map<int, vector<int>>::iterator it = statistics.begin(); it != statistics.end(); it++) {
		int gezi = 0;
		for (vector<int>::iterator ie = it->second.begin(); ie != it->second.end(); ie++) {
			++gezi;
			int hour = gezi*intervalTime / 60;
			int mimute = gezi*intervalTime % 60;//值
			if (*ie > 180*intervalTime) {
				string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "数值偏大");
				abnormal.push_back(s);
			}
			if (!Sample.empty()) {
				cout << *ie - *is << endl;
				if (abs(*ie - *is) > 50) {
					string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "与样本曲线相差较大，" + "差值为," + to_string((*ie - *is)));
					abnormal.push_back(s);
				}
				is++;
			}
			num.push_back(*ie);
			if (num.size() == 4) {
				biaozhun = ((num[2] + num[1]) / 2 - (num[1] + num[0]) / 2) * 3 / 2 + (num[2] + num[1]) / 2;
				if (abs(biaozhun - *ie) > 100) {
					string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "突变," + "差值为," + to_string((*ie)) + "-" + to_string(biaozhun) + "=," + to_string(biaozhun - *ie) + "," + to_string(num[0]) + "," + to_string(num[1]) + "," + to_string(num[2]));
					abnormal.push_back(s);
					if (*ie == 0 && hour >= 5 && hour <24) {
						int count = 0;
						for (vector<int>::iterator is = ie; *is == 0; is++) {
							count++;
						}
						if (count*intervalTime >= 10) {
							string &s1(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "可能存在数据缺失，" + "时长为，" + to_string(count*intervalTime));
							abnormal.push_back(s1);
						}
					}
					else if (hour < 6 && hour >0) {
						if (count*intervalTime > 20) {
							string &s1(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "可能存在数据异常峰值，" + "时长为，" + to_string(count*intervalTime));
							abnormal.push_back(s1);
						}
					}
				}
				num.erase(num.begin(),num.begin()+1);
			}
		}
	}
	
	for (map<int, vector<int>>::iterator it = statistics.begin(); it != statistics.end(); it++) {
		for (vector<int>::iterator ie = it->second.begin(); ie != it->second.end(); ie++) {
			outfile << datacar[0] << "," << datacar[1] << "," << datacar[2] << "," << (ie - it->second.begin())*intervalTime / 60 << "," << (ie - it->second.begin())*intervalTime % 60 << "," << datacar[3] << "," << it->first << "," << *ie << ","  << endl;
		}
	}
}

void Data::greateSamples()
{
	cout << "请输入样本目录" << endl;
	string samplePath("C:\\Users\\Public\\Documents\\卡口数据");
	/*设置格子*/
	vectorTmp.resize(60 * 24 / intervalTime, 0);
	/*获取文件列表*/
	vector<string> fileList;
	getFiles(samplePath, fileList);
	if (fileList.empty()) {
		cout << "目录下没有找到文件" << endl;
		return;
	}

	ifstream infile;
	string input;
	vector<string> instr;           //分段
	vector<int> datatemp;
	int index;
	int temp;

	for (vector<string>::iterator it = fileList.begin(); it != fileList.end(); it++) {
		statistics.clear();
		datacar.clear();
		count = 0;

		infile.open(*it);
		if (infile.is_open()) {
			cout << "打开文件成功" << *it << endl;
		}
		else {
			cout << "打开文件失败" << endl;
			Sleep(1000);
			return;
		}

		while (getline(infile, input)) {
			datatemp.clear();
			instr.clear();
			count++;
			/*分段*/
			for (int index = 0, temp = 0; temp = index, index = input.find(",", index); index++) {
				if (index == string::npos) {
					instr.push_back(input.substr(temp));
					break;
				}
				instr.push_back(input.substr(temp, index - temp));
			}
			/*拆分放入vector<int> datatemp*/
			/*2018 6 11 12 58 1.2 570412 4,*/
			for (int i = 0; i < funtion[funtionNum].columns.size(); i++) {
				string &tmp = instr[funtion[funtionNum].columns[i]];
				if (i == 0) {
					for (string::iterator it = tmp.begin(); it != tmp.end(); it++) {
						if (*it == '/' || *it == ':' || *it == ' ' || *it == '-') {
							tmp.replace(it, it + 1, ",");
						}
					}
					for (int index = 0, temp = 0; temp = index, index = tmp.find(",", index); index++) {
						string &s = tmp.substr(temp, index - temp);
						for (auto &s : s) {
							if (s > 57 || s < 48) {
								cout << "原始数据第" + to_string(count) + "行,存在非法字符" << "\t" << s << endl;
							}
						}
						if (index == string::npos) {
							string &s = tmp.substr(temp);
							for (auto &s : s) {
								if (s > 57 || s < 48) {
									cout << "原始数据第" + to_string(count) + "行,存在非法字符" << "\t" << s << endl;
								}
							}
							datatemp.push_back(stoi(tmp.substr(temp)));
							break;
						}
						datatemp.push_back(stoi(tmp.substr(temp, index - temp)));
					}
					continue;
				}
				datatemp.push_back(stoi(tmp));
			}
			if (datatemp.size() == 8)
				datatemp.erase(datatemp.begin() + 5, datatemp.begin() + 6);
			if (datatemp[1] > 12 || datatemp[1] < 0 || datatemp[2] > 31 || datatemp[2] < 0 || datatemp[3] > 23 || datatemp[3] < 0 || datatemp[4] > 59 || datatemp[4] < 0) {
				cout << "原始数据第" + to_string(count) + "行,时间范围异常" << endl;
				return;
			}
			keyDispose(datatemp,false);                                  //传字段
		}
		infile.close();
		if (Sample.empty()) {
			for (map<int, vector<int>>::iterator ie = statistics.begin(); ie != statistics.end(); ie++) {
				for (vector<int>::iterator is = ie->second.begin(); is != ie->second.end(); is++) {
					Sample.push_back(*is);
				}
			}
		}
		else {
			vector<long long>::iterator ia = Sample.begin(); 
			for (map<int, vector<int>>::iterator ie = statistics.begin(); ie != statistics.end(); ie++) {
				for (vector<int>::iterator is = ie->second.begin(); is != ie->second.end(); is++) {
					*ia += *is;
					ia++;
				}
			}
		}
	}
}

void Data::getFiles(string path, vector<string>& files)
{
	//文件句柄  
    long   hFile = 0;
	//文件信息  
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
    do
	{
	//如果是目录,迭代之  
	//如果不是,加入列表  
		if ((fileinfo.attrib &  _A_SUBDIR))
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
		}
		else
		{
			files.push_back(p.assign(path).append("\\").append(fileinfo.name));
		}
	}while (_findnext(hFile, &fileinfo) == 0);
	_findclose(hFile);
	}
}

