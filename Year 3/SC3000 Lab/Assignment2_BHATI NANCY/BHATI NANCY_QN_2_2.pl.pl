%query2
queen_of_UK(queen_elizabeth).

male(prince_charles).
male(prince_andrew).
male(prince_edward).
female(princess_ann).

parent(queen_elizabeth, prince_charles).
parent(queen_elizabeth, prince_ann).
parent(queen_elizabeth, prince_andrew).
parent(queen_elizabeth, prince_edward).

%order of succession
successor(X) :- parent(queen_elizabeth, X).

%line of succession
line_of_succession(Order) :- findall(X, successor(X), Order).