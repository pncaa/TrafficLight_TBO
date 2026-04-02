# 🚦 Arduino Traffic Light + Pedestrian Crossing

Proyek ini merupakan simulasi sistem lampu lalu lintas sederhana dengan tambahan pedestrian crossing menggunakan Arduino. Sistem ini memungkinkan penyebrang jalan menekan tombol untuk menghentikan kendaraan sementara.

---

## 📌 Fitur Utama
- 1 traffic light untuk kendaraan
- 2 pedestrian traffic light (dua sisi jalan)
- Tombol untuk penyebrang jalan
- Logika interaktif:
  - Default: kendaraan hijau, pedestrian merah
  - Saat tombol ditekan:
    - Kendaraan merah selama 5 detik
    - Pedestrian hijau selama 5 detik
    - Kendaraan kuning berkedip selama 2 detik
- Menggunakan konsep modularisasi (fungsi)

---

## 🔌 Konfigurasi Pin

### 🚗 Traffic Light (Kendaraan)
| Warna | Pin |
|------|-----|
| Merah | 12 |
| Kuning | 11 |
| Hijau | 10 |

### 🚶 Pedestrian Traffic Light
| Warna | Pin |
|------|-----|
| Merah 1 | 3 |
| Merah 2 | 5 |
| Hijau 1 | 2 |
| Hijau 2 | 4 |

### 🔘 Tombol
| Komponen | Pin |
|----------|-----|
| Button | 9 |

---

## 🖥️ Desain Rangkaian

Berikut adalah tampilan rangkaian pada Tinkercad:

![Circuit Design](images/Circuit4.png)

---

## 🔗 Link Simulasi Tinkercad
Klik link berikut untuk melihat dan menjalankan simulasi:

👉 https://www.tinkercad.com/things/2O46Q4010ss-pedestrian-traffic-light

---

## ⚙️ Cara Menjalankan
1. Buka Arduino IDE / Tinkercad
2. Upload file `.ino`
3. Pastikan rangkaian sesuai dengan konfigurasi pin
4. Tekan tombol untuk mengaktifkan pedestrian crossing
5. Jalankan simulasi / upload ke board Arduino

