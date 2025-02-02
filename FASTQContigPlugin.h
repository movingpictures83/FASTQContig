#ifndef FASTQContigPLUGIN_H
#define FASTQContigPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class FASTQContigPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "FASTQContig";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
