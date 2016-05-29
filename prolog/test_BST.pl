%% -*- Mode: Prolog; -*-

comp(A, A, 0).
comp(A, B, -1) :- A < B.
comp(A, B, 1) :- A > B.

verify(A, A).
verify(Exp, Act) :- Exp \= Act,
                    format('expected ~p, received ~p~n', [Exp, Act]).

addEach(_, T, T, A, Hi) :- A =:= Hi + 1.
addEach(Comp, T, T1, Itr, Hi) :- Itr =< Hi,
                                 add(T, Itr, Comp, TR),
                                 I is Itr + 1,
                                 addEach(Comp, TR, T1, I, Hi).

containsEach(_, A, Hi) :- A =:= Hi + 1.
containsEach(T, Itr, Hi) :- Itr =< Hi,
                            contains(T, Itr),
                            I is Itr + 1,
                            containsEach(T, I, Hi).

go :-
    T1 = empty,
    size(T1, S1), verify(0, S1),
    list(T1, L1), verify([], L1),
    add(T1, 5, comp, T2),
    contains(T2, 5),
    size(T2, S2), verify(1, S2),
    list(T2, L2), verify([5], L2),
    addEach(comp, T2, T3, 0, 10),
    size(T3, S3), verify(11, S3),
    list(T3, L3), verify([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], L3),
    containsEach(T3, 0, 10),
    \+ contains(T3, 11).
