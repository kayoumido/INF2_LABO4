//
//  Exceptions.h
//  Labo4
//
//  Created by Robin Reuteler on 04.04.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#ifndef Exceptions_h
#define Exceptions_h

class NullLength : public std::length_error {
public:
    NullLength(std::string &what) : length_error(what) {}

    NullLength(const char *what) : length_error(what) {}
};

class ArithmeticLengthError : public std::length_error {
public:
    ArithmeticLengthError(std::string &what) : length_error(what) {}

    ArithmeticLengthError(const char *what) : length_error(what) {}
};


class ArithmeticOverflow : public std::overflow_error {
public:
    ArithmeticOverflow(std::string &what) : overflow_error(what) {}

    ArithmeticOverflow(const char *what) : overflow_error(what) {}
};

class SizeMismatch : public std::invalid_argument {
public:
    SizeMismatch(std::string &what) : invalid_argument(what) {}

    SizeMismatch(const char *what) : invalid_argument(what) {}
};

class OutOfBounds : public std::out_of_range {
public:
    OutOfBounds(std::string &what) : out_of_range(what) {}

    OutOfBounds(const char *what) : out_of_range(what) {}
};

#endif /* Exceptions_h */
