#ifndef FIGURE_CLASS 
#define FIGURE_CLASS
#include "fiches.hpp"
#include <random>

class Figure{
public:
        //Constructeur
    Figure(int shape)
        : shape(static_cast<Shape>(shape)){
        Atribuition();
    }
    ~Figure(){}

        //Function responsable pour faire les atribuitions de couleur et le form de chaque piece
    void Atribuition(){
            //Coulors randomic
        for (int i = 0; i < 4; i++){
            if (i == 0){
                form[0].setColor(static_cast<Color>(Random()));
            }else{
                form[i].setColor(form[0].getColor());
            }
        }

            //Define la forme du Shape correspondante
        switch (shape) {
        case 1: //I
            form[0].setPosX(3);
            form[1].setPosX(4);
            form[2].setPosX(5);
            form[3].setPosX(6);
            break;

        case 2: //J
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(6);
            form[3].setPosX(6);
            form[3].setPosY(1);
            break;

        case 3: //L
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(6);
            form[3].setPosX(6);
            form[3].setPosY(1);
            break;

        case 4: //O
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(4);
            form[2].setPosY(1);
            form[3].setPosX(5);
            form[3].setPosY(1);
            break;

        case 5: //T
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(6);
            form[3].setPosX(5);
            form[3].setPosY(1);
            break;

        case 6: //S
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(4);
            form[2].setPosY(1);
            form[3].setPosX(3);
            form[3].setPosY(1);
            break;

        case 7: //Z
            form[0].setPosX(4);
            form[1].setPosX(5);
            form[2].setPosX(4);
            form[2].setPosY(1);
            form[3].setPosX(3);
            form[3].setPosY(1);
            break;

        default:
            break;
        }


    };

        //Function randomic pour ajouter un valeur entre 1 et 7 et faire la correspondence entre les enum Color
    int Random(){
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 7);
        int cor = distribution(generator);
        return cor;
    }

protected:
    Fiches form[4]; 
    Shape shape;
};

#endif