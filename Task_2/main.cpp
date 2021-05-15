#include "modAlphaCipher.h"


bool isValid(const string& s)
{
    for(const auto &c:s) // öèêë ïğîõîäèò ïî âñåìó ìàññèâó è âûäàåò ñàì îáúåêò ıòîãî ìàññèâà
        if (!isalpha(c) )
            return false;
    return true;
    
}


int main(int argc, char **argv)
{
    int key;
    string st;
    unsigned operation;
    cout<<"ÂÂÅÄÈÒÅ ÊËŞ× (×ÈÑËÎ) : ";
    cin>>key;
    if (!cin.good()) {
        clog<<"ÊËŞ× ÍÅ ÏÎÄÕÎÄÈÒ\n";
        return 1;
    }
    cout<<"ÊËŞ× ÏĞÈÍßÒ\n";
    modAlphaCipher cipher(key);
    do {
        cout<<"ÂÛÁÅĞÈÒÅ ÎÏÅĞÀÖÈŞ (0-ÂÛÕÎÄ, 1-ÇÀØÈÔĞÎÂÀÒÜ, 2-ĞÀÑØÈÔĞÎÂÀÒÜ): ";
        cin>>operation;
        if (operation > 2) {
            cout<<"ÎØÈÁÊÀ Â ÂÛÁÎĞÅ ÎÏÅĞÀÖÈÈ\n";
        } else if (operation >0) {
            cout<<"ÂÂÅÄÈÒÅ ÑÒĞÎÊÓ, ÑÎÑÒÎßÙÓŞ ÈÇ ËÀÒÈÍÈÖÛ : ";
            cin>>st;
            if (isValid(st)) {
                if (operation==1) {
                    cout<<"ÇÀØÈÔĞÎÂÀÍÍÀß ÑÒĞÎÊÀ: "<<cipher.coder(st)<<endl;
                } else {
                    cout<<"ĞÀÑØÈÔĞÎÂÀÍÍÀß ÑÒĞÎÊÀ: "<<cipher.decoder(st)<<endl;
                }
            } else {
                cout<<"ÍÅÊÎĞĞÅÊÒÍÀß ÑÒĞÎÊÀ.\n";
            }
        }
    } while (operation!=0);

    return 0;
}