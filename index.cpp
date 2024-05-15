#include <iostream>
#include <string>
using namespace std;

// Структура для зберігання директора
struct Director {
    string surname;
    string name;
    string middle_name;
    int years_in_position;
    string phone;
};

// Структура для зберігання інформації про фабрику
struct Factory {
    string name;
    string country;
    string city;
    string street;
    int building;
    string phone;
    string website;
    Director director;
};

// Функція для введення даних про директора
void inputDirector(Director& director) {
    cout << "Прізвище: ";
    cin >> director.surname;
    cout << "Ім'я: ";
    cin >> director.name;
    cout << "По батькові: ";
    cin >> director.middle_name;
    cout << "Кількість років на посаді: ";
    cin >> director.years_in_position;
    cout << "Телефон: ";
    cin >> director.phone;
}

// Функція для введення даних про фабрику
void inputFactory(Factory* factories, int index) {
    cout << "Назва: ";
    cin >> factories[index].name;
    cout << "Країна: ";
    cin >> factories[index].country;
    cout << "Місто: ";
    cin >> factories[index].city;
    cout << "Вулиця: ";
    cin >> factories[index].street;
    cout << "Будинок: ";
    cin >> factories[index].building;
    cout << "Телефон: ";
    cin >> factories[index].phone;
    cout << "Сайт: ";
    cin >> factories[index].website;
    cout << "Директор:\n";
    inputDirector(factories[index].director);
}

// Функція для виведення даних про фабрику
void printFactory(const Factory& factory) {
    cout << "Назва: " << factory.name << endl;
    cout << "Країна: " << factory.country << endl;
    cout << "Місто: " << factory.city << endl;
    cout << "Вулиця: " << factory.street << endl;
    cout << "Будинок: " << factory.building << endl;
    cout << "Телефон: " << factory.phone << endl;
    cout << "Сайт: " << factory.website << endl;
    cout << "Директор:\n";
    cout << "  Прізвище: " << factory.director.surname << endl;
    cout << "  Ім'я: " << factory.director.name << endl;
    cout << "  По батькові: " << factory.director.middle_name << endl;
    cout << "  Кількість років на посаді: " << factory.director.years_in_position << endl;
    cout << "  Телефон: " << factory.director.phone << endl;
}

int main() {
    int size = 10; // Розмір масиву
    Factory* factories = new Factory[size]; // Створення динамічного масиву структур

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Створення масиву фабрик" << endl;
        cout << "2. Додавання фабрики" << endl;
        cout << "3. Виведення інформації про фабрики" << endl;
        cout << "4. Виведення інформації про одну фабрику" << endl;
        cout << "5. Заміна інформації про фабрику" << endl;
        cout << "6. Видалення фабрики" << endl;
        cout << "7. Видалення масиву фабрик" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: // Створення масиву фабрик
                for (int i = 0; i < size; ++i) {
                    cout << "\nФабрика " << i + 1 << ":" << endl;
                    inputFactory(factories, i);
                }
                break;
            case 2: // Додавання фабрики
                // Пошук вільного місця в масиві
                for (int i = 0; i < size; ++i) {
                    if (factories[i].name.empty()) {
                        inputFactory(factories, i);
                        break;
                    }
                }
                break;
            case 3: // Виведення інформації про фабрики
                for (int i = 0; i < size; ++i) {
                    if (!factories[i].name.empty()) {
                        cout << "\nФабрика " << i + 1 << ":" << endl;
                        printFactory(factories[i]);
                    }
                }
                break;
            case 4: // Виведення інформації про одну фабрику
                int index;
                cout << "Введіть номер фабрики: ";
                cin >> index;
                if (index >= 1 && index <= size && !factories[index - 1].name.empty()) {
                    cout << "\nФабрика " << index << ":" << endl;
                    printFactory(factories[index - 1]);
                } else {
                    cout << "Фабрики з таким номером не існує або не була створена." << endl;
                }
                break;
            case 5: // Заміна інформації про фабрику
                int replaceIndex;
                cout << "Введіть номер фабрики, яку потрібно замінити: ";
                cin >> replaceIndex;
                if (replaceIndex >= 1 && replaceIndex <= size && !factories[replaceIndex - 1].name.empty()) {
                    cout << "\nФабрика " << replaceIndex << ":" << endl;
                    inputFactory(factories, replaceIndex - 1); // Вводимо нові дані про фабрику
                } else {
                    cout << "Фабрики з таким номером не існує або не була створена." << endl;
                }
                break;
            case 6: // Видалення фабрики
                int deleteIndex;
                cout << "Введіть номер фабрики, яку потрібно видалити: ";
                cin >> deleteIndex;
                if (deleteIndex >= 1 && deleteIndex <= size && !factories[deleteIndex - 1].name.empty()) {
                    factories[deleteIndex - 1] = Factory(); // Очищаємо дані про фабрику
                    cout << "Фабрику " << deleteIndex << " видалено." << endl;
                } else {
                    cout << "Фабрики з таким номером не існує або не була створена." << endl;
                }
                break;
            case 7: // Видалення масиву фабрик
                delete[] factories;
                factories = nullptr;
                cout << "Масив фабрик видалено." << endl;
                break;
            case 0: // Вихід
                cout << "Програма завершена." << endl;
                break;
            default:
                cout << "Некоректний вибір. Будь ласка, виберіть опцію з меню." << endl;
        }
    } while (choice != 0);

    return 0;
}

