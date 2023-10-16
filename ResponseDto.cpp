#include <iostream>
#include "ResponseDto.h"

using namespace std;

Response::Response() {}
Response::Response(bool success, std::string message) {
	this->success = success;
	this->message = message;
}

void Response::setSuccess(string message) {
	success = true;
	message = message;
}

void Response::setFailure(string message) {
	success = false;
	message = message;
}

bool Response::getSuccess() {
	return this->success;
}
std::string Response::getMessage() {
	return this->message;
}