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
	//cout << "Funtion()����" << endl;
}

Funtion::Funtion(unsigned int n) {
	//cout << "Funtion��unsigned int������" << endl;
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
	//	cout << "funtion��unsigned int����ӳɹ�" << endl;
		columns.push_back(n);
		return true;
	}
	else {
	//	cout << "funtion��unsigned int�����ʧ��" << endl;
		return false;
	}
}

Data::Data() : funtionNum(0){
	/*��ȡ�����ļ� �ļ�·����ʼ��*/
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
	//	cout << "��ȡ�����ļ�path_peizhi�ɹ�" << endl;
	}
	else {
	//	cout << "��ȡ�����ļ�path_peizhiʧ��" << endl;
	}
	
	filePath = "C:\\Users\\Public\\Documents\\��������";
	path.push_back("C:\\Users\\Public\\Documents\\��������");
	path.push_back("C:\\Users\\Public\\Documents\\����羯");
	/*filePath = "E:\\��\\�ҵ��ĵ�\\��������";
	path.push_back("E:\\��\\�ҵ��ĵ�\\��������");
	path.push_back("E:\\��\\�ҵ��ĵ�\\����羯");*/

	funtionNum = 0;              //����Ĭ�Ϸ���

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
		cout << "1������Ĭ���ļ�·��";
		cout << "\n��ǰ�ļ�·��Ϊ ��" << filePath;
		cout << "\n2��������ȡ���ݷ���";
		cout << "\n��ǰ��ȡ���ݷ��� ��" << funtionNum << endl;
		funtion[funtionNum].showFuntion();
		cout << "\n3������ʱ����";
		cout << "\n��ǰʱ���� ��" << intervalTime;
		cout << "\n4��ִ��";
		cout << "\n5����������";
		cout << "\n0���˳�";
		cout << "\n��ѡ��" << endl;
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
				cout << "��������ʱ��" << endl;
				cin >> intervalTime;
				break;
			case '4':
				programExec();
				break;
			case '5':
				greateSamples();
				break;
			case '0':
				cout << "�˳��ɹ�" << endl;
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
		cout << "��ǰĬ��·�� ��" << filePath << "\n";
		cout << "·���б�\n";
		for (it = path.begin(), num = 0; !path.empty() && it != path.end(); it++) {
			cout << ++num << " ��" << *it << endl;
		}
		cout << "a : ɾ��·��\n";
		cout << "b : �½�·��\n";
		cout << "c : ������һ��\n";
		cout << "��ѡ��" << endl;

		cin >> s;
		cin.clear();

		if (s == "a") {
			if (path.empty()) {
				cout << "û��·������ɾ��" << endl;
			}
			cout << "������ɾ��·�����" << endl;
			cin >> n;
			path.erase(path.begin() + n - 1);
			continue;
		}
		else if (s == "b") {
			cout << "�������µ�·��" << endl;
			string str;
			cin >> str;
			path.push_back(str);
			cout << "�½�·���ɹ�" << endl;
			continue;
		}
		else if (s == "c") {
			break;
		}

		try {
			n = stoi(s);
		} 
		catch (std::invalid_argument& e){
			cout << "����δ������" << endl;
			_sleep(1000);
			continue;
		}
	    catch (std::out_of_range& e){
			cout << "�������" << endl;
			_sleep(1000);
			continue;
		}
		n = stoi(s);
		if (n <= 0 || n > num) {
			cout << "û���ҵ���·��" << endl;
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
			cout << "���� : " << i << "\t";
			for (int j = 0; j < funtion[i].columns.size(); j++) {
				cout << funtion[i].columns[j] << " ";
			}
			cout << endl;
		}
		cout << "a���½�����" << endl;
		cout << "b��ɾ������" << endl;
		cout << "c���޸ķ���" << endl;
		cout << "d��������һ��" << endl;
		cin >> s;
		cin.clear();
		if(s == "a") {
			cout << "����������" << endl;
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
				cout << "û�з�������ɾ��" << endl;
				continue;
			}
			cout << "����ɾ�����" << endl;
			int n;
			cin >> n;
			if (n >= 0 && n < funtion.size()) {
				cout << n << "\t" << funtion.size() << endl;
				funtion.erase(funtion.begin() + n);
				cout << "ɾ���ɹ�" << endl;
			}
			else {
				cout << "ɾ��ʧ��" << endl;
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
	/*����쳣����*/
	abnormal.clear();
	/*���ø���*/
	vectorTmp.resize(60 * 24 / intervalTime,0);
	/*��ȡ�ļ��б�*/
	vector<string> fileList;
	getFiles(filePath, fileList);
	if (fileList.empty()) {
		cout << "Ŀ¼��û���ҵ��ļ�" << endl;
		return;
	}
	/*����Ŀ��Ŀ¼*/
	string newPath = filePath + "_��������";
	mkdir(newPath.c_str());

	string abnormalstr = filePath + "_�쳣��Ϣ";
	mkdir(abnormalstr.c_str());

	ifstream infile;
	ofstream outfile;
	string input;
	vector<string> instr;           //�ֶ�
	vector<int> datatemp;
	int index;
	int temp;

	for (vector<string>::iterator it = fileList.begin(); it != fileList.end(); it++) {
		statistics.clear();
		datacar.clear();
		
		infile.open(*it);
		if (infile.is_open()) {
			cout << "���ļ��ɹ�" << *it << endl;
		}
		else {
			cout << "���ļ�ʧ��" << endl;
			Sleep(1000);
			return;
		}
		abnormal.push_back(*it);

		index = it->rfind("\\");
		it->insert(index, "_��������");
		outfile.open(*it);
		if (outfile.is_open()) {
			cout << "��д���ļ��ɹ�" << *it << endl;
		}
		else {
			cout << "��д���ļ�ʧ��" << endl;
		}

		count = 0;
		int n = 0;
		while (getline(infile, input)) {
			datatemp.clear();
			instr.clear();
			count++;
			/*�ֶ�*/
			for (int index = 0, temp = 0; temp = index, index = input.find(",", index); index++) {
				if (index == string::npos) {
					instr.push_back(input.substr(temp));
					break;
				}
				instr.push_back(input.substr(temp, index - temp));
			}
			/*��ַ���vector<int> datatemp*/
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
									abnormal.push_back("ԭʼ���ݵ�" + to_string(count) + "��,���ڷǷ��ַ�");
								}
							}
							datatemp.push_back(stoi(tmp.substr(temp)));
							break;
						}	
						string &s = tmp.substr(temp,index-temp);
						for (auto &s : s) {
							if (s > 57 || s < 48) {
								abnormal.push_back("ԭʼ���ݵ�" + to_string(count) + "��,���ڷǷ��ַ�");
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

			keyDispose(datatemp,true);                             //���ֶ�
		}
		
		dataCheck(outfile,*it);                                    //�쳣���
		
		/*�쳣��Ϣ����5000��д���ļ�*/
		if (abnormal.size() > 5000) {
			++num;
			string abnormalFile = abnormalstr + "\\�쳣��Ϣ" + to_string(num) + ".csv";
			ofstream inabnormal(abnormalFile);
			if (inabnormal.is_open()) {
				cout << "�쳣�ļ��򿪳ɹ�" << endl;
				for (vector<string>::iterator it = abnormal.begin(); it != abnormal.end(); it++) {
					inabnormal << *it << endl;
				}
			}
			else {
				cout << "�쳣�ļ���ʧ��" << endl;
			}
		}
		infile.close();
		outfile.close();
	}
	++num;
	string abnormalFile = abnormalstr + "\\�쳣��Ϣ" + to_string(num) + ".csv";
	ofstream inabnormal(abnormalFile);
	if (inabnormal.is_open()) {
		cout << "�쳣�ļ��򿪳ɹ�" << endl;
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
		abnormal.push_back("ԭʼ���ݵ�" + to_string(count) + "��,ʱ�䷶Χ�쳣");
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
	string temp1("�������ֱ���,");
	string temp2("����������ȱʧ,");
	
	if (it->first != statistics.size()) {
		if (it->first >= 9)
			abnormal.push_back("������󳵵������ڻ����9���������쳣����");
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
			int mimute = gezi*intervalTime % 60;//ֵ
			if (*ie > 180*intervalTime) {
				string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "��ֵƫ��");
				abnormal.push_back(s);
			}
			if (!Sample.empty()) {
				cout << *ie - *is << endl;
				if (abs(*ie - *is) > 50) {
					string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "�������������ϴ�" + "��ֵΪ," + to_string((*ie - *is)));
					abnormal.push_back(s);
				}
				is++;
			}
			num.push_back(*ie);
			if (num.size() == 4) {
				biaozhun = ((num[2] + num[1]) / 2 - (num[1] + num[0]) / 2) * 3 / 2 + (num[2] + num[1]) / 2;
				if (abs(biaozhun - *ie) > 100) {
					string &s(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "ͻ��," + "��ֵΪ," + to_string((*ie)) + "-" + to_string(biaozhun) + "=," + to_string(biaozhun - *ie) + "," + to_string(num[0]) + "," + to_string(num[1]) + "," + to_string(num[2]));
					abnormal.push_back(s);
					if (*ie == 0 && hour >= 5 && hour <24) {
						int count = 0;
						for (vector<int>::iterator is = ie; *is == 0; is++) {
							count++;
						}
						if (count*intervalTime >= 10) {
							string &s1(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "���ܴ�������ȱʧ��" + "ʱ��Ϊ��" + to_string(count*intervalTime));
							abnormal.push_back(s1);
						}
					}
					else if (hour < 6 && hour >0) {
						if (count*intervalTime > 20) {
							string &s1(to_string(datacar[0]) + "," + to_string(datacar[1]) + "," + to_string(datacar[2]) + "," + to_string(hour) + "," + to_string(mimute) + "," + to_string(datacar[3]) + "," + to_string(it->first) + "," + to_string(*ie) + "," + "���ܴ��������쳣��ֵ��" + "ʱ��Ϊ��" + to_string(count*intervalTime));
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
	cout << "����������Ŀ¼" << endl;
	string samplePath("C:\\Users\\Public\\Documents\\��������");
	/*���ø���*/
	vectorTmp.resize(60 * 24 / intervalTime, 0);
	/*��ȡ�ļ��б�*/
	vector<string> fileList;
	getFiles(samplePath, fileList);
	if (fileList.empty()) {
		cout << "Ŀ¼��û���ҵ��ļ�" << endl;
		return;
	}

	ifstream infile;
	string input;
	vector<string> instr;           //�ֶ�
	vector<int> datatemp;
	int index;
	int temp;

	for (vector<string>::iterator it = fileList.begin(); it != fileList.end(); it++) {
		statistics.clear();
		datacar.clear();
		count = 0;

		infile.open(*it);
		if (infile.is_open()) {
			cout << "���ļ��ɹ�" << *it << endl;
		}
		else {
			cout << "���ļ�ʧ��" << endl;
			Sleep(1000);
			return;
		}

		while (getline(infile, input)) {
			datatemp.clear();
			instr.clear();
			count++;
			/*�ֶ�*/
			for (int index = 0, temp = 0; temp = index, index = input.find(",", index); index++) {
				if (index == string::npos) {
					instr.push_back(input.substr(temp));
					break;
				}
				instr.push_back(input.substr(temp, index - temp));
			}
			/*��ַ���vector<int> datatemp*/
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
								cout << "ԭʼ���ݵ�" + to_string(count) + "��,���ڷǷ��ַ�" << "\t" << s << endl;
							}
						}
						if (index == string::npos) {
							string &s = tmp.substr(temp);
							for (auto &s : s) {
								if (s > 57 || s < 48) {
									cout << "ԭʼ���ݵ�" + to_string(count) + "��,���ڷǷ��ַ�" << "\t" << s << endl;
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
				cout << "ԭʼ���ݵ�" + to_string(count) + "��,ʱ�䷶Χ�쳣" << endl;
				return;
			}
			keyDispose(datatemp,false);                                  //���ֶ�
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
	//�ļ����  
    long   hFile = 0;
	//�ļ���Ϣ  
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
    do
	{
	//�����Ŀ¼,����֮  
	//�������,�����б�  
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

