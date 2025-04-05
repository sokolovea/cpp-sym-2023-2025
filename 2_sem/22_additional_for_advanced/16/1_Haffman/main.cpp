#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Узел дерева Хаффмана
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode *left, *right;
    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Сравнивает узлы по частоте
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};

// Создает узел дерева Хаффмана
HuffmanNode* createNode(char data, int frequency) {
    return new HuffmanNode(data, frequency);
}

// Удаляет дерево Хаффмана
void deleteTree(HuffmanNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Строит коды Хаффмана для каждого символа
void buildCodes(HuffmanNode* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->data] = code;
    }
    buildCodes(root->left, code + "0", codes);
    buildCodes(root->right, code + "1", codes);
}

void compressFile(string filename) {
    cout << "Найденные частоты символов:" << endl;
    ifstream file(filename, ios::binary);
    unordered_map<char, int> frequencyMap;
    char c;
    while (file.get(c)) {
        frequencyMap[c]++;
    }
    file.close();

    cout << "Построение дерева Хаффмана" << endl;
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> pq;
    for (auto& pair : frequencyMap) {
        pq.push(createNode(pair.first, pair.second));
    }
    while (pq.size() != 1) {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();
        int sum = left->frequency + right->frequency;
        HuffmanNode* newNode = createNode('\0', sum); //???
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    HuffmanNode* root = pq.top();

    // Построение кодов Хаффмана
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);


    for (auto& pair : frequencyMap) {
        string pairFirst = "";
        if ((unsigned char)pair.first >= 32)
        {
            pairFirst += pair.first;
        }
        else
        {
            pairFirst += "#";
            pairFirst += std::to_string((unsigned char)pair.first);
        }
        cout << "Символ: " << pairFirst << "\tЧастота: " << std::setw(10) << pair.second << "\tКод: " << codes[pair.first] << endl;
    }
    cout << endl;

    // Сжатие файла и запись в новый файл
    ifstream inputFile(filename, ios::binary);
    ofstream outputFile(filename + ".huf", ios::binary);
    string buffer = "";
    char byte = 0;
    int count = 0;
    while (inputFile.get(c)) {
        buffer += codes[c];
        while (buffer.length() >= 8) {
            byte <<= 1;
            byte |= buffer[0] - '0';
            buffer = buffer.substr(1);
            count++;
            if (count == 8) {
                outputFile.put(byte);
                byte = 0;
                count = 0;
            }
        }
    }
    if (buffer != "") {
        while (buffer.length() < 8) {
            buffer += "0";
        }
        byte <<= (8 - buffer.length());
        for (char bit : buffer) {
            byte <<= 1;
            byte |= bit - '0';
        }
        outputFile.put(byte);
    }
    inputFile.close();
    outputFile.close();

    cout << "Сжатие завершено: " << filename + ".huf" << endl;

    //Раскодировать файл здесь

    // Открываем сжатый файл для чтения и создаем файл для раскодированных данных
    ifstream compressedFile(filename + ".huf", ios::binary);
    ofstream decompressedFile("DECODED_" + filename, ios::binary);
    if (!decompressedFile) {
        cerr << "Ошибка создания расшифрованногофайла!" << endl;
        return;
    }

    // Раскодирование битов и запись раскодированных символов в выходной файл
    HuffmanNode* current = root;
    double counter = 0; //счетчик байт
    // char byte;



    while (compressedFile.read(&byte, sizeof(byte))) {
        counter += 1;
        // Перебираем каждый бит в байте
        for (int i = 7; i >= 0; --i) {
            // Проверяем текущий бит (начиная с старшего)
            if (byte & (1 << i)) {
                // Если текущий бит установлен в 1, двигаемся вправо по дереву
                if (current->right) {
                    current = current->right;
                }
            } else {
                // Если текущий бит установлен в 0, двигаемся влево по дереву
                if (current->left) {
                    current = current->left;
                }
            }
            // Если достигли листа, записываем символ в выходной файл и сбрасываем указатель на корень дерева
            if (!current->left && !current->right) {
                decompressedFile.put(current->data);
                current = root;
            }
        }
    }

    cout << "counter bytes = " << counter << endl;
    cout << "counter KB = " << counter / 1024 << endl;
    cout << "counter MB = " << counter / 1024 / 1024 << endl;

    // Закрываем файлы
    compressedFile.close();
    decompressedFile.close();

    cout << "Decompression completed. Decompressed file: " << filename.substr(0, filename.find_last_of(".")) << endl;

    // Освобождение памяти
    deleteTree(root);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    compressFile(filename);

    return 0;
}
