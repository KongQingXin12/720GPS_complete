
#include "readtxt.h"
class GPStxt_834 :public readtxt
{
private:
	string pos;
	string gps;
    string mode;
	vector<string>ans;
public:
	GPStxt_834();
    GPStxt_834(string r, string w,string m);
	vector<string> deal_pos();
	void deal_read_mode(string gps_name);
	void deal_vec();
	~GPStxt_834();
};

