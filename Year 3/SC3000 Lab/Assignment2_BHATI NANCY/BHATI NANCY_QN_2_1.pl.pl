%query1

queen_of_UK(queen_elizabeth).

male(prince_charles).
male(prince_andrew).
male(prince_edward).
female(princess_ann).

parent(queen_elizabeth, prince_charles).
parent(queen_elizabeth, prince_ann).
parent(queen_elizabeth, prince_andrew).
parent(queen_elizabeth, prince_edward).

%the order of birth
born_before(prince_charles, princess_ann).
born_before(princess_ann, prince_andrew).
born_before(prince_andrew, prince_edward).

% the succession rule based on the old royal succession order
successor(X) :-  male(X),\+ (born_before(Y, X), male(Y)).%male first
% any remaining male successors in birth order
successor(X) :- male(X), \+ (born_before(X, Y), \+male(Y)).
%  After males,a female successor if no earlier-born female exists
successor(X) :- female(X),\+ (born_before(Y, X), female(Y)).

%line of succession.
line_of_succession(Order) :- findall(X, successor(X), Order).
