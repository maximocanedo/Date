# Date
Clase Date, que maneja fechas en C++ desde el 1 de enero del año 9 D.C. Inspirado en la clase homónima que tiene Javascript.
## Uso
### Constructores
Se puede crear un objeto Date de tres formas: 
  * Con día, mes, año, (horas, minutos, segundos)
 ```cpp
    Date miFecha(12, 11, 2003); // 12-nov-2003, la hora por defecto es 00:00:00.000
    Date fechaConHora(12, 11, 2003, 22, 50); // 12-nov-2003 22:50:00.000
 ```
  * Con un número de serie, que son los días que pasaron desde el martes 1 de enero del año 9 D.C.
 ```cpp
    Date miFecha(728611) // Establece la fecha en el 12 de noviembre de 2003 00:00
    Date miFechaConHora(728611, 82200000); // 12-nov-2003 22:50:00.000
 ```
  * Pasando 'true' o 'false' como parámetro establece la fecha actual.
```cpp
   Date fechaActual(true); // 25-9-2022 20:45:38.000
```
## Métodos
### getDate()
 Devuelve el día del mes, como un entero entre 1 y 31.
 ```cpp
   Date miFecha(12,11,2003);
   int miFecha.getDate(); // 12
```
### getMonth()
 Devuelve el mes, como un entero entre 1 y 12.
 ```cpp
   Date miFecha(12,11,2003);
   int miFecha.getMonth(); // 11
```
### getYear()
 Devuelve los dos últimos dígitos del año, como un entero entre 0 y 99.
 ```cpp
   Date miFecha(12,11,2013);
   int miFecha.getYear(); // 13
```
### getFullYear()
 Devuelve el año completo, como un entero.
 ```cpp
   Date miFecha(12,11,2003);
   int miFecha.getFullYear(); // 2003
```
### getDay()
 Devuelve el día de semana, como un entero entre 0 (Domingo) y 6 (Sábado)
 ```cpp
   Date miFecha(12,11,2003);
   int miFecha.getDay(); // 3
```
### getHours()
 Devuelve la hora, como un entero entre 0 y 23.
 ```cpp
   Date miFecha(12,11,2003,22,50);
   int miFecha.getHours(); // 22
```
### getMinutes()
 Devuelve los minutos, como un entero entre 0 y 59.
 ```cpp
   Date miFecha(12,11,2003,22,50);
   int miFecha.getMinutes(); // 50
```
### getSeconds()
 Devuelve los segundos, como un entero entre 0 y 59.
 ```cpp
   Date miFecha(12,11,2003,22,50);
   int miFecha.getSeconds(); // 50
```
### getMilliseconds()
 Devuelve los milisegundos, como un entero entre 0 y 999.
 ```cpp
   Date miFecha(12,11,2003,22,50,10,144);
   int miFecha.getMilliseconds(); // 144
```
### getSerial()
 Devuelve el número de serial de la fecha, que son los días que pasaron desde el 1 de enero del año 9 hasta la fecha en cuestión. (Entero)
 ```cpp
   Date miFecha(12,11,2003,22,50);
   int miFecha.getSerial(); // 728611
```
### getSerialTime()
 Devuelve el número de serial de la hora, que son los milisegundos que pasaron desde las 00:00:00.000 horas hasta la hora en cuestión. (Entero)
 ```cpp
   Date miFecha(24,12,1980, 14,51,32,549);
   int miFecha.getSerial(); // 53492549
```
### getMonthName(bool, bool, int)
 Devuelve el nombre del mes como un vector de chars. 
 El primer parámetro indica si es el nombre completo (true) o corto (false). Por ejemplo "Agosto" o "Ago".
 El segundo parámetro indica si comienza con mayúscula (true) o minúscula (false). Por ejemplo "agosto" o "ago". 
 El tercer parámetro es un entero que indica el idioma (0 para inglés, 1 para español, 2 para francés, 3 para italiano).
 El cuarto parámetro se usaba para definir si se usaba el mes UTC o el mes adaptado a la zona horaria, pero ya está fuera de uso.
 ```cpp
   Date miFecha(24,12,1980, 14,51,32,549);
   miFecha.getMonthName(true, true, 1); // "Diciembre"
   miFecha.getMonthName(false, true, 0); // "Dec"
```
### getDayName(bool, bool, int)
 Devuelve el nombre del mes como un vector de chars. 
 El primer parámetro indica si es el nombre completo (true) o corto (false). Por ejemplo "Agosto" o "Ago".
 El segundo parámetro indica si comienza con mayúscula (true) o minúscula (false). Por ejemplo "agosto" o "ago". 
 El tercer parámetro es un entero que indica el idioma (0 para inglés, 1 para español, 2 para francés, 3 para italiano).
 El cuarto parámetro se usaba para definir si se usaba el mes UTC o el mes adaptado a la zona horaria, pero ya está fuera de uso.
 ```cpp
   Date miFecha(24,12,1980, 14,51,32,549);
   miFecha.getDayName(true, true, 1); // "Miércoles"
   miFecha.getDayName(false, true, 0); // "Wed"
```


