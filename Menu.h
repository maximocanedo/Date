#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

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



class Menu {
protected:
    Item opciones[30];
    int opcs;
    char titulo[72];
    int level = 0;
    char l[16] = "";
public:
    Menu(const char * tt, int lt, const Item o[], int cs) {
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

};

int UserChoose() {
    cout<<endl<<"Ingrese opción: ";
    int y; cin>>y;
    system("cls");
    return y;
}


#endif // MENU_H_INCLUDED
