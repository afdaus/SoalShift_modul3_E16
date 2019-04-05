# SoalShift_modul3_E16
# SOAL 1
1. Langkah pertama untuk menyelesaikan soal ini yaitu mengurutkan terlebih dahulu input dari user, disini saya menggunakan Bubble Sort.
2. Selanjutnya membuat fungsi untuk menghitung faktorial nya, dengan cara rekursif (nilai yang sekarang dikalikan nilai sebelumnya).
3. Setelah itu membuat thread dengan syntax seperti berikut `pthread_create(&tid[arr[i]], NULL, &tulis,(void *)&nilai);` tid merupakan thread id, tulis merupakan nama fungsi untuk menghitung faktorial nya, sedangkan nilai merupakan global variabel yang berfungsi sebagai batas yang akan digunakan pada fungsi faktorial.
# SOAL 2
- SERVER PENJUAL

Pada server penjual, menggunakan 1 thread yang berfungsi untuk mencetak stok yang tersedia setiap 5 detik. menggunakan perintah `pthread_create(&nama_thread, NULL, nama_fungsi, NULL);` serta dibuat infinite loop sehingga thread akan tetap mencetak selama server masih berjalan. Kemudian, untuk tetap bisa menjaga jumlah stok bernilai sama pada server penjual maupun server pembeli, maka menggunakan konsep shared memory, yang diakses pada thread tersebut, menggunakan perintah `int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);` `key_t key = 1234;` `stok = shmat(shmid, NULL, 0);` dan `shmdt(stok);`. Pada main digunakan untuk berkomunikasi dengan client (menggunakan socket pada c) dengan menerima inputan dari client dan menambahkan nilai stok.

- SERVER PEMBELI

Pada  server pembeli, menggunakan 1 thread yang berfungsi menerima inputan dari client serta menambahkan nilai stok ketika server menerima inputan `beli`. Pada server pembeli juga digunakan shared memory untuk tetap bisa menjaga jumlah stok yang bernilai sama pada server penjual maupun server pembeli. Perintah yang digunakan ialah `int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);` `key_t key = 1234;` `stok = shmat(shmid, NULL, 0);` dan `shmdt(stok);`. Pada main hanya digunakan untuk menjalankan thread dan mengkoneksikan dari client dan server (menggunakan socket pada c).

- CLIENT

Pada client, hanya menggunakan socket dan menerima inputan user, serta mengirimnya ke server yang telah terhubung.
# SOAL 3
Menggunakan 4 thread, yaitu sebagai berikut:
- Thread 1

Thread 1 digunakan untuk menjalankan peran Agmal, dimana WakeUp_Status akan bertambah sebanyak 15 ketika fitur `Agmal Ayo Bangun` dipanggil (bertambahnya nilai ini menggunakan flag, dimana ketika fitur dipanggil, maka flag akan berjalan dan Wake_Status akan bertambah). Selain itu pada thread 1 juga digunakan mutex untuk mengendalikan kasus unik, dimana jika fitur `Iraj Ayo Tidur` sudah dijalankan sebanyak 3 kali, maka mutex akan berjalan, mencetak "Agmal Ayo Bangun disabled 10 s" kemudian thread akan di sleep selama 10 detik. thread 1 akan berjalan dari awal program dijalankan hingga WakeUp_Status bernilai lebih dari 100 atau Spirit_Status bernilai kurang dari sama dengan 0 (flag akan menyala dan thread akan di kill dengan `pthread_kill(nama_thread,SIGKILL);`).

- Thread 2

Thread 2 digunakan untuk menjalankan peran Iraj, dimana Spirit_Status akan berkurang sebanyak 20 ketika fitur `Iraj Ayo Tidur` dipanggil (berkurangnya nilai ini menggunakan flag, dimana ketika fitur dipanggil, maka flag akan berjalan dan Spirit_Status akan berkurang). Selain itu pada thread 1 juga digunakan mutex untuk mengendalikan kasus unik, dimana jika fitur `Agmal Ayo Bangun` sudah dijalankan sebanyak 3 kali, maka mutex akan berjalan, mencetak "Iraj Ayo Tidur disabled 10 s" kemudian thread akan di sleep selama 10 detik. thread 2 akan berjalan dari awal program dijalankan hingga WakeUp_Status bernilai lebih dari 100 atau Spirit_Status bernilai kurang dari sama dengan 0 (flag akan menyala dan thread akan di kill dengan `pthread_kill(nama_thread,SIGKILL);`).

