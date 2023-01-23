// Classe LED
class LED {
  private:
    int pin; // Pin del LED
  	int stato;

  public:
    // Costruttore: imposta la modalità del pin del LED come output
    LED(int p) {
      pin = p;
      pinMode(pin, OUTPUT);
      spegni();
    }

    // Metodo per accendere il LED
    void accendi() {
      digitalWrite(pin, HIGH);
      stato=1;
    }

    // Metodo per spegnere il LED
    void spegni() {
      digitalWrite(pin, LOW);
      stato=0;
    }
  	void inverti() {
      if(stato==0) {
      	accendi();
      }
      else {
        spegni();
      }
    }
  	void lampeggio(int nrLampeggi) {
      int i=0;
      while(i<nrLampeggi) {
        if(stato==1) {
          i++;
        }
        delay(500);
        inverti();
      }
    }
    void ledTest(int numeroTest) {
      if (numeroTest==0) {
	      lampeggio(5);
      }
    }
};

// Crea un oggetto LED sulla porta 13
LED led(13);

void setup() {
  // Non c'è nulla da fare qui
  led.ledTest(0);
}

void loop() {
  // Aspetta per un secondo
  /*delay(1000);
  led.inverti();*/
}
