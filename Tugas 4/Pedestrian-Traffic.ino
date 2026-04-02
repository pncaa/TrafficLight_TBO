// Traffic Light (Kendaraan)
const int merahKendaraan = 12;
const int kuningKendaraan = 11;
const int hijauKendaraan = 10;

// Pedestrian (masing-masing LED)
const int merahPed1 = 3;
const int merahPed2 = 5;
const int hijauPed1 = 2;
const int hijauPed2 = 4;

// Tombol
const int tombol = 9;

bool sedangProses = false;

void setup() {
  pinMode(merahKendaraan, OUTPUT);
  pinMode(kuningKendaraan, OUTPUT);
  pinMode(hijauKendaraan, OUTPUT);

  pinMode(merahPed1, OUTPUT);
  pinMode(merahPed2, OUTPUT);
  pinMode(hijauPed1, OUTPUT);
  pinMode(hijauPed2, OUTPUT);

  pinMode(tombol, INPUT_PULLUP);

  kondisiNormal();
}

void loop() {
  if (digitalRead(tombol) == LOW && !sedangProses) {
    sedangProses = true;
    delay(50); // debounce

    jalankanSiklus();

    sedangProses = false;
  }
}

// ================= FUNCTION =================

void kondisiNormal() {
  // Kendaraan hijau
  digitalWrite(hijauKendaraan, HIGH);
  digitalWrite(kuningKendaraan, LOW);
  digitalWrite(merahKendaraan, LOW);

  // Pedestrian merah
  digitalWrite(merahPed1, HIGH);
  digitalWrite(merahPed2, HIGH);
  digitalWrite(hijauPed1, LOW);
  digitalWrite(hijauPed2, LOW);
}

void jalankanSiklus() {

  // 1. Kendaraan MERAH, Pedestrian HIJAU
  digitalWrite(hijauKendaraan, LOW);
  digitalWrite(kuningKendaraan, LOW);
  digitalWrite(merahKendaraan, HIGH);

  digitalWrite(merahPed1, LOW);
  digitalWrite(merahPed2, LOW);
  digitalWrite(hijauPed1, HIGH);
  digitalWrite(hijauPed2, HIGH);

  delay(5000); // 5 detik

  // 2. Pedestrian kembali MERAH
  digitalWrite(hijauPed1, LOW);
  digitalWrite(hijauPed2, LOW);
  digitalWrite(merahPed1, HIGH);
  digitalWrite(merahPed2, HIGH);

  // 3. Kuning kedip 2 detik
  digitalWrite(merahKendaraan, LOW);

  for (int i = 0; i < 4; i++) {
    digitalWrite(kuningKendaraan, HIGH);
    delay(250);
    digitalWrite(kuningKendaraan, LOW);
    delay(250);
  }

  // 4. Kembali normal
  kondisiNormal();
}