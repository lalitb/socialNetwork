#include "LinkedInException.hpp"

LinkedInException::LinkedInException(const char* message): msg_(message){
}

LinkedInException::LinkedInException(const std::string& message): msg_(message){
}

LinkedInException::~LinkedInException() throw(){
}

const char* LinkedInException::what() const throw(){
    return msg_.c_str();
}
