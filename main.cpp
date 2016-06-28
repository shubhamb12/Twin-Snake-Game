#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool kill;
const int width=20,height=20;
int x1,y1,x2,y2,fx1,fy1,fx2,fy2,score;
int tx1[100],ty1[100],tx2[100],ty2[100],nt1=0,nt2=0;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir1,dir2;
void init()
{
    kill = false;
    dir1 = STOP;
    dir2 = STOP;
    x1 = width / 3;
    y1 = height / 3;
    x2 = (2*width) / 3;
    y2 = (2*height) / 3;
    fx1 = rand() % width;
    fy1 = rand() % height;
    fx2 = rand() % width;
    fy2 = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int i = 0; i < width; i++)
        cout << "# ";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0||j==width-1)
              {
                   cout << "#";
                   continue;
              }
            if (i == y1 && j == x1)
                cout << "O";
            else if (i == fy1 && j == fx1)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nt1; k++)
                {
                    if (tx1[k] == j && ty1[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (i == y2 && j == x2)
                cout << "V";
            else if (i == fy2 && j == fx2)
                cout << "G";
            else
            {
                bool print = false;
                for (int k = 0; k < nt2; k++)
                {
                    if (tx2[k] == j && ty2[k] == i)
                    {
                        cout << "v";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }



        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "# ";
    cout << endl;
    cout << "Score: " << score << endl;
    //cout <<"length 1 "<<nt1<<" length 2 "<<nt2<<endl;
    cout << "G is Food For Snake V and Use J,K,L and I to control X \nF is Food For Snake O and Use A,S,D and W to control O\nPress x to end the Game";
}
void Input()
{
    int i=2;
    while (_kbhit()&&i--)
    {
        switch (_getch())
        {
            case 'a':
                dir1 = LEFT;
                break;
            case 'd':
                dir1 = RIGHT;
                break;
            case 'w':
                dir1 = UP;
                break;
            case 's':
                dir1 = DOWN;
                break;
            case 'j':
                dir2 = LEFT;
                break;
            case 'l':
                dir2 = RIGHT;
                break;
            case 'i':
                dir2 = UP;
                break;
            case 'k':
                dir2 = DOWN;
                break;
            case 'x':
                kill = true;
                break;
            default:
                break;
        }


    }
}
void Logic1()
{
    int prevX = tx1[0];
    int prevY = ty1[0];
    int prev2X, prev2Y;
    tx1[0] = x1;
    ty1[0] = y1;
    for (int i = 1; i < nt1; i++)
    {
        prev2X = tx1[i];
        prev2Y = ty1[i];
        tx1[i] = prevX;
        ty1[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir1)
    {
        case LEFT:
            x1--;
            break;
        case RIGHT:
            x1++;
            break;
        case UP:
            y1--;
            break;
        case DOWN:
            y1++;
            break;
        default:
            break;
    }
  // if (x1 > width || x1 < 0 || y1 > height || y1 < 0)
     // kill = true;
    if (x1 >= width) x1 = 0; else if (x1 < 0) x1 = width - 1;
    if (y1 >= height) y1 = 0; else if (y1 < 0) y1 = height - 1;

    for (int i = 0; i < nt1; i++)
        if (tx1[i] == x1 && ty1[i] == y1)
            kill = true;

    if (x1 == fx1 && y1 == fy1)
    {
        score += 10;
        fx1 = rand() % width;
        fy1 = rand() % height;
        nt1++;
    }
}

void Logic2()
{
    int prevX = tx2[0];
    int prevY = ty2[0];
    int prev2X, prev2Y;
    tx2[0] = x2;
    ty2[0] = y2;
    for (int i = 1; i < nt2; i++)
    {
        prev2X = tx2[i];
        prev2Y = ty2[i];
        tx2[i] = prevX;
        ty2[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir2)
    {
        case LEFT:
            x2--;
            break;
        case RIGHT:
            x2++;
            break;
        case UP:
            y2--;
            break;
        case DOWN:
            y2++;
            break;
        default:
            break;
    }
    //if (x2 > width || x2 < 0 || y2 > height || y2 < 0)
     // kill = true;
    if (x2 >= width) x2 = 0; else if (x2 < 0) x2 = width - 1;
    if (y2 >= height) y2 = 0; else if (y2 < 0) y2 = height - 1;

    for (int i = 0; i < nt2; i++)
        if (tx2[i] == x2 && ty2[i] == y2)
            kill = true;

    if (x2 == fx2 && y2 == fy2)
    {
        score += 10;
        fx2 = rand() % width;
        fy2 = rand() % height;
        nt2++;
    }
}
int main()
{
    init();
    while (!kill)
    {
        Draw();
        Input();
        Logic1();
        Logic2();
        Sleep(50); //sleep(10);
    }
    return 0;
}
