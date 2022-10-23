#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


struct dtime {
    int dia;
    int mes;
    int any;
    int hora;
    int minutos;
    int segundos;
    int diaSemana;
};
//         MONTH[lang][short/long][capitalize?][months][24]
const char MONTH[3][2][2][12][24] = {
    { // Inglés
        { /**/
            { /**/ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"},
            { /**/ "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}
        },
        { /**/
            { /**/ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
            { /**/ "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"}
        }
    }, // Fin Inglés
    { // Español
        { /**/
            { /**/ "Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"},
            { /**/ "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"}
        },
        { /**/
            { /**/ "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"},
            { /**/ "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"}
        }
    }, // Fin Español
    { // Francés
        { /**/
            { /**/ "Jan", "Fév", "Mar", "Avr", "Mai", "Jun", "Jul", "Aoû", "Sep", "Oct", "Nov", "Déc"},
            { /**/ "jan", "fév", "mar", "avr", "mai", "jun", "jul", "aoû", "sep", "oct", "nov", "déc"}
        },
        { /**/
            { /**/ "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"},
            { /**/ "janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre"}
        }
    }, // Fin Francés
};
// WEEKDAY[lang][s/l][capitalize][weekday]
const char WEEKDAY[3][2][2][7][24] = {
    { // Inglés
        { /* Corto */
            { /**/ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" },
            { /**/ "sun", "mon", "tue", "wed", "thu", "fri", "sat" },
        }, { /* Largo */
            { /**/ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" },
            { /**/ "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" },
        }
    }, // Fin Inglés
    { // Español
        { /* Corto */
            { /**/ "Dom", "Lun", "Mar", "Mié", "Jue", "Vie", "Sáb" },
            { /**/ "dom", "lun", "mar", "mié", "jue", "vie", "sáb" }
        }, { /* Largo */
            { /**/ "Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado" },
            { /**/ "domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado" }
        }
    },
    { // Francés
        { /* Corto */
            { /**/ "Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam" },
            { /**/ "dim", "lun", "mar", "mer", "jeu", "ven", "sam" }
        }, { /* Largo */
            { /**/ "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" },
            { /**/ "dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi" }
        }
    } // Fin Francés
};


const int UK_FULL_NO_WEEKDAY = 1;
const int UK_FULL = 2;
const int UK_SHORT_NO_WEEKDAY = 3;
const int UK_SHORT = 4;
const int UK_NUMERIC = 5;

const int SP_FULL_NO_WEEKDAY = 6;
const int SP_FULL = 7;
const int SP_SHORT_NO_WEEKDAY = 8;
const int SP_SHORT = 9;
const int SP_NUMERIC = 10;

const int FR_FULL_NO_WEEKDAY = 11;
const int FR_FULL = 12;
const int FR_SHORT_NO_WEEKDAY = 13;
const int FR_SHORT = 14;
const int FR_NUMERIC = 15;

struct dtime convertSerialToDateTime(int serie, int serieHora = 0) {
    struct dtime a;
    if(serieHora >= 86400) {
        int diasDeMas = serieHora / 86400;
        serieHora = serieHora % 86400;
        serie += diasDeMas;
       // cout<<"Días de más: "<<diasDeMas<<". "<<endl;
    }
    int h = 0, m = 0, s = 0;
    for(int i = 0; i < serieHora; i++) {
        s++;
        if(s == 60) {
            s = 0;
            m++;
            if(m == 60) {
                m = 0;
                h++;
            }
        }
    }
    int aa = 1583, mm = 1, dd = 1, wd = 6;
    for(int i = 1; i < serie; i++) {
        bool esBisiesto = (aa % 400 == 0) ? true : (aa % 100 == 0) ? false : aa % 4 == 0;
        int diasPorMes[13] = {0, 31, (esBisiesto ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        dd++;
        wd++; if(wd == 7) wd = 0;

       // if(aa > 2000) cout<<dd<<"/"<<mm<<"/"<<aa<<". "<<endl;

        if(dd == diasPorMes[mm]) {
            dd = 0;
            //cout<<dd<<"/"<<mm<<"/"<<aa<<". "<<endl;
            if(mm == 12) {
                mm = 1;
                aa++;
            } else mm++;
        }
    }

    a.dia = dd;
    a.mes = mm;
    a.any = aa;
    a.diaSemana = wd;
    a.hora = h;
    a.minutos = m;
    a.segundos = s;
    if(dd == 0) {
        a.diaSemana++;
        a.dia++;
    }
    //cout<<dd<<"/"<<mm<<"/"<<aa<<". "<<h<<":"<<m<<"."<<s<<". "<<endl;

    return a;

}

int convertDateToSerial(struct dtime a) {
    int date = a.dia, day = a.diaSemana, month = a.mes, fullYear = a.any, hours = a.hora, minutes = a.minutos, seconds = a.segundos;
    if(month > 12) {
        fullYear += month / 12;
        month = month % 12;
    }
    int preserial = 0;
    for(int i = 1583; i < fullYear; i++) {
        // Por cada año, sumamos 365 / 366 seriales.
        bool isLeapYear = (i % 400 == 0) ? true : (i % 100 == 0) ? false : i % 4 == 0;
        preserial += isLeapYear ? 366 : 365;
    }
    for(int i = 1; i < month; i++) {
        // Por cada mes, sumamos sus días.
        bool isLeapYear = (fullYear % 400 == 0) ? true : (fullYear % 100 == 0) ? false : fullYear % 4 == 0;
        int daysPerMonth[13] = {0, 31, (isLeapYear? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        preserial += daysPerMonth[i];
    }
    for(int i = 1; i <= date; i++) {
        // Finalmente sumamos cada día restante.
        preserial++;
    }
    return preserial;
}

int convertTimeToSerial(struct dtime a) {
    int hours = a.hora, minutes = a.minutos, seconds = a.segundos;
    return (hours * (60*60)) + (minutes * 60) + seconds;
}


class DateTime {
protected:
    int date = 1
      , month = 1
      , year = 0
      , fullYear = 1700
      , day = 5
      , hours = 0
      , minutes = 0
      , seconds = 0;
    const bool isLeapYear = (fullYear % 400 == 0) ? true : (fullYear % 100 == 0) ? false : fullYear % 4 == 0;
    int daysPerMonth[13] = {0, 31, (isLeapYear? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int fullSerial;
    int serialTime = 0;

public:
    /* Principal Set */
    void copyFrom(DateTime a) {
        setDate(a.getDate());
        setDay(a.getDay());
        setMonth(a.getMonth());
        setFullYear(a.getFullYear());
        setYear(a.getYear());
        setHours(a.getHours());
        setMinutes(a.getMinutes());
        setSeconds(a.getSeconds());
        setSerial(a.getSerial());
        setSerialTime(a.getSerialTime());
    }
    /* Gets */
    int getDate() {return date;} // Devuelve la fecha
    int getDay() {return day;} // Devuelve el día de semana como un entero entre 0 y 6.
    int getMonth() {return month;} // Devuelve el mes del año como un entero entre 1 y 12.
    int getFullYear() {return fullYear;} // Devuelve el año actual en cuatro cifras.
    int getYear() {return year;} // [No funciona] Devuelve el año actual en dos cifras.
    int getHours() {return hours;} // Devuelve la hora actual como un entero entre 0 y 23.
    int getMinutes() {return minutes;} // Devuelve los minutos como un entero entre 0 y 59.
    int getSeconds() {return seconds;} // Devuelve los segundos como un entero entre 0 y 59.
    int getSerial() {return fullSerial;} // Devuelve el número de serie como un entero que cuenta los días que pasaron desde el 1 de enero de 1700.
    int getSerialTime() {return serialTime;} // Devuelve los segundos que pasaron desde la medianoche.

    const char * getMonthName(bool lng = false, bool capitalize = false, int lang = 1) {
        // MONTH[lang][short/long][capitalize?][months]
        return MONTH[lang][lng ? 1 : 0][capitalize ? 0 : 1][getMonth() - 1];
    }
    const char * getDayName(bool lng = false, bool capitalize = false, int lang = 1) {
        // WEEKDAY[lang][s/l][capitalize][weekday]
        return WEEKDAY[lang][lng? 1 : 0][capitalize ? 0 : 1][getDay()];
    }
    /* Sets */
    void setDate(int d) {date = d;}
    void setDay(int d) {day = d;}
    void setMonth(int m) {month = m;}
    void setFullYear(int y) {fullYear = y;}
    void setYear(int y) {year = y;}
    void setHours(int h) {hours = h;}
    void setMinutes(int m) {minutes = m;}
    void setSeconds(int s) {seconds = s;}
    void setSerial(int s) {fullSerial = s;}
    void setSerialTime(int s) {serialTime = s;}


    void print(int sets = 2, bool showTime = true, bool showSeconds = true) {
        // 0: Español ([date]/[month]/[fullYear])
        // 1: Español ( [date] de [month] de [fullYear].)
        // 2: Inglés ([month] [date], [fullYear].)

        switch(sets) {
        case 0:
            cout<<date<<"/"<<month<<"/"<<fullYear;
            break;
        case 1: // UK - Full without weekday
            cout<<getMonthName(true, true, 0)<<" "<<date<<", "<<fullYear;
            break;
        case 2: // UK - Full with weekday
            cout<<getDayName(true, true, 0)<<", "<<getMonthName(true, true, 0)<<" "<<date<<" "<<fullYear;
            break;

        case 3: // UK - Short without weekday
            cout<<getMonthName(false, true, 0)<<" "<<date<<", "<<fullYear;
            break;
        case 4: // UK - Short with weekday
            cout<<getDayName(false, true, 0)<<" "<<getMonthName(false, true, 0)<<" "<<date<<" "<<fullYear;
            break;

        case 5: // UK - Numeric
            cout<<(month < 10 ? "0" : "")<<month<<"-"<<(date < 10 ? "0" : "")<<date<<"-"<<fullYear;
            break;
        case 6: // SP - Full No Weekday
            cout<<date<<" de "<<getMonthName(true, false, 1)<<" de "<<fullYear;
            break;
        case 7: // SP - Full
            cout<<getDayName(true, true, 1)<<", "<<date<<" de "<<getMonthName(true, false, 1)<<" de "<<fullYear;
            break;
        case 8: // SP - Short No Weekday
            cout<<date<<" "<<getMonthName(false, false, 1)<<" "<<fullYear;
            break;
        case 9: // SP - Short
            cout<<getDayName(false, true, 1)<<"., "<<date<<" "<<getMonthName(false, false, 1)<<" "<<fullYear;
            break;
        case 10: // SP - Numeric
            cout<<date<<"/"<<month<<"/"<<fullYear;
            break;
        case 11: // FR - Full No Weekday FR_FULL_NO_WEEKDAY = 11;
            cout<<date<<" "<<getMonthName(true, false, 2)<<" "<<fullYear;
            break;
        case 12: // FR - Full
            cout<<getDayName(true, true, 2)<<" "<<date<<" "<<getMonthName(true, false, 2)<<" "<<fullYear;
            break;
        case 13: // FR - Short No Weekday
            cout<<date<<" "<<getMonthName(false, false, 2)<<" "<<fullYear;
            break;
        case 14: // FR - Short
            cout<<getDayName(false, true, 2)<<" "<<date<<" "<<getMonthName(false, false, 2)<<" "<<fullYear;
            break;
        case 15: // FR - Numeric
            cout<<fullYear<<"-"<<month<<"-"<<date;
            break;
        default:
            break;
        }

        /*
        const int SP_FULL_NO_WEEKDAY = 6;
        const int SP_FULL = 7;
        const int SP_SHORT_NO_WEEKDAY = 8;
        const int SP_SHORT = 9;
        const int SP_NUMERIC = 10;
        */
        if(showTime) cout<<" "<<(hours < 10 ? "0" : "")<<hours<<":"<<(minutes < 10 ? "0" : "")<<minutes;
        if(showTime && showSeconds) cout<<":"<<(seconds < 10 ? "0" : "")<<seconds;

        //cout<<"\n\tSERIAL: "<<getSerial()<<". "<<endl;
    }

    void load(bool conHora = false) {
        struct dtime ax;
        cout<<"Ingrese día: "; cin>>ax.dia;
        cout<<"Ingrese mes: "; cin>>ax.mes;
        cout<<"Ingrese año: "; cin>>ax.any;
        if(conHora) {
            cout<<"Ingrese hora: "; cin>>ax.hora;
            cout<<"Ingrese minutos: "; cin>>ax.minutos;
        } else {
            ax.hora = 0; ax.minutos = 0;
        }
        ax.segundos = 0;

        fullSerial = convertDateToSerial(ax);
        serialTime = convertTimeToSerial(ax);

        //cout<<"Serial: "<<fullSerial<<" "<<serialTime<<". "<<endl;

        struct dtime a = convertSerialToDateTime(fullSerial, serialTime);
        date = a.dia; month = a.mes; fullYear = a.any; day = a.diaSemana;
        hours = a.hora; minutes = a.minutos; seconds = a.segundos;

        //print(SP_NUMERIC, true);
        cout<<endl;

    }

    // Constructor con números de serie:
    DateTime(int serial, int serialHours = 0) {
        struct dtime a = convertSerialToDateTime(serial, serialHours);
        date = a.dia; month = a.mes; fullYear = a.any; day = a.diaSemana; hours = a.hora; minutes = a.minutos; seconds = a.segundos;
        fullSerial = serial;
    }
    DateTime(int d, int m, int y, int hh = 0, int mm = 0, int ss = 0) {
        struct dtime ax;
        ax.dia = d; ax.mes = m; ax.any = y;
        ax.hora = hh; ax.minutos = mm; ax.segundos = ss;

        fullSerial = convertDateToSerial(ax);
        serialTime = convertTimeToSerial(ax);

       // cout<<"SerialDate: "<<serialDate<<". "<<endl<<"SerialTime: "<<serialTime<<". "<<endl;

        struct dtime a = convertSerialToDateTime(fullSerial, serialTime);
        date = a.dia; month = a.mes; fullYear = a.any; day = a.diaSemana;
        hours = a.hora; minutes = a.minutos; seconds = a.segundos;

    }
    DateTime(bool d) { // Constructor que devuelve la fecha y hora actuales.
        time_t t = time(NULL);
        struct tm tiempoLocal = *localtime(&t);
        int aa = tiempoLocal.tm_year + 1900;
        int mt = tiempoLocal.tm_mon + 1;
        int dd = tiempoLocal.tm_mday;
        int hh = tiempoLocal.tm_hour;
        int mm = tiempoLocal.tm_min;
        int ss = tiempoLocal.tm_sec;

        struct dtime ax;
        ax.dia = dd; ax.mes = mt; ax.any = aa;
        ax.hora = hh; ax.minutos = mm; ax.segundos = ss;

        fullSerial = convertDateToSerial(ax);
        serialTime = convertTimeToSerial(ax);

       // cout<<"SerialDate: "<<serialDate<<". "<<endl<<"SerialTime: "<<serialTime<<". "<<endl;

        struct dtime a = convertSerialToDateTime(fullSerial, serialTime);
        date = a.dia; month = a.mes; fullYear = a.any; day = a.diaSemana;
        hours = a.hora; minutes = a.minutos; seconds = a.segundos;



    }

};

/*Fecha restarFechas(Fecha f1, Fecha f2) {
    int s1 = f1.getSerie()
      , s2 = f2.getSerie();
    int rs = s1 - s2;
    Fecha r(rs);
    return r;
}*/


int documentacion() {
    cout<<"DOCUMENTACIÓN"<<endl<<endl;
    cout<<"La clase DateTime permite almacenar y trabajar con fechas y horas desde el 1 de enero de 1700 00:00hs."<<endl<<endl;
    cout<<"\tDateTime myDate(true);\n";
    cout<<"\t-Crea un objeto de tipo DateTime, con los datos de la fecha actual.\n\n";
    cout<<"\tDateTime myDate;\n";
    cout<<"\t-Crea un objeto de tipo DateTime, pero con los valores por defecto (1/1/1700 00:00hs). \n\n";
    cout<<"\tint DateTime.getHours();\n";
    cout<<"\t-Devuelve un entero entre 0 y 23.\n\n";
    cout<<"\tint DateTime.getMinutes();\n";
    cout<<"\t-Devuelve un entero entre 0 y 59.\n\n";
    cout<<"\tint DateTime.getSeconds();\n";
    cout<<"\t-Devuelve un entero entre 0 y 59.\n\n";
    cout<<"\tint DateTime.getDate();\n";
    cout<<"\t-Devuelve un entero entre 1 y 31.\n\n";
    cout<<"\tint DateTime.getMonth();\n";
    cout<<"\t-Devuelve un entero entre 1 y 12.\n\n";
    cout<<"\tint DateTime.getYear();\n";
    cout<<"\t-Devuelve un entero entre 0 y 99.\n\n";
    cout<<"\tint DateTime.getFullYear();\n";
    cout<<"\t-Devuelve un entero mayor o igual a 1700.\n\n";
    cout<<"\tint DateTime.getSerial();\n";
    cout<<"\t-Devuelve el número de serie.\n\n";
    return 1;
}









#endif // FECHA_H_INCLUDED
