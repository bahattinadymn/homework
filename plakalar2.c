#include <stdio.h>
#include <string.h>

#define MAX_SEHIR 8 // kullandigimiz dosyadaki maksimum sehir sayisi

int main() {
    FILE *dosya;
    int plaka_kodlari[MAX_SEHIR];   // plaka kodlari dosyadan okundugunda bunlari saklayan tam sayi dizisi
    char sehirler[MAX_SEHIR][30];   // sehir isimleri dosyadan okuhdugunda bunlari saklayan karakter dizisi
    int toplam_sehir = 0;   // dosyadan okunan her sehir icin degeri bir artar
    int aranan_plaka;  // kullanicinin klavyeden girecegi plaka kodunu saklayan degisken
    int bulundu = 0;  // girilen plaka kodunun dosyada olup olmadigini kontrol eder

    // Dosyayi acildi
    dosya = fopen("C:\\Users\\bhtna\\Documents\\Artvin_08.txt", "r");
      // dosya adresi ve dosyada yapilacak islem gstergesi (r -> read)

          if (dosya == NULL) {     
              printf("Dosya acilmadi!\n");
               return 1;
           }   // dosynin acilip acilmadigini kontrol eder


    // Dosyadan plaka kodlari ve sehirleri oku

    while (fscanf(dosya, "%d %s", &plaka_kodlari[toplam_sehir], sehirler[toplam_sehir]) != EOF) { 
        toplam_sehir++;
      //EOF (end of file) dosyanin sonu
    } // plaka kodlarini ve sehirleri dosyadan okuyup dizi olarak alir


    fclose(dosya);
    // dosya okuma islemi tamamlandi dosya kapatildi

    // Kullanicidan plaka kodu iste
    printf("Lutfen bir plaka kodu giriniz: ");
    scanf("%d", &aranan_plaka);

    // Aranan plaka kodunu bul
    for (int i = 0; i < toplam_sehir; i++) {
        if (plaka_kodlari[i] == aranan_plaka) {
            printf("Plaka kodu %d olan sehir: %s Ve bu şehir dogu karadeniz bolgesinde yey alir\n", aranan_plaka, sehirler[i]);
            bulundu = 1;
            break; //girilen plaka kodu dizinin elmanlari ile karsilastirilir ve dizide varsa ekrana yazdirilir
        }
    }

    if (!bulundu) {
        printf("Plaka kodu %d'ye ait bir şehir bulunamadi.\n", aranan_plaka);
    } 
          //girilen plaka kodu bulunamazsam ekrana bulunamadi ifadesi yazdirilir

    return 0;
}