//
//  Exceptions.h
//  Labo4
//
//  Created by Robin Reuteler on 04.04.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#ifndef Exceptions_h
#define Exceptions_h

class Null_length_error : public std::length_error
{
public:
    Null_length_error(std::string& what):length_error(what){}
    Null_length_error(const char* what):length_error(what){}
};

class Overflow : public std::overflow_error
{
public:
    Overflow(std::string& what):overflow_error(what){}
    Overflow(const char* what):overflow_error(what){}
};

#endif /* Exceptions_h */
