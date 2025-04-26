#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);
const byte address[6] = "00001";

void setup() {
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_LOW);
    radio.stopListening();
}

void loop() {
    const char* texts[] = {"FRENTE", "TRAS", "DIREITA", "TRAS"};

    for (int i = 0; i < 4; i++) {
        int tam = strlen(texts[i]);
        radio.write(texts[i], tam+1);
        delay(1000);
    }
}