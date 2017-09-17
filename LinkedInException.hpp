#pragma once

#include <exception>
#include <string>

class LinkedInException: public std::exception {

public:
  explicit LinkedInException(const char* message);
  explicit LinkedInException(const std::string& message);
  virtual const char* what() const throw();
  virtual ~LinkedInException() throw(); 

protected:
  std::string msg_;

};
