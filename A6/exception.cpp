#include "exception.h"

AppException::AppException(std::string message) : std::exception(), message{ std::move(message) }
{}


std::string& AppException::getMessage()
{
	return this->message;
}
