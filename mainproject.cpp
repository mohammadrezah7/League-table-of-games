#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; // تعداد تیم ها
    cout << "enter of your team's number : ";
    cin >> n;
    string words[n]; // برای گرفتن اسامی تیم ها
    cout << "enter your team's name 1 : ";
    int x = 2;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        if (i != n - 1) {
            cout << "team " << x << " : ";
        }
        x++;
    }
    cout << "your teams : ";
    for (int i = 0; i < n; i++) {
        cout << words[i];
        if (i != n - 1)
            cout << " , ";
    }
    int y; // تعداد بازی ها
    cout << endl;
    cout << "enter the number of game that you want : ";
    cin >> y;
    int goals[n] = {0}; // آرایه جهت ذخیره گل های هر تیم
    int goalskhorde[n] = {0}; // آرایه جهت ذخیره گل های خورده هر تیم
    int points[n] = {0}; // آرایه جهت ذخیره امتیازهای هر تیم
    cout << "corect format : team1" << endl << "goal1" << endl << "team2" << endl << "goal2" << endl;
    int u = 0;
    for (int j = 0; j < y; j++) {
        string q;
        cin >> q;
        int d = 0;
        cin >> d;
        string q2;
        cin >> q2;
        int d2 = 0;
        cin >> d2;
        for (int i = 0; i < n; i++) {
            if (q == words[i] && d2 < d) {
                points[i] = points[i] + 3;
                goals[i] = goals[i] + d;
                goalskhorde[i] = goalskhorde[i] - d2;
            }
            if (q == words[i] && d2 == d) {
                points[i] = points[i] + 1;
                goals[i] = goals[i] + d;
                goalskhorde[i] = goalskhorde[i] - d2;
            }
            if (q == words[i] && d2 > d) {
                points[i] = points[i] + 0;
                goals[i] = goals[i] + d;
                goalskhorde[i] = goalskhorde[i] - d2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (q2 == words[i] && d2 > d) {
                points[i] = points[i] + 3;
                goals[i] = goals[i] + d2;
                goalskhorde[i] = goalskhorde[i] - d;
            }
            if (q2 == words[i] && d2 == d) {
                points[i] = points[i] + 1;
                goals[i] = goals[i] + d2;
                goalskhorde[i] = goalskhorde[i] - d;
            }
            if (q2 == words[i] && d2 < d) {
                points[i] = points[i] + 0;
                goals[i] = goals[i] + d2;
                goalskhorde[i] = goalskhorde[i] - d;
            }
        }
    }
    int tafazol[n];
    for (int i = 0; i < n; i++) {
        tafazol[i] = goals[i] + goalskhorde[i];
    }

    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // مرتب‌سازی بر اساس امتیاز و tafazol
    sort(indices, indices + n, [&](int a, int b) {
        if (points[a] == points[b]) {
            return tafazol[a] > tafazol[b];
        }
        return points[a] > points[b];
    });
    int z4 = 1;
    int z5 = 0;
    for (int i = 0; i < n; i++) {
        int index = indices[i];
        cout << "rank ";
        cout<<z4;
        if(points[index]==points[indices[i+1]] && tafazol[index]==tafazol[indices[i+1]]){
            z5++;
        }
        if((points[index]>points[indices[i+1]]) || (points[index]==points[indices[i+1]] && tafazol[index]>tafazol[indices[i+1]])){
            z4 = z4 + z5 + 1;
            z5 = 0;
        }
        cout<< " | " << words[index] << " | points : " << points[index] << " | tafazol : " << tafazol[index] << endl;
    }
    return 0;
}