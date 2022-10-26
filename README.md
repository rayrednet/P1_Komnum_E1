# P1_Komnum_E1
Praktikum Komputasi Numerik 2022

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
1. Hitung fungsi pada intercal yang sama dari x terjadi perubahan tanda dari f(x<sub>n</sub>) dan f(x<sub>n+1</sub>). Atau dengan kata lain : f(x<sub>n</sub>) x f(x<sub>n+1</sub>) < 0
2. Estimasi pertama untuk akar persamaan dapat diperoleh melalui : x<sub>t</sub> = (x<sub>n</sub> + x<sub>n+1</sub>) /2
3. Lakukan evaluasi untuk menentukan dalam interval mana akar persamaan berada : <br>
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
      
## Source Code Iterasi Numerik

```ruby
import numpy as np
import matplotlib.pyplot as plt
 
#Mendefinisikan fungsi
def f(x):
    return (1 - (0.6 * x)) / x
 
iterasi_maks = 50 
ketelitian = 10E-6  
x1 = float(input("Masukkan x1: "))       
x2 = float(input("Masukkan x2: "))      
 
# Memeriksa apakah value x1 dan x2 sesuai syarat
if f(x1) * f(x2) > 0:
    print('Angka tidak memenuhi kriteria bolzano (bertanda sama)')
    exit()
 

print('----------------------------------------------------------------------------')
print('iterasi \t x1\t\t x2\t\t xt\t\t f(xt)        ')
print('----------------------------------------------------------------------------')

for i in range(iterasi_maks):
    xt = (x1 + x2)/2

    # Output hasil sesuai iterasi
    print(str(i + 1)+'\t\t% 10.8f\t% 10.8f\t% 10.8f\t% 10.8f\t' %(x1, x2, xt, f(xt)))
 
    if np.abs(f(xt)) < ketelitian:
        print('----------------------------------------------------------------------------')
        print('Nilai akar: '+ str(xt))
        exit()

    if f(x1) * f(xt) < 0:
        x2 = xt

    else: 
        x1 = xt
 
print('----------------------------------------------------------------------------')
if i == iterasi_maks - 1:
    print('\n\nIterasi maksimum!!!')
    print('Nilai akar: '+ str(xt))

print("\n")
```

Contoh input `x1 = 0.5` dan `x2 = 2`, diperoleh output sebagai berikut:

<img width="717" alt="image" src="https://user-images.githubusercontent.com/89933907/197981885-da6f3dfc-307d-405d-a91e-b997f58a7437.png">


## Source Code Grafik Fungsi

```ruby
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100) 

y = (1 - (0.6 * x)) / x

# mengatur axis di pusat
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('zero')

ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

plt.plot(x, y, 'r')

# show the plot
plt.show()
```
Jika code iterasi fungsi dijalankan maka grafik akan langsung keluar, berdasarkan contoh kasus tersebut didapatkan grafik sebagai berikut:

![WhatsApp Image 2022-10-26 at 15 50 36](https://user-images.githubusercontent.com/89933907/197982430-c06df7cc-60a1-42e8-9056-1e6e1f9c0620.jpg)


