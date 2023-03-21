#include <iostream>
using namespace ::std;
#include <math.h>
#define N 16
#define N1 20
unsigned short int Numer[20];
int a, b;
class BIT
{

public:
    int mas[20];
    void SHOW() {
        printf_s("\n%-8s", "БИТЫ");
        for (int i = N - 1; i >= 0; i--) printf_s("%3d", i);
        printf_s("%10s", "10-код");
        printf_s("%10s", "16-код");
        for (int j = 0; j < N1; j++) {
            unsigned short int numer = Numer[j];
            char masBit[N];

            for (int i = 0; i < N; i++)
            {
                masBit[i] = (numer & 1) ? 1 : 0;
                numer >>= 1;
            }

            printf_s("\n%-8d", j + 1);
            for (int i = N - 1; i >= 0; i--) printf_s("%3d", masBit[i]);
            printf_s("%10d", Numer[j]);
            printf("%10x", Numer[j]);
            cout << '\n';
        };
    };
    BIT() {
        for (int j = 0; j < N1; j++) {
            Numer[j] = rand() % 65536;
        }
    }
    ~BIT() {}
    void DIAPOZON() {
        cout << "\n\n     ДИАПОЗОН\n\n";
        cout << "\nВведите a:";
        cin >> a;
        cout << "Введите b:";
        cin >> b;
        cout << "ВХОДЯТ НОМЕРА:";
        for (int j = 0; j < N1; j++) {
            if (Numer[j] >= a && Numer[j] <= b)cout << j + 1 << ' ';
        }
    }
    void operator[](BIT& v1) {
        cout << "\n\n     ПРОВЕРКА БИТА\n\n";
        cout << "\nВведите номер бита:";
        cin >> a;
        cout << "ВПИСАНА 1 В " << a << " БИТ В НОМЕРА:";
        for (int j = 0; j < N1; j++)
            if (Numer[j] & (1 << a)) cout << j + 1 << ' ';
    }
    void operator=(BIT& v1) {
        cout << "\n\n     УСТАНОВКА БИТА\n\n";
        cout << "\nВведите номер бита:";
        cin >> a;
        cout << "Введите номер числа для установки " << a << " бита:";
        cin >> b;
        Numer[b - 1] |= (1 << a);
        cout << "Новое число: " << Numer[b - 1];
    }
    void operator()(BIT& v1) {
        cout << "\n\n     СБРОС БИТА\n\n";
        cout << "\nВведите номер бита:";
        cin >> a;
        cout << "Введите номер числа для сброса " << a << " бита:";
        cin >> b;
        Numer[b - 1] &= ~(1 << a);
        cout << "Новое число: " << Numer[b - 1];
    }
    void operator<(BIT& v1) {
        cout << "\n\n     СДВИГ ВЛЕВО\n\n";
        cout << "\nСдвиг влево на:";
        cin >> a;
        cout << "Введите номер числа для сдвига на" << a << " бита(ов):";
        cin >> b;
        Numer[b - 1] = Numer[b - 1] << a;
        cout << "Новое число: " << Numer[b - 1];
    }
    void operator>(BIT& v1) {
        cout << "\n\n     СДВИГ ВПРАВО\n\n";
        cout << "\nСдвиг вправо на:";
        cin >> a;
        cout << "Введите номер числа для сдвига на" << a << " бита(ов):";
        cin >> b;
        Numer[b - 1] = Numer[b - 1] >> a;
        cout << "Новое число: " << Numer[b - 1];
    }
    void operator<<(BIT& v1) {
        cout << "\n\n     ЦИКЛИЧЕСКИЙ СДВИГ ВЛЕВО\n\n";
        cout << "Циклический сдвиг влево на:";
        cin >> a;
        cout << "Введите номер числа для сдвига на " << a << " бита(ов):";
        cin >> b;
        int bit;
        for (int i = 0; i < a; i++) {
            bit = Numer[b - 1] & 0x8000 ? 1 : 0;
            Numer[b - 1] <<= 1;
            Numer[b - 1] |= bit;
        }
        cout << "Новое число: " << Numer[b - 1] << endl;
    }
    void operator>>(BIT& v1) {
        cout << "\n\n     ЦИКЛИЧЕСКИЙ СДВИГ ВПРАВО\n\n";
        cout << "Циклический сдвиг вправо на:";
        cin >> a;
        cout << "Введите номер числа для сдвига на " << a << " бита(ов):";
        cin >> b;
        int bit;
        for (int i = 0; i < a; i++) {
            bit = Numer[b - 1] & 0x0001;
            Numer[b - 1] >>= 1;
            Numer[b - 1] |= bit << 15;
        }
        cout << "Новое число: " << Numer[b - 1] << endl;
    }
    void operator&(BIT& v1) {
        cout << "\n\n     <<И>>\n\n";
        cout << "номер числа 1:";
        cin >> a;
        cout << "номер числа 2:";
        cin >> b;
        cout << "\n" << a << "&" << b << "= " << (Numer[a - 1] & Numer[b - 1]) << endl;
    }
    void operator|(BIT& v1) {
        cout << "\n\n     <<ИЛИ>>\n\n";
        cout << "номер числа 1:";
        cin >> a;
        cout << "номер числа 2:";
        cin >> b;
        cout << "\n" << a << "|" << b << "= " << (Numer[a - 1] | Numer[b - 1]) << endl;
    }
    void operator%(BIT& v1) {
        cout << "\n\n     <<ИСКЛЮЧАЮЩЕЕ ИЛИ>>\n\n";
        cout << "номер числа 1:";
        cin >> a;
        cout << "номер числа 2:";
        cin >> b;
        cout << "\n" << a << "^" << b << "= " << (Numer[a - 1] ^ Numer[b - 1]) << endl;
    }
    void operator-(BIT& v1) {
        cout << "\n\n     <<ИНВЕРТИРОВАНИЕ>>\n\n";
        cout << "номер числа 1:";
        cin >> a;
        Numer[a - 1] = ~Numer[a - 1];
        cout << Numer[a - 1] << endl;
    }

    friend void RUN();
};
void RUN()
{
    printf_s("\n%-8s", "БИТЫ");
    for (int i = N - 1; i >= 0; i--) printf_s("%3d", i);
    printf_s("%10s", "10-код");
    for (int j = 0; j < N1; j++) {
        if ((Numer[j] & (1 << 3)) && (Numer[j] & (1 << 14)) && (bool((1 << 15) & Numer[j])) == 0) {
            unsigned short int numer = Numer[j];
            char masBit[N];
            for (int i = 0; i < N; i++)
            {
                masBit[i] = (numer & 1) ? 1 : 0;
                numer >>= 1;
            }
            printf_s("\n%-8d", j + 1);
            for (int i = N - 1; i >= 0; i--) printf_s("%3d", masBit[i]);
            printf_s("%10d\n", Numer[j]);
            cout << '\n';
        }
    };
}
int main()
{
    BIT Net;
    BIT Net2;
    setlocale(0, "");
    BIT BIT;
    BIT.SHOW();
    BIT.DIAPOZON();

    Net[Net2];
    Net = Net2;
    Net(Net2);
    Net < Net2;
    Net > Net2;
    Net << Net2;
    Net >> Net2;
    Net& Net2;
    Net | Net2;
    Net% Net2;
    Net - Net2;
    BIT.SHOW();
    cout << "\n\n         НУЖНЫЕ ДАННЫЕ    \n\n";
    RUN();
}	
