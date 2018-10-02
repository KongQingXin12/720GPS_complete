#include "readtxt.h"

readtxt::readtxt()
{

}

readtxt::readtxt(string r, string w)
{


    w_filename = w;
    r_filename = r;
}

void readtxt::trans()
{
    ifstream in;            //以读的方式打开
    in.open(r_filename);        //以读的方式打开文件
    if (!in)                         //判断是否成功打开
        cout << "open failed" << endl;
    for (int i = 0; ; i++)
    {
        char s[200];
        in.getline(s, 200);
        string str(s);
        ans.push_back(str);
        //读取文件内字符串，还有其他读取方式，可根据需要使用
        if (str == "停止")
        {
            break;
        }
    }
    in.close();                       //关闭文件
    deal_vec(ans);
    write();
}

void readtxt::deal_str(string &s)
{
    string temp;
    auto pos1 = s.find(']');
    auto pos2 = s.find(',');//找到第一个逗号
    auto pos3 = s.find(',', pos2 + 1);//找到第二个逗号
    temp += s.substr(pos2 + 1, pos3 - pos2 - 1);
    temp += " ";
    temp += s.substr(pos1 + 1, pos2 - pos1 - 1);
    temp.replace(temp.find("经"), temp.find("：") + 2, "E");
    temp.replace(temp.find("纬"), temp.find("：") + 2, "N");
    s = temp;
}

void readtxt::deal_vec(vector<string> &ans)
{
    //int len = ans.size();
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        string temp = *i;
        //auto pos_T = temp.find('T');
        //auto pos_time = temp.find("时间");
        //|| temp.find("发现时间") != string::npos
        if (temp.find("目标编号") != string::npos )
        {
            continue;
        }
        else if (temp.find("[") != string::npos)
        {
            deal_str(temp);
            *i = temp;
        }
        else
        {
            *i = "";
        }
    }
    //ans.push_back("停止");
}

void readtxt::write()
{
    int length = ans.size();
    ofstream ou;            //以写的方式打开
    remove(w_filename.c_str());
    ou.open(w_filename, ios::app);        //以向尾部追加的方式打开
    if (ou.is_open())                          //判断是否打开
    {
        cout << "写入文件" << endl;
        cout << w_filename << endl;
        for (int i = 0; i < length; i++)
        {
            if (ans[i].find("目标编号") != string::npos&&i != 0)
            {
                ou << "pause" << endl;
            }
            if (ans[i].empty())
            {
                continue;
            }
            else
            {
                ou << ans[i] << endl;
            }
        }
        //向文件内输入 hello
    }
    else
        cout << "open failed" << endl;
    ou << "停止" << endl;
    ou.close();
}
