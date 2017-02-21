   /*!
    \file matrix.cpp
    \brief viikkotehtava 1 matrix-tiedosto

    */


#include <iostream>
#include "matrix.h"


void printMatrix(int rows, int cols){




    /*
    *
    *Tulostetaan alkioiden paikka-indeksit.
    *Aloitetaan numerointi 1:sta.
    *esim nxm-matriisi tuottaa alkiot: 1:n+1 ja 1:m+1
    *
    */

        for(int i=1;i<rows+1;i++){
            for (int j=1;j<cols+1;j++){
                std::cout <<i <<j << " ";
            }
            std::cout << "\n";
        }


    }

