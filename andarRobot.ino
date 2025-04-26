#define IN1_M1 8
#define IN2_M1 9
#define IN3_M1 10
#define IN4_M1 11

#define IN1_M2 4
#define IN2_M2 5
#define IN3_M2 6
#define IN4_M2 7

const int steps[8][4] = {
  { 1, 0, 0, 0 },
  { 1, 1, 0, 0 },
  { 0, 1, 0, 0 },
  { 0, 1, 1, 0 },
  { 0, 0, 1, 0 },
  { 0, 0, 1, 1 },
  { 0, 0, 0, 1 },
  { 1, 0, 0, 1 },
};

void setup() {
    Serial.begin(9600);
    pinMode(IN1_M1, OUTPUT);
    pinMode(IN2_M1, OUTPUT);
    pinMode(IN3_M1, OUTPUT);
    pinMode(IN4_M1, OUTPUT);
    pinMode(IN1_M2, OUTPUT);
    pinMode(IN2_M2, OUTPUT);
    pinMode(IN3_M2, OUTPUT);
    pinMode(IN4_M2, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        String com; 
        com = Serial.readStringUntil('\n');
        com.trim();
        Serial.println(com);
        if (com == "FRENTE") {
            moverFrente(1000);
        } else if (com == "TRAS") {
            moverTras(1000);
        } else if (com == "DIREITA") {
            giraDireita(1000);
            moverFrente(1000);
        } else if (com == "ESQUERDA") {
            giraEsquerda(1000);
            moverFrente(1000);
        }
    }
}

void moverFrente(int contagemPassos) {
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(IN1_M1, steps[j][0]);
      digitalWrite(IN2_M1, steps[j][1]);
      digitalWrite(IN3_M1, steps[j][2]);
      digitalWrite(IN4_M1, steps[j][3]);
      
      digitalWrite(IN1_M2, steps[j][3]);
      digitalWrite(IN2_M2, steps[j][2]);
      digitalWrite(IN3_M2, steps[j][1]);
      digitalWrite(IN4_M2, steps[j][0]);
      delay(2);
    }
  }
}

void moverTras(int contagemPassos) {
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(IN1_M1, steps[j][3]);
      digitalWrite(IN2_M1, steps[j][2]);
      digitalWrite(IN3_M1, steps[j][1]);
      digitalWrite(IN4_M1, steps[j][0]);
      
      digitalWrite(IN1_M2, steps[j][0]);
      digitalWrite(IN2_M2, steps[j][1]);
      digitalWrite(IN3_M2, steps[j][2]);
      digitalWrite(IN4_M2, steps[j][3]);
      delay(2);
    }
  }
}

void giraDireita(int contagemPassos) {
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(IN1_M1, steps[j][0]);
      digitalWrite(IN2_M1, steps[j][1]);
      digitalWrite(IN3_M1, steps[j][2]);
      digitalWrite(IN4_M1, steps[j][3]);
      
      digitalWrite(IN1_M2, steps[j][0]);
      digitalWrite(IN2_M2, steps[j][1]);
      digitalWrite(IN3_M2, steps[j][2]);
      digitalWrite(IN4_M2, steps[j][3]);
      delay(2);
    }
  }
}

void giraEsquerda(int contagemPassos) {
  for (int i = 0; i < contagemPassos; i++) {
    for (int j = 7; j >= 0; j--) {
      digitalWrite(IN1_M1, steps[j][0]);
      digitalWrite(IN2_M1, steps[j][1]);
      digitalWrite(IN3_M1, steps[j][2]);
      digitalWrite(IN4_M1, steps[j][3]);
      
      digitalWrite(IN1_M2, steps[j][0]);
      digitalWrite(IN2_M2, steps[j][1]);
      digitalWrite(IN3_M2, steps[j][2]);
      digitalWrite(IN4_M2, steps[j][3]);
      delay(2);
    }
  }
}