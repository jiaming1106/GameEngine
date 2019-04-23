#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

#include <stdio.h>
#include <string>
#include <mysql/mysql.h>

using namespace std;

class SQLInterface
{
    public:
        SQLInterface();
        ~SQLInterface();

        void get_operators(int* pic, int* tt);

    private:

        bool _init(string host, string user, string pwd, string db_name);

        bool _query(string sql);

    private:
        MYSQL *mysql;
};

#endif // SQLINTERFACE_H
