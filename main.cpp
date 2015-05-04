/*! 
 *  \mainpage Containers
 *  \section intro_sec Description
 *  There are examples of using lists, stacks and queue.\n
 *  Available operations: adding and removing elements.
 */

/*!
 *  \file main.cpp 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <stack>

/* IMPORTANT NOTE:
   Using atoi() instead of stoi()
   atoi() can convert words to 0 value unlike stoi()
   Simple protection from fools */

/*! 
 *  \brief String-splitting algorithm.
 *  \param string Reference to splitted string.
 *  \param delim Delimiter for splitting.
 *  \return items Vector of source string parts.
 */
std::vector <std::string> split(std::string &string, char delim) 
{
    std::vector <std::string> items;
    std::stringstream stringStream (string);
    std::string item;

    while (std::getline(stringStream, item, delim))
        if (item.size())
            items.push_back(item);

    return items;
}

/*! 
 *  \brief Making actions with created list.
 *  \param l Reference to list of strings.
 *  \param count Amount of actions.
 *  \return Function returns nothing.
 */
void listAction(std::list<std::string> &l, int count)
{
    int index;

    std::string str;
    std::vector<std::string> strings;
    std::list<std::string>::iterator it;

    for (int i = 0; i < count; i ++)
    {
        std::cout << "Input command: ";

        fflush (stdin);
        getline (std::cin, str);
        strings = split(str, ' ');

        if (!strings.size())
        {
            std::cout << "Bad arguments amount. " << std::endl; 
            i --;
            continue;
        }

        if (strings.at(0) == "a")
        {
            if (strings.size() > 3)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            index = atoi(strings.at(1).c_str());

            if ((std::size_t)index > l.size() || index < 0)
            {
                std::cout << "Bad index. " << std::endl; 
                i --;
                continue;
            }

            it = l.begin();
            for (int i = 0; i < index; i ++) it ++;
            l.insert(it, strings.at(2));
        }
        else if (strings.at(0) == "d")
        {
            if (strings.size() > 2)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            index = atoi(strings.at(1).c_str());

            if ((std::size_t)index >= l.size() || index < 0)
            {
                std::cout << "Bad index. " << std::endl; 
                i --;
                continue;
            }

            it = l.begin();
            for (int i = 0; i < index; i ++) it ++;
            l.erase(it);
        }
        else
        {
            std::cout << "Bad command. " << std::endl; 
            count --;
        }
    }
}

/*! 
 *  \brief Making actions with created stack.
 *  \param s Reference to stack of strings.
 *  \param count Amount of actions.
 *  \return Function returns nothing.
 */
void stackAction(std::stack<std::string> &s, int count)
{
    std::string str;
    std::vector<std::string> strings;

    for (int i = 0; i < count; i ++)
    {
        std::cout << "Input command: ";

        fflush (stdin);
        getline (std::cin, str);
        strings = split(str, ' ');

        if (!strings.size())
        {
            std::cout << "Bad arguments amount. " << std::endl; 
            i --;
            continue;
        }

        if (strings.at(0) == "a")
        {
            if (strings.size() > 2)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            s.push(strings.at(1));
        }
        else if (strings.at(0) == "d")
        {
            if (strings.size() > 1)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            if (!s.size())
            {
                std::cout << "Stack is empty. " << std::endl; 
                i --;
                continue;
            }

            s.pop(); 
        }
        else
        {
            std::cout << "Bad command. " << std::endl;
            i --;
        }
    }
}

/*! 
 *  \brief Making actions with created queue.
 *  \param q Reference to queue of strings.
 *  \param count Amount of actions.
 *  \return Function returns nothing.
 */
void queueAction(std::queue<std::string> &q, int count)
{
    std::string str;
    std::vector<std::string> strings;

    for (int i = 0; i < count; i ++)
    {
        std::cout << "Input command: ";

        fflush (stdin);
        getline (std::cin, str);
        strings = split(str, ' ');

        if (!strings.size())
        {
            std::cout << "Bad arguments amount. " << std::endl; 
            i --;
            continue;
        }

        if (strings.at(0) == "a")
        {
            if (strings.size() > 2)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            q.push(strings.at(1));
        }
        else if (strings.at(0) == "d")
        {
            if (strings.size() > 1)
            {
                std::cout << "Bad arguments amount. " << std::endl; 
                i --;
                continue;
            }

            if (!q.size())
            {
                std::cout << "Stack is empty. " << std::endl;
                i --;
                continue;
            }

            q.pop();
        }
        else
        {
            std::cout << "Bad command. " << std::endl; 
            i --;
        }
    }
}

/*! 
 *  \brief Printing created list, stack and queue.
 *  \param l Reference to list of strings.
 *  \param s Reference to stack of strings.
 *  \param q Reference to queue of strings.
 *  \return Function returns nothing.
 */
template <typename T> void print (std::list<T> &l, std::stack<T> &s, std::queue<T> &q)
{
    std::cout << std::endl << std::endl << "Printing ..." << std::endl << "List : ";

    if (l.size())
        for (std::list<T>::iterator i = l.begin(); i != l.end(); i ++)
            std::cout << *i << " ";

    std::cout << std::endl << "Stack : ";

    if (s.size())
    {
        std::stack<T> stemp = s;
        do
        {
            std::cout << stemp.top() << " ";
            stemp.pop();
        }
        while (stemp.size());
    }

    std::cout << std::endl << "Queue : ";

    if (q.size())
    {
        std::queue<T> qtemp = q;
        do
        {
            std::cout << qtemp.front() << " ";
            qtemp.pop();
        }
        while (qtemp.size());
    }

    std::cout << std::endl << std::endl;
}

/*! 
 *  \brief Program entry point.
 *  \details User can choose list, stack or queue of strings for actions on them.
 */
void main()
{
    int count, 
        successCode = 0;

    std::string str;

    std::list  <std::string> l;
    std::stack <std::string> s;
    std::queue <std::string> q;

    do
    {
        fflush (stdin);

        std::cout << "Structure data type (list, stack, queue) (input \"exit\" to quit): ";
        std::cin >> str;

        if (str == "list")
            successCode = 1;
        else if (str == "stack")
            successCode = 2;
        else if (str == "queue")
            successCode = 3;
        else if (str == "exit")
            exit(0);
        else
        {
            std::cout << "Bad structure data type." << std::endl;
            continue;
        }

        fflush (stdin);

        std::cout << "Actions count : ";
        std::cin >> str;

        count = atoi(str.c_str());
        if (count > 0)
        {
            switch (successCode)
            {
                case 1: listAction  (l, count); break;
                case 2: stackAction (s, count); break;
                case 3: queueAction (q, count);
            }
            print(l, s, q);
        }
        else 
            std::cout << "Bad actions count." << std::endl;
    }
    while (1);
}
