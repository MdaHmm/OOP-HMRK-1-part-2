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
        std::cout << "������� ������� ��� � �������� �������� -> ";
        std::string fio;
        std::getline(std::cin, fio);
        _fio = fio;
        std::cout << "������� ����� ��������� �������� �������� -> ";
        std::string home_phone;
        std::getline(std::cin, home_phone);
        _home_phone = home_phone;
        std::cout << "������� ����� �������� �������� �������� -> ";
        std::string work_phone;
        std::getline(std::cin, work_phone);
        _work_phone = work_phone;
        std::cout << "������� ����� ���������� �������� �������� -> ";
        std::string mobile_phone;
        std::getline(std::cin, mobile_phone);
        _mobile_phone = mobile_phone;
        std::cout << "������� �������������� ���������� �� �������� -> ";
        std::string more_info;
        std::getline(std::cin, more_info);
        _more_info = more_info;
    }

    bool successfuly() {
        std::cout << "������� �������� \"�������� ��������\"\n����������?\n1 - ��.\n����� ������ - ��������� � ������� ����.";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice != 1) {
            Subscriber();
            return true;
        }
    }

    void ShowAllData() {
        std::cout << "�������: " << _fio << std::endl;
        std::cout << "��������� �������: " << _mobile_phone << std::endl;
        std::cout << "������� �������: " << _work_phone << std::endl;
        std::cout << "�������� �������: " << _home_phone << std::endl;
        std::cout << "�������������� ����������: " << _more_info << std::endl << std::endl;
    }

    ~Subscriber() {
        std::cout << "������� ������." << std::endl;
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

     std::cout << "�������� ��������:\n1 - �������� ��������.\n2 - ������� ��������.\n3 - ������� ������ ���� ���������.";
     std::cin >> choice;
     std::cin.ignore();

     if(choice != 1 && choice != 2 && choice != 3)
         std::cout << "������ �����.";
     else
         if(choice == 1)
             Subscriber();

     /*
     Subscriber* sub1 = new Subscriber();
     sub1->ShowAllData();
     delete(sub1);*/


    return 0;
}


/*�������� ���������� ����������� �����. ����������
������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, ��������������
���������� � ��������) ������ ���������������� ������.
��������� ����� �����������-�������, ���������-�������, ��������������,
inline-���������-�������,
����������� ��������������, ���������� ����������.
����������� ���������� �������� ����������� ������ ���
���. ������������ ������������ ����������� ���������
����� ���������, ������� ���������, ������ ���������
�� ���, ���������� ���� ���������*/

