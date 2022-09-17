int VRX = 5;
int VRY = 18;
int LedVermelho = 13;
int LedVerde = 12;
int LedAmarelo = 14;
int LedAzul = 27;

int Ordem[10];

int Rodada = 3;

void setup() {
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedAmarelo, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(0));
  GerarOrdem();

}

void loop() {
  for (int i = 0; i < Rodada; i++) {
    PiscarLed(Ordem[i]);
  }
  for (int j = 0; j < Rodada; j++) {
    int Botao = EsperarJogador();
    Serial.print("Apertou o botao: ");
    Serial.println(Botao);
    if (Botao == Ordem[j]) {

    } else {
      Errou();
      break;
    }

  }
  Rodada++;

  delay(10); // this speeds up the simulation
}

void GerarOrdem() {
  for (int i = 0; i < 10; i++) {
    Ordem[i] = random(0, 4);
    Serial.print(Ordem[i]);
    Serial.print(", ");
  }
}

void PiscarLed(int Led) {
  if (Led == 0) {
    digitalWrite(LedVermelho, HIGH);
    delay(1000);
    digitalWrite(LedVermelho, LOW);
    delay(1000);
  } else if (Led == 1) {
    digitalWrite(LedVerde, HIGH);
    delay(1000);
    digitalWrite(LedVerde, LOW);
    delay(1000);
  } else if (Led == 2) {
    digitalWrite(LedAmarelo, HIGH);
    delay(1000);
    digitalWrite(LedAmarelo, LOW);
    delay(1000);
  } else if (Led == 3) {
    digitalWrite(LedAzul, HIGH);
    delay(1000);
    digitalWrite(LedAzul, LOW);
    delay(1000);
  }
}

int EsperarJogador() {
  VRX = analogRead(5);
  VRY = analogRead(18);
  int Botao;
  while (VRX > 1500 && VRX < 3000 && VRY > 1500 && VRY < 3000) {
    delay(100);
    VRX = analogRead(5);
    VRY = analogRead(18);
    delay(250);
  }
  delay(250);
  if (VRY > 3000) {
    Botao = 1;
  } else if (VRY < 1000) {
    Botao = 0;
  } else if (VRX > 4000) {
    Botao = 2;
  } else if (VRX < 1000) {
    Botao = 3;
  }

  return Botao;
}

void Errou() {
  digitalWrite(LedVermelho, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedAmarelo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(200);
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedAzul, LOW);
  delay(200);
  digitalWrite(LedVermelho, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedAmarelo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(200);
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedAzul, LOW);
  delay(200);
  digitalWrite(LedVermelho, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedAmarelo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(200);
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedAzul, LOW);
  delay(200);
  digitalWrite(LedVermelho, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedAmarelo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(200);
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedAzul, LOW);
  delay(200);
  digitalWrite(LedVermelho, HIGH);
  digitalWrite(LedVerde, HIGH);
  digitalWrite(LedAmarelo, HIGH);
  digitalWrite(LedAzul, HIGH);
  delay(200);
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedVerde, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedAzul, LOW);
  delay(200);
  Rodada = -1;
  GerarOrdem();

}
