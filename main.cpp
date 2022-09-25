#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <locale.h>
#include <time.h>
#include <sstream>

using namespace std;

#include "errores.h"
#include "Fecha.h"
#include "Menu.h"

int fechaDesdeSerie() {
    cout<<"Debe ingresar un espacio entre los números de serie. Ejemplo 110984 82200 \n\n"<<endl;
    cout<<"Ingrese número de serie: "; int s, t; cin>>s>>t;
    Date i(s, t);
    cout<<endl;
    cout<<"Datos de la fecha #"<<s<<"-"<<t<<": "<<endl<<endl;
    i.print(Date().SP_FULL);
    cout<<endl<<endl;
    return 1;
}
int serieDesdeFecha() {
    cout<<"Ingrese datos de la fecha: ";
    Date i(0,0);
    i.load();
    cout<<endl;
    cout<<"Datos de la fecha: "<<endl;
    i.print(Date().SP_FULL);
    cout<<endl;
    cout<<"\nNúmero de serie: "<<i.getSerial()<<" "<<i.getSerialTime()<<". \n"<<endl;
    return 1;
}
int restarDiasAFecha() {
    cout<<"Ingrese la fecha a la cual restar días: "<<endl;
    Date a(1);
    a.load();
    int r = a.getSerial(), fh = a.getSerialTime();
    cout<<endl<<"(";
    a.print(Date().SP_FULL);
    cout<<")"<<endl;
    cout<<endl<<"Ingrese la cantidad de días a restar: "; int df; cin>>df;
    Date res(r - df, fh);
    cout<<endl<<"Resultado: "; res.print(Date().SP_FULL); cout<<endl<<endl;
    return 1;
}
int sumarDiasAFecha() {
    cout<<"Ingrese la fecha a la cual sumar días: "<<endl;
    Date a(1);
    a.load();
    int r = a.getSerial(), fh = a.getSerialTime();
    cout<<endl<<"("; a.print(Date().SP_FULL); cout<<")"<<endl;
    cout<<endl<<"Ingrese la cantidad de días a sumar: "; int df; cin>>df;
    Date res(r + df, fh);
    cout<<endl<<"Resultado: "; res.print(Date().SP_FULL); cout<<endl<<endl;
    return 1;
}
/*
 */
int fa() {
    Date f(true);
    cout<<"\n\tHoy es: ";
    f.print(Date().SP_FULL);
    cout<<endl<<endl;
    cout<<"\tDía: "<<f.getDate()<<". "<<endl;
    cout<<"\tDía de semana: "<<f.getDayName(true, true, 1)<<" ("<<f.getDay()<<"). "<<endl;
    cout<<"\tMes: "<<f.getMonthName(true, true, 1)<<" ("<<f.getMonth()<<"). "<<endl;
    cout<<"\tAño (2 dígitos): "<<f.getYear()<<". "<<endl;
    cout<<"\tAño (4 dígitos): "<<f.getFullYear()<<". "<<endl;
    cout<<"\tHora: "<<f.getHours()<<". "<<endl;
    cout<<"\tMinutos: "<<f.getMinutes()<<". "<<endl;
    cout<<"\tSegundos: "<<f.getSeconds()<<". "<<endl;
    return 0;
}
/**/

int verFechaEnDiferentesFormas() {

   // Date fecha1(12,11,2003,22,50);
    Date fecha1(1);
    fecha1.load();

    cout<<"Default: ";
    fecha1.print();
    cout<<endl<<endl;

    for(int i = 1; i <= 20; i++) {
        fecha1.print(i, false);
        cout<<endl;
        if(i % 5 == 0) cout<<endl;
    }
    return 0;
}

int verZonasHorarias() {
    Date bsas(0), paris(0), auckland(0), sf(0), perth(0), utc(0);
    bsas.now();
    int hba = bsas.getHours();
    utc.copyFrom(bsas);
    utc.setHours(hba + 3);
    int UTC = utc.getHours();
    sf.copyFrom(bsas);
    sf.setHours(UTC - 7);
    cout<<endl<<"San Francisco, CA, Estados Unidos [UTC-7]: \n\t"; sf.print(7); cout<<endl;

    cout<<endl<<"> Buenos Aires, Argentina [UTC-3]: \n\t"; bsas.print(7); cout<<endl;


    cout<<endl<<"Tiempo Universal Coordinado [UTC]: \n\t"; utc.print(7); cout<<endl;

    paris.copyFrom(bsas);
    paris.setHours(UTC + 2);
    cout<<endl<<"París, Francia [UTC+2]: \n\t"; paris.print(7); cout<<endl;

    perth.copyFrom(bsas);
    perth.setHours(UTC + 8);
    cout<<endl<<"Perth, OA, Australia [UTC+8]: \n\t"; perth.print(7); cout<<endl;

    auckland.copyFrom(bsas);
    auckland.setHours(UTC + 12);
    cout<<endl<<"Auckland, Nueva Zelanda [UTC+12]: \n\t"; auckland.print(7); cout<<endl;



    cout<<endl;
    return 1;
}

int main() {
    setlocale(LC_ALL, "");
    Item opciones[10] = {
        Item{1, "Documentación de Date", documentacion},
        Item{2, "Obtener fecha desde número de serie", fechaDesdeSerie},
        Item{3, "Obtener número de serie desde una fecha dada", serieDesdeFecha},
        Item{4, "Restar días a una fecha dada", restarDiasAFecha},
        Item{5, "Sumar días a una fecha dada", sumarDiasAFecha},
        Item{6, "Obtener fecha actual", fa},
        Item{7, "Ver fecha en diferentes formatos", verFechaEnDiferentesFormas},
        Item{8, "Convertir hora de Buenos Aires a cinco zonas horarias", verZonasHorarias},
        Item{-1, ""},
        Item{0, "Salir del programa"}
    };

    Menu menuPrincipal("Fechas", 1, opciones, 10);

    while(true) {
        system("cls");
        menuPrincipal.write();
        int c = UserChoose();
        if(c != 0) menuPrincipal.exec(c);
        else return 0;

        system("pause");
    }

    cout<<endl;
    system("pause");
    return 0;
}
