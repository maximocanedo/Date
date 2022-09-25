# Date
Clase Date, que maneja fechas en C++ desde el 1 de enero del año 9 D.C. Inspirado en la clase homónima que tiene Javascript.
## Uso
Se puede crear un objeto Date de tres formas: 
  * Con día, mes, año, (horas, minutos, segundos)
 ```cpp
    Date miFecha(12, 11, 2003);
    Date fechaConHora(12, 11, 2003, 22, 50);
 ```
  * Con un número de serie, que son los días que pasaron desde el martes 1 de enero del año 9 D.C.
 ```cpp
    Date miFecha(728611) // Establece la fecha en el 12 de noviembre de 2003.
 ```
 
