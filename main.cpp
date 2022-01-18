#include <iostream>
#include <map>
#include <iterator>
#include <cmath>
#include <stdlib.h>

typedef unsigned long long big_number;





class SKP_lab3
{

private:
    //p-liczba piuerwsza
    //q-geberator grupy
    //y-liczba do zlogarytmowania
    big_number p;
    big_number g;
    big_number y;
    big_number l;
    std::map < big_number, big_number > data;
public:

    SKP_lab3 (big_number liczba_pierwsza, big_number generator_grupy,
              big_number liczba_do_zlogarytmowania)
    {

        this->p = liczba_pierwsza;

        this->g = generator_grupy;

        this->y = liczba_do_zlogarytmowania;

        this->l = ceil (sqrt (liczba_pierwsza - 1));

    }

    big_number powmod(big_number x,big_number y,big_number p)
    {
        big_number res = 1;
        x = x % p;
        while (y > 0)
        {
            if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }


    void insert_data_into_map ()
    {
        big_number i;
        big_number tmp;
        for (i= 0; i < this->l-1 ; i++)
        {
            tmp = powmod (this->g, i * this->l, this->p);
            data.insert(std::pair<big_number,big_number>(tmp,i));
        }
    }

    int find_z () {
        int j;
        for (j = 0; j < this->l; ++j) {
            int k = (powmod(this->g, j, this->p) * this->y) % this->p;

            if (data[k]) {
                int result = data[k] * this->l - j;
                if (result < this->p)
                    return result;
            }
        }
        return -1;

    }
    void map_to_String ()
    {
        for (auto itr = data.begin (); itr != data.end (); ++itr)
        {
            std::cout << itr->second << '\t' << itr->first << std::endl;
        }

    }

    void to_String ()
    {

        std::cout << "liczba_pierwsza   " << this->
                p << "\n" << "generator_grupy   " << this->
                g << "\n" << "liczba_do_zlogarytmowania   " << this->
                y << "\n" << "liczba iteracji   " << this->l << std::endl;

    }

};
int main (int argc, char **argv)
{

    SKP_lab3 * clastest =
            new SKP_lab3 (strtoull (argv[1], 0, 0), strtoull (argv[2], 0, 0),
                          strtoull (argv[3], 0, 0));
    //clastest->to_String ();
    clastest->insert_data_into_map ();
    //clastest->map_to_String ();
    std::cout << clastest->find_z ()<<std::endl;





}
