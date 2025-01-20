#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FASTQContigPlugin.h"

void FASTQContigPlugin::input(std::string file) {
   readParameterFile(file);
}

void FASTQContigPlugin::run() {}

void FASTQContigPlugin::output(std::string file) {
       	std::string outputfile = file;



	std::string myCommand = "while read -r line; do bedtools bamtofastq -i "+PluginManager::addPrefix(myParameters["alignmentdir"])+"/\"${line}\"_reads.bam -fq "+file+"/\"${line}\".fastq; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<FASTQContigPlugin> FASTQContigPluginProxy = PluginProxy<FASTQContigPlugin>("FASTQContig", PluginManager::getInstance());
