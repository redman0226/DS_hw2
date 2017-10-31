Pseudo code: 
1. Store the sequence of the players and find which player start the game 
2. While(there is a vocabulary) do
3.   If(the order is clockwise) then 
4.    For(i<length of vocabulary): 
5.     For every player, put backward the letter of vocabulary. 
6.    Output the player who takes the last letter of vocabulary. 
7.    If(the last letter of vocabulary is vowel) then 
8.     Keep the same order of players taking the letter. 
9.    Else 
10.     Change the order to counterclockwise.  
11.   Else  
12.    For(i<length of vocabulary): 
13.     For every player, put forward the letter of vocabulary. 
14.    Output the player who takes the last letter of vocabulary. 
15.    If(the last letter of vocabulary is vowel) then 
16.     Keep the same order of players taking the letter. 
17.    Else 
18.     Change the order to clockwise. 
19. Output the last player and letters. 
 
 
 
