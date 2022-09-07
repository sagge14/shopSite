#include "myFunc.h"

enum commands
{
    ADD = 1,
    REMOVE,
    SHOWSITE,
    SHOWCART,
    EXIT
};
using namespace std;

int main() {

    map<string, int> myShop;
    map<string, int> myCart;
    int command = 0;
    int productCount;

    cout << "---Shop site---" << endl;
    cout << "How many uniq products will be added to the site?:";
    enterValue(productCount,1);
    for (int i = 0; i < productCount; ++i)
        addProductInShop(myShop);

    while(command != EXIT)
    {
        system("cls");
        cout << "---Shop---" << endl;
        cout << "Valid command: '1' for add product in cart;" << endl;
        cout << "               '2' for remove product from cart;" << endl;
        cout << "               '3' for show total on site;" << endl;
        cout << "               '4' for show total on cart;" << endl;
        cout << "               '5' for exit." << endl;
        cin.clear();
        cout << "Enter command:";
        cin >> command;
        system("cls");
        if(command == ADD)
        {
            cout << "---Add product in basket---" << endl;
            try {
                moveProduct(myShop,myCart);
                cout << "-ok, product has been added to the cart!" << endl;
            }
            catch (const TooMuchCountError& e)
            {
                cout << e.what() << endl;
                cout << "Total count:" << e.getTotal() << endl;
            }
            catch (const EmptyError& e)
            {
                cout << e.what() << endl;
            }
            catch (const WrongArticleError& e)
            {
                cout << e.what() << endl;
            }

        }
        else if (command == REMOVE)
        {
            cout << "---Remove product---" << endl;
            try
            {
                moveProduct(myCart, myShop);
                cout << "-ok, product has been removed from the cart!" << endl;
            }
            catch (const TooMuchCountError& e)
            {
                cout << e.what() << endl;
                cout << "Total count:" << e.getTotal() << endl;
            }
            catch (const EmptyError& e)
            {
                cout << e.what() << endl;
            }
            catch (const WrongArticleError& e)
            {
                cout << e.what() << endl;
            }
        }
        else if (command == SHOWSITE)
        {
            cout << "---Total on site---" << endl;
            for(const auto& c:myShop)
                cout << "Article " << c.first << " count " << c.second << endl;
        }
        else if (command == SHOWCART)
        {
            cout << "---Total in basket---" << endl;
            for(const auto& c:myCart)
                cout << "Article " << c.first << " count " << c.second << endl;
        }
        else
        {
            cout << "Unknown command!" << endl;
            cin.ignore();
            cin.clear();
        }

        system("pause");
    }
    system("cls");

    cout << "---Bye, bye!---" << endl;
    system("pause");
    return 0;
}
