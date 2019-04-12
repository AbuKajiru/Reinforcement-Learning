/*P15/37738/2016
Abubakar Kajiru Mohamed*/

#include <iostream> // For standard input and output
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

using namespace std;

int main()
{
    int i = 4;
    int j = 4;
    int myStateDiagram[4][4];
    int QMatrix[4][4];
    int startingState;
    int currentState;
    int myRandAction;
    int myRandState;
    int episodes;

    bool initialization;

    double QValue;
    double maxValue;
    double learningRate;

    myStateDiagram[0][0] = -1;
    myStateDiagram[0][1] = 0;
    myStateDiagram[0][2] = -1;
    myStateDiagram[0][3] = -1;
    myStateDiagram[1][0] = 0;
    myStateDiagram[1][1] = -1;
    myStateDiagram[1][2] = 0;
    myStateDiagram[1][3] = -1;
    myStateDiagram[2][0] = -1;
    myStateDiagram[2][1] = 0;
    myStateDiagram[2][2] = -1;
    myStateDiagram[2][3] = 100;
    myStateDiagram[3][0] = -1;
    myStateDiagram[3][1] = -1;
    myStateDiagram[3][2] = 0;
    myStateDiagram[3][3] = 100;

    learningRate = 100;

    srand(time(0));

    //display state diagram
    for(i=0;i<4;i++)
    {
        cout << "[";
        for(j=0;j<4;j++)
        {
            cout << myStateDiagram[i][j] << "\t";
        }
        cout << "]" << endl;
    }

    while(learningRate>=1||learningRate<=0)
    {
        cout << "\nPlease Enter Learning Rate: (The Value Should be Between 0 and 1) \t";
        cin >> learningRate;

        if(learningRate>=1||learningRate<=0)
        {
            cout << "\nYou Entered An Invalid Value!\nPlease Try Again!" << endl;
        }

    }

    cout << "\nYour Learning Rate Is: \t" << learningRate << "\n" << endl;

    cout << "Your Q Matrix (Initialized to Zeros Before The Epochs.)\n" << endl;

    //initiate Q matrix to zero
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            QMatrix[i][j] = 0;
        }
    }

    //display q matrix
     for(i=0;i<4;i++)
    {
        cout << "[";
        for(j=0;j<4;j++)
        {
            cout << QMatrix[i][j] << "\t";
        }
        cout << "]" << endl;
    }

    //select number of episodes
    cout << "Please enter number of episodes you want (If unsure enter 10)\t";
    cin >> episodes;

    if(episodes>0)
    {
        while(episodes>0)
        {
            srand(time(0));

            cout << "------------------********-----------------" << endl;
            cout << "|------------------------------------------|" << endl;
            cout << "------------------********-----------------" << endl;
            cout << "Episode: \t" << episodes << endl;

            //pick random state
            myRandState = ((rand() % 4) + 0);

            startingState = myRandState;

            cout << "\nStarting State: \t" << startingState;

            currentState = 0;
            initialization = true;

            while(currentState!=3)
             {
                    if (initialization == true)
                    {
                        currentState = myRandState;
                        initialization = false;
                    }

                    //select one possible action
                    myRandAction = ((rand() % 4) + 0);

                    while(myStateDiagram[currentState][myRandAction]==-1)
                    {
                           myRandAction = ((rand() % 4) + 0);
                    }

                    cout << "\nPossible Action Chosen: \t" << myRandAction;

                    maxValue = 0;

                    for(i=0;i<4;i++)
                    {
                        if(QMatrix[myRandAction][i]!=-1)
                        {
                            int tempValue = QMatrix[myRandAction][i];

                            if(tempValue>maxValue)
                            {
                                maxValue = tempValue;
                            }
                        }
                    }

                    QValue = myStateDiagram[currentState][myRandAction] + learningRate * maxValue;

                    QMatrix[currentState][myRandAction] = QValue;

                    currentState = myRandAction;

            }

            episodes--;

            cout << "\nEpisodes: " << episodes;
        }
    }

    cout << "\n";
    //display q matrix
     for(i=0;i<4;i++)
    {
        cout << "[";
        for(j=0;j<4;j++)
        {
            cout << QMatrix[i][j] << "\t";
        }
        cout << "]" << endl;
    }

    return 0;
}
