#include <cassert>
#include <iostream>
#include <numeric>
#include <cstdlib>
constexpr int g_consoleLines{ 25 };
class Tile
{
    private:
    int m_val{};
    public:
    Tile(int val=0):
    m_val{val} {}
    bool isEmpty()
    {
        if(m_val==0)
        return true;
        else return false;
    }
    int getNum(){return m_val;}
    friend std::ostream& operator<<(std::ostream& ob,Tile& T)
    {
    if(T.getNum()==0)
    std::cout<<"    ";
    else if(T.getNum()>9)
    std::cout<<" "<<T.getNum()<<" ";   //Double digit number
    else
    std::cout<<"  "<<T.getNum()<<" ";  //Single digit number
    return ob;
    }
};
class Board
{
    private:
    Tile m_board[4][4]{Tile{1},Tile{2},Tile{3},Tile{4},Tile{5},Tile{6},Tile{7},Tile{8},Tile{9},Tile{10},Tile{11},Tile{12},Tile{13},Tile{14},Tile{15},Tile{16}};
    public:
    Board()
    {
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
            m_board[i][j]=Tile(((3*i)+i)+j+1);
        }
    }
    m_board[3][3]=Tile(0);
    }
    friend std::ostream& operator<<(std::ostream& ob,Board b)
    {
        for(int i=0;i<g_consoleLines;i++)
        std::cout<<"\n";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            std::cout<<b.m_board[i][j];
        std::cout<<"\n";
        }
        return ob;
    }
    void moveTile(char ch)
    {
        int temp1;
        int temp2;
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<4;j++)
                if(m_board[i][j].getNum()==0)
                {
                    temp1=i;
                    temp2=j;
                }
        }
        if(ch=='a')
        {
            if((temp2-1)<0)
            std::cout<<"Cannot move left\n";
            else
            {
                int temp=m_board[temp1][temp2-1].getNum();
                m_board[temp1][temp2]=Tile(temp);
                m_board[temp1][temp2-1]=Tile(0);
                std::cout<<*this;
            }
        }
        if(ch=='w')
        {
            if((temp1-1)<0)
            std::cout<<"Cannot move up\n";
            else
            {
                int temp=m_board[temp1-1][temp2].getNum();
                m_board[temp1][temp2]=Tile(temp);
                m_board[temp1-1][temp2]=Tile(0);
                std::cout<<*this;
            }
        }
        if(ch=='d')
        {
            if((temp2+1)>3)
            std::cout<<"Cannot move right\n";
            else
            {
                int temp=m_board[temp1][temp2+1].getNum();
                m_board[temp1][temp2]=Tile(temp);
                m_board[temp1][temp2+1]=Tile(0);
                std::cout<<*this;
            }
        }
        if(ch=='s')
        {
            if((temp1+1)>3)
            std::cout<<"Cannot move down\n";
            else
            {
                int temp=m_board[temp1+1][temp2].getNum();
                m_board[temp1][temp2]=Tile(temp);
                m_board[temp1+1][temp2]=Tile(0);
                std::cout<<*this;
            }
        }
        if(ch=='r')
        {
            BoardRandomize();
        }
    }
    void BoardRandomize()
    {
        int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                int temp=rand()%16;
                while(arr[temp]==-1)
                {
                    temp=rand()%16;
                }
                m_board[i][j]=temp;
                arr[temp]=-1;

            }
        }
        std::cout<<*this;
    }
};
namespace UserInput
{
bool isValid(char ch)
{
    if(ch=='w' || ch=='a' || ch=='s' || ch=='d' || ch=='q' || ch=='r' || ch=='g' || ch=='q')
    return true;
    else return false;
}
char getInput()
{
    char temp{};
    std::cin>>temp;
    return temp;
}
char getCommand()
{
    char tempo{};
    while(!isValid(tempo))
    tempo=getInput();
    return tempo;
}
};
int main()
{
    std::cout<<"Here are the instructions of the game\n ";
    std::cout<<"Press w to move the blank tile up\n ";
    std::cout<<"Press a to move the blank tile left\n ";
    std::cout<<"Press s to move the blank tile down\n ";
    std::cout<<"Press d to move the blank tile right\n ";
    std::cout<<"Press r to randomise the board\n ";
    std::cout<<"Press 1 to START\n ";
    std::cout<<"Press q to exit\n ";
    while(1)
    {
        char temp1;
        std::cin>>temp1;
        if(temp1=='1')
        break;
    }
    Board b;
    std::cout<<b;
    char temp2;
    while(1)
    {
        while(1)
        {
            temp2=UserInput::getCommand();
            if(temp2=='q')
            {
                std::cout<<"GoodBye";
                return 0;
            }
            else
                b.moveTile(temp2);
        }
    }

    
    return 0;
}