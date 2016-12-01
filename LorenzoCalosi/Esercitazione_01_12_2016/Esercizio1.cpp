#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

void loadMerch(string newMerch, vector<string>& merch);
void loseMerch(string lostMerch, vector<string>& merch);
void clearMerch(vector<string>& merch);
void printMerch(vector<string>& merch);

int main()
{
    srand (time(NULL));
    vector<string> merch;
    cout << "Carichi la tua roba e sei pronto all'avventura!" << endl;
    string startingItems[4] = {"vino","lana","avorio","legno"};
    loadMerch(startingItems[0],merch);
    loadMerch(startingItems[1],merch);
    loadMerch(startingItems[2],merch);
    loadMerch(startingItems[3],merch);
    printMerch(merch);
    cout << "Perdi l'ultimo oggetto caricato!" << endl;
    merch.pop_back();
    printMerch(merch);
    cout << "Ottieni del tè da un mercante amico!" << endl;
    loadMerch("tè",merch);
    printMerch(merch);
    cout << "Scambi della lana per del frumento!" << endl;
    loseMerch("lana",merch);
    loadMerch("frumento",merch);
    printMerch(merch);
    cout << "Pirati ti rubano il vino!" << endl;
    loseMerch("vino",merch);
    printMerch(merch);
    cout << "Riordini l'inventario!" << endl;
    sort(merch.begin(),merch.end());
    printMerch(merch);
    cout << "La tempesta te lo incasina!" << endl;
    random_shuffle(merch.begin(),merch.end());
    printMerch(merch);
    cout << "Vendi tutto per dell'oro!" << endl;
    clearMerch(merch);
    loadMerch("oro",merch);
    printMerch(merch);
}

void loseMerch(string lostMerch, vector<string>& merch)
{
    merch.erase(find(merch.begin(),merch.end(),lostMerch));
    return;
}

void clearMerch(vector<string>& merch)
{
    merch.clear();
    return;
}

void loadMerch(string newMerch, vector<string>& merch)
{
    merch.push_back(newMerch);
    return;
}

void printMerch (vector<string>& merch)
{
    cout << "Inventario Corrente:\n\n";
    for(vector<string>::iterator iter = merch.begin(); iter != merch.end(); iter++)
    {
        cout << "\t" << *iter << endl;
    }
    cout << "\n\n";
}
