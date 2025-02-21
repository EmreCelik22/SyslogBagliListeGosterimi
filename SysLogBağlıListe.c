#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_SATIR_UZUNLUK 1024

// Bağlı liste düğüm yapısı
typedef struct Dugum {
    char veri[MAKS_SATIR_UZUNLUK]; // Syslog satırını saklayan karakter dizisi
    struct Dugum* sonraki; // Sonraki düğüme işaretçi
} Dugum;

// Bağlı listeye yeni düğüm ekleyen fonksiyon
void dugum_ekle(Dugum** bas, const char* satir) {
    Dugum* yeni_dugum = (Dugum*)malloc(sizeof(Dugum)); // Yeni düğüm için bellek tahsisi
    if (!yeni_dugum) {
        printf("Bellek tahsis hatası!\n");
        return;
    }
    strncpy(yeni_dugum->veri, satir, MAKS_SATIR_UZUNLUK); // Syslog satırını kopyala
    yeni_dugum->veri[MAKS_SATIR_UZUNLUK - 1] = '\0'; // Güvenlik için sonlandırıcı karakter ekle
    yeni_dugum->sonraki = NULL;

    if (*bas == NULL) {
        *bas = yeni_dugum; // Liste boşsa baş düğümü olarak ayarla
    } else {
        Dugum* gecici = *bas;
        while (gecici->sonraki)
            gecici = gecici->sonraki;
        gecici->sonraki = yeni_dugum; // Listenin sonuna ekle
    }
}

// Bağlı listedeki verileri ekrana yazdıran fonksiyon
void listeyi_yazdir(Dugum* bas) {
    Dugum* gecici = bas;
    while (gecici) {
        printf("%s", gecici->veri); // Her düğümün verisini yazdır
        gecici = gecici->sonraki;
    }
}

// Bağlı listeyi temizleyen fonksiyon
void listeyi_temizle(Dugum** bas) {
    Dugum* gecici = *bas;
    while (gecici) {
        Dugum* silinecek = gecici;
        gecici = gecici->sonraki;
        free(silinecek); // Belleği serbest bırak
    }
    *bas = NULL;
}

int main() {
    // Syslog dosyasını okuma modunda aç
    FILE* dosya = fopen("/var/log/syslog", "r");
    if (!dosya) {
        printf("Syslog dosyası açılamadı!\n");
        return 1;
    }

    Dugum* bas = NULL;
    char satir[MAKS_SATIR_UZUNLUK];
    
    // Syslog dosyasını satır satır oku ve bağlı listeye ekle
    while (fgets(satir, MAKS_SATIR_UZUNLUK, dosya)) {
        dugum_ekle(&bas, satir);
    }
    fclose(dosya);
    
    printf("Syslog verileri:\n");
    listeyi_yazdir(bas); // Bağlı listeyi ekrana yazdır
    
    listeyi_temizle(&bas); // Belleği temizle
    return 0;
}
