import random
from libs import welcome_message

welcome_message("Welcome to My Journey")

user = input("Masukkan Nama Kamu: ")

while user == "":
    user = input("Isi Namanya dong: ")




    

while True:
    bentuk_goa = "[_] "
    goa_kosong = [bentuk_goa] * 4  
    goa = goa_kosong.copy()
    posisi = random.randint(1, 4)
    goa[posisi - 1] = "[O_O]"
    goa_kosong = ''.join(goa_kosong)
    goa = ''.join(goa)
    
    print(f"Haloo {user} Coba Perhatikan Goa dibawah ini! \n{goa_kosong}")
    ular = int(input(f"Dimanakah gua tempat ular berada [1 / 2 / 3 / 4]? "))
    yakin = input(f"Apakah anda yakin dengan jawaban anda yaitu {ular} jika benar ketik y jika salah pilih n : ")

    if yakin == "y":
        if ular == posisi:
            print(f"Halo {user}\n {goa} \n Selamat Kamu Menang🏆")
        else:
            print(f"Halo {user}\n {goa} \n Yah Kamu Salah Menebaknya😞\n Jangan Sedih yaa😊😊")
    elif yakin == "n":
        print("Program Berhetii")
        exit()
    else:
        print("Programnya Selesai Coba Ulangi Lagi")
        exit()
    play_again = input(f"Silahkan Ketik y jika ingin lanjut. jika ingin berhenti Ketik n  ")
    if play_again == "n":
        break

print("Makasih telah bermain game di Games.id Jangan Lupa Beri Rating Untuk Permainan kami yaa")

