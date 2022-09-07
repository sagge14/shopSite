//
// Created by Sg on 07.09.2022.
//
#pragma once
#include <iostream>
#include <exception>
using namespace std;
class WrongArticleError: public exception
{
public:
    const char* what() const noexcept override
    {
        return "Entered article was not found!";
    }
};
class EmptyError: public exception
{
public:
    const char* what() const noexcept override
    {
        return "Empty!";
    }
};
class TooMuchCountError: public exception
{
    int Total;
public:

    explicit TooMuchCountError(int _n):exception()
    {
        Total = _n;
    }
    int getTotal() const {return Total;}
    const char* what() const noexcept override
    {
        return "Too much count for this article! ";
    }
};
