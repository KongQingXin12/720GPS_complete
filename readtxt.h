#ifndef READTXT_H
#define READTXT_H
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include<vector>
using namespace std;

class readtxt
{
private:
    string r_filename;
    string w_filename;
    vector<string> ans;
public:
    readtxt();
    readtxt(string r,string w);
    void trans();
    void deal_str(string &s);
    void deal_vec(vector<string>&ans);
    void write();
};

#endif // READTXT_H
