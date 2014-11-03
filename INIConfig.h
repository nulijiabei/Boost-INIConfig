#ifndef INICONFIG_H
#define INICONFIG_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace boost;
using namespace boost::property_tree;

class INIConfig
{
public:
    INIConfig(string);
    ~INIConfig();
public:
    bool ReadINI();
    bool WriteINI();
    bool AddString(string, string);
    bool PutString(string, string);
    string GetString(string, string);
    int GetInt(string, int);
    vector<string> GetChildString(string);
private:
    string path;
    ptree conf;
};

#endif // INICONFIG_H
