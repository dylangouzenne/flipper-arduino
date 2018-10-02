// ////////////////// programme pour le fliper //////////////////

#include <Servo.h>                    // permet de faire appel à la bibliothèque Servo
#include <LiquidCrystal.h>            //fait appel a la bibliothèque liquidCristal

Servo monservo1;                       // crée une constante appelée « monservo » utilisable par la bibliothèque Servo.
Servo monservo2;                       // crée une constante appelée « monservo » utilisable par la bibliothèque Servo.

int bouton1 = 8;                       // déclare le bouton1 sur la PIN 8.
int etatbouton1 = 0;                   // variable représentant le bouton, soit ouvert ou fermé, ici au départ à 0 donc fermé.

int bouton2 = 0;                       // déclare le bouton2 sur la PIN 0.
int etatbouton2 = 0;                   // variable représentant le bouton, soit ouvert ou fermé, ici au départ à 0 donc fermé.

LiquidCrystal lcd (12,11,5,4,3,2);    // liaison 4 bits de données ecran

int obstacle1 = 6;                    // déclarer obstacle1 sur le pin 6
int etatobstacle1 = 0;                // On lit l’état du bouton obstacle1 pour savoir s’il est ouvert ou fermé

int obstacle2 = 7;                    // déclarer obstacle2 sur le pin 7
int etatobstacle2 = 0;                // On lit l’état du bouton obstacle2 pour savoir s’il est ouvert ou fermé

int led1 = 10;                        // déclarer led1 pour obstacle1 sur pin 10
int led2 = 13;                        // déclarer led2 pour obstacle2 sur pin 13

int compteur = 0;


void setup() {

Serial.begin(9600);
  
pinMode (bouton1, INPUT);              // on indique que le bouton1 est une entrée.
monservo1.attach(9);                   // commande de la bibliothèque Servo, qui consiste à « attacher » le servomoteur à la PIN 9

pinMode (bouton2, INPUT);              // on indique que le bouton2 est une entrée.
monservo2.attach(1);                   // commande de la bibliothèque Servo, qui consiste à « attacher » le servomoteur à la PIN 2

lcd.begin(16,2);                      // utilisation d'un écran 16 colonnes et 2 lignes
lcd.write("Are you ready ?");         // petit test pour vérifier que tout marche

pinMode (obstacle1, INPUT);           // on indique que obstacle1 est une entrée.
pinMode (obstacle2, INPUT);           // on indique que obstacle2 est une entrée.

pinMode (led1, OUTPUT);               // on indique que led1 est une entrée
pinMode (led2, OUTPUT);               // on indique que led2 est une entrée



}

void loop() {

// ************************** lecture de l'etat des composants ************************* 
  
 etatbouton1 = digitalRead (bouton1);           // On lit l’état du bouton1 pour savoir s’il est ouvert ou fermé
 etatbouton2 = digitalRead (bouton1);           // On lit l’état du bouton2 pour savoir s’il est ouvert ou fermé
 etatobstacle1 = digitalRead (obstacle1);     // On lit l’état du bouton obstacle1 pour savoir s’il est ouvert ou fermé
 etatobstacle2 = digitalRead (obstacle2);     // On lit l’état du bouton obstacle2 pour savoir s’il est ouvert ou fermé

// ************************** initialisation des servo *************************

 monservo1.write (0);                         // initialisation du servo 1 a l'angle 0
 monservo2.write (0);                         // initialisation du servo 2 a l'angle 0

// ************************** affichage compteur a l'écran  *************************

 lcd.setCursor(0,1);
 Serial.println(compteur);
 lcd.write(compteur);

 // ************************** ballet 1 *************************

  if (etatbouton1 == HIGH) {           // Si la variable “etatbouton1” est ouverte, à l’état haut, donc laisse passer le courant. 
    monservo1.write (90);              // alors le servomoteur prend un angle de 90°.
    delay(150) ;                      // on attend un délais de 5 secondes  
    monservo1.write (0);               // le servomoteur revient à l’angle 0, sa position de départ.   
    }

  if (etatbouton1 == HIGH){            // Si la variable “etatbouton1” est ouverte, à l’état haut, donc laisse passer le courant.
    lcd.clear();                      // effacer l'ecran
    lcd.write("Pool");                // message afficher a la pression du bouton
    delay(500);                      // crée un délais de 150 millisecondes avant de refaire la boucle et de tester à nouveau l’état du bouton.
    lcd.clear();
  }

// ************************** ballet 2 *************************

  if (etatbouton2 == HIGH) {           // Si la variable “etatbouton2” est ouverte, à l’état haut, donc laisse passer le courant. 
    monservo2.write (90);              // alors le servomoteur prend un angle de 90°.
    delay(150) ;                      // on attend un délais de 5 secondes  
    monservo2.write (0);               // le servomoteur revient à l’angle 0, sa position de départ.   
  }

  if (etatbouton2 == HIGH){            // Si la variable “etatbouton2” est ouverte, à l’état haut, donc laisse passer le courant.
    lcd.clear();                      // effacer l'ecran
    lcd.write("Pool");                // message afficher a la pression du bouton
    delay(500);                      // crée un délais de 150 millisecondes avant de refaire la boucle et de tester à nouveau l’état du bouton.
    lcd.clear();
  }
 
// ************************** etat obstacle 1 *************************


 if (etatobstacle1 == HIGH){          // Si la variable “etatobstacle1” est ouverte, à l’état haut, donc laisse passer le courant.
    lcd.clear();
    lcd.write("obstacle 1 toucher");
    lcd.setCursor(0,1);
    lcd.write(compteur);
    digitalWrite(led1, HIGH);         // On passe la variable led1 à l'etat haut
    compteur ++;
    //delay(50);
    
  }
  else                                // Si la variable “etatobstacle1 ” est ouverte, à l’état bas, donc ne laisse plus passer le courant
    digitalWrite(led1, LOW);          // On passe la variable led1 à l'etat bas

// ************************** etat obstacle 2 *************************


if (etatobstacle2 == HIGH){          // Si la variable “etatobstacle2” est ouverte, à l’état haut, donc laisse passer le courant.
    lcd.clear();
    lcd.write("obstacle 2 toucher");
    lcd.setCursor(0,1);
    lcd.write(compteur);
    digitalWrite(led2, HIGH);         // On passe la variable led2 à l'etat haut
    compteur ++;
    //delay(50);
    
  }
  else                                // Si la variable “etatobstacle2 ” est ouverte, à l’état bas, donc ne laisse plus passer le courant
    digitalWrite(led2, LOW);          // On passe la variable led2 à l'etat bas
  
}
