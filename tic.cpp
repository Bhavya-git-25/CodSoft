#include<iostream>
using namespace std;

char b[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void showBoard()
{
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<b[i][j];
            if(j!=2)
                cout<<" | ";
        }

        cout<<"\n";

        if(i!=2)
            cout<<"---------\n";
    }
    cout<<"\n";
}

bool win(char ch)
{
    for(int i=0;i<3;i++)
    {
        if(b[i][0]==ch && b[i][1]==ch && b[i][2]==ch)
            return true;
    }

    for(int i=0;i<3;i++)
    {
        if(b[0][i]==ch && b[1][i]==ch && b[2][i]==ch)
            return true;
    }

    if(b[0][0]==ch && b[1][1]==ch && b[2][2]==ch)
        return true;

    if(b[0][2]==ch && b[1][1]==ch && b[2][0]==ch)
        return true;

    return false;
}

bool draw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(b[i][j]!='X' && b[i][j]!='O')
                return false;
        }
    }

    return true;
}

int minimax(bool ai)
{
    if(win('O'))
        return 10;

    if(win('X'))
        return -10;

    if(draw())
        return 0;

    if(ai)
    {
        int best = -1000;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b[i][j]!='X' && b[i][j]!='O')
                {
                    char temp = b[i][j];

                    b[i][j]='O';

                    int score = minimax(false);

                    b[i][j]=temp;

                    if(score > best)
                        best = score;
                }
            }
        }

        return best;
    }
    else
    {
        int best = 1000;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b[i][j]!='X' && b[i][j]!='O')
                {
                    char temp = b[i][j];

                    b[i][j]='X';

                    int score = minimax(true);

                    b[i][j]=temp;

                    if(score < best)
                        best = score;
                }
            }
        }

        return best;
    }
}

void computerMove()
{
    int bestScore = -1000;
    int r = -1;
    int c = -1;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(b[i][j]!='X' && b[i][j]!='O')
            {
                char temp = b[i][j];

                b[i][j]='O';

                int score = minimax(false);

                b[i][j]=temp;

                if(score > bestScore)
                {
                    bestScore = score;
                    r = i;
                    c = j;
                }
            }
        }
    }

    b[r][c]='O';
}

void playerMove()
{
    int pos;

    cout<<"Enter position (1-9): ";
    cin>>pos;

    int row = (pos-1)/3;
    int col = (pos-1)%3;

    if(pos<1 || pos>9 || b[row][col]=='X' || b[row][col]=='O')
    {
        cout<<"Wrong Move! Try Again\n";
        playerMove();
    }
    else
    {
        b[row][col]='X';
    }
}

int main()
{
    cout<<"TIC TAC TOE\n";
    cout<<"Player = X\n";
    cout<<"Computer = O\n";

    while(true)
    {
        showBoard();

        playerMove();

        if(win('X'))
        {
            showBoard();
            cout<<"You Win\n";
            break;
        }

        if(draw())
        {
            showBoard();
            cout<<"Match Draw\n";
            break;
        }

        computerMove();

        if(win('O'))
        {
            showBoard();
            cout<<"Computer Wins\n";
            break;
        }

        if(draw())
        {
            showBoard();
            cout<<"Match Draw\n";
            break;
        }
    }

    return 0;
}