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

Instrucciones para la tarea de assembler Risc-V

Programe la versión en C de la función sort en el archivo sort-c-nbits.c y
pruebe con:

  make sort-c-nbits.run

Se exige que la salida termine con el mensaje 'Felicitaciones: ...'.
De otra forma su tarea será rechazada.  Para depurar ejecute el comando:

  make sort-c-nbits.ddd

Cuando funcione correctamente, programe la versión en assembler Risc-V en
el archivo sort-rv-nbits.c.  Pruebe con el comando:

  make sort-rv-nbits.run

La salida debe ser la misma que la de la versión en C.  Para depurar en
assembler ejecute el comando:

  make sort-rv-hexamax.ddd

-----------------------------------------------

Tips para la depuración

Video con ejemplos de uso de ddd: https://youtu.be/FtHZy7UkTT4
Archivos con los ejemplos:
https://www.u-cursos.cl/ingenieria/2020/2/CC3301/1/novedades/r/demo-ddd.zip

Le serán utiles estos comandos:

   make sort-rv-hexamax.ddd   (lanza ddd para depurar sort-rv-hexamax.s)

En el momento que aparezca la ventana de ddd, la ejecución ya comenzó
y se detuvo en la función main.  Continúe la ejecución con el botón
cont.  La salida del programa se muestra en la ventana del terminal,
no en la ventana de ddd.  Seleccione el menú View->Machine Code Window
para ver el assembler.  Coloque breakpoints en lugares estratégico con
break .while_begin por ejemplo.

Si falla uno de los tests en la versión en assembler, lea atentamente el
mensaje.  Se le explicará cómo detener la ejecución justo antes de ordenar
el arreglo que fallará.

*** Solución de problemas ***

Si el programa no termina porque hay un ciclo infinito, detenga la ejecución
con control-C en el terminal de Debian, no en la ventana de ddd.  No salga de
ddd porque el programa no ha terminado.  Ejecute con stepi para examinar
los registros y así diagnosticar el problema.  El programa todavía está en el
ciclo infinito.

Es normal que ddd abra una ventana de diálogo para reclamar porque no
encuentra los fuentes de algunas funciones de biblioteca, como exit.
Ignore el problema presionando el botón OK y continúe.

Si al lanzar el depurador aparece la ventana de ddd en blanco o en el terminal
aparece este mensaje:

bind: Address already in use
qemu: could not open gdbserver on 1234

significa que su última ejecución del programa con ddd no terminó
adecuadamente.  Deberá matar el proceso (el programa) de la siguiente manera.
En el terminal de Debian ingrese este comando:

ps aux | grep qemu

Si la salida es:

pss        34660  0.0  0.2 4410944 7976 pts/2    Sl   15:40   0:00 qemu-riscv32 -g 1234 sort-c-hexamax
pss        34682  0.0  0.0   6252   636 pts/3    S+   15:46   0:00 grep qemu

el identificador del proceso que no terminó adecuadamente es 34660.  Mate
el proceso con este comando:

kill -9 34660

Ahora podrá lanzar ddd nuevamente.

-----------------------------------------------

Entrega de la tarea

En un terminal ejecute el comando:

  make zip      (crea hexa.zip que contiene sort-c-hexamax.c,
                 sort-rv-hexamax.s y resultados.txt, con la ejecución
                 de su tarea)

Entregue por U-cursos el archivo hexa.zip

Recuerde descargar de u-cursos lo que entregó, descargar nuevamente los
archivos adjuntos y vuelva a probar la tarea tal cual como la entregó.
Esto es para evitar que Ud. reciba un 1.0 en su tarea porque entregó
los archivos equivocados.  Créame, sucede a menudo por ahorrarse esta
verificacion.  Su tarea debe ordenar correctamente, si no será rechazada.

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

   make -n sort-rv-hexamax.ddd

También es útil usar make con la opción -B para forzar la recompilación
de los fuentes a pesar de que no han cambiado desde la última compilación.
Por ejemplo:

   make -B sort-rv-hexamax.run

Recompilará para generar el archivo sort-rv-hexamax desde cero
