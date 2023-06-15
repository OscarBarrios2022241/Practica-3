#include <Stepper.h>
#include "LedControl.h"     // incluye libreria LedControl

LedControl lc=LedControl(11,13,10,1); // crea objeto
#define Pul3 4
#define Pul2 3
#define Pul1 2
#define demora 1000     // constante demora con valor de 1000


byte cero[8]= {       // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito cero
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B00111000
};

byte uno[8]= {        // array que contiene todos los elementos de las
  B00010000,        // filas necesarias por mostrar el digito uno
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

byte dos[8]= {        // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito dos
  B01000100,
  B00000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111100
};

byte tres[8]= {       // array que contiene todos los elementos de las
  B00111000,        // filas necesarias por mostrar el digito tres
  B01000100,
  B00000100,
  B00011000,
  B00000100,
  B00000100,
  B01000100,
  B00111000
};

const int pasos_T = 1500;
Stepper Motor(pasos_T, 5, 7, 6, 8);
bool inter =0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(2) , Interrupcion1, FALLING);//Interrupcion que controlara el 1er pulsador
  Motor.setSpeed(15);
  pinMode(Pul1, INPUT);
  pinMode(Pul2, INPUT);
  pinMode(Pul3, INPUT);
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);     // blanquea matriz
}

void loop() {
  if(inter == 1){//Se crea la variable inter para controlar el 1er pulsador
  Motor.step(-10000);
  delay(50);
  mostrar_1();        // llama funcion mostrar_0
  delay(demora);      // demora
  inter = 0;
  }

  if(digitalRead(Pul2)== 0){
  Motor.step(20000);
  mostrar_0();        // llama funcion mostrar_1
  delay(demora);      // demora
  delay(50);
  }

  if(digitalRead(Pul3)== 0){
  Motor.step(-10000);
  mostrar_2();        // llama funcion mostrar_2
  delay(demora);      // demora
  delay(50);
  }

  digitalWrite(5,LOW);
   digitalWrite(6,LOW);
    digitalWrite(7,LOW);
     digitalWrite(8,LOW);
}


void Interrupcion1(){//Interrupcion que se va a ejecutar al momento de presionar el 1er pulsador
  inter = 1;
}


void mostrar_0(){     // funcion mostrar_0
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
    lc.setRow(0,i,cero[i]);   // establece fila con valor de array cero en misma posicion
  }
}

void mostrar_1(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno[i]);    // establece fila con valor de array uno en misma posicion
  }
}




void mostrar_2(){     // funcion mostrar_2
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,dos[i]);    // establece fila con valor de array dos en misma posicion
  }
}

void mostrar_3(){     // funcion mostrar_3
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,tres[i]);   // establece fila con valor de array tres en misma posicion
  }
}