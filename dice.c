
/*
 * ----------------------------------------------------------------------------
 *from an idea of Heliox
 *https://www.youtube.com/watch?v=S-oBujsoe-Q
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <h2mille@gmail.com wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Hugo van Santen
 * ----------------------------------------------------------------------------
 */

// Pour les LED
#define pinLed1 0
#define pinLed2 1
#define pinLed3 2
#define pinLed4  3
// on indique la pin du capteur d'inclinaison
#define buttonPin  4
// Temps que le dé reste affiché 1000 ms = 1 seconde
#define TIME  7000 


void print_led(int number){
  int led;
  switch(number)
  {
    case 1:
      led=0b1000;
      break;
    case 2:
      led=0b0001;
      break;
    case 3:
      led=0b1100;
      break;
    case 4:
      led=0b1010;
      break;
    case 5:
      led=0b1101;
      break;
    case 6:
      led=0b0111;
      break;
    case 0:
    default:
      led=0b0;
        break;
  }
  // on compare le n-ième bit pour la n-ième led.
  //ça donne 2 puissance n, qu'on décalle de n à droit.
  //Ainsi, on a 1 si le bit est à 1, 0 sinon.
  digitalWrite (pinLed1, (led&0b0001)>>0);
  digitalWrite (pinLed2, (led&0b0010)>>1);
  digitalWrite (pinLed3, (led&0b0100)>>2);
  digitalWrite (pinLed4, (led&0b1000)>>3);
}

// ----- DECLARATION ENTREES ET SORTIES ------
void setup ()
{
  //On indique que les LED sont des sorties
  pinMode (pinLeds1, OUTPUT);
  pinMode (pinLeds2, OUTPUT);
  pinMode (pinLeds3, OUTPUT);
  pinMode (pinLeds4, OUTPUT);
  // On indique que le detecteur d'inclinaison est une entrée.
  pinMode (buttonPin, INPUT);

  randomSeed(analogRead(0)); // on initialise le fait de pouvoir lancer des randoms
}

// ----- ACTIONS A EFFECTUER ------
void loop()
{  
  // On vérifie l'état du capteur d'inclinaison
  int buttonState;
  // Variable pour le random de l'animation 
  long ranim;
  // Variable pour le random du résultat final
  long ran;
  // Il n'y a pas encore eu de lancement de dé
  int last = 0;

  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){ // Si on bouge le dé
  // Animation pour 8 affichages de dé avec 200 ms entre chaque
    for (int i=0; i <= 7; i++){ 
    last=8
    ranim = random(1, 6); // on effectue un random pour chaque affichage
    if(ranim>=last)
      ranim++;
    last = ranim; // On stock le chiffre pour éviter d'afficher les 2 mêmes valeurs de dé pendant l'animation
    print_led(ranim);
    delay(200); // Pause entre l'affichage de l'animation : 200ms led éteintes
    print_led(0);
    delay(50);
    }
    
  // RANDOM DU RESULTAT FINAL
    ran = random(1, 7);
    print_led(ran);
    delay (TIME);
  // On éteint tout pour pouvoir relancer le dé
    print_led(0);
  }
  
  delay(100);
}
