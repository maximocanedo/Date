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
### Date.getDate()
 Devuelve el día del mes, como un entero entre 1 y 31.
 ```cpp
   Date miFecha(12,11,2003);
   miFecha.getDate(); // 12
```
### Date.getMonth()
 Devuelve el mes, como un entero entre 1 y 12.
 ```cpp
   Date miFecha(12,11,2003);
   miFecha.getMonth(); // 11
```
