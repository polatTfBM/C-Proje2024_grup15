# C-Proje2024_grup15
#include <stdio.h>
#include <ctype.h> // toupper fonksiyonu için

// Tuş takımına göre basım sayısını dönen bir fonksiyon
int tuşSayisi(char harf) {
    switch(harf) {
        case 'A': case 'D': case 'G': case 'J': case 'M': case 'P': case 'T': case 'W': return 1;
        case 'B': case 'E': case 'H': case 'K': case 'N': case 'Q': case 'U': case 'X': return 2;
        case 'C': case 'F': case 'I': case 'L': case 'O': case 'R': case 'V': case 'Y': return 3;
        case ' ': return 1; // Boşluk için
        default: return 0;  // Geçersiz karakterler için
    }
}

int main() {
    char karakter;
    int toplamTus = 0;

    char txtName[120];       // Kullanıcının girdiği dosya adı
    char txtFullName[200];   // Tam dosya yolu

    printf("Kisa mesaji iceren dosyanin adini giriniz (örneğin: mesaj.txt): ");
    scanf("%s", txtName);

    // Tam dosya yolunu oluştur
    sprintf(txtFullName, "/Users/polatashyrov/Desktop/Proje2024C/%s", txtName);

    // Dosyayı aç
    FILE *dosya = fopen(txtFullName, "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı: %s\n", txtFullName);
        return 1;
    }

    // Dosya karakter karakter okunur
    while ((karakter = fgetc(dosya)) != EOF) {
        karakter = toupper(karakter); // Büyük harfe çevir
        toplamTus += tuşSayisi(karakter);
    }

    fclose(dosya);

    // Çıktıyı frekans.txt dosyasına yaz
    FILE *ciktiDosya = fopen("/Users/polatashyrov/Desktop/Proje2024C/frekans.txt", "w");
    if (ciktiDosya == NULL) {
        printf("Çıktı dosyası oluşturulamadı!\n");
        return 1;
    }

    fprintf(ciktiDosya, "Toplam %d kez tuşa basılacaktır.\n", toplamTus);
    fclose(ciktiDosya);

    printf("Sonuç frekans.txt dosyasına yazıldı.\n");
    return 0;
}

