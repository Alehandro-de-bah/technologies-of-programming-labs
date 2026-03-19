#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class IncorrectRectangleConstructor : public std::exception
{
public:
    const char* what() const noexcept override { return "Incorrect corners in rectangle constructor!"; }
};

class IncorrectScale : public std::exception
{
public:
    const char* what() const noexcept override { return "Incorrect scale!"; }
};

class IncorrectEllipseConstructor : public std::exception
{
public:
    const char* what() const noexcept override { return "Incorrect xRadius/yRadius in ellipse constructor!"; }
};

class EmptyCompositeShape : public std::exception
{
public:
    const char* what() const noexcept override { return "There are no figures in CompositeShape!"; }
};

#endif
