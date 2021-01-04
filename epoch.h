/*
    Copyright 2020. Eduardo Programador
    www.eduardoprogramador.com
    consultoria@eduardoprogramador.com
*/

#include "lepoch_conv.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <malloc.h>

big EpochConverter::get_unix_time()
{
    return l_epo;
}

msg EpochConverter::get_normal_time()
{
    return n_epo;
}

void EpochConverter::set_normal_time(msg normal_t)
{
    n_epo = normal_t;
}

void EpochConverter::set_unix_time(big number)
{
    l_epo = number;
}

void EpochConverter::convertToNormal()
{
    char *res;
    big t = EpochConverter::get_unix_time();
    struct tm *t_str;
    t_str = localtime(&t);

    normal hour = t_str->tm_hour;
    normal minute = t_str->tm_min;
    normal second = t_str->tm_sec;
    normal day = t_str->tm_mday;
    normal month = t_str->tm_mon + 1;
    normal year = t_str->tm_year + 1900;

    res = reinterpret_cast<char *>(ALLOCATION);

    char temp[50];

    sprintf(temp,"%d",day);
    strcpy(res,temp);
    strcat(res,"/");
    sprintf(temp,"%d",month);
    strcat(res,temp);
    strcat(res,"/");
    sprintf(temp,"%d",year);
    strcat(res,temp);
    strcat(res," ");

    sprintf(temp,"%d",hour);
    strcat(res,temp);
    strcat(res,":");
    sprintf(temp,"%d",minute);
    strcat(res,temp);
    strcat(res,":");
    sprintf(temp,"%d",second);
    strcat(res,temp);

    EpochConverter::set_normal_time(res);

}

void EpochConverter::convertToUnix()
{
    struct tm t_st;
    bzero(&t_st, sizeof(struct tm));
    t_st.tm_mday = epoc->day;
    t_st.tm_mon = epoc->month - 1;
    t_st.tm_year = epoc->year - 1900;
    t_st.tm_hour = epoc->hour;
    t_st.tm_min = epoc->minute;
    t_st.tm_sec = epoc->second;

    big res = mktime(&t_st);
    EpochConverter::set_unix_time(res);
}

void EpochConverter::now()
{
    struct tm *str_now;
    big t_now;
    time(&t_now);
    str_now = localtime(&t_now);

    l_epo = mktime(str_now);
    EpochConverter::convertToNormal();

}






