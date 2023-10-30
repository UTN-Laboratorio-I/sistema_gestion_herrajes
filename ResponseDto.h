#include <iostream>
#pragma once
using namespace std;

template <class T>
class Response
{
private:
	bool _success;
	std::string _message;
	T _data;
public:
	Response() {};
	Response(bool success, std::string message) {
		this->_success = success;
		this->_message = message;
	}

	void setSuccess(string message, T data) {
		_success = true;
		_message = message;
		_data = data;
	}
	void setFailure(string message) {
		_success = false;
		_message = message;
	}
	bool getSuccess() {
		return this->_success;
	}
	std::string getMessage() {
		return this->_message;
	}

	T getData() {
		return this->_data;
	}
	void setData(T data) {
		this->_data = data;
	}
};

