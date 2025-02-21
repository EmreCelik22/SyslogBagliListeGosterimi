# Bağlı Liste ile Sistem Logları Takibi
Bu proje, C dilinde bağlı liste veri yapısını kullanarak sistem loglarını tutmak ve yönetmek için bir örnek uygulamadır. Proje, her bir log kaydını bir düğümde saklar ve yeni loglar dinamik olarak listeye eklenir.

## Özellikler
Log Ekleme: Yeni log kayıtlarını dinamik olarak listeye ekler.

Log Yazdırma: Eklenen tüm log kayıtlarını ekrana yazdırır.

Bağlı Liste Kullanımı: Loglar, bellek yönetimi için dinamik olarak bağlanmış düğümler halinde tutulur.

Bellek Yönetimi: Kullanılan bellek, işlem tamamlandıktan sonra temizlenir.

## Proje Yapısı

main.c: Uygulamanın ana C dosyası.

struct Dugum: Log kayıtlarını saklayan bağlı liste düğüm yapısı.

dugum_ekle(): Bağlı listeye yeni log kaydı ekler.

listeyi_yazdir(): Tüm log kayıtlarını ekrana yazdırır.

listeyi_temizle(): Bağlı listeyi temizler ve belleği serbest bırakır.

## Kullanılan Teknolojiler

C Programlama Dili

Bağlı Liste (Linked List) Veri Yapısı

Dosya İşlemleri

## Nasıl Çalıştırılır?

Programın çalıştırılması için bir C dili derleyicisine ihtiyacınız olacak.

### Tavsiye Edilen Araçlar:

GCC (GNU Compiler Collection)

Code::Blocks

Dev-C++

Çevrimiçi derleyici: <a href="https://www.onlinegdb.com/online_c_compiler">Online C Compiler</a>
