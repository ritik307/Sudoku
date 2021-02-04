    #include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int finish=0;
void result(){
    cout<<"\n\n\n";
    cout<<"\t\t\t .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. "<<endl;
    cout<<"\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |"<<endl;
    cout<<"\t\t\t| |  _______     | || |  _________   | || |    _______   | || | _____  _____ | || |   _____      | || |  _________   | |"<<endl;
    cout<<"\t\t\t| | |_   __ \\    | || | |_   ___  |  | || |   /  ___  |  | || ||_   _||_   _|| || |  |_   _|     | || | |  _   _  |  | |"<<endl;
    cout<<"\t\t\t| |   | |__) |   | || |   | |_  \\_|  | || |  |  (__ \\_|  | || |  | |    | |  | || |    | |       | || | |_/ | | \\_|  | |"<<endl;
    cout<<"\t\t\t| |   |  __ /    | || |   |  _|  _   | || |   '.___`-.   | || |  | '    ' |  | || |    | |   _   | || |     | |      | |"<<endl;
    cout<<"\t\t\t| |  _| |  \\ \\_  | || |  _| |___/ |  | || |  |`\\____) |  | || |   \\ `--' /   | || |   _| |__/ |  | || |    _| |_     | |"<<endl;
    cout<<"\t\t\t| | |____| |___| | || | |_________|  | || |  |_______.'  | || |    `.__.'    | || |  |________|  | || |   |_____|    | |"<<endl;
    cout<<"\t\t\t| |              | || |              | || |              | || |              | || |              | || |              | |"<<endl;
    cout<<"\t\t\t| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |"<<endl;
    cout<<"\t\t\t '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' "<<endl;
    cout<<"\n\n";
}
void print(vector<vector<int>>& board){           
    cout<<"\t\t\t\t\t\t\t\t  _____________________________________"<<endl;
    cout<<"\t\t\t\t\t\t\t\t||_____________________________________||"<<endl;
    for(int i=0;i<=8;i++){
        if(i==3 || i==6){  
            cout<<"\t\t\t\t\t\t\t\t||_____________________________________||"<<endl;                                     
            cout<<"\t\t\t\t\t\t\t\t||_____________________________________||"<<endl;
        }
        for(int j=0;j<=8;j++){
            if(j==3 || j==6)
                cout<<"|| ";
            else if(j==0)
                cout<<"\t\t\t\t\t\t\t\t|| ";
            else
                cout<<"+ "; 
            if(board[i][j]!=0)           
                cout<<board[i][j]<<" ";
            if(board[i][j]==0)
                cout<<"_ ";    
            if(j==8)
                cout<<"||";
        }
        cout<<"\n";
    }
    cout<<"\t\t\t\t\t\t\t\t||_____________________________________||"<<endl;
    cout<<"\t\t\t\t\t\t\t\t||_____________________________________||"<<endl;
    // cout<<"===========LO KAR DIYA SOLVE==========="<<endl;
}
bool full(vector<vector<int>>& board){
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            if(board[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

vector<int> findPossible(vector<vector<int>>&board,int x,int y){
    vector<int> possible(10,0);
    for(int i=0;i<=8;i++){
        if(board[x][i]!=0){
            possible[board[x][i]]=1;
        }
    }

    for(int j=0;j<=8;j++){
        if(board[j][y]!=0){
            possible[board[j][y]]=1;
        }
    }

    int temp1,temp2;
    if(x>=0 && x<=2){
        temp1=0;
    }
    else if(x>=3 && x<=5){
        temp1=3;
    }
    else{
        temp1=6;
    }

    if(y>=0 && y<=2){
        temp2=0;
    }
    else if(y>=3 && y<=5){
        temp2=3;
    }
    else{
        temp2=6;
    }
    for(int i=temp1;i<temp1+3;i++){
        for(int j=temp2;j<temp2+3;j++){
            if(board[i][j]!=0){
                possible[board[i][j]]=1;
            }
        }
    }

    for(int i=1;i<10;i++){
        if(possible[i]==0){
            possible[i]=i;
        }
        else{
            possible[i]=0;
        }
    }
    return possible;
}

void solver(vector<vector<int>>& board){
    if(full(board)){
        finish=1;
        result();
        //cout<<"===========LO KAR DIYA SOLVE==========="<<endl;
        print(board);
        //cout<<"===========LO KAR DIYA SOLVE==========="<<endl;
        return;
       
    }
    else{
        //cout<<"Not full"<<endl;
        int x=-1;
        int y=-1;
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                if(board[i][j]==0){
                    x=i;
                    y=j;
                    break;
                } 
            }
            if(x!=-1 || y!=-1)
                    break;
        }
        vector<int> possibleChance=findPossible(board,x,y);
        
        // cout<<"x: "<<x<<" y "<<y<<endl;
        // for(int i=1;i<10;i++){
        //     cout<<"e"<<i<<" : "<<possibleChance[i]<<endl;
        // }

        for(int i=1;i<10;i++){
            if(possibleChance[i]!=0){
                board[x][y]=possibleChance[i];
                print(board);
                //cout<<"======================================="<<endl;
                solver(board);
                if(finish==1)
                    return;
            }
            
        }
        board[x][y]=0;
    }
}

void intro(){
    cout<<"\n\n\n\n";
    cout<<"\t\t\t";
    cout<<"   SSSSSSSSSSSSSSS UUUUUUUU      UUUUUUUU DDDDDDDDDDDDD              OOOOOOOOO      KKKKKKKKK    KKKKKKK UUUUUUUU     UUUUUUUU"<<endl;
    cout<<"\t\t\t";
    cout<<" SS:::::::::::::::S U::::::U     U::::::U D::::::::::::DDD         OO:::::::::OO    K:::::::K    K:::::K U::::::U     U::::::U"<<endl;
    cout<<"\t\t\t";
    cout<<"S:::::SSSSSS::::::S U::::::U     U::::::U D:::::::::::::::DD     OO:::::::::::::OO  K:::::::K    K:::::K U::::::U     U::::::U"<<endl;
    cout<<"\t\t\t";
    cout<<"S:::::S     SSSSSSS UU:::::U     U:::::UU DDD:::::DDDDD:::::D   O:::::::OOO:::::::O K:::::::K   K::::::K UU:::::U     U:::::UU"<<endl;
    cout<<"\t\t\t";
    cout<<"S:::::S              U:::::U     U:::::U    D:::::D    D:::::D  O::::::O   O::::::O KK::::::K  K:::::KKK  U:::::U     U:::::U"<<endl;
    cout<<"\t\t\t";
    cout<<"S:::::S              U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K:::::K K:::::K     U:::::D     D:::::U"<<endl;
    cout<<"\t\t\t";
    cout<<" S::::SSSS           U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K::::::K:::::K      U:::::D     D:::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"  SS::::::SSSSS      U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K:::::::::::K       U:::::D     D:::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"    SSS::::::::SS    U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K:::::::::::K       U:::::D     D:::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"       SSSSSS::::S   U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K::::::K:::::K      U:::::D     D:::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"            S:::::S  U:::::D     D:::::U    D:::::D     D:::::D O:::::O     O:::::O   K:::::K K:::::K     U:::::D     D:::::U" <<endl;
    cout<<"\t\t\t"; 
     cout<<"            S:::::S  U::::::U   U::::::U    D:::::D    D:::::D  O::::::O   O::::::O KK::::::K  K:::::KKK  U::::::U   U::::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"SSSSSSS     S:::::S  U:::::::UUU:::::::U  DDD:::::DDDDD:::::D   O:::::::OOO:::::::O K:::::::K   K::::::K  U:::::::UUU:::::::U" <<endl;
    cout<<"\t\t\t";
    cout<<"S::::::SSSSSS:::::S   UU:::::::::::::UU   D:::::::::::::::DD     OO:::::::::::::OO  K:::::::K    K:::::K   UU:::::::::::::UU"  <<endl;
    cout<<"\t\t\t";
    cout<<"S:::::::::::::::SS      UU:::::::::UU     D::::::::::::DDD         OO:::::::::OO    K:::::::K    K:::::K     UU:::::::::UU"    <<endl;
    cout<<"\t\t\t";
    cout<<" SSSSSSSSSSSSSSS          UUUUUUUUU       DDDDDDDDDDDDD              OOOOOOOOO      KKKKKKKKK    KKKKKKK       UUUUUUUUU"      <<endl;

}
vector<vector<int>> boardmaker(){
    vector<vector<int>> board(9,vector<int>(9,0));
    int check=1;
    cout<<"\n\n\n\t\t\t\t\t";
    cout<<"*********************************************************************************"<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"\t\t    E N T E R   V A L U E S   T O   S U D O K U "<<endl;
    cout<<"\t\t\t\t\t";
    cout<<"*********************************************************************************"<<endl;
    while(check!=0){
        int x,y,val;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\tEnter x: ";
        cin>>x;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\tEnter y: ";
        cin>>y;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\tEnter value : ";
        cin>>val;
        //cout<<"\t\t\t\t\t\t\t*";
        board[x][y]=val;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t---------------------------------"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\t1.TO CONTINUE"<<endl;
        cout<<"\t\t\t\t\t";    
        cout<<"\t\t\t\t0.TO QUIT"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\tEnter your choice: ";
        cin>>check;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t---------------------------------"<<endl;
    }
    cout<<"\t\t\t\t\t";
    cout<<"*********************************************************************************"<<endl;
    return board;
}

int main(){
    //vector<vector<int>> board(9,vector<int>(9,0));
    vector<vector<int>> board(9,vector<int>(9,0));
    int choice=1;
    intro();
    board=boardmaker();
    cout<<"\n";
    print(board);
    cout<<"\n";
    while(1){
        cout<<"\t\t\t\t\t";
        cout<<"*********************************************************************************"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\tS H O U L D   W E   S T A R T   T H E   M A G I C "<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"*********************************************************************************"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\t1.YES!! Lets Go"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\t2.RE-ENTER THE VALUES"<<endl;
        cout<<"\t\t\t\t\t";
        cout<<"\t\t\t\tENTER YOUR CHOICE: ";
        cin>>choice;
        if(choice==2){
            board=boardmaker();
            cout<<"\n";
            print(board);
            cout<<"\n";
        }
        else if(choice==1){
            cout<<"\t\t\t\t\t";
            cout<<"*********************************************************************************"<<endl;
            break;
        }
       
    }
    solver(board);
    //print(board);
    system("pause");
    return 0;
}