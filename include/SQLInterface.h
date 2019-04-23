#ifndef SQLINTERFACE_H
#define SQLINTERFACE_H

#include <stdio.h>
#include <string>
#include <memory>
#include <mysql/mysql.h>
#include <um/Marco.h>
#include <um/Operator.h>

using namespace std;

class SQLInterface
{
    public:
        SQLInterface();
        ~SQLInterface();

        void get_operators(int* pic, int* tt);

        void update_operator(shared_ptr<um::Operator> op);

        void add_operator(shared_ptr<um::Operator> op);

        void del_operator(um::OperatorHandle op);

        void clear_operator();

    private:

        bool _init(string host, string user, string pwd, string db_name);

        bool _query(string sql);

    private:
        MYSQL *mysql;
};

#endif // SQLINTERFACE_H
