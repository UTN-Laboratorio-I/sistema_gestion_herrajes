#include <iostream>
#pragma once
using namespace std;

class Response
{
private:
	bool success;
	std::string message;
public:
	Response();
	Response(bool success, std::string message);

	void setSuccess(string message);
	void setFailure(string message);
	bool getSuccess();
	std::string getMessage();
};

