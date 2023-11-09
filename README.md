# Quadratic Assignment Problem con Forward Checking.

## Autor

Sebastian Alonso Naranjo Henriquez  
Rol: 201973614-0

## Requistos previos

Asegúrate de tener las siguientes carpetas creadas y disponibles en el directorio raíz del proyecto:
- Carpeta "Instancias_pequeñas"
- Carpeta "Christofides"
- Carpeta "Nugent"
- Carpeta "Taillard"

## Estructura del proyecto

QAP_FC/ <br>
├── Instancias_pequeñas/ <br>
│   ├── instance4A.dat <br>
│   ├── instance4B.dat <br>
│   └── ... <br>
├── Christofides/ <br>
│   ├── chr12a.dat <br>
│   ├── chr12b.dat <br>
│   └── ... <br>
├── Nugent/ <br>
│   ├── nug12.dat <br>
│   ├── nug14.dat <br>
│   └── ... <br>
├── Taillard/ <br>
│   ├── tai10a.dat <br>
│   ├── tai10b.dat <br>
│   └── ...
├── Soluciones/ <br>
│   ├── instance4A.out <br>
│   ├── instance4B.dat <br>
│   └── ... <br>
├── QAP.cpp <br>
├── Makefile <br>
└── README.md <br>

## Instrucciones de ejecución

1. Asegúrate de que los nombres de las carpetas no contengan espacios. En caso de que alguna carpeta tenga un espacio en su nombre, reemplázalo por un guion bajo "_" u otro carácter que lo haga desaparecer.
2. Asegúrate de tener los archivos de instancia necesarios en las carpetas correspondientes.
3. Ejecuta el programa utilizando el comando `make`.
4. Se te solicitará ingresar el directorio de instancias que deseas resolver (Christofides, Instancias_pequeñas, Nugent, Taillard).
5. Luego, ingresa el nombre de la instancia que deseas ejecutar sin incluir la extensión `.dat`, solo el nombre del archivo.
6. Observa los resultados generados por el programa en la carpeta Soluciones

## Ejemplo de uso

    Realizar el comando `make` para iniciar la ejecución, por terminal saldran los siguiente mensajes.
       1. Ingrese el nombre de la carpeta: 
       2. Ingrese el nombre del archivo: 
Para la primera opción, por favor completa la oración con el nombre del directorio de instancias que deseas resolver.

En cuanto a la segunda opción, ingresa el nombre específico de la instancia que deseas resolver.

       1. Ingrese el nombre de la carpeta: Nugent
       2. Ingrese el nombre del archivo: nug12

## Notas Adicionales

En relación al rendimiento y los casos límite del algoritmo, se ha logrado alcanzar soluciones para instancias de tamaño máximo 10 en un tiempo razonable.
La implementación actual no dispone de generación de soluciones parciales para instancias excesivamente grandes.