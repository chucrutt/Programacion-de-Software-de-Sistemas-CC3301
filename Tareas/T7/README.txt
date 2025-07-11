==========================================================
Esta es la documentación para compilar y ejecutar su tarea
==========================================================

Se está ejecutando el comando: less README.txt

***************************
*** Para salir: tecla q ***
***************************

Para avanzar a una nueva página: tecla <page down>
Para retroceder a la página anterior: tecla <page up>
Para avanzar una sola línea: tecla <enter>
Para buscar un texto: tecla / seguido del texto (/...texto...)
         por ejemplo: /ddd

-----------------------------------------------

Codeblocks:

Si lo prefiere, lance codeblocks y abra el archivo viajante.cbp.
Hay 3 perfiles de ejecución para probar su tarea:
+ Debug (equivale a make run-g)
+ Sanitize (make run-san)
+ Release (make run)

-----------------------------------------------

Ud. debe programar la funcion solicitada en el archivo viajante.c.

Debe probar su tarea bajo Debian 12 de 64 bits nativo o virtualizado.
Queda excluido WSL 1 para hacer las pruebas.  Sí puede usar WSL 2.
Estos son los requerimientos para aprobar su tarea:

+ make run-san debe felicitarlo y no debe reportar ningún problema como
  por ejemplo desplazamientos indefinidos.
+ make run-g debe felicitarlo.
+ make run debe felicitarlo por aprobar este modo de ejecución.  Esta
  prueba será rechazada si la función solicitada es 80% más lenta que
  la solución del profesor.

Cuando pruebe su tarea con make run en su computador asegúrese de que
que está configurado en modo alto rendimiento y que no estén corriendo
otros procesos intensivos en uso de CPU al mismo tiempo.  De otro modo
podría no lograr la eficiencia solicitada.

Para depurar use: make ddd

Video con ejemplos de uso de ddd: https://youtu.be/FtHZy7UkTT4
Archivos con los ejemplos:
https://www.u-cursos.cl/ingenieria/2020/2/CC3301/1/novedades/r/demo-ddd.zip

-----------------------------------------------

Entrega de la tarea

Ejecute: make zip

Entregue por U-cursos el archivo integral.zip

A continuación es muy importante que descargue de U-cursos el mismo
archivo que subió, luego descargue nuevamente los archivos adjuntos y
vuelva a probar la tarea tal cual como la entregó.  Esto es para
evitar que Ud. reciba un 1.0 en su tarea porque entregó los archivos
equivocados.  Créame, sucede a menudo por ahorrarse esta verificación.

-----------------------------------------------

Limpieza de archivos

make clean

Hace limpieza borrando todos los archivos que se pueden volver
a reconstruir a partir de los fuentes: *.o binarios etc.

-----------------------------------------------

Acerca del comando make

El comando make sirve para automatizar el proceso de compilación asegurando
recompilar el archivo binario ejecutable cuando cambió uno de los archivos
fuentes de los cuales depende.

A veces es útil usar make con la opción -n para que solo muestre
exactamente qué comandos va a ejecutar, sin ejecutarlos de verdad.
Por ejemplo:

   make -n ddd

También es útil usar make con la opción -B para forzar la recompilación
de los fuentes a pesar de que no han cambiado desde la última compilación.
Por ejemplo:

   make -B run
