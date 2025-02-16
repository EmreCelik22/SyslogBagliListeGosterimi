#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Düğüm yapısı tanımı
struct LogDugumu {
    char mesaj[100];           // Log mesajı
    char zaman[20];            // Tarih/zaman bilgisi
    struct LogDugumu* sonraki; // Sonraki düğüme işaretçi
};

// Log ekleme fonksiyonu
void logEkle(struct LogDugumu** bas, const char* mesaj, const char* zaman) {
    // Yeni düğüm oluştur
    struct LogDugumu* yeniDugum = (struct LogDugumu*)malloc(sizeof(struct LogDugumu));
    strcpy(yeniDugum->mesaj, mesaj);
    strcpy(yeniDugum->zaman, zaman);
    yeniDugum->sonraki = NULL;

    // Liste boşsa yeni düğümü baş düğüm yap
    if (*bas == NULL) {
        *bas = yeniDugum;
        return;
    }

    // Listenin sonuna ekle
    struct LogDugumu* gecici = *bas;
    while (gecici->sonraki != NULL) {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeniDugum;
}

// Logları yazdırma fonksiyonu
void loglariYazdir(struct LogDugumu* bas) {
    struct LogDugumu* gecici = bas;
    while (gecici != NULL) {
        printf("Zaman: %s, Mesaj: %s\n", gecici->zaman, gecici->mesaj);
        gecici = gecici->sonraki;
    }
}

int main() {
    struct LogDugumu* logListesi = NULL;

    // Log ekleme
    logEkle(&logListesi, "Sistem baslatildi", "2025-02-16 10:00");
    logEkle(&logListesi, "Kullanici oturum acti", "2025-02-16 10:30");
    logEkle(&logListesi, "Disk alani dolmak uzere", "2025-02-16 11:00");
    logEkle(&logListesi, "CPU sicakligi yuksek", "2025-02-16 11:00");

    // Logları yazdır
    loglariYazdir(logListesi);

    return 0;
}

