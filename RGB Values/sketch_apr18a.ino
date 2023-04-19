// Definir los pines del sensor de color TCS3200
const int S0 = 4;
const int S1 = 5;
const int S2 = 6;
const int S3 = 7;
const int OUT = 8;

void setup() {
  Serial.begin(9600);

  // Configurar los pines de control del sensor de color
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT); 
  
  // Configurar el sensor de color para el modo de ganancia 100
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);
}

void loop() {
  int R = getRed();
  delay(200);

  int G = getGreen();
  delay(200);

  int B = getBlue();
  delay(200);

  Serial.print("RED " + String(R));
  Serial.print(" GREEN " + String(G));
  Serial.println(" BLUE " + String(B));

  // Esperar 1 segundo antes de volver a medir el color
 delay(1000);
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
