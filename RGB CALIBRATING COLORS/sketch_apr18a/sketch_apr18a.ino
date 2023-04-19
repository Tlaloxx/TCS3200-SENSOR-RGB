// Definir los pines del sensor de color TCS3200
const int OUT = 3;
const int S0 = 4;
const int S1 = 5;
const int S2 = 6;
const int S3 = 7;

void setup() {
  
  // Establecer la velocidad de la comunicación serial
  Serial.begin(9600);

  // Configurar los pines de control del sensor de color
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT); 
  
  // Configurar el sensor de color en una escala de frecuencia del 100%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}

void loop() {
  int R = getRed();
  delay(100);

  int G = getGreen();
  delay(100);

  int B = getBlue();
  delay(100);

  // Valores RGB para calibrar la deteccion de colores
  
  Serial.print("RED " + String(R));
  Serial.print(" GREEN " + String(G));
  Serial.println(" BLUE " + String(B));

/*
COLOR  
R = 12    
G = 9    
B = 6
       
1. (R > G)
2. (G < B)
3. (R > 10)
4. (R < 15)
*/

if(R < G && G > B && R > 1 && R < 10){
  Serial.println(" El color es rojo");
  }
if(R <= G && G <= B && R < 5 && R > 1){
  Serial.println(" El color es amarillo");
  }
}

int getRed() {
  // Leer color rojo
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int RED = pulseIn(OUT, LOW);
  return RED; 
}

int getGreen() {
  // Leer color verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int GREEN = pulseIn(OUT, LOW);
  return GREEN; 
}

int getBlue() {
  // Leer color azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int BLUE = pulseIn(OUT, LOW);
  return BLUE; 
}
