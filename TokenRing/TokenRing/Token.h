#pragma once
#include <string>
#include <vector>
class Token
{
public:
	int ip_plecare;
	int ip_destinatie;
	std::string mesaj;
	std::string trimis="Nu";
	std::string liber = "Nu";
	std::vector<std::string> istoric;

};

