//
// Created by Sg on 07.09.2022.
//
#pragma once
#include <map>
#include "myException.h"
#include <algorithm>
#include <limits>
int enterCount()
{
    bool input = false;
    string count;
    int nCount;

    while(!input)
    {
        cin.ignore();
        cin.clear();

        cout << "Enter count:";
        cin >> count;

        if (!std::all_of(count.begin(), count.end(), [](const char& ch) { return isdigit(ch); }))
        {
            throw invalid_argument("entered value must be int > 0!");
        }
        try
        {
            nCount = stoi(count);
            input = true;
        }
        catch (const out_of_range& e)
        {
            cout << "Error:too much value!" << endl;
        }
    }
    return nCount;

}
string enterArticle()
{
    string article;
    cout << "Enter article:";
    cin >> article;
    return article;
}
void addProductInShop(map<string, int>& Shop)
{
    string article;
    int count;
    bool input = false;

    while(!input)
    {
        article = enterArticle();
        if(Shop.find(article) == Shop.end())
            input = true;
        else
            cout << "Entered article already exist!" << endl;
    }

    input = false;

    while(!input)
    {
        try
        {
            count = enterCount();
            input = true;
        }
        catch (const invalid_argument& e)
        {
            cout << "Error:" << e.what() << endl;
        }
    }

    Shop.insert(make_pair(article, count));
    cout << "-ok, new position has been added!" << endl;

}
void moveProduct(map<string, int>& from, map<string, int>& to)
{
    bool input = false;

    if(from.empty())
        throw EmptyError();

    string article = enterArticle();

    if(from.find(article) == from.end())
        throw WrongArticleError();

    int count;

    while(!input)
    {
        try
        {
            count = enterCount();
            input = true;
        }
        catch (const invalid_argument& e)
        {
            cout << "Error:" << e.what() << endl;
        }
    }

    if(from.at(article) < count)
        throw TooMuchCountError(from.at(article));


    from.at(article) -= count;
    if(from.at(article) == 0)
        from.erase(article);

    if(to.find(article) == to.end())
        to.insert(make_pair(article,count));
    else
        to.at(article) += count;

}
template<typename T>
void enterValue(T &n, T min = numeric_limits<T>::max(), T max = numeric_limits<T>::max())
{
    n = max / 2;
    do
    {
        if(!cin || (n < min || n > max))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "-------------------Error----------------\n";
            cout << min << " <= number diapason <= " << max;
            cout << "\n-----------------------------------------\n";
            cout << "Repeat enter:";
        }

        cin>>n;
    }
    while(!cin || (n < min || n > max));
}