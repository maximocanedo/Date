/*
 * M�ximo Canedo
 *
 * Clase Date versi�n 3.1.
 *
 * Novedades:
 * - Date.happensBefore(Date) y Date.happensAfter(Date) reciben una fecha e informan si sucedi� antes o despu�s.
 * - Se puede a�adir d�as, meses, a�os, horas, minutos y segundos de forma directa en el objeto. P.ej. miFecha.addDays(int);
 *
 * Limitaciones:
 * - Los m�todos que restan meses, a�os, horas, minutos y segundos de forma directa (P.ej. miFecha.subtractMonths(int)) por
 * el momento no funcionan muy bien. Se sugiere evitar su uso.
 *
 */
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Date {
protected:
    int date = 1
      , month = 1
      , year = 9
      , fullYear = 9
      , day = 2
      , hours = 0
      , minutes = 0
      , seconds = 0
      , milliseconds = 0;
    int fullSerial = 0;
    int serialTime = 0;

public:
    /* Constantes */
    const char MONTH[5][2][2][12][24] = {
        { // Lat�n (Calendario Juliano)
            { /**/
                { /**/ "Ian", "Feb", "Mar", "Apr", "Mai", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"},
                { /**/ "ian", "feb", "mar", "apr", "mai", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}
            },
            { /**/
                { /**/ "Ianuarius", "Februarius", "Martius", "Aprilis", "Maius", "Junius", "Julius", "Augustus", "September", "October", "November", "December"},
                { /**/ "ianuarius", "februarius", "martius", "aprilis", "maius", "junius", "julius", "augustus", "september", "october", "november", "december"}
            }
        }, // Fin Lat�n
        { // Ingl�s
            { /**/
                { /**/ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"},
                { /**/ "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}
            },
            { /**/
                { /**/ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
                { /**/ "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"}
            }
        }, // Fin Ingl�s
        { // Espa�ol
            { /**/
                { /**/ "Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"},
                { /**/ "ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"}
            },
            { /**/
                { /**/ "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"},
                { /**/ "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"}
            }
        }, // Fin Espa�ol
        { // Franc�s
            { /**/
                { /**/ "Jan", "F�v", "Mar", "Avr", "Mai", "Jun", "Jul", "Ao�", "Sep", "Oct", "Nov", "D�c"},
                { /**/ "jan", "f�v", "mar", "avr", "mai", "jun", "jul", "ao�", "sep", "oct", "nov", "d�c"}
            },
            { /**/
                { /**/ "Janvier", "F�vrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Ao�t", "Septembre", "Octobre", "Novembre", "D�cembre"},
                { /**/ "janvier", "f�vrier", "mars", "avril", "mai", "juin", "juillet", "ao�t", "septembre", "octobre", "novembre", "d�cembre"}
            }
        }, // Fin Franc�s
        { // Italiano
            { /**/
                { /**/ "Gen", "Feb", "Mar", "Apr", "Mag", "Giu", "Lug", "Ago", "Set", "Ott", "Nov", "Dic"},
                { /**/ "gen", "feb", "mar", "apr", "mag", "giu", "lug", "ago", "set", "ott", "nov", "dic"}
            },
            { /**/
                { /**/ "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"},
                { /**/ "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"}
            }
        } // Fin Italiano
    };
    const char WEEKDAY[4][2][2][7][24] = {
        { // Ingl�s
            { /* Corto */
                { /**/ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" },
                { /**/ "sun", "mon", "tue", "wed", "thu", "fri", "sat" },
            }, { /* Largo */
                { /**/ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" },
                { /**/ "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" },
            }
        }, // Fin Ingl�s
        { // Espa�ol
            { /* Corto */
                { /**/ "Dom", "Lun", "Mar", "Mi�", "Jue", "Vie", "S�b" },
                { /**/ "dom", "lun", "mar", "mi�", "jue", "vie", "s�b" }
            }, { /* Largo */
                { /**/ "Domingo", "Lunes", "Martes", "Mi�rcoles", "Jueves", "Viernes", "S�bado" },
                { /**/ "domingo", "lunes", "martes", "mi�rcoles", "jueves", "viernes", "s�bado" }
            }
        },
        { // Franc�s
            { /* Corto */
                { /**/ "Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam" },
                { /**/ "dim", "lun", "mar", "mer", "jeu", "ven", "sam" }
            }, { /* Largo */
                { /**/ "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" },
                { /**/ "dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi" }
            }
        }, // Fin Franc�s
        { // Italiano
            { /* Corto */
                { /**/ "Dom", "Lun", "Mar", "Mer", "Gio", "Ven", "Sab" },
                { /**/ "dom", "lun", "mar", "mer", "gio", "ven", "sab" }
            }, { /* Largo */
                { /**/ "Domenica", "Luned�", "Marted�", "Mercoled�", "Gioved�", "Venerd�", "Sabato" },
                { /**/ "domenica", "luned�", "marted�", "mercoled�", "gioved�", "venerd�", "sabato" }
            }
        } // Fin Italiano
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

    const int IT_FULL_NO_WEEKDAY = 16;
    const int IT_FULL = 17;
    const int IT_SHORT_NO_WEEKDAY = 18;
    const int IT_SHORT = 19;
    const int IT_NUMERIC = 20;

    /* Principal Set */
    void copyFrom(Date a) {
        setFromSerial(a.getSerial());
        setTimeFromSerial(a.getSerialTime());
    }

    /* Gets */
    int getDate() {return date;}                        // Devuelve la fecha
    int getDay() {return day;}                          // Devuelve el d�a de semana como un entero entre 0 y 6.
    int getMonth() {return month;}                      // Devuelve el mes del a�o como un entero entre 1 y 12.
    int getFullYear() {return fullYear;}                // Devuelve el a�o actual en cuatro d�gitos.
    int getYear() {return year;}                        // Devuelve el a�o actual en dos d�gitos.
    int getHours() {return hours;}                      // Devuelve la hora actual como un entero entre 0 y 23.
    int getMinutes() {return minutes;}                  // Devuelve los minutos como un entero entre 0 y 59.
    int getSeconds() {return seconds;}                  // Devuelve los segundos como un entero entre 0 y 59.
    int getMilliseconds() {return milliseconds;}        // Devuelve los milisegundos como un entero entre 0 y 999.
    int getSerial() {return fullSerial;}                // Devuelve el n�mero de serie como un entero que cuenta los d�as que pasaron desde el 1 de enero de 1700.
    int getSerialTime() {return serialTime;}            // Devuelve los segundos que pasaron desde la medianoche.
    const char * getMonthName(bool lng = false, bool capitalize = false, int lang = 1) {
        int finalFullYear = (fullYear), finalMonth = (month), finalDate = (date);
        bool calendarioJuliano = (finalFullYear < 1582 || finalFullYear == 1582 && month < 10 || finalFullYear == 1582 && finalMonth == 10 && finalDate <= 4);
        return MONTH[calendarioJuliano ? 0 : lang + 1][lng ? 1 : 0][capitalize ? 0 : 1][finalMonth - 1];
        // MONTH[lang][short/long][capitalize?][months]
    }
    const char * getDayName(bool lng = false, bool capitalize = false, int lang = 1, bool useUTC = false) {
        // WEEKDAY[lang][s/l][capitalize][weekday]
        return WEEKDAY[lang][lng? 1 : 0][capitalize ? 0 : 1][(day)];
    }

    /* Sets */
    void setDate(int d) {
        setFromDate(d, month, fullYear);
    }
    void setDay(int d) {
        // Si estamos en mi�rcoles y d = lunes, entonces restamos 2 d�as.
        int dia_anterior = day;
        int dia_nuevo = d;
        int nuevaSerial = fullSerial;

        if(dia_anterior == dia_nuevo) {
            cout<<"";
        } else if(dia_anterior < dia_nuevo) { // Si p.ej. estamos en mi�rcoles y d = viernes
            nuevaSerial += (dia_nuevo - dia_anterior);
        } else if(dia_anterior > dia_nuevo) { // Si p.ej. estamos en mi�rcoles y d = lunes
            nuevaSerial = nuevaSerial - abs(dia_anterior - dia_nuevo);
        }

        Date temp(nuevaSerial, serialTime);
        copyFrom(temp);

    }
    void setMonth(int m) {
        setFromDate(date, m, fullYear);
    }
    void setFullYear(int y) {
        setFromDate(date, month, y);
    }
    void setYear(int y) {
        setFromDate(date, month, (2000 + y));
    }
    void setHours(int h) {
        setSerialFromTime(h, minutes, seconds, milliseconds);
    }
    void setMinutes(int m) {
        setSerialFromTime(hours, m, seconds, milliseconds);
    }
    void setSeconds(int s) {
        setSerialFromTime(hours, minutes, s, milliseconds);
    }
    void setMilliseconds(int ms) {
        setSerialFromTime(hours, minutes, seconds, ms);
    }

    void addDays(int d) {
        setFromSerial(fullSerial + d);
    }
    void addMonths(int m) {
        setFromDate(date, month + m, fullYear);
    }
    void addYears(int y) {
        setFromDate(date, month, fullYear + y);
    }
    void addHours(int h) {
        setSerialFromTime(hours + h, minutes, seconds, milliseconds);
    }
    void addMinutes(int m) {
        setSerialFromTime(hours, minutes + m, seconds, milliseconds);
    }
    void addSeconds(int s) {
        setSerialFromTime(hours, minutes, seconds + s, milliseconds);
    }
    void addMilliseconds(int ms) {
        setSerialFromTime(hours, minutes, seconds, milliseconds + ms);
    }

    void subtractDays(int d) {
        setFromSerial(fullSerial - d);
    }
    void subtractMonths(int m) {
        setFromDate(date, month - m, fullYear);
    }
    void subtractYears(int y) {
        setFromDate(date, month, fullYear - y);
    }
    void subtractHours(int h) {
        setSerialFromTime(hours - h, minutes, seconds, milliseconds);
    }
    void subtractMinutes(int m) {
        setSerialFromTime(hours, minutes - m, seconds, milliseconds);
    }
    void subtractSeconds(int s) {
        setSerialFromTime(hours, minutes, seconds - s, milliseconds);
    }
    void subtractMilliseconds(int ms) {
        setSerialFromTime(hours, minutes, seconds, milliseconds - ms);
    }


    void setSerial(int s) {
        setFromSerial(s);
    }
    void setSerialTime(int s) {
        setTimeFromSerial(s);
    }
    void setFromSerial(int serie = 1) {
        fullSerial = serie;
        // Contamos los d�as desde el martes 1 de enero del a�o 9 D.C.
        date = 1; day = 2; month = 1; fullYear = 9;
        // Empezamos a contar d�a por d�a, hasta llegar al n�mero de serie que recibimos.
        for(int i = 1; i < serie; i++) {
            bool calendarioJuliano = (fullYear < 1582 || fullYear == 1582 && month < 10 || fullYear == 1582 && month == 10 && date < 4);
            // Para las fechas anteriores al 4/10/1582 contamos los d�as seg�n el calendario juliano.
            if(calendarioJuliano) {
                // En el calendario juliano, son bisiestos todos los a�os divisibles por 4.
                bool esBisiesto = (fullYear % 4 == 0);
                int diasPorMesJuliano[13] = {0, 31, (esBisiesto ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                // Contamos los d�as y los d�as semanales.
                date++;
                day++; if(day == 7) day = 0;
                // Cuando llegamos al �ltimo d�a de cada mes...
                if(date == diasPorMesJuliano[month]) {
                    // Restablecemos el contador de d�as,
                    date = 0;
                    // Y si encima era el 31 de diciembre...
                    if(month == 12) {
                        // Restablecemos tambi�n el mes y contamos otro a�o.
                        month = 1;
                        fullYear++;
                        // Si no, simplemente contamos otro mes.
                    } else month++;
                }
            } // Fin calendario juliano
            else {
                /* El jueves 4 de octubre del 1582 Espa�a, Italia, Francia y Portugal
                adoptaron el calendario gregoriano. Como entre ambos calendarios hab�a
                un desfase de once d�as, del jueves 4 de octubre se pas� al viernes 15. */
                if(date == 4 && month == 10 && fullYear == 1582) {
                    // Ac� ponemos 'date' en 14 porque luego se le suma 1 y comienza a contar desde el viernes 15.
                    date = 14;
                    day = 4;
                }
            }
            // A partir del 15/10/1582 contamos usando el calendario gregoriano.
            bool calendarioGregoriano = (fullYear > 1582 || fullYear == 1582 && month > 10 || fullYear == 1582 && month == 10 && date >= 14);
            if(calendarioGregoriano) {
                // En el calendario gregoriano son bisiestos
                // Los a�os divisibles por 4, salvo los que sean divisibles por 100 pero no por 400.
                bool esBisiesto = (fullYear % 400 == 0) ? true : (fullYear % 100 == 0) ? false : fullYear % 4 == 0;
                int diasPorMes[13] = {0,31,(esBisiesto? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                // Cuando llegamos al �ltimo d�a de cada mes,
                if(date == diasPorMes[month]) {
                    // Restablecemos el contador de d�as
                    date = 0;
                    // Y si se trata del 31 de diciembre,
                    if(month == 12) {
                        // Restablecemos el contador de meses y contamos un a�o m�s.
                        month = 1;
                        fullYear++;
                        // Si no, simplemente contamos un mes m�s.
                    } else month++;
                }
                // Contamos d�as...
                date++;
                day++; if(day == 7) day = 0;
            }
        }
        year = fullYear % 100;
    }
    void setFromDate(int d = 1, int m = 1, int y = 9) {
        // Si recibimos un mes mayor a 12, lo dividimos.
        if(m > 12) {
            y += m / 12; // El cociente se lo sumamos al a�o,
            m = m % 12; // De forma que nos queden menos de 12 meses.
        }
        if(d < 1) d = 1;
        if(m < 1) m = 1;
        int preserial = 0; // Esta variable contar� los d�as.

        // Comenzamos contando los a�os desde el 9 D.C.
        for(int i = 9; i < y; i++) {
            // Por cada a�o vamos a sumar 355, 365, o 366 seg�n cada caso.
            bool isLeapYear = (i < 1583 ? i % 4 == 0 : (i % 400 == 0) ? true : (i % 100 == 0) ? false : i % 4 == 0 );
            preserial += i == 1582 ? 355 : (isLeapYear ? 366 : 365);
            // Como en 1582 se produjo el cambio de calendario, este a�o s�lo tuvo 355.
            // Para todos los dem�s casos nos preguntamos si fue bisiesto o no y sumamos 366 o 365 seriales, seg�n el caso.
        }

        // Ahora contamos los meses
        for(int i = 1; i < m; i++) {
            // Sumamos los d�as de cada mes
            bool isLeapYear = (y < 1583 ? y % 4 == 0 : (y % 400 == 0) ? true : (y % 100 == 0) ? false : y % 4 == 0 );
            bool k = (y == 1582); // Si estamos en 1582, contar� 21 d�as para octubre.
            //                        1,                   2,               3,  4,  5,  6,  7,  8,  9,      10,     11, 12
            int daysPerMonth[13] = {0, 31, (k ? 28 : (isLeapYear? 29 : 28)), 31, 30, 31, 30, 31, 31, 30, (k? 21 : 31), 30, 31};
            // Sumamos las seriales correspondientes a cada mes.
            preserial += daysPerMonth[i];
        }

        // Ahora contamos los d�as restantes.
        for(int i = 1; i <= d; i++) {
            // Si llega al 4 de octubre de 1582, luego sigue el 15.
            if(y == 1582 && m == 10 && i == 5) i = 15;
            // Sumamos una serial m�s.
            preserial++;
        }
        setFromSerial(preserial);
    }
    void setTimeFromSerial(int s = 1) {
        int diaEnMS = 86400000;
        if(s >= diaEnMS) {
            int dias_de_mas = s / diaEnMS;
            s = s % diaEnMS;
            int d = getDate();
            d = d + dias_de_mas;
            setDate(d);
        }
        serialTime = s;
        hours = 0;
        minutes = 0;
        seconds = 0;
        milliseconds = 0;

        hours = s / 3600000;
        s %= 3600000;

        minutes = s / 60000;
        s %= 60000;

        seconds = s / 1000;
        s %= 1000;

        milliseconds = s;

    }
    void setSerialFromTime(int h = 0, int m = 0, int s = 0, int ms = 0) {
        if(ms < 0) {
            int msabs = abs(ms + 0);
            int segundos_de_menos = msabs / 60;
            ms = 1000 - msabs % 60;
            s -= segundos_de_menos;
        }
        if(s < 0) {
            int sabs = abs(s + 0);
            int minutos_de_menos = sabs / 60;
            s = 60 - sabs % 60;
            m -= minutos_de_menos;
        }
        if(m < 0) {
            int mabs = abs(m + 0);
            int horas_de_menos = mabs / 60;
            m = 60 - mabs % 60;
            h -= horas_de_menos;
        }
        if(h < 0) {
            int habs = abs(h + 0);
            int dias_de_menos = 1 + habs / 24;
            h = 24 - habs % 24;
            setSerial(getSerial() - dias_de_menos);
        }
        setTimeFromSerial(ms + s * 1000 + m * 60000 + h * 60 * 60000);
    }

    bool happensBefore(Date e) {
        int sd1 = e.getSerial()
          , sh1 = e.getSerialTime()
          , sd0 = getSerial()
          , sh0 = getSerialTime();
        bool h = (sd0 == sd1 && sh0 < sh1 || sd0 < sd1);
        return h;
    }
    bool happensAfter(Date e) {
        int sd1 = e.getSerial()
          , sh1 = e.getSerialTime()
          , sd0 = getSerial()
          , sh0 = getSerialTime();
        bool h = (sd0 == sd1 && sh0 > sh1 || sd0 > sd1);
        return h;
    }

    void now() {
        time_t t = time(NULL);
        struct tm tiempoLocal = *localtime(&t);

        int aa, mt, dd, hh, mm, ss, ms;

            aa = tiempoLocal.tm_year + 1900;
            mt = tiempoLocal.tm_mon + 1;
            dd = tiempoLocal.tm_mday;
            hh = tiempoLocal.tm_hour;
            mm = tiempoLocal.tm_min;
            ss = tiempoLocal.tm_sec;
            ms = 0;

        setFromDate(dd, mt, aa);
        setSerialFromTime(hh, mm, ss, ms);
    }
    void yesterday() {
        now();
        subtractDays(1);
    }
    void tomorrow() {
        now();
        addDays(1);
    }
    void print(int sets = 2, bool showTime = true, bool showSeconds = true) {
        int finalFullYear = fullYear
          , finalMonth = month
          , finalDate = date;

        switch(sets) {
        case 0:
            cout<<finalDate<<"/"<<finalMonth<<"/"<<finalFullYear;
            break;
        case 1: // UK - Full without weekday
            cout<<getMonthName(true, true, 0)<<" "<<(finalDate)<<", "<<(finalFullYear);
            break;
        case 2: // UK - Full with weekday
            cout<<getDayName(true, true, 0)<<", "<<getMonthName(true, true, 0)<<" "<<(finalDate)<<" "<<(finalFullYear);
            break;
        case 3: // UK - Short without weekday
            cout<<getMonthName(false, true, 0)<<" "<<(finalDate)<<", "<<(finalFullYear);
            break;
        case 4: // UK - Short with weekday
            cout<<getDayName(false, true, 0)<<" "<<getMonthName(false, true, 0)<<" "<<(finalDate)<<" "<<(finalFullYear);
            break;
        case 5: // UK - Numeric
            cout<<((finalMonth) < 10 ? "0" : "")<<(finalMonth)<<"-"<<((finalDate) < 10 ? "0" : "")<<(finalDate)<<"-"<<(finalFullYear);
            break;
        case 6: // SP - Full No Weekday
            cout<<(finalDate)<<" de "<<getMonthName(true, false, 1)<<" de "<<(finalFullYear);
            break;
        case 7: // SP - Full
            cout<<getDayName(true, true, 1)<<", "<<(finalDate)<<" de "<<getMonthName(true, false, 1)<<" de "<<(finalFullYear);
            break;
        case 8: // SP - Short No Weekday
            cout<<(finalDate)<<" "<<getMonthName(false, false, 1)<<" "<<(finalFullYear);
            break;
        case 9: // SP - Short
            cout<<getDayName(false, true, 1)<<"., "<<(finalDate)<<" "<<getMonthName(false, false, 1)<<" "<<(finalFullYear);
            break;
        case 10: // SP - Numeric
            cout<<(finalDate)<<"/"<<(finalMonth)<<"/"<<(finalFullYear);
            break;
        case 11: // FR - Full No Weekday FR_FULL_NO_WEEKDAY = 11;
            cout<<(finalDate)<<" "<<getMonthName(true, false, 2)<<" "<<(finalFullYear);
            break;
        case 12: // FR - Full
            cout<<getDayName(true, true, 2)<<" "<<(finalDate)<<" "<<getMonthName(true, false, 2)<<" "<<(finalFullYear);
            break;
        case 13: // FR - Short No Weekday
            cout<<(finalDate)<<" "<<getMonthName(false, false, 2)<<" "<<(finalFullYear);
            break;
        case 14: // FR - Short
            cout<<getDayName(false, true, 2)<<" "<<(finalDate)<<" "<<getMonthName(false, false, 2)<<" "<<(finalFullYear);
            break;
        case 15: // FR - Numeric
            cout<<(finalFullYear)<<"-"<<(finalMonth)<<"-"<<(finalDate);
            break;
        case 16: // IT - Full No Weekday
            cout<<(finalDate)<<" "<<getMonthName(true, false, 3)<<" "<<(finalFullYear);
            break;
        case 17: // IT - Full
            cout<<getDayName(true, true, 3)<<", "<<(finalDate)<<" "<<getMonthName(true, false, 3)<<" "<<(finalFullYear);
            break;
        case 18: // IT - Short No Weekday
            cout<<(finalDate)<<" "<<getMonthName(false, false, 3)<<" "<<(finalFullYear);
            break;
        case 19: // IT - Short
            cout<<getDayName(false, true, 3)<<"., "<<(finalDate)<<" "<<getMonthName(false, false, 3)<<" "<<(finalFullYear);
            break;
        case 20: // IT - Numeric
            cout<<(finalDate)<<"/"<<(finalMonth)<<"/"<<(finalFullYear);
            break;
        default:
            break;
        }

        if(showTime) cout<<" "<<(hours < 10 ? "0" : "")<<(hours)<<":"<<(minutes < 10 ? "0" : "")<<(minutes);
        if(showTime && showSeconds) cout<<":"<<((seconds) < 10 ? "0" : "")<<(seconds);

        bool calendarioJuliano = (fullYear < 1582 || fullYear == 1582 && month < 10 || fullYear == 1582 && month == 10 && date <= 4);

    }
    void load(bool conHora = false) {
        int dia, mes, any, hora, mins, segundos;
        cout<<"Ingrese d�a: "; cin>>dia;
        cout<<"Ingrese mes: "; cin>>mes;
        cout<<"Ingrese a�o: "; cin>>any;
        if(conHora) {
            cout<<"Ingrese hora: "; cin>>hora;
            cout<<"Ingrese minutos: "; cin>>mins;
        } else {
            hora = 0; mins = 0;
        }
        segundos = 0;

        setFromDate(dia, mes, any);
        setSerialFromTime(hora, mins, segundos, 0);

    }

    /* Constructores */
    Date(int serial, int serialHours = 0) { // Constructor a partir de seriales
        setFromSerial(serial);
        setTimeFromSerial(serialHours);
    }
    Date(int d, int m, int y, int hh = 0, int mm = 0, int ss = 0, int ms = 0) { // Constructor a partir de fecha
        setFromDate(d, m, y);
        setSerialFromTime(hh, mm, ss, ms);
    }
    Date(bool useLocalTime = true) { // Constructor que devuelve la fecha y hora actuales.
        now();
    }

    /* Destructor */
    ~Date() {}

};

int documentacion() {
    cout<<"DOCUMENTACI�N"<<endl<<endl;
    cout<<"La clase Date permite almacenar y trabajar con fechas y horas desde el 1 de enero del a�o 9 D.C. 00:00hs."<<endl<<endl;
    cout<<"\tDate myDate(true);\n";
    cout<<"\t-Crea un objeto de tipo Date, con los datos de la fecha actual.\n\n";
    cout<<"\tDate myDate;\n";
    cout<<"\t-Crea un objeto de tipo Date, pero con los valores por defecto (1/1/9 D.C. 00:00hs). \n\n";
    cout<<"\tint Date.getHours();\n";
    cout<<"\t-Devuelve un entero entre 0 y 23.\n\n";
    cout<<"\tint Date.getMinutes();\n";
    cout<<"\t-Devuelve un entero entre 0 y 59.\n\n";
    cout<<"\tint Date.getSeconds();\n";
    cout<<"\t-Devuelve un entero entre 0 y 59.\n\n";
    cout<<"\tint Date.getDate();\n";
    cout<<"\t-Devuelve un entero entre 1 y 31.\n\n";
    cout<<"\tint Date.getMonth();\n";
    cout<<"\t-Devuelve un entero entre 1 y 12.\n\n";
    cout<<"\tint Date.getYear();\n";
    cout<<"\t-Devuelve un entero entre 0 y 99.\n\n";
    cout<<"\tint Date.getFullYear();\n";
    cout<<"\t-Devuelve un entero mayor o igual a 9.\n\n";
    cout<<"\tint Date.getSerial();\n";
    cout<<"\t-Devuelve el n�mero de serie.\n\n";
    return 1;
}

#endif // FECHA_H_INCLUDED
