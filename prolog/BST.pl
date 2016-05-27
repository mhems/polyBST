%% -*- Mode: Prolog; -*-

size(empty, 0).
size(node(_, L, R), S) :- size(L, LS), size(R, RS), S is 1 + LS + RS.

add(empty, E, node(E, empty, empty)).
add(node(V1, L1, R1), E, node(V1, L2, R1)) :- E < V1, add(L1, E, L2).
add(node(V1, L1, R1), E, node(V1, L1, R2)) :- E > V1, add(R1, E, R2).

contains(node(V, _, _), V).
contains(node(V, L, _), E) :- E < V, contains(L, E).
contains(node(V, _, R), E) :- E > V, contains(R, E).

list(empty, []).
list(node(V, L, R), Z) :- list(L, LL), list(R, RL),
                          VRL = [V|RL], append(LL, VRL, Z).
