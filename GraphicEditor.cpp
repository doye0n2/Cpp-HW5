//GraphicEditor.cpp
#include "GraphicEditor.h"
#include <iostream>
using namespace std;

// GraphicEditor ������
// ���� ����Ʈ�� ���۰� ���� ��Ÿ���� �����͸� �ʱ�ȭ
GraphicEditor::GraphicEditor() {
    pStart = pLast = nullptr;
}

// GraphicEditor �Ҹ���
// ���� ����Ʈ�� ��ȸ�ϸ� �������� ������ ���� ��ü���� ����
GraphicEditor::~GraphicEditor() {
    Shape* current = pStart; // ����Ʈ�� ���ۺ��� Ž��
    while (current != nullptr) { // ����Ʈ ������ �ݺ�
        Shape* next = current->getNext(); // ���� ��ü�� ����
        delete current; // ���� ��ü ����
        current = next; // ���� ��ü�� �̵�
    }
}

// ���� ���� �޼���
void GraphicEditor::insertItem(int type) {
    Shape* p = nullptr; // ���� ������ ���� ��ü�� ����ų ������ �ʱ�ȭ

    // �Էµ� Ÿ�Կ� ���� ���� ��ü�� �������� ����
    switch (type) {
    case 1:
        p = new Line(); // �� ��ü ����
        break;
    case 2:
        p = new Circle(); // �� ��ü ����
        break;
    case 3:
        p = new Rectangle(); // �簢�� ��ü ����
        break;
    default:
        break; // �߸��� �Է��� ��� �ƹ� �۾��� ���� ����
    }

    // ����Ʈ�� ��� �ִ� ���
    if (pStart == nullptr) {
        pStart = p; // ù ��° �������� ����
        pLast = p;  // ������ ������ ����
        return;
    }

    // ����Ʈ�� ��� ���� ���� ���
    pLast->add(p);            // ���� ������ ������ next�� �� ���� �߰�
    pLast = pLast->getNext(); // pLast�� ���� �߰��� �������� ����
}

// ���� ���� �޼���
void GraphicEditor::deleteItem(int index) {
    // ����Ʈ�� ��� �ִ� ���
    if (pStart == nullptr) {
        cout << "������ �����ϴ�!" << endl; // ���� �޽��� ���
        return;
    }

    Shape* tmp = pStart; // ������ ������ Ž���ϱ� ���� ������
    Shape* pre = nullptr; // ������ ������ ���� ������ ����ų ������

    // ù ��° ���� ���� ó��
    if (index == 0) {
        pStart = tmp->getNext(); // ���� �����͸� ���� �������� �̵�
        delete tmp;              // ù ��° ���� ����
        return;
    }

    // �Էµ� �ε������� Ž��
    for (int i = 0; i < index; i++) {
        pre = tmp;              // ���� ������ ���� �������� ����
        tmp = tmp->getNext();   // ���� �������� �̵�
        if (tmp == nullptr) {   // �ε��� ������ �ʰ��� ���
            cout << "�߸��� �ε����Դϴ�!" << endl; // ���� �޽��� ���
            return;
        }
    }

    // ���� ����Ʈ�� �籸���Ͽ� ����
    pre->add(tmp->getNext()); // ���� ������ next�� ���� ����� next�� ����
    delete tmp;               // ���� ��� ���� ����
}

// ���� ��� �޼���
void GraphicEditor::show() {
    Shape* tmp = pStart; // ����Ʈ�� ���ۺ��� Ž��
    int i = 0;           // ��¿� �ε���
    while (tmp != nullptr) { // ����Ʈ ������ �ݺ�
        cout << i++ << ": "; // ���� �ε��� ���
        tmp->paint();        // ���� ���� ���
        tmp = tmp->getNext(); // ���� �������� �̵�
    }
}

// ���α׷� ���� �޼���
void GraphicEditor::run() {
    cout << "�׷��� �������Դϴ�." << endl; // �ʱ� �޽��� ���
    int menu, index, type; // �޴�, �ε���, Ÿ�� ���� �ʱ�ȭ

    // ���� �ݺ��Ͽ� ����� �Է� ó��
    while (true) {
        menu = UI::getMenu(); // �޴� ���� �Է�
        switch (menu) {
        case 1: // ���� ����
            type = UI::getShapeTypeToInsert(); // ������ ���� Ÿ�� �Է�
            insertItem(type); // ���� ���� ó��
            break;
        case 2: // ���� ����
            index = UI::getShapeIndexToDelete(); // ������ ���� �ε��� �Է�
            deleteItem(index); // ���� ���� ó��
            break;
        case 3: // ���� ���
            show(); // ���� ����Ʈ�� �ִ� ���� ���
            break;
        default: // ����
            return;
        }
    }
}
