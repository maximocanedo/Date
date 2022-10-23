/*
 * Máximo Canedo
 * Legajo N.º 25839
 *
 * Clases Menu, Item
 *
 */
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "rlutil.h"

int s() {
    Error(1).print();
    return 1;
}



class Item {
protected:
    char label[128];
    int opc;
    bool esOpcion = (opc >= 0);
    int (*callback)();
    int h = 0;
public:
    Item(int nro = -1, const char * l = "Opción no válida", int (*op)() = s, int h = 0) : callback(op) {
        strcpy(label, l);
        opc = nro;
        esOpcion = (opc >= 0);
    }
    const char * getLabel() {return label;}
    bool esOpc() {return esOpcion;}
    int getID() {return opc;}
    void Mostrar(int h = 0) {
        if(esOpcion) cout<<opc<<". "<<label<<" ";
        else {
            for(int i = 0; i < h; i++) cout<<"   ";
            cout<<" "<<label<<" ";
        }
    }
    int exec() {
        return callback();
    }
};


void drawOptionInScreen(Item option, int x, int y, bool onHover) {
    bool esOpcion = option.esOpc();
    if(onHover && esOpcion) { // Si el elemento en cuestión está seleccionado..
        rlutil::setBackgroundColor(rlutil::YELLOW); // Se pinta el fondo de amarillo,
        rlutil::setColor(rlutil::BLACK); // Y se escribe en negro.
    } else  { // Si el elemento en cuestión no está seleccionado...
        rlutil::setBackgroundColor(rlutil::BLACK); // Pintamos el fondo de negro,
        rlutil::setColor(rlutil::WHITE); // Y escribimos en blanco.
    }
    rlutil::locate(x,y); // Nos ubicamos en la posición correspondiente...
    cout<<" "<<option.getLabel()<<" "<<endl; // Y escribimos finalmente el texto de la opción.
    rlutil::setBackgroundColor(rlutil::BLACK); // Pintamos el fondo de negro,
    rlutil::setColor(rlutil::WHITE); // Y escribimos en blanco.
}

class Menu {
protected:
    Item opciones[42];
    int opcs;
    char titulo[72];
    int level = 0;
    char l[16] = "";
public:

    Item * getOptionList() {return opciones;}
    int getOptionsLength() {return opcs;}
    const char * getTitle() {return titulo;}
    int getLevel() {return level;}

    Menu(const char * tt, int lt, Item o[], int cs) {
        for(int i = 0; i < cs; i++) opciones[i] = o[i];
        opcs = cs;
        strcpy(titulo, tt);
        level = lt;
    }
    void write() {
        for(int j = 0; j < level; j++) cout<<"---";
            cout<<titulo<<endl;
        for(int i = 0; i < opcs; i++) {
            for(int j = 0; j < level; j++) cout<<"   ";
            opciones[i].Mostrar(level);
            cout<<endl;
        }

    }

    int exec(int opt) {
        for(int i = 0; i < opcs; i++) {
            if(opciones[i].getID() == opt) {
                opciones[i].exec();
                return 1;
            }
        }
        cout<<"Opción inválida. "<<endl;
        return 0;
    }

    void graph() {
        int optionsLength = getOptionsLength();
        int tabs = getLevel() + 5;
        Item * options = getOptionList();
        rlutil::cls();
        rlutil::hidecursor();
        int activeOption = 0;
        int ultimaOpcionSeleccionada = -1;

        while(true) {
            //rlutil::cls();
            rlutil::locate(tabs, 2);
            cout<<getTitle()<<endl;
            rlutil::locate(tabs, 4);
            cout<<"Elegí una opción: "<<endl;
            if(ultimaOpcionSeleccionada == -1) {
                for(int i = 0; i < optionsLength; i++)
                    drawOptionInScreen(options[i], tabs - 1, 6 + i, (activeOption == i));
                ultimaOpcionSeleccionada = 0;
            } else {
                drawOptionInScreen(options[ultimaOpcionSeleccionada], tabs -1, 6 + ultimaOpcionSeleccionada, false);
                drawOptionInScreen(options[activeOption], tabs - 1, 6 + activeOption, true);
            }

            rlutil::locate(tabs - 3, 6 + activeOption);
            ultimaOpcionSeleccionada = activeOption;
            int pressedKey = rlutil::getkey();
            switch(pressedKey) {
            case 14: {
                bool noHayaOpcion = true;
                while(noHayaOpcion) {
                    if(activeOption == 0) activeOption = optionsLength;
                    if(activeOption > 0) activeOption--;
                    noHayaOpcion = !options[activeOption].esOpc();
                }
                rlutil::locate(tabs - 3, 6 + activeOption);
                cout<<" "<<endl;
                break;
            }
            case 15: {
                bool noHayaOpcion = true;
                while(noHayaOpcion) {
                    if(activeOption == optionsLength - 1) activeOption = -1;
                    if(activeOption < optionsLength - 1) activeOption++;
                    noHayaOpcion = !options[activeOption].esOpc();
                }
                rlutil::locate(tabs - 3, 6 + activeOption);
                cout<<" "<<endl;
                break;
            }
            case 1:
                int numeroOpcion = options[activeOption].getID();
                rlutil::cls();
                rlutil::locate(0,0);
                exec(numeroOpcion);
                ultimaOpcionSeleccionada = -1;
                system("pause && cls");
                break;
            }
        }

    }

};

int UserChoose() {
    cout<<endl<<"Ingrese opción: ";
    int y; cin>>y;
    system("cls");
    return y;
}


#endif // MENU_H_INCLUDED
