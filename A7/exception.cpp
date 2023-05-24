#include "exception.h"

AppException::AppException(std::string message) : std::exception(), message{ std::move(message) }
{}


std::string& AppException::getMessage()
{
	return this->message;
}


ValidatorException::ValidatorException(std::string message) : std::exception(), message{ std::move(message) }
{}

std::string& ValidatorException::getMessage()
{
	return this->message;
}