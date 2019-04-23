#include "SQLInterface.h"
#include <iostream>
#include <math.h>

SQLInterface::SQLInterface()
{
    mysql = mysql_init(NULL);
    if(mysql == NULL)
    {
        cout<<"Error:"<<mysql_error(mysql);
    }
    _init("localhost","root","test","game");
}

SQLInterface::~SQLInterface()
{
    if(mysql!=NULL)
    {
        mysql_close(mysql);
    }
}

/**< JUST FOR FUN */
void SQLInterface::get_operators(int* pic, int* tt)
{
    if(mysql)
    {
        _query("select player,type,position from data ;");
        MYSQL_RES* result = mysql_store_result(mysql);
        int num_rows=mysql_num_rows(result);
        for(int i=0;i<num_rows;i++)
        {
            MYSQL_ROW row = mysql_fetch_row(result);
            int player = atoi(row[0]);
            int type = atoi(row[1]);
            int pos = std::round(atof(row[2]));
            pic[pos] = player;
            tt[pos] = type;
            //pic[pos] = _render(player,type);
        }
        mysql_free_result(result);
    }
}

bool SQLInterface::_init(string host, string user, string pwd, string db_name)
{
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), pwd.c_str(), db_name.c_str(), 0, NULL, 0);
    if(mysql == NULL) {
        cout << "Error: " << mysql_error(mysql);
        exit(1);
    }
    return true;
}

bool SQLInterface::_query(string sql)
{
    if(mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    return true;
}

