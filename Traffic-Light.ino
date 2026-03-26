// Array pin [lajur][hijau, kuning, merah]
int lampu[4][3] = {
  {2, 3, 4},
  {5, 6, 7},
  {8, 9, 10},
  {11, 12, 13}
};

void setup() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(lampu[i][j], OUTPUT);
    }
  }
}

void semuaMerah() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lampu[i][0], LOW);  
    digitalWrite(lampu[i][1], LOW);  
    digitalWrite(lampu[i][2], HIGH); 
  }
}

// Fungsi kedip kuning
void kuningKedip(int pinKuning, int jumlahKedip, int delayTime) {
  for (int i = 0; i < jumlahKedip; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(delayTime);
    digitalWrite(pinKuning, LOW);
    delay(delayTime);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {

    // Semua merah
    semuaMerah();

    // Kuning sebelum hijau (kedip ±2 detik)
    digitalWrite(lampu[i][2], LOW); // merah mati
    kuningKedip(lampu[i][1], 4, 250);

    // Hijau (5 detik)
    digitalWrite(lampu[i][0], HIGH);
    delay(5000);
    digitalWrite(lampu[i][0], LOW);

    // Kuning setelah hijau (kedip 3x)
    kuningKedip(lampu[i][1], 3, 333);

    // Kembali merah
    digitalWrite(lampu[i][2], HIGH);
  }
}