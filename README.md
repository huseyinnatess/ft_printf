<div align="center">

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

#### *Çünkü ft_putnbr() and ft_putstr() yeterli değil*

[42 Okulunun](https://42.fr/en/homepage/) 'printf()' projesi, Hedef, çeşitli format belirleyicilerini (c, s, p, d, i, u, x, X ve % gibi) ele alabilen printf işlevinin basitleştirilmiş bir sürümünü yeniden oluşturmaktır.

## Prototip

```c
int ft_printf(const char *str, ...);
```

## Desteklenen format belirticileri

| Format | Output |
| :-------: | ---- |
| `%c` | Tek bir karakter yazdırır |
| `%s` | String yazdırır |
| `%p` | Hexadecimal formatta basılmış bir pointer yazdırır |
| `%d` | Decimal sayı yazdırır |
| `%i` | İnteger sayı yazdırır |
| `%u` | Unsigned sayılar yazdırır |
| `%x` | Hexadecimal tabanda küçük harflerle bir sayı yazdırır |
| `%X` | Hexadecimal tabanda büyük harflerle bir sayı yazdırır |
| `%%` | Tek '%' karakteri yazdırır |

## Makefile Kuralları

Makefile, 'libftprintf.a' adında bir kütüphane oluşturur. Aşağıdaki kurallar bulunmak zorunda:
* `make`
* `make all`
* `make clean`
* `make fclean`
* `make re`


## Variadic Argümanlar (va_list)

-   Bir fonksiyonun sınırsız argüman alabilmesi için kullanılır.
    
-   Bir fonksiyonun sınırsız parametre aldigini belirtmek için kendi argümanlarindan sonra '...' koyuyoruz. int topla(int miktar, ...);
    
-   va_start makrosu iki arguman alır. Birincisi argümanların tutulacağı va_list değişkeni, ikincisi ise fonksiyonun hangi değişkenden sonra sınırsız argüman almaya başlayacağını gösterir.
    
-   va_arg, ilk parametre olarak işlem yapılacak va_list'i aliyor. Va_arg her çağrıldığında bir sonraki indeks'i (argümanı) alır. Örneğin argümanlarin 22,33,44 olduğunu düşünelim. var_arg ilk cağrıldığında 22, ikinci çağrıldığında 33'ü çeker. İkinci aldığı parametre ise içeriden alınacak olan değerin hangi veri tipinde alınacağina karar verir.
    
-   va_end ile argüman kullanımını sonlandırıp, temizlik işlemini yaparız. Fakat daha sonra argümanlara ihtiyacımız olursa, tekrar start verebiliriz.


## Neden Format Değişkenini Kullanmak Zorundayız?

```c
Önemli: Önce projeyi inceleyip ardından burayı okumanı tavsiye ederim.
```

Şöyle açıklayayım olayı. Örneğin
```c
ft_printf("%d, %c", 572, 'A');
```
bu şekilde fonksiyonunuzu çalıştırdınız. Fonksiyonunuz 4 sayısını return edecek çünkü 4 karakter yazdırdık. Format değişkenini kullanmadan direk rtn değişkeninde yazılan karakter sayısını tuttuğumuzu düşünelim. Ortaya şöyle bir senaryo çıkacatır. 

Diyelim ki printf fonksiyonumuz 572 sayısını başarılı şekilde yazdı. rtn değerimiz 3 oldu ama 'A' karakterini yazdırırken hata olduğunu ve -1 döndüğünü düşünelim rtn değerimiz 3'tü 'A' karakterinde yazdırma esnasında hata olduğu için -1 döndü. rtn bu durumda 3 + (-1) = 2 oldu. Ancak hata durumunda bizim -1 döndürmemiz gerekiyordu. rtn'de önceden sayı var olduğu için onunla toplanmış oldu.

Bu yüzden sonucu önce geçici bir değişkende (format) tutup -1 gelip gelmediğini kontrol etmeliyiz. -1 gelmedi ise rtn'ye eklemeliyiz.

Umarım açıklayıcı olmuştur bunun haricinde takılacağınızı düşündüğüm her yere yorum satırları ile açıklama yaptım. Kolay gelsin.

