#include "include/INIConfig.h"
#include <vector>
#include <boost/format.hpp>

INIConfig::INIConfig(string _path)
{
    path = _path;
}

INIConfig::~INIConfig(){}

bool INIConfig::ReadINI()
{
    try
    {
        read_ini(path, conf);
    }
    catch (std::exception& e)
    {
        return false;
    }
    return true;
}

bool INIConfig::AddString(string _path, string _value)
{
    try
    {
        conf.add(_path, _value);
    }
    catch (std::exception& e)
    {
        return false;
    }
    return true;
}

bool INIConfig::PutString(string _path, string _value)
{
    try
    {
        conf.put(_path, _value);
    }
    catch (std::exception& e)
    {
        return false;
    }
    return true;
}

string INIConfig::GetString(string _path, string _default)
{
    return conf.get<string>(_path, _default);
}

int INIConfig::GetInt(string _path, int _default)
{
    return conf.get<int>(_path, _default);
}

vector<string> INIConfig::GetChildString(string _path)
{
    vector<string> child;
    try
    {
        auto x = conf.get_child(_path);
        for (auto& pos : x)
        {
            child.push_back(pos.first);
        }
    }
    catch (std::exception&)
    {
        return std::move(child);
    }
    return std::move(child);
}

bool INIConfig::WriteINI()
{
    try
    {
        write_ini(path, conf);
    }
    catch (std::exception&)
    {
        return false;
    }
    return true;
}

