#include <Stepper.h>

#define buttonPin1 3
#define buttonPin2 4
#define buttonPin3 5
// Definición de pines
const int stepsPerRevolution = 2048; // Pasos por vuelta del motor
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

// Variables de estado
int currentLevel = 1; // Nivel actual del ascensor


// Variables para controlar el motor paso a paso
int targetPosition = 0;
int currentPosition = 0;

void setup()
{
  // Configurar pines de entrada/salida
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  // Establecer la velocidad del motor
  stepper.setSpeed(10); // Ajusta la velocidad según sea necesario
}

void loop()
{
  // Comprobar si se presionó el pulsador del nivel 2
  if (digitalRead(buttonPin2) == 0)
  {
    if (currentLevel == 1)
    {
      targetPosition = stepsPerRevolution / 2; // Mover hacia el nivel 2
      stepper.setSpeed(10); // Ajusta la velocidad según sea necesario
      stepper.step(targetPosition - currentPosition);
      currentPosition = targetPosition;
      currentLevel = 2;
    }
  }

  // Comprobar si se presionó el pulsador del nivel 3
  if (digitalRead(buttonPin3) == 0)
  {
    if (currentLevel == 1 || currentLevel == 2)
    {
      targetPosition = stepsPerRevolution; // Mover hacia el nivel 3
      stepper.setSpeed(10); // Ajusta la velocidad según sea necesario
      stepper.step(targetPosition - currentPosition);
      currentPosition = targetPosition;
      currentLevel = 3;
    }
  }
}
