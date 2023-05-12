#pragma once
#include <exception>
#include <string>
class AppException : public std::exception {
	std::string message;
public:
	AppException(std::string message);
	std::string& getMessage();
};