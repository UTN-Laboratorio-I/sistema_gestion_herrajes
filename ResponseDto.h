#include <iostream>
#pragma once
using namespace std;

template <class T>
class Response
{
private:
	bool success;
	std::string message;
	T data;
public:
	Response() {};
	Response(bool success, std::string message) {
		this->success = success;
		this->message = message;
	}

	void setSuccess(string message, T data) {
		success = true;
		message = message;
		data = data;
	}
	void setFailure(string message) {
		success = false;
		message = message;
	}
	bool getSuccess() {
		return this->success;
	}
	std::string getMessage() {
		return this->message;
	}
};

