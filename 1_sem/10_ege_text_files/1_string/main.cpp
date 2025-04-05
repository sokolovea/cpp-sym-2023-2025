#include <iostream>
#include <string>

int main() {
    // 1. �������� � ������������� ������
    std::string str = "Hello, World!";
    std::cout << "Initial string: " << str << std::endl << std::endl;

    // 2. ��������� ����� ������
    std::cout << "Length: " << str.length() << std::endl << std::endl;

    // 3. ������ � �������� �� �������
    std::cout << "Character at index 1: " << str[1] << std::endl << std::endl;
    std::cout << "Character at index 4 using .at(): " << str.at(4) << std::endl << std::endl;

    // 4. ��������� �������� �� �������
    str[7] = 'w';
    std::cout << "After modifying character at index 7: " << str << std::endl << std::endl;

    // 5. ���������� � ������ � ������� operator+= � append
    str += " How are you?";
    std::cout << "After += operation: " << str << std::endl << std::endl;

    str.append(" I'm fine.");
    std::cout << "After append: " << str << std::endl << std::endl;

    // 6. ������� ���������
    str.insert(7, "dear ");
    std::cout << "After insert: " << str << std::endl << std::endl;

    // 7. �������� ��������
    str.erase(7, 5); // ������� 5 �������� ������� � ������� 7
    std::cout << "After erase: " << str << std::endl << std::endl;

    // 8. ����� ���������
    size_t pos = str.find("orld");
    if (pos != std::string::npos) {
        std::cout << "\"World\" found at index: " << pos << std::endl << std::endl;
    } else {
        std::cout << "\"World\" not found\n" << std::endl;
    }

    // 9. ���������� ���������
    std::string sub = str.substr(0, 5); // ��������� ������ 5 ��������
    std::cout << "Substring (first 5 characters): " << sub << std::endl << std::endl;

    // 10. ��������� �����
    std::string str2 = "Hello";
    std::cout << "\"" << str << "\"; " << str2 << std::endl;
    if (str == str2) {
        std::cout << "Match with \"" << str2 << "\"" << std::endl;
    } else {
        std::cout << "Do not match with \"" << str2 << "\"" << std::endl;
    }

    std::cout << "Input string!" << std::endl;
    std::cin >> str;
    std::cout << str << std::endl;
    // std::cin.ignore();
    std::cout << "Input string!" << std::endl;
    std::getline(std::cin, str);
    std::cout << str << std::endl;


    return 0;
}
