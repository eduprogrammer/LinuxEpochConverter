/*
    Copyright 2020. Eduardo Programador
    www.eduardoprogramador.com
    consultoria@eduardoprogramador.com
*/

#include <ctime>
#include "epoch_types.h"

class EpochConverter
{

    private:
            msg n_epo;
            big l_epo;
            epoch_str *epoc;

    public:

        EpochConverter()
        {
           now();
        }

        EpochConverter(big lEpoch)
        {
            l_epo = lEpoch;
        }

        EpochConverter(epoch_str *str)
        {
            epoc = str;
        }

        ~EpochConverter()
        {
            epoc = nullptr;
            n_epo = 0;
            l_epo = 0;
        }

        big get_unix_time();

        msg get_normal_time();

        void set_unix_time(big number);

        void set_normal_time(msg normal_t);

        void convertToNormal();

        void convertToUnix();

        void now();

};



