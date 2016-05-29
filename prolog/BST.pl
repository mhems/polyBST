%% -*- Mode: Prolog; -*-

size(empty, 0).
size(node(_, L, R, _), S) :- size(L, LS),
                             size(R, RS),
                             S is 1 + LS + RS.

add(empty, E, C, node(E, empty, empty, C)).
add(node(V1, L1, R1, C), E, C, node(V1, L2, R1, C)) :-
    call(C, E, V1, R),
    R < 0,
    add(L1, E, C, L2).
add(node(V, L, R, C), V, C, node(V, L, R, C)).
add(node(V1, L1, R1, C), E, C, node(V1, L1, R2, C)) :-
    call(C, E, V1, R),
    R > 0,
    add(R1, E, C, R2).

contains(node(V, _, _, _), V).
contains(node(V, L, _, C), E) :-
    call(C, E, V, Res),
    Res < 0,
    contains(L, E).
contains(node(V, _, R, C), E) :-
    call(C, E, V, Res),
    Res > 0,
    contains(R, E).

list(empty, []).
list(node(V, L, R, _), Z) :- list(L, LL),
                             list(R, RL),
                             VRL = [V|RL],
                             append(LL, VRL, Z).
