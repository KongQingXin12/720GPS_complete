#include "GPStxt_834.h"



GPStxt_834::GPStxt_834()
{
}

GPStxt_834::GPStxt_834(string r, string w, string m)
{
	pos = r;
	gps = w;
	mode = m;
}

vector<string> GPStxt_834::deal_pos()
{
	vector<string> dir;
	deal_vec();
	string temp = gps;
	int cnt = 1;
	string number;
	for (auto i = ans.begin(); i != ans.end(); i++)
	{
		string str = *i;
		if (str.find("目标编号：") != string::npos)
		{
			number = str.substr(str.find("：") + 2);
			gps += number;
			gps += ".txt";
			if (find(dir.begin(),dir.end(),gps)==dir.end())
			{
				deal_read_mode(gps);
			}
			dir.push_back(gps);
		}
		else if (str.find("pause") != string::npos)
		{
			gps = temp;
			cnt = 1;
		}
		else
		{
			ofstream write_gps;
			write_gps.open(gps, ios::app);
			write_gps << "Waypoint" << "\t" << cnt << "\t" << number << "-" << cnt << "\t" << "User Waypoint" << "\t" << str << endl;
			cnt++;
		}

	}
	return dir;
}

void GPStxt_834::deal_read_mode(string gps_name)
{
	ifstream read_m;
	read_m.open(mode);
	ofstream write_gps;
	write_gps.open(gps_name, ios::out | ios::trunc);
	write_gps << "grid" << "\t" << "纬度/经度 hdd.dddddddd" << "\n" << "Datum" << "\t" << "WGS 84" << "\n" << "Header" << "\t" << "name" << "\t" << "Description" << "\t" << "typs" << "\t" << "Position" << "\n" << endl;
}

void GPStxt_834::deal_vec()
{
	ifstream read_p;
	read_p.open(pos);
	while (1)
	{
		char s[200];
		read_p.getline(s, 200);
		string str(s);
		if (str.find("停止") != string::npos)
		{
			break;
		}
		ans.push_back(s);

	}
}


GPStxt_834::~GPStxt_834()
{
}
