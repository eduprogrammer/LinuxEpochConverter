/*
    Copyright 2020. Eduardo Programador
    www.eduardoprogramador.com
    consultoria@eduardoprogramador.com
*/

#include "epoch.h"
#include <iostream>

using namespace std;

int main()
{
    EpochConverter ec;

    cout << "Tempo agora em Unix: " << ec.get_unix_time() << endl;
    cout << "Tempo agora normal: " << ec.get_normal_time();

    cout << "\n\n###################################\n\n";


    return 0;
}


