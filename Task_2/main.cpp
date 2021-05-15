#include "modAlphaCipher.h"


bool isValid(const string& s)
{
    for(const auto &c:s) // ���� �������� �� ����� ������� � ������ ��� ������ ����� �������
        if (!isalpha(c) )
            return false;
    return true;
    
}


int main(int argc, char **argv)
{
    int key;
    string st;
    unsigned operation;
    cout<<"������� ���� (�����) : ";
    cin>>key;
    if (!cin.good()) {
        clog<<"���� �� ��������\n";
        return 1;
    }
    cout<<"���� ������\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"�������� �������� (0-�����, 1-�����������, 2-������������): ";
        cin>>operation;
        if (operation > 2) {
            cout<<"������ � ������ ��������\n";
        } else if (operation >0) {
            cout<<"������� ������, ��������� �� �������� : ";
            cin>>st;
            if (isValid(st)) {
                if (operation==1) {
                    cout<<"������������� ������: "<<cipher.coder(st)<<endl;
                } else {
                    cout<<"�������������� ������: "<<cipher.decoder(st)<<endl;
                }
            } else {
                cout<<"������������ ������.\n";
            }
        }
    } while (operation!=0);

    return 0;
}