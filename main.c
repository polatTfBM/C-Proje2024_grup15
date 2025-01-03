#include <stdio.h>
#include <ctype.h> // toupper fonksiyonunu kullanmak için gerekli

int tusSayisi(char harf);// Okunur olması için protatip tanımlama

int main() {
    char karakter;
    int toplamTus = 0; // Toplam tuş basım sayısını tutacak değişken

    char txtName[120];       // Kullanıcının girdiği dosya adını tutar
    char txtFullName[200];   // Dosyanın tam yolunu tutar

    // Kullanıcıdan dosya adını isteme
    printf("Kisa mesaji iceren dosyanin adini giriniz (örneğin: mesaj.txt): ");
    scanf("%s", txtName);

    // Tam dosya yolunu oluşturma
    sprintf(txtFullName, "/Users/polatashyrov/Desktop/Proje2024C/%s", txtName);

    // Dosyayı okuma modunda aç
    FILE *dosya = fopen(txtFullName, "r");
    if (dosya == NULL) { // Eğer dosya açılamazsa
        printf("Dosya açılamadı: %s\n", txtFullName); // Hata mesajı
        return 1;
    }

    // Dosyayı karakter karakter oku
    while ((karakter = fgetc(dosya)) != EOF) {
        karakter = toupper(karakter); // Karakteri büyük harfe çevir
        toplamTus += tusSayisi(karakter); // Her karakter için gerekli tuş basım sayısını topla
    }

    fclose(dosya); // Dosyayı kapat

    // Sonuç dosyasına toplam tuş basımını yaz
    FILE *ciktiDosya = fopen("/Users/polatashyrov/Desktop/Proje2024C/frekans.txt", "w");
    if (ciktiDosya == NULL) { // Eğer çıktı dosyası oluşturulamazsa
        printf("Çıktı dosyası oluşturulamadı!\n"); // Hata mesajı
        return 1;
    }

    fprintf(ciktiDosya, "Toplam %d kez tuşa basılacaktır.\n", toplamTus); // Sonuç dosyasına yaz
    fclose(ciktiDosya); // Çıktı dosyasını kapat

    // Kullanıcıya sonuç hakkında bilgi ver
    printf("Sonuç frekans.txt dosyasına yazıldı.\n");
    printf("Toplam %d kez tuşa basılacaktır.\n", toplamTus);

    return 0;
}

// Verilen bir karakter için kaç tuşlama gerektiğini hesaplayan fonksiyon
int tusSayisi(char harf) {
    switch(harf) {
        case 'A':case 'D': case 'G': case 'J': case 'M': case 'P': case 'T': case 'W': return 1; // Birinci grup harfler: 1 tuş basımı
        case 'B': case 'E': case 'H': case 'K': case 'N': case 'Q': case 'U': case 'X': case ',': return 2; // İkinci grup harfler: 2 tuş basımı
        case 'C': case 'F': case 'I': case 'L': case 'O': case 'R': case 'V': case 'Y': return 3; // Üçüncü grup harfler: 3 tuş basımı
        case ' ': case'.': return 1; // Boşluk karakteri: 1 tuş basımı
        default: return 0;  // Geçersiz karakterler için 0 döndür
    }
}
