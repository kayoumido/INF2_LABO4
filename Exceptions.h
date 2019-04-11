//
//  Exceptions.h
//  Labo4
//
//  Created by Robin Reuteler on 04.04.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#ifndef Exceptions_h
#define Exceptions_h

#include <string>

class OutOfMemory : public std::bad_alloc {
    std::string _what;
public:
    explicit OutOfMemory(std::string &what) : bad_alloc(), _what(what) {}
    explicit OutOfMemory(const char *what) : bad_alloc(), _what(what) {}

    virtual const char* what() const noexcept {
        return this->_what.c_str();
    }
};

class NullLength : public std::length_error {
public:
    explicit NullLength(std::string &what) : length_error(what) {}

    explicit NullLength(const char *what) : length_error(what) {}
};

class TooBig : public std::length_error {
public:
    explicit TooBig(std::string &what) : length_error(what) {}

    explicit TooBig(const char *what) : length_error(what) {}
};

class ArithmeticLengthError : public std::length_error {
public:
    explicit ArithmeticLengthError(std::string &what) : length_error(what) {}

    explicit ArithmeticLengthError(const char *what) : length_error(what) {}
};


class ArithmeticOverflow : public std::overflow_error {
public:
    explicit ArithmeticOverflow(std::string &what) : overflow_error(what) {}

    explicit ArithmeticOverflow(const char *what) : overflow_error(what) {}
};

class SizeMismatch : public std::invalid_argument {
public:
    explicit SizeMismatch(std::string &what) : invalid_argument(what) {}

    explicit SizeMismatch(const char *what) : invalid_argument(what) {}
};

class OutOfBounds : public std::out_of_range {
public:
    explicit OutOfBounds(std::string &what) : out_of_range(what) {}

    explicit OutOfBounds(const char *what) : out_of_range(what) {}
};

#endif /* Exceptions_h */