- Thread 3

Thread 3 digunakan untuk menjalankan fungsi `All Status`, dimana thread akan mencetak status kedua variabel ketika flag sudah menyala. Flag akan menyala ketika fitur `All Status` dipanggil. thread 3 juga menggunakan mutex agar fungsi tetap berada pada kondisi infinite loop hingga flag menyala.

- Thread 4

Thread 4 ini akan mengaktifkan flag (flag diaktifkan bedasarkan input pada thread 5) pada masing-masing fitur ketika fitur tersebut dijalankan. Ketika WakeUp_Status bernilai lebih dari sama dengan 100 atau Spirit_Status bernilai kurang dari sama dengan 0, maka thread 4 akan mencetak "Agmal Terbangun, mereka bangun pagi dan berolahraga" ketika WakeUp_Status bernilai lebih dari sama dengan 100 dan akan mencetak "Iraj ikut tidur, dan bangun kesiangan bersama Agmal" ketika Spirit_Status bernilai kurang dari sama dengan 0. Setelah itu thread 4 akan di kill menggunakan perintah `pthread_kill(nama_thread, SIGKILL);`.

- Thread 5

Thread 5 digunakan untuk menerima inputan dari user.
# SOAL 4

Jadi untuk menjalankan apa yang diminta soal nomor 4, saya menggunakan 7 thread. 2 thread pertama memiliki fungsi yang sama, yaitu menyimpan 10 baris dari ps aux ke dalam folder bernama SimpanProses.txt. Thread pertama akan menyimpan dengan nama file SimpanProses1.txt, sedangkan thread kedua akan menyimpan dengan nama file SimpanProses2.txt. Lalu thread ketiga dan keempat akan digunakan untuk zip dari SimpanProses1.txt dan SimpanProses2.txt. Thread ketiga akan zip file SimpanProses1.txt ke dalam file zip bernama KompresProses1.zip sedangkan thread keempat akan zip file SimpanProses2.txt ke dalam file zip bernama KompresProses2.zip. Proses zip dari SimpanProses1.txt dan SimpanProses2.txt saya tambahkan -rmj sehingga setelah di zip, file SimpanProses1.txt dan SimpanProses2.txt akan di delete. Thread ketiga dan keempat akan berjalan setelah thread pertama dan kedua telah selesai dengan menggunakan Mutual Exclusion. Thread kelima saya buat untuk print "Menunggu 15 detik untuk mengekstrak kembali". Thread kelima saya buat setelah thread 1,2,3, dan thread 4 telah selesai. Lalu thread 6 dan 7 saya buat untuk unzip dari KompresProses1.zip dan KompresProses2.zip.
# SOAL 5

Untuk nomor 5, kami menggunakan 13 thread. 
1 thread digunakan untuk membaca inputan string yang merupakan nama monster yang akan digunakan.
1 thread digunakan untuk membaca inputan berupa key press. thread ini akan selalu nyala
1 thread digunakan untuk membuat standby mode. Di dalam standby mode ini, akan ada suatu variabel yang akan selalu nyala ketika di dalam mode stand by mode. Variabel ini akan digunakan 3 thread untuk membuat Hunger_Status berkurang 5 tiap 10 detik, Hygiene_Status berkurang 10 tiap 30 detik, dan Health_Status bertambah 5 tiap 10 detik.
Lalu di dalam thread standby mode ini akan selalu dicek apakah Hygiene_Status dan Hunger_Status nya lebih besar dari 0, jika Hygiene_Status atau Hunger_Statusnya lebih kecil sama dengan 0 maka Monster akan mati.
1 thread digunakan untuk battlescene.
1 thread digunakan untuk makan myfoodstock dan setelah dimakan Health_Status akan bertambah 15 dan myfoodstock akan berkurang 1. 
1 thread digunakan untuk membuat shop. Dalam shop ini akan menampilkan Stock yang ada di shop dengan menggunakan shared memory. Sedangkan shop aslinya berada di program lain.
1 thread digunakan ketika sedang dalam battlescene, jika menggunakan attack, maka health musuh akan berkurang 20.
1 thread digunakan ketika musuh sudah diserang, musuh akan menyerang balik dengan damage yang sama yaitu 20.
1 thread digunakan untuk bath dan menambah Hygiene_Status sebanyak 30.
1 thread digunakan untuk countdown 20 detik yang berada pada stand by mode ketika user memilih bath.
