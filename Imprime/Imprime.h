#ifndef _IMPRIME_H
#define _IMPRIME_H

#include <Arduino.h>
#include <ArduinoJson.h>

class Imprime {

    private:

    public:
        Imprime();
        void pula_linha(int nivel=0);
        void seta_nivel(int nivel=0);
        void separador(int nivel=0);
        void piscaLed();
        String stringSerial();
        void ledDebug(int pino);
        void temposLed(int tempoLigado=1000,int tempoDesligado=1000);
        void print(String texto="", String valor="", int nivel=0);
};
#endif