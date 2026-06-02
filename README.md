# Kid-icarus
Proyecto de Microprocesadores
Modo 1: Un jugador. Un jugador controla al personaje principal con el teclado, moviéndose hacia
la izquierda, derecha, saltando y disparando.
Modo 2: Computadora vs enemigos. La computadora controla automáticamente al personaje
principal, simulando una estrategia básica para avanzar, esquivar enemigos y atacar.
Requisitos:
• El personaje principal debe ser representado por un hilo independiente. Este hilo gestionará
el movimiento horizontal, salto, disparo y pérdida de vidas.
• Los enemigos deben ser representados por hilos independientes o por un conjunto de hilos
que controlen su aparición, movimiento y ataques.
• Los proyectiles del jugador deben ser gestionados por hilos independientes, desplazándose
por la pantalla hasta impactar contra un enemigo o salir del área visible.
• El escenario debe incluir plataformas representadas con ASCII-Art, sobre las cuales el
personaje podrá desplazarse o saltar.
• Debe implementarse detección de colisiones entre jugador, enemigos, proyectiles,
plataformas y límites del escenario.
• Los hilos deben sincronizarse para mantener el estado del juego coherente y evitar
condiciones de carrera. Para esto, podrán utilizar mutex, semáforos, variables de condición o
barreras.
• Mostrar en consola la posición del jugador, enemigos, proyectiles, plataformas, vidas y
puntuación en tiempo real.
• Registrar cuando el jugador elimine enemigos, pierda vidas o alcance una nueva zona del
escenario.
• El juego finalizará cuando el jugador pierda todas sus vidas o alcance la parte superior/final
del nivel.

Para compilar
- g++ src/*.cpp -Iinclude -o kidicarus -lncurses
- ./kidicarus

<img width="888" height="882" alt="image" src="https://github.com/user-attachments/assets/7206fd18-1cab-4f8f-89a5-2f5249d1fe19" />
<img width="1266" height="759" alt="image" src="https://github.com/user-attachments/assets/1b4ae3a3-8a55-44fa-b25b-8a2f1c93a710" />
<img width="854" height="404" alt="image" src="https://github.com/user-attachments/assets/1a4212a2-321d-4e51-8e20-b5476d47463b" />
