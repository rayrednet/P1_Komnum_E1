# P1_Komnum_E1
Praktikum Komputasi Numerik 2022

### Notes
Jika gambar screenshot kurang jelas, klik gambar agar lebih jelas

## Identitas Kelompok 1 (Komputasi Numerik E)
| Name           | NRP        |
| ---            | ---        |
| Rayssa Ravelia | 5025211219 |
| Glenaya        | 5025211202 |
| Mashita Dewi   | 5025211036 |

## Perintah Soal
> Anda sudah mengerti algoritma pemrosesan metode Bolzano, dan Anda sudah memahami cara kerjanya. Sekarang Anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode Bolzano (yang dapat menampilkan proses iteratif numerik, lengkap dengan grafik fungsinya)

## Penjelasan Singkat Metode Bolzano
####  Metode bolzano adalah pembagi interval atau metode yang digunakan untuk mencari akar - akar persamaan nonlinear melalui proses iterasi. Metode bolzano sering disebut dengan metode setengah interval (_interval harving_), metode bagi dua, metode biseksi, atau metode pemotongan biner.

#### Langkah - langkah yang harus dilakukan pada Metode Bolzano adalah sebagai berikut :
1. `Hitung fungsi` pada interval yang sama dari x terjadi perubahan tanda dari f(x<sub>n</sub>) dan f(x<sub>n+1</sub>). Atau dengan kata lain : f(x<sub>n</sub>) x f(x<sub>n+1</sub>) < 0
2. `Estimasi` pertama untuk `akar persamaan` dapat diperoleh melalui : x<sub>t</sub> = (x<sub>n</sub> + x<sub>n+1</sub>) /2
3. Lakukan `evaluasi` untuk menentukan dalam interval mana akar persamaan berada : <br>
   a. Jika f(x<sub>n</sub>) x f(x<sub>n+1</sub>) < 0 <br>
      Akar persamaan dalam sub-interval pertama, tetapkan x<sub>n+1</sub> = x<sub>t</sub><br>
      Lalu lanjutkan ke langkah yang ke-4 <br>
   b. Jika f(x<sub>n</sub>) x f(x<sub>n+1</sub>) > 0 <br>
      Akar persamaan dalam sub-interval pertama, tetapkan x<sub>n</sub> = x<sub>t</sub> <br>
      Lalu lanjutkan ke `langkah yang ke-4` <br>
   c. Jika f(x<sub>n</sub>) x f(x<sub>n+1</sub>) = 0 <br> 
      Akar persamaan adalah x<sub>t</sub>, dan hitungan selesai
4. Kembali ke `langkah 2` untuk menghitung nilai perkiraan `akar yang baru`
5. Jika nilai yang didapat pada no. 4 sudah `sesuai` dengan batasan yang ditentukan, maka `proses selesai` dan x<sub>t</sub> adalah akar yang dicari.
      
## Penyelesaian

Untuk membuat penyelesaian akar dengan metode Bolzano, kami menggunakan bahasa pemrograman `C++` untuk membuat `iterasinya`.

Langkah pertama yang dilakukan adalah mendeklarasikan `presisi angka` yang diinginkan dan `banyaknya iterasi` yang dilakukan, serta fungsi yang akan dipakai pada program ini.
```ruby
int max_iteration = 1000; 
double precision = 10E-10;

//for example we use problem in ppt Komnum2 number 3a
double f(double x)
{
    return (pow(x,3)-(3*x)+1);
}
```

Langkah kedua, deklarasikan nilai `x1 dan x2`, yang dimana hasilnya dimasukkan ke dalam fungsi menjadi variabel `a dan b`

```ruby
double x1, x2;
    printf ("Input x1: ");
    scanf ("%lf", &x1);
    printf ("Input x2: ");
    scanf ("%lf", &x2);

    double a, b;
    a = f(x1);
    b = f(x2);
```

Setelah itu, `cek nilai x1 dan x2` sebagai parameter Bolzano yang ketika dimasukkan ke dalam fungsi memiliki nilai dengan `tanda berlawanan`

```ruby
if(a * b > 0) 
        puts("The numbers don't meet the Bolzano requirement by having the same sign");
```

Jika nilai `x1 dan x2 tidak sesuai kriteria`, maka tampilkan `pesan error` seperti yang tertera di atas. Selain itu, maka program dapat dijalankan dengan mengikuti `tahap perhitungan metode Bolzano`

```ruby
else
    {
        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");
        printf("iteration \t      x1\t\t     x2\t\t\t      xt\t\t     f(x1)\t\t     f(x2)\t\t     f(xt)\t\t\t");
        puts("");
        puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");

        double xt;
        for(int i = 1; i <= max_iteration; i++)
        {
            xt = (x1 + x2) / 2;
            printf("  %d \t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t %.10lf\t\t", i, x1, x2, xt, a, b, f(xt));
            puts("");

            //substitute xt with new boundaries near 0
            if((a >= 0 && f(xt) >= 0) || (a <= 0 && f(xt) <= 0))
            {
                x1 = xt;
                a = f(xt);
            }
            else 
            {
                x2 = xt;
                b = f(xt);
            }

            //end the program if f(xt) value already near the precision we wanted
            if(abs(f(xt)) < precision)
            {
                puts("-------------------------------------------------------------------------------------------------------------------------------------------------------------");
                printf("Root: %.15lf\n", xt);
                break;
            }   
        }
    }
  ```
 
 Setelah didapatkan akar yang dicari, kita harus membuat `grafik dari fungsi` yang dipakai. Untuk membuat grafik, kami menggunakan bahasa pemrograman `Python` dengan dua library, yaitu:
 
 ```ruby
import numpy as np
import matplotlib.pyplot as plt
```
Library `numpy` berguna untuk menghasilkan x pada interval tertentu, sedangkan library `matplotlib` berguna untuk membuat grafik.

Setelah itu, gunakan library numpy untuk menghasilkan `300 titik uji` pada interval `-10 hingga 10`

```ruby
x = np.linspace(-10, 10, 300); 
```

Selanjutnya, `definisikan fungsi` yang akan dibuat grafiknya. Kami menggunakan fungsi yang sama seperti pada iterasi metode Bolzano yakni pada ppt Komnum2 soal 3a

```ruby
y = (pow(x,3)-(3*x)+1)
```

Langkah selanjutnya adalah mengatur bidang grafik untuk membuat kanvas grafik dan sumbu x dan y harus berada di tengah

```ruby
fig = plt.figure() #graphic canvas
ax = fig.add_subplot(1, 1, 1) #we only need 1 graph with 1 row and 1 column

#set main y in center
ax.spines['left'].set_position('center')

#set main x in center
ax.spines['bottom'].set_position('center')

#give transparent color to lines that we don't need
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
```

Langkah terakhir, lakukan plotting pada kanvas grafik pada diagram kartesisus dengan tipe 'y', dan tampilkan plot

```ruby
plt.plot(x, y, 'y')
plt.show()
```

 ## Contoh Kasus
   
 Sebagai contoh, kita masukkan nilai `x1` adalah `1.5` dan `x2` adalah `1.7`, akan diperoleh hasil output sebagai berikut:
  
<img width="578" alt="image" src="https://user-images.githubusercontent.com/89933907/198072247-1ecb2ceb-7f70-4f33-993f-22ed69870f1e.png">

Maka dari output tersebut akar yang dicari dari persamaan tersebut adalah `1.532088886201382`

Serta grafik yang diperoleh dari fungsi tersebut adalah sebagai berikut

![python graph](https://user-images.githubusercontent.com/89933907/198080782-f10a2529-1897-4e36-901f-5972d65df769.jpg)


