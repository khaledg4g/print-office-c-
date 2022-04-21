
// Fonction setup(), appelée au démarrage de la carte Arduino
void setup() {
pinMode(4,OUTPUT); //LED VERTE
  pinMode(8,OUTPUT); //LED ROUGE
  pinMode(12,OUTPUT); //ventilateur
  // Initialise la communication avec le PC
  Serial.begin(9600);
}

// Fonction loop(), appelée continuellement en boucle tant que la carte Arduino est alimentée
void loop() {
  
  // Mesure la tension sur la broche A0
  int valeur_brute = analogRead(A0);
  
  // Transforme la mesure (nombre entier) en température via un produit en croix
  int temperature_celcius = valeur_brute * (5.0 / 1023.0 * 100.0);
//String num_str1(std::(float));
  // Envoi la mesure au PC pour affichage et attends 250ms
  Serial.println(temperature_celcius);
  //Serial.write(temperature_celcius);
  delay(250);
  if(temperature_celcius>30)
  {
   digitalWrite(4,LOW); //  VERTE ETEINTE
   digitalWrite(8,HIGH); //  ROUGE ALLUMEE
    digitalWrite(12,LOW); //  ventilateur ALLUME
  }
  
  else{
    digitalWrite(4,HIGH); // VERTE ALLUMEE
    digitalWrite(8,LOW); // ROUGE ETEINTE
    digitalWrite(12,HIGH); //  ventilateur ETEINT
  }
  
}
