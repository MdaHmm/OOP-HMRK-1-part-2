#include <iostream>
#include <string>
#include <vector>

class Subscriber {
private:
    std::string _fio;
    std::string _home_phone;
    std::string _work_phone;
    std::string _mobile_phone;
    std::string _more_info;
public:
    Subscriber() {
        std::cout << "Введите фамилию имя и отчество абонента -> ";
        std::string fio;
        std::getline(std::cin, fio);
        _fio = fio;
        std::cout << "Введите номер домашнего телефона абонента -> ";
        std::string home_phone;
        std::getline(std::cin, home_phone);
        _home_phone = home_phone;
        std::cout << "Введите номер рабочего телефона абонента -> ";
        std::string work_phone;
        std::getline(std::cin, work_phone);
        _work_phone = work_phone;
        std::cout << "Введите номер мобильного телефона абонента -> ";
        std::string mobile_phone;
        std::getline(std::cin, mobile_phone);
        _mobile_phone = mobile_phone;
        std::cout << "Укажите дополнительную информацию об абоненте -> ";
        std::string more_info;
        std::getline(std::cin, more_info);
        _more_info = more_info;
    }

    bool successfuly() {
        std::cout << "Выбрана операция \"Добавить абонента\"\nПродолжить?\n1 - Да.\nЛюбой символ - вернуться в главное меню.";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice != 1) {
            Subscriber();
            return true;
        }
    }

    void ShowAllData() {
        std::cout << "Абонент: " << _fio << std::endl;
        std::cout << "Мобильный телефон: " << _mobile_phone << std::endl;
        std::cout << "Рабочий телефон: " << _work_phone << std::endl;
        std::cout << "Домашний телефон: " << _home_phone << std::endl;
        std::cout << "Дополнительная информация: " << _more_info << std::endl << std::endl;
    }

    ~Subscriber() {
        std::cout << "Абонент удален." << std::endl;
    }
};

class PhoneBook {
private:
    std::vector <Subscriber*>_subscribers;
public:
    void AddSub(Subscriber* subscriber) {
        _subscribers.push_back(subscriber);
    }

    void ShowSub() {
        for (const auto& it : _subscribers)
            it->ShowAllData();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Subscriber* sub = new Subscriber();
    std::cout << std::endl;
    Subscriber* sub2 = new Subscriber();
    std::cout << std::endl;
    Subscriber* sub3 = new Subscriber();
    std::cout << std::endl;
    /*sub->ShowAllData();*/
    PhoneBook* phb = new PhoneBook();
    phb->AddSub(sub);
    phb->AddSub(sub2);
    phb->AddSub(sub3);
    phb->ShowSub();

    /* int choice;

     std::cout << "Выберите действие:\n1 - добавить абонента.\n2 - удалить абонента.\n3 - вывести список всех абонентов.";
     std::cin >> choice;
     std::cin.ignore();

     if(choice != 1 && choice != 2 && choice != 3)
         std::cout << "Ошибка ввода.";
     else
         if(choice == 1)
             Subscriber();

     /*
     Subscriber* sub1 = new Subscriber();
     sub1->ShowAllData();
     delete(sub1);*/


    return 0;
}


/*Создайте приложение «Телефонная книга». Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциями-членами, конструкторами,
inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память под
ФИО. Предоставьте пользователю возможность добавлять
новых абонентов, удалять абонентов, искать абонентов
по ФИО, показывать всех абонентов*/

