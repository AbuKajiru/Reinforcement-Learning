# Reinforcement-Learning
The following files consist of a list of project files that I created during the Machine Learning Course on Reinforcement Learning at the University of Nairobi.
It involves a single project that dictates to train the computer on the proper suitable path to take from any initial state to a predefined goal state.
There are four rooms, i.e: A, B, C and D.
In which case room A has a door that can access room B and vice-versa.
In which case room B has a door that can access room C and vice-versa.
In which case room C has a door that can access room D and vice-versa.

NOTE:
When in room A the computer(our agent in training) cannot access room (C and D) and vice-versa.
When in room B the computer(our agent in training) cannot access room D and vice-versa.

The room might look like this:

|-----------|-------------|  
|           |             |
|  ROOM B       ROOM C    |
|                         |
|-------    |--------     |  
|           |             |
|  ROOM A   |   ROOM D    |
|           |             |
|-----------|-------------|

In order to represent the data in a reward matrix in the begininning I represented the dashes as shown below with (-1) in the arrays.

State/Action    A   B   C   D
    A           -   0   -   -
    B           0   -   0   - 
    C           -   0   -   100
    D           -   -   0   100

In this case Room D is the goal state and any action that moves into the room is rewarded 100 and 0 otherwise and a (-) represents actions that cannot be allowed because of the non-existent doors.

The Q matrix representing the memory is initialised to zero and is updated within each episode.

I was however unable to get it to completely work because of the random number generator. It does not generate the required values, which are important since ending one epoch is determined by whether or not we can randomly choose our next state as the final state.

But for your convenience try and run only one epoch or two. (If you can help me fix the random number generator please do and let me know).
